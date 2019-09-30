import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJB implements Runnable {

	private PrintWriter out;
	
	final String file = "B-small-attempt1";
	Random rnd = new Random(42);

    static class Vector {
        long x, y;

        Vector(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Vector diff(Vector o) {
            return new Vector(x - o.x, y - o.y);
        }
    }

    static long vMul(Vector a, Vector b) {
        return a.x * b.y - a.y * b.x;
    }

    static long sMul(Vector a, Vector b) {
        return a.x * b.x + a.y * b.y;
    }

    static boolean isect(Vector a1, Vector a2, Vector b1, Vector b2) {
        if (Math.min(a1.x, a2.x) > Math.max(b1.x, b2.x) ||
            Math.min(b1.x, b2.x) > Math.max(a1.x, a2.x) ||
            Math.min(a1.y, a2.y) > Math.max(b1.y, b2.y) ||
            Math.min(b1.y, b2.y) > Math.max(a1.y, a2.y)) {
            return false;
        }
        return Math.signum(vMul(b1.diff(a1), a2.diff(a1))) * Math.signum(vMul(b2.diff(a1), a2.diff(a1))) <= 0 &&
               Math.signum(vMul(a1.diff(b1), b2.diff(b1))) * Math.signum(vMul(a2.diff(b1), b2.diff(b1))) <= 0;
    }

    static boolean isectCont(Vector a1, Vector a2, Vector a3) {
        return vMul(a1.diff(a2), a3.diff(a2)) == 0 &&
                sMul(a1.diff(a2), a3.diff(a2)) > 0;
    }

	static class InputData {

        int n;
        Vector[] vs;

		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            vs = new Vector[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vector(in.nextLong(), in.nextLong());
            }
		}

        int[] best;
        long bestS = 0;

        void rec(int i, int[] a) {
            if (i == n) {
                if (isectCont(vs[a[n - 2]], vs[a[n - 1]], vs[a[0]]) ||
                    isectCont(vs[a[n - 1]], vs[a[0]], vs[a[1]])) {
                    return;
                }
                for (int j = 1; j < n - 2; ++j) {
                    if (isect(vs[a[j]], vs[a[j + 1]], vs[a[n - 1]], vs[a[0]])) {
                        return;
                    }
                }
                System.err.println(Arrays.toString(a));
                long s = 0;
                for (int j = 0; j < n; ++j) {
                    s += vMul(vs[a[j]], vs[a[(j + 1) % n]]);
                }
                if (s > bestS) {
                    bestS = s;
                    best = a.clone();
                }
                return;
            }
            loop: for (a[i] = 1; a[i] < n; ++a[i]) {
                for (int j = 0; j < i; ++j) {
                    if (a[i] == a[j]) {
                        continue loop;
                    }
                }
                if (i >= 2 && isectCont(vs[a[i - 2]], vs[a[i - 1]], vs[a[i]])) {
//                    System.err.println(a[i] + " last");
                    continue;
                }
                for (int j = 0; j < i - 2; ++j) {
                    if (isect(vs[a[j]], vs[a[j + 1]], vs[a[i - 1]], vs[a[i]])) {
//                        System.err.println(a[i] + " isect " + j);
                        continue loop;
                    }
                }
                rec(i + 1, a);
            }
//            System.err.println("ret");
        }
		
		void solve(PrintWriter out) {
            int[] ans = new int[n];
            rec(1, ans);
            for (int i : best) {
                out.print(i + " ");
            }
            out.println();
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
		new GCJB().run();
	}
	
}
