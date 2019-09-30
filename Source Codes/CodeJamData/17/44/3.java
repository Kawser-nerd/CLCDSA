import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static final int DIJ[] = {0, 1, 0, -1, 0};

	static class HK {
		static int n;
		static boolean edges[][];
		static int matchingL[], matchingR[];
		static int hkDist[], hkQueue[];

		static void init() {
			edges = new boolean[n][n];
			matchingL = new int[n];
			matchingR = new int[n];
			hkDist = new int[n];
			hkQueue = new int[2 * n];
		}

		static int hopcroftKarp() {
			fill(matchingL, -1);
			fill(matchingR, -1);
			int size = 0;
			while (true) {
				fill(hkDist, -1);
				int queueHead = 0, queueTail = 0;
				for (int i = 0; i < n; i++) {
					if (matchingL[i] < 0) {
						hkQueue[queueTail++] = i;
						hkQueue[queueTail++] = 0;
					}
				}
				int resDist = -1;
				while (queueHead < queueTail) {
					int cur = hkQueue[queueHead++];
					int cdist = hkQueue[queueHead++];
					if ((cdist + Integer.MIN_VALUE) > (resDist + Integer.MIN_VALUE)) {
						break;
					}
					for (int next = 0; next < n; next++) {
						if (!edges[cur][next] || hkDist[next] != -1) {
							continue;
						}
						hkDist[next] = cdist;
						int next2 = matchingR[next];
						if (next2 < 0) {
							resDist = cdist;
						} else {
							hkQueue[queueTail++] = next2;
							hkQueue[queueTail++] = cdist + 1;
						}
					}
				}
				if (resDist == -1) {
					return size;
				}
				for (int i = 0; i < n; i++) {
					if (matchingL[i] < 0 && hopcroftKarpDfs(i, 0)) {
						++size;
					}
				}
			}
		}

		static boolean hopcroftKarpDfs(int cur, int cdist) {
			for (int next = 0; next < n; next++) {
				if (!edges[cur][next] || hkDist[next] != cdist) {
					continue;
				}
				hkDist[next] = -1;
				int next2 = matchingR[next];
				if (next2 < 0 || hopcroftKarpDfs(next2, cdist + 1)) {
					matchingR[next] = cur;
					matchingL[cur] = next;
					return true;
				}
			}
			return false;
		}
	}

	static class IntList {

		int data[] = new int[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		int get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void clear() {
			size = 0;
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void expand() {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
		}

		void insert(int index, int value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		int remove(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(int value) {
			expand();
			data[size++] = value;
		}

		int pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(int value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		int shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			int value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static void solve() throws Exception {
		int m = nextInt();
		int n = nextInt();
		int moves = nextInt();
		boolean map[][] = new boolean[n][m];
		int nSoldiers = 0;
		int soldierI[] = new int[n * m];
		int soldierJ[] = new int[n * m];
		nTurrets = 0;
		int turretI[] = new int[n * m];
		int turretJ[] = new int[n * m];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < m; j++) {
				switch (l.charAt(j)) {
				case '#':
					break;
				case '.':
					map[i][j] = true;
					break;
				case 'S':
					map[i][j] = true;
					soldierI[nSoldiers] = i;
					soldierJ[nSoldiers] = j;
					++nSoldiers;
					break;
				case 'T':
					map[i][j] = true;
					turretI[nTurrets] = i;
					turretJ[nTurrets] = j;
					++nTurrets;
					break;
				default:
					throw new AssertionError();
				}
			}
		}
		int reach[][][] = new int[nSoldiers][n][m];
		int queue[] = new int[3 * n * m];
		for (int i = 0; i < nSoldiers; i++) {
			int cReach[][] = reach[i];
			for (int a[]: cReach) {
				fill(a, -1);
			}
			cReach[soldierI[i]][soldierJ[i]] = -2;
			queue[0] = soldierI[i];
			queue[1] = soldierJ[i];
			queue[2] = 0;
			int queueHead = 0, queueTail = 3;
			do {
				int curI = queue[queueHead++];
				int curJ = queue[queueHead++];
				int curDist = queue[queueHead++];
				if (curDist == moves) {
					break;
				}
				for (int d = 0; d < 4; d++) {
					int nextI = curI + DIJ[d];
					int nextJ = curJ + DIJ[d + 1];
					if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m &&
						map[nextI][nextJ] && cReach[nextI][nextJ] == -1) {
						cReach[nextI][nextJ] = d;
						queue[queueTail++] = nextI;
						queue[queueTail++] = nextJ;
						queue[queueTail++] = curDist + 1;
					}
				}
			} while (queueHead != queueTail);
		}
		HK.n = max(nSoldiers, nTurrets);
		HK.init();
		hit = new boolean[nTurrets][n][m];
		int meetI[][] = new int[nSoldiers][nTurrets];
		int meetJ[][] = new int[nSoldiers][nTurrets];
		for (int i = 0; i < nSoldiers; i++) {
			fill(meetI[i], -1);
			fill(meetJ[i], -1);
		}
		for (int i = 0; i < nTurrets; i++) {
			boolean cHit[][] = hit[i];
			for (int d = 0; d < 4; d++) {
				int curI = turretI[i];
				int curJ = turretJ[i];
				while (true) {
					cHit[curI][curJ] = true;
					for (int j = 0; j < nSoldiers; j++) {
						if (reach[j][curI][curJ] != -1) {
							HK.edges[j][i] = true;
							meetI[j][i] = curI;
							meetJ[j][i] = curJ;
						}
					}
					curI += DIJ[d];
					curJ += DIJ[d + 1];
					if (curI < 0 || curI >= n || curJ < 0 || curJ >= m || !map[curI][curJ]) {
						break;
					}
				}
			}
		}
		int ans = HK.hopcroftKarp();
		pathI = new int[nSoldiers][];
		pathJ = new int[nSoldiers][];
		IntList curPathI = new IntList();
		IntList curPathJ = new IntList();
		for (int i = 0; i < nSoldiers; i++) {
			int j = HK.matchingL[i];
			if (j < 0) {
				continue;
			}
			int curI = meetI[i][j];
			int curJ = meetJ[i][j];
			curPathI.push(curI);
			curPathJ.push(curJ);
			while (reach[i][curI][curJ] != -2) {
				int d = reach[i][curI][curJ];
				curI -= DIJ[d];
				curJ -= DIJ[d + 1];
				curPathI.push(curI);
				curPathJ.push(curJ);
			}
			int l = curPathI.size();
			pathI[i] = new int[l];
			pathJ[i] = new int[l];
			for (int k = 0; k < l; k++) {
				pathI[i][k] = curPathI.get(l - k - 1);
				pathJ[i][k] = curPathJ.get(l - k - 1);
			}
			curPathI.clear();
			curPathJ.clear();
		}
		killed = new boolean[nTurrets];
		clear = new boolean[n][m];
		blocked = new boolean[nSoldiers];
		events = new IntList();
		for (int i = 0; i < nSoldiers; i++) {
			if (HK.matchingL[i] >= 0) {
				if (go(i) != -1) {
					throw new AssertionError();
				}
			}
		}
		printCase();
		out.println(ans);
		for (int i = 0; i < ans; i++) {
			out.println((events.get(2 * i) + 1) + " " + (events.get(2 * i + 1) + 1));
		}
	}

	static int nTurrets;
	static boolean hit[][][], killed[];
	static int pathI[][], pathJ[][];
	static boolean clear[][], blocked[];
	static IntList events;

	static int go(int soldier) {
		if (blocked[soldier]) {
			return soldier;
		}
		int curPathI[] = pathI[soldier];
		int curPathJ[] = pathJ[soldier];
		pos: for (int pos = 0;; pos++) {
			if (pos >= curPathI.length) {
				throw new AssertionError();
			}
			int curI = curPathI[pos];
			int curJ = curPathJ[pos];
			if (clear[curI][curJ]) {
				continue;
			}
			int turret;
			for (turret = 0;; turret++) {
				if (turret >= nTurrets) {
					continue pos;
				}
				if (!killed[turret] && hit[turret][curI][curJ]) {
					break;
				}
			}
			if (HK.matchingR[turret] < 0) {
				events.push(soldier);
				events.push(turret);
				killed[turret] = true;
				HK.matchingR[HK.matchingL[soldier]] = -1;
				HK.matchingL[soldier] = -1;
				return -1;
			}
			blocked[soldier] = true;
			int res = go(HK.matchingR[turret]);
			blocked[soldier] = false;
			if (res != -1) {
				events.push(soldier);
				events.push(turret);
				killed[turret] = true;
				HK.matchingR[HK.matchingL[soldier]] = -1;
				HK.matchingL[soldier] = -1;
				return res == soldier ? -1 : res;
			}
			--pos;
			continue;
		}
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}