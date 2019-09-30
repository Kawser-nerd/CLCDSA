import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
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
	
	static void solve() throws Exception {
		int n = nextInt();
		int a = nextInt();
		boolean e[][] = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < n; j++) {
				e[i][j] = l.charAt(j) == 'Y';
			}
		}
//		System.err.println(Arrays.deepToString(e));
		boolean used[] = new boolean[n];
		boolean seen[] = new boolean[n];
		if (dfs(n, e, used, seen, a) != n) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		printCase();
		int current;
		current: for (current = 0; current < n; current++) {
			used[current] = true;
			fill(seen, false);
			dfs(n, e, used, seen, a);
			for (int j = 0; j < n; j++) {
				if (!seen[j] && j != current && !e[current][j]) {
					used[current] = false;
					continue current;
				}
			}
			out.print(current);
			break;
		}
		if (current >= n) {
			throw new AssertionError();
		}
		for (int i = 1; i < n; i++) {
			int next;
			next: for (next = 0; next < n; next++) {
				if (used[next]) {
					continue;
				}
				if (e[current][next]) {
					if (next == a) {
						continue;
					}
					used[next] = true;
					fill(seen, false);
					dfs(n, e, used, seen, a);
					for (int j = 0; j < n; j++) {
						if (!seen[j] && !used[j] && !e[current][j]) {
							used[next] = false;
							continue next;
						}
					}
				} else {
					used[next] = true;
					fill(seen, false);
					dfs(n, e, used, seen, a);
					for (int j = 0; j < n; j++) {
						if (!seen[j] && !used[j] && !e[next][j]) {
							used[next] = false;
							continue next;
						}
					}
					current = next;
				}
				out.print(" " + next);
				break;
			}
			if (next >= n) {
				throw new AssertionError();
			}
		}
		out.println();
//		i: for (;;) {
//			j: for (int j = 0; j < n; j++) {
//				if (used[j]) {
//					continue;
//				}
//				if (j == a) {
//					for (int k = 0; k < n; k++) {
//						if (!used[k] && k != a && !e[a][k]) {
//							continue j;
//						}
//					}
//					out.print(" " + a);
//					for (int k = 0; k < n; k++) {
//						if (!used[k] && k != a) {
//							out.print(" " + k);
//						}
//					}
//					out.println();
//					return;
//				} else {
//					used[j] = true;
//					fill(seen, false);
//					if (dfs(n, e, used, seen, a) == n - i - 1) {
//						out.print(" " + j);
//						continue i;
//					}
//					used[j] = false;
//				}
//			}
//			break;
//		}
//		throw new AssertionError();
	}
	
	static int dfs(int n, boolean[][] e, boolean[] used, boolean[] seen, int cur) {
		if (seen[cur] || used[cur]) {
			return 0;
		}
		seen[cur] = true;
		int ans = 1;
		for (int next = 0; next < n; next++) {
			if (!used[next] && e[cur][next]) {
				ans += dfs(n, e, used, seen, next);
			}
		}
		return ans;
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