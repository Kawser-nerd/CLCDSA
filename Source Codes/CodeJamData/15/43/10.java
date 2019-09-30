import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R2C implements Runnable {

	private PrintWriter out;
	final String file = "C-large";
	static Random rnd = new Random(42);

	static class InputData {

        int n;
        String[][] ss;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            ss = new String[n][];
            for (int i = 0; i < n; ++i) {
                String line = in.in.readLine();
                ss[i] = line.split(" ");
            }
		}
		
		void solve(PrintWriter out) {
            HashMap<String, Integer> wordsSet = new HashMap<>();
            for (String[] ar : ss) {
                for (String s : ar) {
                    if (!wordsSet.containsKey(s)) {
                        wordsSet.put(s, wordsSet.size());
                    }
                }
            }
            int m = wordsSet.size();
            int gn = n + 2 * m;
            int[][] g = new int[gn][gn];
            for (int i = 0; i < n; ++i) {
                for (String s : ss[i]) {
                    int j = wordsSet.get(s);
                    g[i][n + j] = 1000000000;
                    g[n + m + j][i] = 1000000000;
                }
            }
            for (int i = 0; i < m; ++i) {
                g[n + i][n + m + i] = 1;
            }
            int ans = 0;
            ArrayList<Integer>[] edges = new ArrayList[gn];
            for (int i = 0; i < gn; ++i) {
                edges[i] = new ArrayList<>();
                for (int j = 0; j < gn; ++j) {
                    if (g[i][j] > 0 || g[j][i] > 0) {
                        edges[i].add(j);
                    }
                }
            }
            while (dfs(0, 1, g, new boolean[gn], edges)) {
                ans++;
            }
            out.println(ans);
		}

        private boolean dfs(int s, int t, int[][] g, boolean[] col, ArrayList<Integer>[] edges) {
            if (s == t) {
                return true;
            }
            if (col[s]) {
                return false;
            }
            col[s] = true;
            for (int j : edges[s]) {
                if (g[s][j] > 0 && dfs(j, t, g, col, edges)) {
                    g[s][j]--;
                    g[j][s]++;
                    return true;
                }
            }
            return false;
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
		new GCJ2015R2C().run();
	}
	
}
