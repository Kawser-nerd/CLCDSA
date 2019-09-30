import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ3B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {

        int n, p, q;
        int[] h, g;
		
		InputData(FastReader in) throws IOException {
            p = in.nextInt();
            q = in.nextInt();
            n = in.nextInt();
            h = new int[n];
            g = new int[n];
            for (int i = 0; i < n; ++i) {
                h[i] = in.nextInt();
                g[i] = in.nextInt();
            }
		}
		
		void solve(PrintWriter out) {
            int total = 0;
            for (int x : h) {
                total += x;
            }
            int[][][] d = new int[n + 1][2][total + 1];
            for (int[][] arr : d) {
                for (int[] ar : arr) {
                    Arrays.fill(ar, -1);
                }
            }
            d[0][0][0] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    int h0 = h[i] - j * q;
                    int shoots = (h0 - 1) / q;
                    int toKill = (h0 - shoots * q + p - 1) / p;
                    int toKill1 = (h[i] + p - 1) / p;
                    for (int t = 0; t <= total; ++t) {
                        if (d[i][j][t] == -1) {
                            continue;
                        }
                        if (t >= toKill1) {
                            d[i + 1][j][t - toKill1] = Math.max(d[i + 1][j][t - toKill1], d[i][j][t] + g[i]);
                        }
                        if (h0 <= 0) {
                            d[i + 1][0][t] = Math.max(d[i + 1][0][t], d[i][j][t]);
                            continue;
                        }
                        d[i + 1][0][t + shoots + 1] = Math.max(d[i + 1][0][t + shoots + 1], d[i][j][t]);
                        if (t + shoots + 1 >= toKill) {
                            d[i + 1][1][t + shoots + 1 - toKill] = Math.max(d[i + 1][1][t + shoots + 1 - toKill], d[i][j][t] + g[i]);
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j <= total / q; ++j) {
                    ans = Math.max(ans, d[n][i][j]);
                }
            }
            out.println(ans);
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
		new GCJ3B().run();
	}
	
}
