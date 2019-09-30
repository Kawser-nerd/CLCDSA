import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R3B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	static Random rnd = new Random(42);

	static class InputData {

        int n, k;
        long[] s;

        InputData() {

        }
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            k = in.nextInt();
            s = new long[n];
            for (int i = 0; i + k <= n; ++i) {
                s[i] = in.nextLong();
            }
		}
		
		void solve(PrintWriter out) {
            long[] add = new long[n];
            long[] minAdd = new long[k];
            long[] maxAdd = new long[k];
            for (int i = k; i < n; ++i) {
                add[i] = add[i - k] + s[i - k + 1] - s[i - k];
                minAdd[i % k] = Math.min(minAdd[i % k], add[i]);
                maxAdd[i % k] = Math.max(maxAdd[i % k], add[i]);
            }
            long l = -1, r = 1000000000000L;
            loop: while (l + 1 < r) {
                long mid = (l + r) / 2;
//                if (mid == 0) {
//                    System.err.println();
//                }
                for (int mod = 0; mod < k; ++mod) {
                    if (maxAdd[k - 1] - minAdd[k - 1] > mid || mod > mid) {
                        break;
                    }
                    for (int i = 0; i < k - 1; ++i) {
                        if (maxAdd[i] - minAdd[i] > mid - mod) {
                            l = mid;
                            continue loop;
                        }
                    }
                    for (int min = 0; min < k - 1; ++min) {
                        // s[0]-(kx+t)+minAdd[k-1]==-mod
                        // -mod..mid-mod
                        long mint = minAdd[min], maxt = minAdd[min];
                        for (int i = 0; i < k - 1; ++i) {
                            if (i == min) {
                                continue;
                            }
                            //t+minAdd[i]>=minAdd[min]
                            //t+maxAdd[i]<=minAdd[min]+mid-mod
                            mint += minAdd[min] - minAdd[i];
                            maxt += minAdd[min] + mid - mod - maxAdd[i];
                        }
                        if (mint > maxt) {
                            throw new AssertionError();
                        }
                        mint -= s[0] + minAdd[k - 1];
                        maxt -= s[0] + minAdd[k - 1];
                        long q = mint / k;
                        mint -= q * k;
                        maxt -= q * k;
                        while (mint < 0) {
                            mint += k;
                            maxt += k;
                        }
                        while (mint >= k) {
                            mint -= k;
                            maxt -= k;
                        }
                        if (mint <= mod && mod <= maxt || mod <= maxt - k) {
                            r = mid;
                            continue loop;
                        }
                        if (mod == 0) {
                            for (int mod1 = 0; mod1 < k; ++mod1) {
                                long mod2 = (k - mod1) % k;
                                if (mod1 + maxAdd[k - 1] - minAdd[k - 1] <= mid && (mint <= mod2 && mod2 <= maxt || mod2 <= maxt - k)) {
                                    r = mid;
                                    continue loop;
                                }
                            }
                        }
                    }
                }
                l = mid;
            }
            out.println(r);
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
//        Random rnd = new Random(42);
//        while (rnd != null) {
//            InputData in = new InputData();
//            in.n = rnd.nextInt(10) + 2;
//            in.k = rnd.nextInt(in.n - 1) + 2;
//            long[] a = new long[in.n];
//            in.s = new long[in.n - in.k + 1];
//            long max = Long.MIN_VALUE, min = Long.MAX_VALUE;
//            for (int i = 0; i < in.n; ++i) {
//                a[i] = rnd.nextInt(11) - 5;
//                min = Math.min(min, a[i]);
//                max = Math.max(max, a[i]);
//            }
//            for (int i = 0; i + in.k <= in.n; ++i) {
//                for (int j = i; j < i + in.k; ++j) {
//                    in.s[i] += a[j];
//                }
//            }
//
//            StringWriter out = new StringWriter();
//            in.solve(new PrintWriter(out));
//            long val = Long.parseLong(out.toString().trim());
//            if (val > max - min) {
//                System.err.println(in.k + " " + Arrays.toString(a) + " " + Arrays.toString(in.s) + " " + val);
//                throw new AssertionError();
//            }
//        }

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
		new GCJ2015R3B().run();
	}
	
}
