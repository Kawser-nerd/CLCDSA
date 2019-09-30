import static java.lang.Double.parseDouble;
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
	
	static int primes[] = new int[78498];
	
	static {
		primes[0] = 2;
		for (int i = 1; i < primes.length; i++) {
			PrimeLoop: for (int prime = primes[i - 1] + 1; ; prime++) {
				for (int j = 0; j < i && primes[j] * primes[j] <= prime; j++) {
					if (prime % primes[j] == 0) {
						continue PrimeLoop;
					}
				}
				primes[i] = prime;
				break;
			}
		}
	}
	
	static void solveTest() throws Exception {
		int d = nextInt();
		int k = nextInt();
		int have[] = new int[k];
		for (int i = 0; i < k; i++) {
			have[i] = nextInt();
		}
		if (k <= 1) {
			out.println("I don't know.");
			return;
		}
		for (int i = 0; i < k - 1; i++) {
			if (have[i] == have[k - 1]) {
				out.println(have[i + 1]);
				return;
			}
		}
		int ans = -1;
		int dd = 1;
		for (int i = 0; i < d; i++) {
			dd *= 10;
		}
		int max = have[0];
		for (int i = 1; i < k; i++) {
			max = Math.max(max, have[i]);
		}
		PLoop: for (int p = 0; p < primes.length && primes[p] < dd; p++) {
			int pp = primes[p];
			if (pp <= max) {
				continue;
			}
			//a*ni+b=n{i+1}
			//a*nj+b=n{j+1}
			//a*(ni-nj)=n{i+1}-n{j+1}
			for (int i = 0; i < k - 1; i++) {
				for (int j = i + 1; j < k - 1; j++) {
					if (have[i] != have[j]) {
						int a = (int) (((long) (have[i + 1] - have[j + 1] + pp) *
							BigInteger.valueOf((have[i] - have[j] + pp) % pp).
								modInverse(BigInteger.valueOf(pp)).longValue()) % pp);
						int b = (int) (((have[1] - (long) have[0] * a) % pp + pp) % pp);
						for (int l = 2; l < k; l++) {
							if (have[l] != (int) (((long) have[l - 1] * a + b) % pp)) {
								continue PLoop;
							}
						}
						int nans = (int) (((long) have[k - 1] * a + b) % pp);
						if (ans == -1) {
							ans = nans;
						} else if (ans != nans) {
							out.println("I don't know.");
							return;
						}
						continue PLoop;
					}
				}
			}
			FindLoop: for (int a = 0; a < pp; a++) {
				int b = (int) (((have[1] - (long) have[0] * a) % pp + pp) % pp);
				for (int i = 2; i < k; i++) {
					if (have[i] != (int) (((long) have[i - 1] * a + b) % pp)) {
						continue FindLoop;
					}
				}
				int nans = (int) (((long) have[k - 1] * a + b) % pp);
				if (ans == -1) {
					ans = nans;
				} else if (ans != nans) {
					out.println("I don't know.");
					return;
				}
			}
		}
		out.println(ans);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
			System.out.print('.');
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
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
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}