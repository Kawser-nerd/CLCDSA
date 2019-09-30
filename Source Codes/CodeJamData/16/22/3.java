import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2016R2B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	static Random rnd = new Random(42);

	static class Val implements Comparable<Val> {
		long a, b;

		public Val(long a, long b) {
			this.a = a;
			this.b = b;
		}

		Val append(long da, long db) {
			return new Val(10 * a + da, 10 * b + db);
		}

		long diff() {
			return a - b;
		}

		@Override
		public int compareTo(Val o) {
			int r = Long.compare(Math.abs(diff()), Math.abs(o.diff()));
			if (r == 0) {
				r = Long.compare(a, o.a);
			}
			if (r == 0) {
				r = Long.compare(b, o.b);
			}
			return r;
		}

		@Override
		public String toString() {
			return a + "-" + b;
		}
	}

	static class InputData {

		String u, v;
		
		InputData(FastReader in) throws IOException {
			u = in.next();
			v = in.next();
		}
		
		void solve(PrintWriter out) {
			Val bestPos = null;
			Val bestEq = new Val(0, 0);
			Val bestNeg = null;
			for (int i = 0; i < u.length(); ++i) {
				Val newBestPos = null, newBestEq = null, newBestNeg = null;
				for (int da = u.charAt(i) == '?' ? 0 : u.charAt(i) - '0'; da <= (u.charAt(i) == '?' ? 9 : u.charAt(i) - '0'); ++da) {
					for (int db = v.charAt(i) == '?' ? 0 : v.charAt(i) - '0'; db <= (v.charAt(i) == '?' ? 9 : v.charAt(i) - '0'); ++db) {
						for (Val from : new Val[] {bestPos, bestEq, bestNeg}) {
							if (from == null) {
								continue;
							}
							Val v = from.append(da, db);
							if (v.diff() < 0 && (newBestNeg == null || newBestNeg.compareTo(v) > 0)) {
								newBestNeg = v;
							}
							if (v.diff() == 0 && (newBestEq == null || newBestEq.compareTo(v) > 0)) {
								newBestEq = v;
							}
							if (v.diff() > 0 && (newBestPos == null || newBestPos.compareTo(v) > 0)) {
								newBestPos = v;
							}
						}
					}
				}
				bestPos = newBestPos;
				bestEq = newBestEq;
				bestNeg = newBestNeg;
//				System.err.println(i + " " + bestNeg + " " + bestPos);
			}
			Val best = null;
			if (bestNeg != null && (best == null || best.compareTo(bestNeg) > 0)) {
				best = bestNeg;
			}
			if (bestEq != null && (best == null || best.compareTo(bestEq) > 0)) {
				best = bestEq;
			}
			if (bestPos != null && (best == null || best.compareTo(bestPos) > 0)) {
				best = bestPos;
			}
			long pow10 = 1;
			for (int it = 0; it < u.length(); ++it) {
				pow10 *= 10;
			}
//			if (pow10 * pow10 <= 10000) {
//				for (long x = 0; x < pow10; ++x) {
//					if (!matches(pad(x, u.length()), u)) {
//						continue;
//					}
//					for (long y = 0; y < pow10; ++y) {
//						if (!matches(pad(y, v.length()), v)) {
//							continue;
//						}
//						Val v1 = new Val(x, y);
//						if (v1.compareTo(best) < 0) {
//							throw new AssertionError(u + " " + v + " " + best + " " + v1);
//						}
//					}
//				}
//			}
			out.println(pad(best.a, u.length()) + " " + pad(best.b, u.length()));
		}

		private boolean matches(String s, String mask) {
			for (int i = 0; i < s.length(); ++i) {
				if (s.charAt(i) != mask.charAt(i) && mask.charAt(i) != '?') {
					return false;
				}
			}
			return true;
		}

		private String pad(long x, int length) {
			String ret = Long.toString(x);
			while (ret.length() < length) {
				ret = "0" + ret;
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
		new GCJ2016R2B().run();
	}
	
}
