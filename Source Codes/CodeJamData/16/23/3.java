import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2016R2C implements Runnable {

	private PrintWriter out;
	
	final String file = "C-large";
	static Random rnd = new Random(42);

	static class InputData {

		int n;
		String[] w1, w2;
		
		InputData(FastReader in) throws IOException {
			n = in.nextInt();
			w1 = new String[n];
			w2 = new String[n];
			for (int i = 0; i < n; ++i) {
				w1[i] = in.next();
				w2[i] = in.next();
			}
		}
		
		void solve(PrintWriter out) {
			HashMap<String, Integer> relabel1 = relabel(w1), relabel2 = relabel(w2);
			ArrayList<Integer>[] g = new ArrayList[relabel1.size()];
			for (int i = 0; i < relabel1.size(); ++i) {
				g[i] = new ArrayList<>();
			}
			for (int i = 0; i < n; ++i) {
				g[relabel1.get(w1[i])].add(relabel2.get(w2[i]));
			}
			int[] du = new int[relabel1.size()];
			int[] dv = new int[relabel2.size()];
			Arrays.fill(du, -1);
			Arrays.fill(dv, -1);
			boolean[] col = new boolean[relabel1.size()];
			int ans = n;
			for (int i = 0; i < relabel1.size(); ++i) {
				if (dfs(i, g, du, dv, col)) {
					ans--;
					Arrays.fill(col, false);
				}
			}
			for (int i = 0; i < relabel1.size(); ++i) {
				if (du[i] == -1) {
					ans--;
				}
			}
			for (int i = 0; i < relabel2.size(); ++i) {
				if (dv[i] == -1) {
					ans--;
				}
			}
			out.println(ans);
		}

		private HashMap<String, Integer> relabel(String[] ss) {
			HashMap<String, Integer> ret = new HashMap<>();
			for (String s : ss) {
				if (!ret.containsKey(s)) {
					ret.put(s, ret.size());
				}
			}
			return ret;
		}

		private boolean dfs(int i, ArrayList<Integer>[] g, int[] du, int[] dv, boolean[] col) {
			if (i == -1) {
				return true;
			}
			if (col[i]) {
				return false;
			}
			col[i] = true;
			for (int j : g[i]) {
				if (j != du[i] && dfs(dv[j], g, du, dv, col)) {
					du[i] = j;
					dv[j] = i;
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
		new GCJ2016R2C().run();
	}
	
}
