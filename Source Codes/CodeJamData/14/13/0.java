import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJR1C implements Runnable {

	private PrintWriter out;
	
	final String file = "C-small-attempt0";
	static Random rnd = new Random(42);

    final static int N = 1000;

    static double[][] ps;

    static {
        ps = new double[N][N];
        for (int i = 0; i < N; ++i) {
            ps[i][i] = 1.0;
        }
        for (int i = 0; i < N; ++i) {
            for (int from = 0; from < N; ++from) {
                double[] newPsi = new double[N];
                for (int j = 0; j < N; ++j) {
                    if (j == from) {
                        // newPsi[j] = ps[i][j] * 1.0 / N + (1.0 - ps[i][j]) * 1.0 / N;
                        newPsi[j] = 1.0 / N;
                    } else {
                        newPsi[j] = ps[i][j] * (1.0 - 1.0 / N) + ps[i][from] * 1.0 / N;
                    }
                }
                ps[i] = newPsi;
            }
        }
//        double[][] ps1 = new double[N][N];
//        final int ITS = 1000000;
//        for (int it = 0; it < ITS; ++it) {
//            int[] ar = new int[N];
//            for (int i = 0; i < N; ++i) {
//                ar[i] = i;
//            }
//            shuffle(ar);
//            for (int i = 0; i < N; ++i) {
//                ps1[ar[i]][i] += 1.0 / ITS;
//            }
//        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (N <= 10) System.err.print(ps[i][j] + " ");
                ps[i][j] = Math.log(ps[i][j]);
            }
            if (N <= 10) System.err.println();
        }
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < N; ++j) {
//                System.err.print(ps1[i][j] + " ");
//            }
//            System.err.println();
//        }
        System.err.println("here");
    }

    private static void shuffle(int[] ar) {
        for (int i = 0; i < ar.length; ++i) {
            int k = rnd.nextInt(ar.length);
            int tmp = ar[i];
            ar[i] = ar[k];
            ar[k] = tmp;
        }
    }

    static class InputData {

        int[] ar;

		InputData(FastReader in) throws IOException {
            int n = in.nextInt();
            if (n != N) {
                throw new AssertionError();
            }
            ar = new int[n];
            for (int i = 0; i < n; ++i) {
                ar[i] = in.nextInt();
            }
		}
		
		void solve(PrintWriter out) {
            double cGood = -N * Math.log(N);
            double cBad = 0.0;
            for (int i = 0; i < N; ++i) {
                cBad += ps[ar[i]][i];
            }
            out.println(cGood > cBad ? "GOOD" : "BAD");
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
		new GCJR1C().run();
	}
	
}
