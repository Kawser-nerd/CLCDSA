import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
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

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static final int DIJ[] = {0, 1, 0, -1, 0};

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

	static IntList edges[];
	static boolean seen[], value[];
	static int order[], pos;

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		char map[][] = new char[n][];
		int nShooters = 0;
		int shooterI[] = new int[n * m];
		int shooterJ[] = new int[n * m];
		for (int i = 0; i < n; i++) {
			map[i] = next().toCharArray();
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '-' || map[i][j] == '|') {
					shooterI[nShooters] = i;
					shooterJ[nShooters] = j;
//					System.err.println("SHOOTER " + nShooters + " " + i + " " + j);
					++nShooters;
				}
			}
		}
		edges = new IntList[2 * nShooters];
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new IntList();
		}
		int shooterH[][] = new int[n][m];
		int shooterV[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				shooterH[i][j] = shooterV[i][j] = -1;
			}
		}
		for (int s = 0; s < nShooters; s++) {
			for (int sd = 0; sd < 4; sd++) {
				int i = shooterI[s], j = shooterJ[s], d = sd;
				move: while (true) {
					i += DIJ[d];
					j += DIJ[d + 1];
					if (i < 0 || i >= n || j < 0 || j >= m) {
						break;
					}
					switch (map[i][j]) {
					case '-':
					case '|':
						if ((sd & 1) == 0) {
							edges[2 * s].push(2 * s + 1);
						} else {
							edges[2 * s + 1].push(2 * s);
						}
						break move;
					case '\\':
						d ^= 1;
						break;
					case '/':
						d ^= 3;
						break;
					case '#':
						break move;
					case '.':
						((d & 1) == 0 ? shooterH : shooterV)[i][j] = 2 * s + (sd & 1);
						break;
					default:
						throw new AssertionError();
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != '.') {
					continue;
				}
				int sh = shooterH[i][j];
				int sv = shooterV[i][j];
//				System.err.println("CELL " + i + " " + j + " " + sh + " " + sv);
				if (sh < 0) {
					if (sv < 0) {
						printCase();
						out.println("IMPOSSIBLE");
						return;
					} else {
						edges[sv ^ 1].push(sv);
					}
				} else {
					if (sv < 0) {
						edges[sh ^ 1].push(sh);
					} else {
						edges[sh ^ 1].push(sv);
						edges[sv ^ 1].push(sh);
					}
				}
			}
		}
//		for (int i = 0; i < edges.length; i++) {
//			for (int j = 0; j < edges[i].size(); j++) {
//				System.err.println("EDGE " + i + " " + edges[i].get(j));
//			}
//		}
		seen = new boolean[edges.length];
		order = new int[edges.length];
		pos = 0;
		for (int i = 0; i < edges.length; i++) {
			dfs1(i);
		}
		if (pos != edges.length) {
			throw new AssertionError();
		}
		fill(seen, false);
		value = new boolean[edges.length];
		for (int i = edges.length - 1; i >= 0; i--) {
			int cur = order[i] ^ 1;
			if (!seen[cur] && !dfs2(cur, value[cur])) {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
		}
		for (int i = 0; i < nShooters; i++) {
			if (value[2 * i] && !value[2 * i + 1]) {
				map[shooterI[i]][shooterJ[i]] = '|';
			} else if (!value[2 * i] && value[2 * i + 1]) {
				map[shooterI[i]][shooterJ[i]] = '-';
			} else {
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
		}
		printCase();
		out.println("POSSIBLE");
		for (char l[]: map) {
			out.println(l);
		}
	}

	static void dfs1(int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		for (int i = 0; i < edges[cur].size(); i++) {
			dfs1(edges[cur].get(i));
		}
		order[pos++] = cur;
	}

	static boolean dfs2(int cur, boolean curValue) {
		if (seen[cur]) {
			return true;
		}
		seen[cur] = true;
		if (value[cur] != curValue) {
			return false;
		}
		if (!curValue) {
			value[cur ^ 1] = true;
		}
		for (int i = 0; i < edges[cur].size(); i++) {
			if (!dfs2(edges[cur].get(i), curValue)) {
				return false;
			}
		}
		return true;
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