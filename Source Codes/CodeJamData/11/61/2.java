import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Solution implements Runnable {
	
	final static long mod = 1000003;

	private PrintWriter out;
	
	final String file = "A-large";
	Random rnd = new Random(42);

	static class InputData {
		String s;
		private long[] fact;
		private long[] invfact;
		
		long split(int n, int k) {
			if (k == 0) {
				return n == 0 ? 1 : 0;
			}
			if (n == 0) {
				return 0;
			}
			return c(n - 1, k - 1);
		}
		
		long c(int n, int k) {
			if (n < k) {
				return 0;
			}
			return (fact[n] * invfact[k] * invfact[n - k]) % mod;
		}
		
		InputData(FastReader in) throws IOException {
			s = in.next();
		}
		
		void solve(PrintWriter out) {
			int n = s.length();
			int runs = 0;
			int[] counts = new int[26];
			int last = -1;
			for (int i = 0; i < s.length(); ++i) {
				int val = s.charAt(i) - 'a';
				counts[val]++;
				if (val != last) {
					runs++;
					last = val;
				}
			}
			fact = new long[n + 2];
			invfact = new long[n + 2];
			fact[0] = invfact[0] = 1;
			for (int i = 0; i <= n; ++i) {
				fact[i + 1] = (fact[i] * (i + 1)) % mod;
				invfact[i + 1] = inv(fact[i + 1]);
			}
			long[][] d = new long[runs + 2][runs + 1];
			d[1][0] = 1;
			for (int it = 0; it < 26; ++it) {
				long[][] t = new long[runs + 2][runs + 1];
				for (int u = 1; u <= runs + 1; ++u) {
					for (int v = 0; u + v <= runs + 1; ++v) {
						if (d[u][v] == 0) {
							continue;
						}
						for (int tu = 0; tu <= u - v && u + tu <= runs + 1; ++tu) {
							for (int tv = 0; tv <= v && u + tu + tv <= runs + 1; ++tv) {
								for (int total = tu + tv; u + total <= runs + 1 && u + tu + v + (total - tu - 2 * tv) <= runs + 1; ++total) {
									long mul = (d[u][v] * c(u - v, tu) * c(v, tv)) % mod;
									mul = (mul * split(total, tu + tv) * split(counts[it], total)) % mod;
									t[u + total][v + total - tu - 2 * tv] = (t[u + total][v + total - tu - 2 * tv] + mul) % mod;
								}
							}
						}
					}
				}
				d = t;
			}
			out.println(d[runs + 1][0]);
		}
	}

	private static long inv(long x) {
		return BigInteger.valueOf(x).modInverse(BigInteger.valueOf(mod)).longValue();
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
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
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}
