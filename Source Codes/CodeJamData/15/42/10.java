import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R2B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	static Random rnd = new Random(42);

    static class Pair implements Comparable<Pair> {
        double r, t;

        public Pair(double r, double t) {
            this.r = r;
            this.t = t;
        }

        @Override
        public int compareTo(Pair o) {
            return Double.compare(t, o.t);
        }

        @Override
        public String toString() {
            return r + " " + t;
        }
    }

	static class InputData {
        int n;
        double totalv, totalt;
        Pair[] ps;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            totalv = in.nextDouble();
            totalt = in.nextDouble();
            ps = new Pair[n];
            for (int i = 0; i < n; ++i) {
                ps[i] = new Pair(in.nextDouble(), in.nextDouble());
            }
		}
		
		void solve(PrintWriter out) {
            Arrays.sort(ps);
            totalt *= totalv;
            double ans = solve(1e-12, 1e-12);
            double ans2 = solve(1e-9, 0);
            double diff = Math.min(1, 1.0 / ans) * Math.abs(ans - ans2);
            if (diff > 1e-6) {
                out.println("!!!!!!!!!!!!");
                totalt /= totalv;
                out.println(totalv + " " + totalt + " " + Arrays.toString(ps));
                double sum = 0;
                for (Pair p : ps) {
                    sum += p.r;
                }
                out.println(totalv / sum);
                out.println(ans2 == 1000000000 ? "IMPOSSIBLE" : ans2);
            }
//            out.println(diff);
            out.println(ans == 1000000000 ? "IMPOSSIBLE" : ans);
		}

        double solve(double EPS, double EPS2) {
            double l = 0.0, r = 1000000000;
            for (int it = 0; it < 100; ++it) {
                double mid = (l + r) / 2.0;
                double mint = 0.0, curv = 0;
                for (int i = 0; i < n; ++i) {
                    double cur = Math.min(mid * ps[i].r, totalv - curv);
                    mint += cur * ps[i].t;
                    curv += cur;
                }
                double maxt = 0.0; curv = 0;
                for (int i = n - 1; i >= 0; --i) {
                    double cur = Math.min(mid * ps[i].r, totalv - curv);
                    maxt += cur * ps[i].t;
                    curv += cur;
                }
                if (curv < totalv - EPS2 || mint - Math.min(1, totalt) * EPS > totalt || maxt + Math.min(1, totalt) * EPS < totalt) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            return r;
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
		new GCJ2015R2B().run();
	}
	
}
