import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R3A implements Runnable {

	private PrintWriter out;
	
	final String file = "A-large";
	static Random rnd = new Random(42);

	static class InputData {

        int n, d;
        int[] p, s;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            d = in.nextInt();
            s = gen(n, in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
            p = gen(n, in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
            for (int i = 1; i < n; ++i) {
                p[i] %= i;
            }
		}

        void solve(PrintWriter out) {
            int[] min = new int[n];
            int[] max = new int[n];
            int[] add = new int[1000000];
            for (int i = 0; i < n; ++i) {
                if (i == 0) {
                    min[i] = max[i] = s[i];
                } else {
                    min[i] = Math.min(min[p[i]], s[i]);
                    max[i] = Math.max(max[p[i]], s[i]);
                }
                if (max[i] - min[i] <= d) {
                    add[Math.max(0, max[i] - d)]++;
                    if (min[i] + 1 < add.length) {
                        add[min[i] + 1]--;
                    }
                }
            }
//            System.err.println(Arrays.toString(s) + " " + Arrays.toString(p) + " " + Arrays.toString(min) + " " + Arrays.toString(max));
            int ans = 0, cur = 0;
            for (int i = 0; i < add.length; ++i) {
                cur += add[i];
                ans = Math.max(ans, cur);
            }
            out.println(ans);
		}
	}

    static int[] gen(int n, int v0, int a, int c, int r) {
        int[] ret = new int[n];
        ret[0] = v0;
        for (int i = 1; i < n; ++i) {
            ret[i] = (ret[i - 1] * a + c) % r;
        }
        return ret;
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
		new GCJ2015R3A().run();
	}
	
}
