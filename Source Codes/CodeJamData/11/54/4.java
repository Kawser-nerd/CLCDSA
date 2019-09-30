import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.round;
import static java.lang.Math.sqrt;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		String s = next();
		if (s.length() > 63) {
			throw new AssertionError();
		}
		long min = 0;
		long mask = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case '0':
				break;
			case '?':
				mask |= 1L << (s.length() - i - 1);
				break;
			case '1':
				min |= 1L << (s.length() - i - 1);
				break;
			default:
				throw new AssertionError();
			}
		}
		boolean have = false;
		for (long cmask = mask; ; cmask = (cmask - 1) & mask) {
			if (isSquare(min | cmask)) {
				if (have) {
					throw new AssertionError(); 
				}
				out.println(Long.toBinaryString(min | cmask));
				have = true;
			}
			if (cmask == 0) {
				break;
			}
		}
		if (!have) {
			throw new AssertionError();
		}
	}
	
	static boolean isSquare(long n) {
		long test = round(sqrt(n));
		while (test * test > n) {
			--test;
		}
		while (test * test < n) {
			++test;
		}
		return test * test == n;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
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