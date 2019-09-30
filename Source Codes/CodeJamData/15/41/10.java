import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R2A implements Runnable {

	private PrintWriter out;
	
	final String file = "A-large";
	static Random rnd = new Random(42);

	static class InputData {
        int n, m;
        char[][] f;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            m = in.nextInt();
            f = new char[n][];
            for (int i = 0; i < n; ++i) {
                f[i] = in.next().toCharArray();
            }
		}

        final static String ds = "^v<>";
        final static int[] dx = {-1, 1, 0, 0};
        final static int[] dy = {0, 0, -1, 1};
		
		void solve(PrintWriter out) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (f[i][j] != '.') {
                        if (!hasArrow(i, j, ds.indexOf(f[i][j]))) {
                            ans++;
                            boolean ok = false;
                            for (int d = 0; d < 4; ++d) {
                                ok |= hasArrow(i, j, d);
                            }
                            if (!ok) {
                                out.println("IMPOSSIBLE");
                                return;
                            }
                        }
                    }
                }
            }
            out.println(ans);
		}

        private boolean hasArrow(int i, int j, int d) {
            i += dx[d];
            j += dy[d];
            while (0 <= i && i < n && 0 <= j && j < m && f[i][j] == '.') {
                i += dx[d];
                j += dy[d];
            }
            return 0 <= i && i < n && 0 <= j && j < m;
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
		new GCJ2015R2A().run();
	}
	
}
