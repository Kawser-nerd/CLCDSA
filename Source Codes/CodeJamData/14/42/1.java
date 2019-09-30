import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class gcj2B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {

        int n;
        int[] a;

		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
		}
		
		void solve(PrintWriter out) {
            Integer[] p0 = new Integer[n];
            for (int i = 0; i < n; ++i) {
                p0[i] = i;
            }
            Arrays.sort(p0, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return a[o1] - a[o2];
                }
            });
            int[] pos = new int[n];
            for (int i = 0; i < n; ++i) {
                pos[i] = p0[i];
            }
            int ans = 0;
//            out.println(Arrays.toString(pos) + " " + Arrays.toString(p0));
            for (int i = 0; i < n; ++i) {
                int dl = pos[i];
                int dr = n - pos[i] - 1;
                for (int j = 0; j < i; ++j) {
                    if (pos[j] < pos[i]) {
                        dl--;
                    } else {
                        dr--;
                    }
                }
                ans += Math.min(dl, dr);
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
		new gcj2B().run();
	}
	
}
