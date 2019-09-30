import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int r = nextInt();
		int c = nextInt();
		nextInt();
		long w[][] = new long[r][c];
		for (int i = 0; i < r; i++) {
			String l = next();
			for (int j = 0; j < c; j++) {
				w[i][j] = l.charAt(j) - '0';
			}
		}
		long wsum[][] = new long[r][c];
		long wisum[][] = new long[r][c];
		long wjsum[][] = new long[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				wsum[i][j] = w[i][j];
				wisum[i][j] = w[i][j] * i;
				wjsum[i][j] = w[i][j] * j;
				if (j > 0) {
					wsum[i][j] += wsum[i][j - 1];
					wisum[i][j] += wisum[i][j - 1];
					wjsum[i][j] += wjsum[i][j - 1];
				}
				if (i > 0) {
					wsum[i][j] += wsum[i - 1][j];
					wisum[i][j] += wisum[i - 1][j];
					wjsum[i][j] += wjsum[i - 1][j];
					if (j > 0) {
						wsum[i][j] -= wsum[i - 1][j - 1];
						wisum[i][j] -= wisum[i - 1][j - 1];
						wjsum[i][j] -= wjsum[i - 1][j - 1];
					}
				}
			}
		}
		for (int size = min(r, c); size >= 3; size--) {
			for (int i = 0; i + size <= r; i++) {
				for (int j = 0; j + size <= c; j++) {
					long sum = wsum[i + size - 1][j + size - 1];
					long isum = wisum[i + size - 1][j + size - 1];
					long jsum = wjsum[i + size - 1][j + size - 1];
					if (j > 0) {
						sum -= wsum[i + size - 1][j - 1];
						isum -= wisum[i + size - 1][j - 1];
						jsum -= wjsum[i + size - 1][j - 1];
					}
					if (i > 0) {
						sum -= wsum[i - 1][j + size - 1];
						isum -= wisum[i - 1][j + size - 1];
						jsum -= wjsum[i - 1][j + size - 1];
						if (j > 0) {
							sum += wsum[i - 1][j - 1];
							isum += wisum[i - 1][j - 1];
							jsum += wjsum[i - 1][j - 1];
						}
					}
					sum -= w[i][j] + w[i][j + size - 1] +
						w[i + size - 1][j] + w[i + size - 1][j + size - 1];
					isum -= w[i][j] * i +
						w[i][j + size - 1] * i +
						w[i + size - 1][j] * (i + size - 1) +
						w[i + size - 1][j + size - 1] * (i + size - 1);
					jsum -= w[i][j] * j +
						w[i][j + size - 1] * (j + size - 1) +
						w[i + size - 1][j] * j +
						w[i + size - 1][j + size - 1] * (j + size - 1);
					if ((long) (2 * i + size - 1) * sum == 2L * isum &&
						(long) (2 * j + size - 1) * sum == 2L * jsum) {
						out.println(size);
						return;
					}
				}
			}
		}
		out.println("IMPOSSIBLE");
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}