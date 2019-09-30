import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
	
	final String f = "A-large";
//	final String f = "sample";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private ArrayList<Integer> primes;
	
	{
		primes = new ArrayList<Integer>();
		primes.add(2);
		loop: for (int i = 3; i <= 1000000; i += 2) {
			for (int j = 0; primes.get(j) * primes.get(j) <= i; ++j) {
				if (i % primes.get(j) == 0) {
					continue loop;
				}
			}
			primes.add(i);
		}
	}

	void solve() throws IOException {
		int d = nextInt();
		int n = nextInt();
		int pow10 = 1;
		for (int i = 0; i < d; ++i) {
			pow10 *= 10;
		}
		long[] ar = new long[n];
		for (int i = 0; i < n; ++i) {
			ar[i] = nextInt();
		}
		if (n < 2) {
			out.println("I don't know.");
			return;
		}
		long solution = -1;
		loop: for (long p : primes) {
			if (p > pow10) {
				break;
			}
			for (int i = 0; i < n; ++i) {
				if (ar[i] >= p) {
					continue loop;
				}
			}
//			loop2: for (int a = 0; a < p; ++a) {
//				int b = (ar[1] + (p - ar[0]) * a) % p;
//				for (int i = 0; i < n - 1; ++i) {
//					if (ar[i + 1] != (a * ar[i] + b) % p) {
//						continue loop2;
//					}
//				}
//				int sol = (a * ar[n - 1] + b) % p;
//				if (solution != -1 && solution != sol) {
//					out.println("I don't know.");
//					return;
//				}
//				solution = sol;
//			}
			long a = -1;
			long x1 = ar[0];
			long y1 = ar[1];
			for (int i = 1; i < n - 1; ++i) {
				long x2 = ar[i];
				long y2 = ar[i + 1];
				long x12 = (x1 - x2 + p) % p;
				long y12 = (y1 - y2 + p) % p;
				if (x12 == 0) {
					if (y12 != 0) {
						continue loop;
					}
				} else {
					long aa = (modInverse(x12, p) * y12) % p;
					if (a != -1 && a != aa) {
						continue loop;
					}
					a = aa;
				}
			}
			if (a == -1) {
				for (a = 0; a < p; ++a) {
					long b = (y1 + (p - x1) * a) % p;
					long sol = (a * ar[n - 1] + b) % p;
					if (solution != -1 && solution != sol) {
						out.println("I don't know.");
						return;
					}
					solution = sol;
				}
				continue;
			}
			long b = (y1 + (p - x1) * a) % p;
			long sol = (a * ar[n - 1] + b) % p;
			if (solution != -1 && solution != sol) {
				out.println("I don't know.");
				return;
			}
			solution = sol;
		}
		if (solution == -1) {
			System.out.println(Arrays.toString(ar));
//			throw new AssertionError();
		}
		out.println(solution);
	}

	private long modInverse(long x, long p) {
		return BigInteger.valueOf(x).modInverse(BigInteger.valueOf(p)).longValue();
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
