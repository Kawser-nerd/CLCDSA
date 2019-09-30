import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int d = nextInt();
		int p[] = new int[n];
		int v[] = new int[n];
		long vsum = 0;
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
			v[i] = nextInt();
			vsum += v[i];
		}
		double l = 0;
		double r = Long.highestOneBit(d * vsum) * 2;
		bin: while (true) {
			double mid = (l + r) / 2;
			double border = Double.NEGATIVE_INFINITY;
			for (int i = 0; i < n; i++) {
				border += d;
				border = max(border, p[i] - mid);
				border += d * (v[i] - 1);
				if (border > p[i] + mid) {
					if (l == mid) {
						break bin;
					} else {
						l = mid;
						continue bin;
					}
				}
			}
			if (r == mid) {
				break bin;
			} else {
				r = mid;
				continue bin;
			}
		}
		out.printf(Locale.US, "%.12f\n", l);
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