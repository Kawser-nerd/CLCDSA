import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static final int DI[] = {1, 0, -1, 0};
	static final int DJ[] = {0, 1, 0, -1};
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		char map[][] = new char[n][];
		for (int i = 0; i < n; i++) {
			map[i] = next().toCharArray();
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			j: for (int j = 0; j < m; j++) {
				int di, dj;
				switch (map[i][j]) {
				case '^':
					di = -1;
					dj = 0;
					break;
				case 'v':
					di = 1;
					dj = 0;
					break;
				case '<':
					di = 0;
					dj = -1;
					break;
				case '>':
					di = 0;
					dj = 1;
					break;
				case '.':
					continue;
				default:
					throw new AssertionError();
				}
				int ci = i + di, cj = j + dj;
				while (true) {
					if (ci < 0 || ci >= n || cj < 0 || cj >= m) {
						break;
					}
					if (map[ci][cj] != '.') {
						continue j;
					}
					ci += di;
					cj += dj;
				}
				++ans;
				d: for (int d = 0; d < 4; d++) {
					di = DI[d];
					dj = DJ[d];
					ci = i + di;
					cj = j + dj;
					while (true) {
						if (ci < 0 || ci >= n || cj < 0 || cj >= m) {
							continue d;
						}
						if (map[ci][cj] != '.') {
							continue j;
						}
						ci += di;
						cj += dj;
					}
				}
				printCase();
				out.println("IMPOSSIBLE");
				return;
			}
		}
		printCase();
		out.println(ans);
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