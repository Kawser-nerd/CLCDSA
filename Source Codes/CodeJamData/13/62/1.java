import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class B implements Runnable {

	private PrintWriter out;

	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {

        int n;
        double[] y;

		InputData(FastReader in) throws IOException {
		    n = in.nextInt();
            y = new double[n];
            for (int i = 0; i < n; ++i) {
                y[i] = in.nextDouble();
            }
		}

		void solve(PrintWriter out) {
		    int[] st1 = new int[n];
            int[] st2 = new int[n];
            int stp1 = 0, stp2 = 0;
            for (int i = 0; i < n; ++i) {
                while (stp1 > 1) {
                    double dx1 = st1[stp1 - 1] - st1[stp1 - 2];
                    double dy1 = y[st1[stp1 - 1]] - y[st1[stp1 - 2]];
                    double dx2 = i - st1[stp1 - 2];
                    double dy2 = y[i] - y[st1[stp1 - 2]];
                    if (dy1 * dx2 > dy2 * dx1) {
                        stp1--;
                    } else {
                        break;
                    }
                }
                st1[stp1++] = i;
                while (stp2 > 1) {
                    double dx1 = st2[stp2 - 1] - st2[stp2 - 2];
                    double dy1 = y[st2[stp2 - 1]] - y[st2[stp2 - 2]];
                    double dx2 = i - st2[stp2 - 2];
                    double dy2 = y[i] - y[st2[stp2 - 2]];
                    if (dy1 * dx2 < dy2 * dx1) {
                        stp2--;
                    } else {
                        break;
                    }
                }
                st2[stp2++] = i;
            }
            st1 = Arrays.copyOf(st1, stp1);
            st2 = Arrays.copyOf(st2, stp2);
            //out.println(Arrays.toString(st1) + " " + Arrays.toString(st2));
            double ans = 0;
            for (int i = 0, p1 = 0, p2 = 0; i < n; ++i) {
                while (p1 + 1 < stp1 && st1[p1 + 1] <= i) {
                    ++p1;
                }
                while (p2 + 1 < stp2 && st2[p2 + 1] <= i) {
                    ++p2;
                }
                double v1 = p1 == stp1 - 1 ? y[st1[p1]] : y[st1[p1]] + (y[st1[p1 + 1]] - y[st1[p1]]) * (i - st1[p1]) / (st1[p1 + 1] - st1[p1]);
                double v2 = p2 == stp2 - 1 ? y[st2[p2]] : y[st2[p2]] + (y[st2[p2 + 1]] - y[st2[p2]]) * (i - st2[p2]) / (st2[p2 + 1] - st2[p2]);
                ans = Math.max(ans, v2 - v1);
            }
            out.println(ans / 2.0);
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
		new B().run();
	}

}