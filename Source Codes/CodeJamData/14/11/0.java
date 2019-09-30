import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJR1A implements Runnable {

	private PrintWriter out;
	
	final String file = "A-large";
	Random rnd = new Random(42);

	static class InputData {

        int n, l;
        long[] a, b;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            l = in.nextInt();
            a = new long[n];
            b = new long[n];
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                for (int j = 0; j < l; ++j) {
                    if (s.charAt(j) == '1') {
                        a[i] |= 1L << j;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                for (int j = 0; j < l; ++j) {
                    if (s.charAt(j) == '1') {
                        b[i] |= 1L << j;
                    }
                }
            }
		}
		
		void solve(PrintWriter out) {
            Arrays.sort(a);
            Arrays.sort(b);
            int ans = Arrays.equals(a, b) ? 0 : l + 1;
            for (int i = 0; i < n; ++i) {
                long[] a1 = new long[n];
                long mask = a[0] ^ b[i];
                for (int j = 0; j < n; ++j) {
                    a1[j] = a[j] ^ mask;
                }
                Arrays.sort(a1);
                if (Arrays.equals(a1, b)) {
                    ans = Math.min(ans, Long.bitCount(mask));
                }
            }
            out.println(ans == l + 1 ? "NOT POSSIBLE" : ans);
		}
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
		new GCJR1A().run();
	}
	
}
