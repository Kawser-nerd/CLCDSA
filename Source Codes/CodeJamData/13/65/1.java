import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class E implements Runnable {

	private PrintWriter out;

	final String file = "E-small-attempt1";
	Random rnd = new Random(42);

    final static int mod = 10007;

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
//            int solve0 = solveSlow(a); //TODO remove!
            int ans = solve();
            int[] a0 = a.clone();
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[i] = -a[n - i - 1];
            }
            a = b;
            System.err.println("---- " + ans);
            ans = (ans + solve()) % mod;
            if (ans == 0) {
                ans = 1;
            }
//            if (ans != solve0) {
//                System.err.println(Arrays.toString(a0) + " " + ans + " " + solve0);
//                throw new AssertionError();
//            }
            out.println(ans);
		}

        private int solveSlow(int[] a) {
//            System.err.println(Arrays.toString(a));
            loop: do {
                for (int i = 1; i < a.length; ++i) {
                    if (a[i - 1] < a[i]) {
                        break loop;
                    }
                }
                return 1;
            } while (false);
            int ret = 0;
            for (int i = 0; i < a.length; ++i) {
                int[] b = new int[a.length - 1];
                for (int j = 0; j < a.length; ++j) {
                    if (j != i) {
                        b[j < i ? j : j - 1] = a[j];
                    }
                }
                ret += solveSlow(b);
            }
            return ret;
        }

        private int solve() {
            int[][][] d = new int[2][n][n + 1];
            for (int i = 0; i < n; ++i) {
                d[0][i][1] = 1;
//                int count = 0;
//                for (int t = 0; t < i; ++t) {
//                    if (a[t] < a[i]) {
//                        count++;
//                    }
//                }
//                d[1][i][1] = count;
            }
            for (int i = 0; i < n; ++i) {
                for (int c1 = 0; c1 < 2; ++c1) {
                    for (int c = 0; c <= n; ++c) {
                        if (d[c1][i][c] == 0) {
                            continue;
                        }
                        for (int j = i + 1; j < n; ++j) {
                            if (a[i] >= a[j]) {
                                d[c1][j][c + 1] = (d[c1][j][c + 1] + d[c1][i][c]) % mod;
                                if (c1 < 1) {
                                    int count = 0;
                                    for (int t = i + 1; t < j; ++t) {
                                        if (a[t] > a[i]) {
                                            count++;
                                        }
                                    }
                                    d[c1 + 1][j][c + 1] = (d[c1 + 1][j][c + 1] + count * d[c1][i][c]) % mod;
                                }
                            }
                        }
                    }
                }
            }
            int[] fact = new int[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; ++i) {
                fact[i] = (fact[i - 1] * i) % mod;
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int c = 1; c <= n; ++c) {
                    if (d[1][i][c] != 0) {
                        System.err.println(i + " " + c + " " + d[1][i][c] + "*" + fact[n - c - 1]);
                        ans = (ans + d[1][i][c] * fact[n - c - 1]) % mod;
                    }
                    if (d[0][i][c] != 0) {
                        int count = 0;
                        for (int t = i + 1; t < n; ++t) {
                            if (a[t] > a[i]) {
                                count++;
                            }
                        }
                        if (count > 0) {
                            System.err.println("c1 " + i + " " + c + " " + (d[0][i][c] * count) + "*" + fact[n - c - 1]);
                            ans = (ans + ((d[0][i][c] * count) % mod) * fact[n - c - 1]) % mod;
                        }
                    }
                }
            }
            return ans;
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
//            Random rnd = new Random();
//            while (rnd != null) {
//                StringBuilder sb = new StringBuilder();
//                int n = 7;
//                sb.append(n + "\n");
//                for (int i = 0; i < n; ++i) {
//                    sb.append(rnd.nextInt(10) + " ");
//                }
//                new Solver(new InputData(new FastReader(new BufferedReader(new StringReader(sb.toString()))))).call();
//            }


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
		new E().run();
	}

}