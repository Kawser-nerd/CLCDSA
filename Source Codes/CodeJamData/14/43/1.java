import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class gcj2C implements Runnable {

	private PrintWriter out;
	
	final String file = "C-large";
	Random rnd = new Random(42);

    static class Rect {
        int x0, y0, x1, y1;

        Rect(int x0, int y0, int x1, int y1) {
            this.x0 = x0;
            this.y0 = y0;
            this.x1 = x1;
            this.y1 = y1;
        }
    }

    static int dist(Rect a, Rect b) {
        int dx = 0;
        if (a.x1 < b.x0) {
            dx = b.x0 - a.x1;
        }
        if (b.x1 < a.x0) {
            dx = a.x0 - b.x1;
        }
        int dy = 0;
        if (a.y1 < b.y0) {
            dy = b.y0 - a.y1;
        }
        if (b.y1 < a.y0) {
            dy = a.y0 - b.y1;
        }
        return Math.max(dx, dy);
    }

	static class InputData {

        int w, h, n;
        Rect[] rects;

		InputData(FastReader in) throws IOException {
            w = in.nextInt();
            h = in.nextInt();
            n = in.nextInt();
            rects = new Rect[n];
            for (int i = 0; i < n; ++i) {
                rects[i] = new Rect(in.nextInt(), in.nextInt(), in.nextInt() + 1, in.nextInt() + 1);
            }
		}
		
		void solve(PrintWriter out) {
            int[] dist = new int[n];
            for (int i = 0; i < n; ++i) {
                dist[i] = rects[i].x0;
            }
            boolean[] col = new boolean[n];
            while (true) {
                int min = -1;
                for (int i = 0; i < n; ++i) {
                    if (!col[i] && (min == -1 || dist[i] < dist[min])) {
                        min = i;
                    }
                }
                if (min == -1) {
                    break;
                }
                col[min] = true;
                for (int j = 0; j < n; ++j) {
                    dist[j] = Math.min(dist[j], dist[min] + dist(rects[min], rects[j]));
                }
            }
            int ans = w;
            for (int i = 0; i < n; ++i) {
                ans = Math.min(ans, dist[i] + w - rects[i].x1);
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
		new gcj2C().run();
	}
	
}
