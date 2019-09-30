import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R1C implements Runnable {

	private PrintWriter out;
	
	final String file = "C-large";
	static Random rnd = new Random(42);

    static class Vector {
        long x, y;

        public Vector(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static long vMul(Vector a, Vector b, Vector o) {
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    }

	static class InputData {
        int n;
        Vector[] vs;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
//            n = 3000;
            vs = new Vector[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vector(in.nextInt(), in.nextInt());
            }
		}
		
		void solve(PrintWriter out) {
            out.println();
            for (int i = 0; i < n; ++i) {
                System.err.println(i);
                int ans = n - 1;
                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        continue;
                    }
                    int cur1 = 0, cur2 = 0;
                    for (int k = 0; k < n; ++k) {
                        long vMul = vMul(vs[j], vs[k], vs[i]);
                        if (vMul > 0) {
                            cur1++;
                        }
                        if (vMul < 0) {
                            cur2++;
                        }
                    }
                    ans = Math.min(ans, Math.min(cur1, cur2));
                }
                out.println(ans);
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
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(16);
			
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
		new GCJ2015R1C().run();
	}
	
}
