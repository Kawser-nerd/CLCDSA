import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2016QC implements Runnable {

	private PrintWriter out;
	
	final String file = "C-large";
	static Random rnd = new Random(42);

	static class InputData {

		int n, cnt;

		InputData(FastReader in) throws IOException {
			n = in.nextInt();
			cnt = in.nextInt();
		}

		static long factor(BigInteger n) {
			for (long x : new long[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
				if (n.mod(BigInteger.valueOf(x)).signum() == 0) {
					return x;
				}
			}
			return 0;
		}

		void solve(PrintWriter out) {
            out.println();
			loop: for (int it = 0; it < cnt; ++it) {
				long x = (1L << (n - 1)) + 2 * rnd.nextInt(1 << (n - 2)) + 1;
				String xs = Long.toString(x, 2);
                long[] divs = new long[11];
				for (int base = 2; base <= 10; ++base) {
                    divs[base] = factor(new BigInteger(xs, base));
                    if (divs[base] == 0) {
                        it--;
                        continue loop;
                    }
                }
                out.print(xs);
                for (int base = 2; base <= 10; ++base) {
                    out.print(" " + divs[base]);
                }
                out.println();
			}
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
		new GCJ2016QC().run();
	}
	
}
