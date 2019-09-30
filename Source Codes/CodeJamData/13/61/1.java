import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class A implements Runnable {

	private PrintWriter out;

	final String file = "A-large";
	Random rnd = new Random(42);

	static class InputData {
        int m;
        long x, n;
        long[] a, t0, t;

		InputData(FastReader in) throws IOException {
            m = in.nextInt();
            x = in.nextLong();
		    n = in.nextLong();
            a = new long[m];
            t0 = new long[m];
            t = new long[m];
            for (int i = 0; i < m; ++i) {
                long s = in.nextLong();
                long e = in.nextLong();
                t0[i] = in.nextLong();
                a[i] = (t0[i] + s) % n;
                t[i] = (e - s + n) % n;
                if (t[i] > x) {
                    throw new AssertionError();
                }
            }
		}

        long[] ar;

		void solve(PrintWriter out) {
            ar = new long[4 * m + 2];
            //out.println(Arrays.toString(a) + " " + Arrays.toString(t0) + " " + Arrays.toString(t));
            long ans = solve(0);
            for (int i = 0; i < m; ++i) {
                for (int add = -4; add <= 4; ++add) {
                    ans = Math.max(ans, solve((a[i] + add + n) % n));
                    ans = Math.max(ans, solve((a[i] + 2 * t[i] + add + n) % n));
                }
            }
//            for (int i = 0; i < n; ++i) {
//                ans = Math.max(ans, solve(i));
//            }
            out.println(ans);
		}

        private long solve(long at) {
            int ars = 0;
            ar[ars++] = 0;
            ar[ars++] = 2 * x;
            boolean cannotStart0 = false, cannotEnd1 = false;
            for (int i = 0; i < m; ++i) {
                long addt = (at - a[i] + n) % n;
                int its = 0;
                while (addt <= t[i] * 2) {
                    its++;
                    ar[ars++] = t0[i] * 2 + addt;
                    if (t0[i] * 2 + addt == 0) {
                        cannotStart0 = true;
                    }
                    if (t0[i] * 2 + addt == 2 * x) {
                        cannotEnd1 = true;
                    }
                    addt += n;
                }
                if (its > 2) {
                    throw new AssertionError(n + " " + a[i] + " " + t0[i] + " " + t[i] + " " + at);
                }
            }
            Arrays.sort(ar, 0, ars);
            //System.err.println(at + " " + ts);
            long ret = 0;
            for (int i = 0; i < ars - 1; ++i) {
                long u = ar[i];
                long v = ar[i + 1];
                if (u > 0 || cannotStart0) {
                    u++;
                }
                if (v < 2 * x || cannotEnd1) {
                    v--;
                }
                u += u % 2;
                v -= v % 2;
                if (u < v) {
                    ret = Math.max(ret, (v - u) / 2);
                }
            }
            return ret;
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
			out = new PrintWriter(file + ".out1");

			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);

			int tests = in.nextInt();
//			Future<String>[] ts = new Future[tests];
//			for (int test = 0; test < tests; ++test) {
//				ts[test] = service.submit(new Solver(new InputData(in)));
//			}
			for (int test = 0; test < tests; ++test) {
                Solver s = new Solver(new InputData(in));
				out.print("Case #" + (test + 1) + ": ");
				out.print(s.call());
			}
			service.shutdown();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

    static BigInteger bi(long value) {
        return BigInteger.valueOf(value);
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

        BigInteger nextBigInteger() throws IOException {
            return new BigInteger(next());
        }
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new A().run();
	}

}