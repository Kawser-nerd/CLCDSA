import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class gcj2A implements Runnable {

	private PrintWriter out;
	
	final String file = "A-large";
	Random rnd = new Random(42);

	static class InputData {

        private final int n, m;
        int[] a;

        InputData(FastReader in) throws IOException {
            n = in.nextInt();
            m = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
		}
		
		void solve(PrintWriter out) {
            TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
            for (int x : a) {
                if (map.containsKey(x)) {
                    map.put(x, map.get(x) + 1);
                } else {
                    map.put(x, 1);
                }
            }
            int ans = 0;
            while (!map.isEmpty()) {
                ans++;
                int u = map.lastKey();
                if (map.get(u) == 1) {
                    map.remove(u);
                } else {
                    map.put(u, map.get(u) - 1);
                }
                Integer v = map.floorKey(m - u);
                if (v != null) {
                    if (map.get(v) == 1) {
                        map.remove(v);
                    } else {
                        map.put(v, map.get(v) - 1);
                    }
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
		new gcj2A().run();
	}
	
}
