import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";
	
	int[] genMask(int seed, int n, Random rnd) {
		int[] mask = new int[(n + 31) / 32];
		rnd.setSeed(seed);
		for (int i = 0; i < mask.length; ++i) {
			mask[i] = (int) rnd.nextLong();
			if (i == mask.length - 1) {
				mask[i] &= (1 << (n % 32)) - 1;
			}
		}
		return mask;
	}
	
	long sum(int[] mask, long[][] sums) {
		long ans = 0;
		for (int i = 0; i < mask.length; ++i) {
			ans += sums[2 * i][mask[i] & 65535];
			ans += sums[2 * i + 1][mask[i] >>> 16];
		}
		return ans;
	}
	
	int hash(long x) {
		return (int)(x ^ (x >>> 32));
	}

	public void solve(int test) throws IOException {
		System.err.println(test);
		out.println("Case #" + (test + 1) + ": ");
		Random rnd0 = new Random();
		int n = nextInt();
//		int n = 500;
		long[] ar = new long[n];
		for (int i = 0; i < n; ++i) {
			ar[i] = nextLong();
//			ar[i] = Math.abs(rnd0.nextLong() % 1000000000000L);
		}
		long[][] sums = new long[2 * ((n + 31) / 32)][65536];
		for (int i = 0; i < sums.length; ++i) {
			for (int m = 0; m < 65535; ++m) {
				for (int j = 0; j < 16; ++j) {
					if (16 * i + j < n && (m & (1 << j)) != 0) {
						sums[i][m] += ar[16 * i + j];
					}
				}
			}
		}
		Random rnd = new Random();
		HashMap<Long, int[]> set = new HashMap<Long, int[]>();
		for (int it = 0; ; ++it) {
//			System.err.print(".");
			int seed = it;
			int[] u = genMask(seed, n, rnd);
			long sum = sum(u, sums);
			if (set.containsKey(sum)) {
				int[] v = set.get(sum);
				System.err.print(".");
				if (!Arrays.equals(u, v)) {
					for (int i = 0; i < n; ++i) {
						if ((u[i / 32] & (1 << (i % 32))) != 0) {
							out.print(ar[i] + " ");
						}
					}
					out.println();
					for (int i = 0; i < n; ++i) {
						if ((v[i / 32] & (1 << (i % 32))) != 0) {
							out.print(ar[i] + " ");
						}
					}
					out.println();
					return;
				}
			} else {
				set.put(sum, u);
			}
//			u = genMask(hash(sum(u, sums)), n, rnd);
//			int[] v = u;
//			v = genMask(hash(sum(v, sums)), n, rnd);
//			int length = 1;
//			for (;; length++) {
//				long sum1 = sum(u, sums);
//				long sum2 = sum(v, sums);
//				if (sum1 == sum2) {
//					System.err.println(length);
//					break;
//				}
//				u = genMask(hash(sum1), n, rnd);
//				v = genMask(hash(sum2), n, rnd);
//				sum2 = sum(v, sums);
//				v = genMask(hash(sum2), n, rnd);
//			}
//			u = genMask(seed, n, rnd);
//			v = u;
//			for (int it = 0; it < length; ++it) {
//				v = genMask(hash(sum(v, sums)), n, rnd);
//			}
//			while (true) {
//				long sum1 = sum(u, sums);
//				long sum2 = sum(v, sums);
//				if (sum1 == sum2) {
//					System.err.println(length);
//					if (!Arrays.equals(u, v)) {
//						for (int i = 0; i < n; ++i) {
//							if ((u[i / 32] & (1 << (i % 32))) != 0) {
//								out.print(ar[i] + " ");
//							}
//						}
//						out.println();
//						for (int i = 0; i < n; ++i) {
//							if ((v[i / 32] & (1 << (i % 32))) != 0) {
//								out.print(ar[i] + " ");
//							}
//						}
//						out.println();
//						return;
//					}
//					break;
//				u = genMask(hash(sum1), n, rnd);
//				v = genMask(hash(sum2), n, rnd);
//			}
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve(test);
		}
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}
