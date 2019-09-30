import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJR1B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {

        int n;
        ArrayList<Integer>[] edges;

		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            edges = new ArrayList[n];
            for (int i = 0; i < n; ++i) {
                edges[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < n - 1; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                edges[u].add(v);
                edges[v].add(u);
            }
		}
		
		void solve(PrintWriter out) {
            int ans = n - 1;
            int[][] d = new int[n][n + 1];
            for (int[] ar : d) {
                Arrays.fill(ar, -1);
            }
            for (int i = 0; i < n; ++i) {
                ans = Math.min(ans, n - dfs(i, n, d));
            }
            out.println(ans);
		}

        private int dfs(int i, int p, int[][] d) {
            if (d[i][p] == -1) {
                int max1 = -1, max2 = -1;
                for (int j : edges[i]) {
                    if (j == p) {
                        continue;
                    }
                    int v = dfs(j, i, d);
                    if (v > max1) {
                        max2 = max1;
                        max1 = v;
                    } else if (v > max2) {
                        max2 = v;
                    }
                }
                if (max2 == -1) {
                    d[i][p] = 1;
                } else {
                    d[i][p] = 1 + max1 + max2;
                }
            }
            return d[i][p];
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
		new GCJR1B().run();
	}
	
}
