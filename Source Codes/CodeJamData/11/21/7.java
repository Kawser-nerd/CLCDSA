import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solveTest() throws Exception {
		int n = nextInt();
		char table[][] = new char[n][];
		for (int i = 0; i < n; i++) {
			table[i] = next().toCharArray();
		}
		int games[] = new int[n];
		int won[] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				switch (table[i][j]) {
				case '1':
					++won[i];
					//$FALL-THROUGH$
				case '0':
					++games[i];
					//$FALL-THROUGH$
				case '.':
					break;
				default:
					throw new AssertionError();
				}
			}
		}
		double wp[] = new double[n];
		for (int i = 0; i < n; i++) {
			wp[i] = (double) won[i] / games[i];
		}
		double owp[] = new double[n];
		for (int i = 0; i < n; i++) {
			double wpsum = 0;
			for (int j = 0; j < n; j++) {
				switch (table[i][j]) {
				case '1':
					wpsum += (double) won[j] / (games[j] - 1);
					break;
				case '0':
					wpsum += (double) (won[j] - 1) / (games[j] - 1);
				}
			}
			owp[i] = wpsum / games[i];
		}
		double oowp[] = new double[n];
		for (int i = 0; i < n; i++) {
			double owpsum = 0;
			for (int j = 0; j < n; j++) {
				switch (table[i][j]) {
				case '0':
				case '1':
					owpsum += owp[j];
				}
			}
			oowp[i] = owpsum / games[i];
		}
		for (int i = 0; i < n; i++) {
			out.printf(Locale.US, "%.12f\n", wp[i] / 4 + owp[i] / 2 + oowp[i] / 4);
		}
	}

	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.println("Case #" + test + ":");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in))
			.readLine();
		in = new BufferedReader(new InputStreamReader(new FileInputStream(
			new File(filename + ".in"))));
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
			throw new IllegalArgumentException("String \"" + token
				+ "\" is not a single character");
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