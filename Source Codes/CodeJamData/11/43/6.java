import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.pow;
import static java.lang.Math.round;
import static java.lang.System.arraycopy;
import static java.util.Arrays.binarySearch;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static long lpow(long a, int n) {
		long ans = 1;
		for (int i = 0; i < n; i++) {
			long nans = ans * a;
			if (nans / a != ans) {
				return Long.MAX_VALUE;
			}
			ans = nans;
		}
		return ans;
	}
	
	static void solveTest() throws Exception {
		long n = nextLong();
		if (n <= 1) {
			out.println(0);
			return;
		}
		int ans = 1;
		for (int i = 2; ; i++) {
			long est = round(pow(n, 1. / i));
			while (lpow(est, i) < n) {
				++est;
			}
			while (lpow(est, i) > n) {
				--est;
			}
			if (est < 2) {
				break;
			}
			ans += pi((int) est);
		}
		out.println(ans);
		if (primes[0] != 2) {
			throw new AssertionError();
		}
//		for (int i = 1; i < primes.length; i++) {
//			if (!BigInteger.valueOf(primes[i]).equals(BigInteger.valueOf(primes[i - 1]).nextProbablePrime())) {
//				throw new AssertionError();
//			}
//		}
//		System.err.println(Arrays.toString(primes));
	}
	
	static int primes[] = new int[] {2};
	
	static int pi(int val) {
		while (val > primes[primes.length - 1]) {
			int nprimes[] = new int[primes.length * 2];
			arraycopy(primes, 0, nprimes, 0, primes.length);
			int i = primes.length;
			primes = nprimes;
			for (; i < primes.length; i++) {
				ps: for (int p = primes[i - 1] + 1; ; p++) {
					for (int j = 0; j < i && (long) primes[j] * primes[j] <= p; j++) {
						if (p % primes[j] == 0) {
							continue ps;
						}
					}
					primes[i] = p;
					break;
				}
			}
		}
		int ans = binarySearch(primes, val);
		return ans >= 0 ? ans + 1 : ~ans;
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