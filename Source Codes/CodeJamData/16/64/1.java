import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static int r, c;
	static boolean map[][] = new boolean[r][c];
	static int dist[][];
	static long queue[];
	static int si, sj, ei, ej;

	static long pair(int a, int b) {
		return (a & 0xffffffffL) | (long) b << 32;
	}
	
	static int first(long a) {
		return (int) a;
	}

	static int second(long a) {
		return (int) (a >> 32);
	}
	
	static final int DIJ[] = {0, 1, 0, -1, 0};

	static int getDist() {
		for (int t[]: dist) {
			fill(t, Integer.MAX_VALUE);
		}
		dist[si][sj] = 0;
		queue[0] = pair(si, sj);
		int queueHead = 0;
		int queueTail = 1;
		do {
			long cur = queue[queueHead++];
			int i = first(cur);
			int j = second(cur);
			int dis = dist[i][j];
			for (int d = 0; d < 4; d++) {
				int ni = i + DIJ[d];
				int nj = j + DIJ[d + 1];
				if (ni >= 0 && ni < r && nj >= 0 && nj < c && map[ni][nj] && dist[ni][nj] == Integer.MAX_VALUE) {
					dist[ni][nj] = dis + 1;
					queue[queueTail++] = pair(ni, nj);
				}
			}
		} while (queueHead < queueTail);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == (dist[i][j] == Integer.MAX_VALUE)) {
					throw new AssertionError();
				}
			}
		}
		return dist[ei][ej];
	}

	static final boolean nei[] = new boolean[512];
	static {
		no: for (int no = 0; no < 512; no++) {
			if ((no & 0x10) != 0) {
				continue;
			}
			int no2 = no | 0x10;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int sh = (no >> (3 * i + j)) & 0x1b;
					int sh2 = (no2 >> (3 * i + j)) & 0x1b;
					if (sh == 0x11 || sh == 0xa || sh2 == 0x11 || sh2 == 0xa) {
						continue no;
					}
				}
			}
			int sig = 0;
			for (int d = 0; d < 4; d++) {
				if ((no & (1 << (3 * (DIJ[d] + 1) + (DIJ[d + 1] + 1)))) == 0) {
					sig |= 1 << d;
				}
			}
			if ((0x135f & (1 << sig)) != 0) {
				nei[no] = true;
			}
		}
	}
	
	static void solve() throws Exception {
//		System.err.println("TEST " + test);
		r = nextInt();
		c = nextInt();
		int d = nextInt();
		si = sj = ei = ej = -1;
		boolean origMap[][] = new boolean[r][c];
		for (int i = 0; i < r; i++) {
			String l = next();
			for (int j = 0; j < c; j++) {
				char ch = l.charAt(j);
				origMap[i][j] = ch != '#';
				if (ch == 'S') {
					si = i;
					sj = j;
				}
				if (ch == 'F') {
					ei = i;
					ej = j;
				}
			}
		}
		map = new boolean[r][c];
		for (int i = 0; i < r; i++) {
			arraycopy(origMap[i], 0, map[i], 0, c);
		}
		dist = new int[r][c];
		queue = new long[r * c];
		int dis = getDist();
		if (d > dis || d < abs(si - ei) + abs(sj - ej) || ((d ^ dis) & 1) != 0) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
//		int all = 0;
//		for (int i = 1; i < r - 1; i++) {
//			for (int j = 1; j < c - 1; j++) {
//				if (!map[i][j]) {
//					++all;
//				}
//			}
//		}
		boolean added[][] = new boolean[r][c];
		long queue[] = new long[2 * r * c];
		long seq[] = new long[r * c];
		int queueHead = 0, queueTail = 0, seqCnt = 0;
		for (int i = 1; i < r - 1; i++) {
			for (int j = 1; j < c - 1; j++) {
				if (map[i][j]) {
					continue;
				}
				int no = 0;
				for (int ii = 0; ii < 3; ii++) {
					for (int jj = 0; jj < 3; jj++) {
						if (map[i + ii - 1][j + jj - 1]) {
							no |= 1 << (3 * ii + jj);
						}
					}
				}
				if (nei[no]) {
					added[i][j] = true;
					queue[queueTail++] = pair(i, j);
				}				
			}
		}
		while (queueHead < queueTail) {
			long cur = queue[queueHead++];
			int i = first(cur);
			int j = second(cur);
			if (map[i][j]) {
				throw new AssertionError();
			}
			{
				int no = 0;
				for (int ii = 0; ii < 3; ii++) {
					for (int jj = 0; jj < 3; jj++) {
						if (map[i + ii - 1][j + jj - 1]) {
							no |= 1 << (3 * ii + jj);
						}
					}
				}
				if (!nei[no]) {
//					throw new AssertionError();
					added[i][j] = false;
					continue;
				}
			}
			seq[seqCnt++] = cur;
			map[i][j] = true;
			for (int iii = max(i - 1, 1); iii < min(i + 2, r - 1); iii++) {
				for (int jjj = max(j - 1, 1); jjj < min(j + 2, c - 1); jjj++) {
					if (map[iii][jjj] || added[iii][jjj]) {
						continue;
					}
					int no = 0;
					for (int ii = 0; ii < 3; ii++) {
						for (int jj = 0; jj < 3; jj++) {
							if (map[iii + ii - 1][jjj + jj - 1]) {
								no |= 1 << (3 * ii + jj);
							}
						}
					}
					if (nei[no]) {
						added[iii][jjj] = true;
						queue[queueTail++] = pair(iii, jjj);
					}				
				}
			}
		}
//		if (seqCnt != all) {
//			for (int i = 0; i < r; i++) {
//				for (int j = 0; j < c; j++) {
//					System.err.print((i == si && j == sj) ? 'S' : (i == ei && j == ej) ? 'F' : origMap[i][j] ? '.' : '#');
//				}
//				System.err.println();
//			}
//			System.err.println();
//			for (int i = 0; i < r; i++) {
//				for (int j = 0; j < c; j++) {
//					System.err.print((i == si && j == sj) ? 'S' : (i == ei && j == ej) ? 'F' : map[i][j] ? '.' : '#');
//				}
//				System.err.println();
//			}
//			throw new AssertionError();
//		}
		int left = 0, right = seqCnt;
		while (true) {
			if (left > right) {
				throw new AssertionError();
			}
			int mid = (left + right) >>> 1;
			for (int i = 0; i < r; i++) {
				arraycopy(origMap[i], 0, map[i], 0, c);
			}
			for (int i = 0; i < mid; i++) {
				long cur = seq[i];
				map[first(cur)][second(cur)] = true;
			}
			dis = getDist();
//			System.err.println("LR " + left + " " + right + " " + mid + " " + dis + " " + d);
			if (dis < d) {
				right = mid - 1;
			} else if (dis > d) {
				left = mid + 1;
			} else {
				break;
			}
		}
		if (dis != d) {
			throw new AssertionError();
		}
		for (int i = 0; i < r - 1; i++) {
			for (int j = 0; j < c - 1; j++) {
				boolean m00 = map[i][j];
				boolean m01 = map[i][j + 1];
				boolean m10 = map[i + 1][j];
				boolean m11 = map[i + 1][j + 1];
				if (m00 && m11 && !m10 && !m01) {
					throw new AssertionError();
				}
				if (!m00 && !m11 && m10 && m01) {
					throw new AssertionError();
				}
			}
		}
		printCase();
		out.println("POSSIBLE");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				out.print((i == si && j == sj) ? 'S' : (i == ei && j == ej) ? 'F' : map[i][j] ? '.' : '#');
			}
			out.println();
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