import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R1B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {

        int n;
        int m;
        int[] ts;
		
		InputData(FastReader in) throws IOException {
            m = in.nextInt();
            n = in.nextInt();
            ts = new int[m];
            for (int i = 0; i < m; ++i) {
                ts[i] = in.nextInt();
            }
		}
		
		void solve(PrintWriter out) {
            long l = -1, r = 100000000000000L;
            while (l + 1 < r) {
                long mid = (l + r) / 2;
                long cnt = 0;
                for (int i = 0; i < m; ++i) {
                    cnt += mid / ts[i] + 1;
                }
                if (cnt < n) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            long cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += l / ts[i] + 1;
            }
            for (int i = 0; i < m; ++i) {
                if (r % ts[i] == 0) {
                    cnt++;
                    if (cnt == n) {
                        out.println((i + 1));
                        return;
                    }
                }
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
		new GCJ2015R1B().run();
	}
	
}
