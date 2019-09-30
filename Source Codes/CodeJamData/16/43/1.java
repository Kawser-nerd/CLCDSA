import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static final int DI[] = {1, 0, -1, 0};
	static final int DJ[] = {0, -1, 0, 1};

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
//		System.err.println("TEST " + n + " " + m);
		int p = 2 * (n + m);
		int pair[] = new int[p];
		int next[] = new int[p];
		int prev[] = new int[p];
		for (int i = 0; i < p; i++) {
			pair[i] = nextInt() - 1;
			next[i] = (i + 1) % p;
			prev[(i + 1) % p] = i;
		}
		boolean h[][] = new boolean[n + 1][m];
		boolean v[][] = new boolean[n][m + 1];
		char ans[][] = new char[n][m];
		for (int i = 0; i < p / 2; i++) {
			for (int j = 0;; j += 2) {
				if (j == p) {
					printlnCase();
					out.println("IMPOSSIBLE");
					return;
				}
				if (pair[j] < 0 || (next[pair[j]] != pair[j + 1] && prev[pair[j]] != pair[j + 1])) {
					continue;
				}
				if (next[pair[j]] != pair[j + 1]) {
					int t = pair[j];
					pair[j] = pair[j + 1];
					pair[j + 1] = t;
				}
				int ci, cj, cd;
				if (pair[j] < m) {
					ci = -1; cj = pair[j]; cd = 0;
				} else if (pair[j] < n + m) {
					ci = pair[j] - m; cj = m; cd = 1;
				} else if (pair[j] < n + 2 * m) {
					ci = n; cj = m - 1 - (pair[j] - (n + m)); cd = 2;
				} else {
					ci = n - 1 - (pair[j] - (n + 2 * m)); cj = -1; cd = 3;
				}
				int ti, tj, td;
				if (pair[j + 1] < m) {
					ti = -1; tj = pair[j + 1]; td = 2;
				} else if (pair[j + 1] < n + m) {
					ti = pair[j + 1] - m; tj = m; td = 3;
				} else if (pair[j + 1] < n + 2 * m) {
					ti = n; tj = m - 1 - (pair[j + 1] - (n + m)); td = 0;
				} else {
					ti = n - 1 - (pair[j + 1] - (n + 2 * m)); tj = -1; td = 1;
				}
//				System.err.println(ci + " " + cj + " " + cd + " --> " + ti + " " + tj + " " + td);
				while (true) {
					int ni = ci + DI[cd], nj = cj + DJ[cd];
//					System.err.println(ci + " " + cj + " " + cd + " 1-> " + ni + " " + nj + " " + cd);
					boolean a[];
					int ai;
					if ((cd & 1) == 0) {
						a = h[min(ci, ni) + 1];
						ai = cj;
//						System.err.println("h " + (min(ci, ni) + 1) + " " + cj);
					} else {
						a = v[ci];
						ai = min(cj, nj) + 1;
//						System.err.println("v " + ci + " " + (min(cj, nj) + 1));
					}
					if (a[ai]) {
						printlnCase();
						out.println("IMPOSSIBLE");
						return;
					}
					a[ai] = true;
					ci = ni; cj = nj;
					if (ci == ti && cj == tj && cd == td) {
//						System.err.println("OK");
						break;
					}
					if (ci < 0 || ci >= n || cj < 0 || cj >= m) {
						// XXX
						printlnCase();
						out.println("IMPOSSIBLE");
						return;
					}
					int nd = (cd + 3) & 3;
					ni = ci + DI[nd]; nj = cj + DJ[nd];
//					System.err.println(ci + " " + cj + " " + cd + " 2-> " + ni + " " + nj + " " + nd);
					if ((nd & 1) == 0) {
						a = h[min(ci, ni) + 1];
						ai = cj;
//						System.err.println("h " + (min(ci, ni) + 1) + " " + cj);
					} else {
						a = v[ci];
						ai = min(cj, nj) + 1;
//						System.err.println("v " + ci + " " + (min(cj, nj) + 1));
					}
					if (!a[ai]) {
						ans[ci][cj] = (cd & 1) == 0 ? '\\' : '/';
						cd = nd;
						continue;
					}
					nd = (cd + 1) & 3;
					ni = ci + DI[nd]; nj = cj + DJ[nd];
//					System.err.println(ci + " " + cj + " " + cd + " 3-> " + ni + " " + nj + " " + nd);
					if ((nd & 1) == 0) {
						a = h[min(ci, ni) + 1];
						ai = cj;
//						System.err.println("h " + (min(ci, ni) + 1) + " " + cj);
					} else {
						a = v[ci];
						ai = min(cj, nj) + 1;
//						System.err.println("v " + ci + " " + (min(cj, nj) + 1));
					}
					if (!a[ai]) {
						ans[ci][cj] = (cd & 1) == 0 ? '/' : '\\';
						cd = nd;
						continue;
					}
					printlnCase();
					out.println("IMPOSSIBLE");
					return;
				}
				next[prev[pair[j]]] = next[pair[j]];
				prev[next[pair[j]]] = prev[pair[j]];
				next[pair[j]] = -1;
				prev[pair[j]] = -1;
				pair[j] = -1;
				next[prev[pair[j + 1]]] = next[pair[j + 1]];
				prev[next[pair[j + 1]]] = prev[pair[j + 1]];
				next[pair[j + 1]] = -1;
				prev[pair[j + 1]] = -1;
				pair[j + 1] = -1;
				break;
			}
		}
		printlnCase();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				out.print(ans[i][j] == 0 ? '/' : ans[i][j]);
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