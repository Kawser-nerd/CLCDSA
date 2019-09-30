import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

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
		int m = nextInt();
		boolean origMap1[][] = new boolean[n][n];
		boolean origMap2[][] = new boolean[n][n];
		int origScore = 0;
		for (int i = 0; i < m; i++) {
			String type = next();
			int r = nextInt() - 1;
			int c = nextInt() - 1;
			switch (type) {
			case "+":
				origMap2[r][c] = true;
				++origScore;
				break;
			case "x":
				origMap1[r][c] = true;
				++origScore;
				break;
			case "o":
				origMap1[r][c] = true;
				origMap2[r][c] = true;
				origScore += 2;
				break;
			default:
				throw new AssertionError();
			}
		}
		boolean map1[][] = new boolean[n][n];
		boolean map2[][] = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			arraycopy(origMap1[i], 0, map1[i], 0, n);
			arraycopy(origMap2[i], 0, map2[i], 0, n);
		}
		int score = origScore;
		boolean haveRows[] = new boolean[n];
		boolean haveCols[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map1[i][j]) {
					haveRows[i] = true;
					haveCols[j] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (!haveRows[i]) {
				for (int j = 0; j < n; j++) {
					if (!haveCols[j]) {
						map1[i][j] = true;
						++score;
						haveRows[i] = true;
						haveCols[j] = true;
						break;
					}
				}
			}
		}
		boolean haveDiag1[] = new boolean[2 * n - 1];
		boolean haveDiag2[] = new boolean[2 * n - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map2[i][j]) {
					haveDiag1[i + j] = true;
					haveDiag2[i - j + n - 1] = true;
				}
			}
		}
		for (int ii = 0; ii < n; ii++) {
			for (int i = ii;; i = 2 * n - ii - 2) {
				if (!haveDiag1[i]) {
					for (int j = n - 1 - ii; j <= n - 1 + ii; j += 2) {
						if (!haveDiag2[j]) {
							int ri = (i + j - (n - 1)) >> 1;
							int rj = (i - j + n - 1) >> 1;
							if (ri + rj != i || ri - rj + n - 1 != j) {
								throw new AssertionError();
							}
							map2[ri][rj] = true;
							++score;
							haveDiag1[i] = true;
							haveDiag2[j] = true;
							break;
						}
					}
				}
				if (i == 2 * n - ii - 2) {
					break;
				}
			}
		}
		int changes = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map1[i][j] != origMap1[i][j] || map2[i][j] != origMap2[i][j]) {
					++changes;
				}
			}
		}
		printCase();
		out.println(score + " " + changes);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map1[i][j] != origMap1[i][j] || map2[i][j] != origMap2[i][j]) {
					out.println((!map1[i][j] ? '+' : map2[i][j] ? 'o' : 'x') + " " + (i + 1) + " " + (j + 1));
				}
			}
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