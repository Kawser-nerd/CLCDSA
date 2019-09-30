import java.io.*;
import java.util.*;

public class A implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	private void solve() {
		int a = in.nextInt(), b = in.nextInt();
		double[] prod = new double[a + 1];
		prod[0] = 1.;
		for (int i = 0; i < a; ++i) {
			double prob = in.nextDouble();
			prod[i + 1] = prod[i] * prob;
		}
		// continue typing
		double ans = (b - a + 1) + (1 - prod[a]) * (b + 1);
		// just enter
		ans = Math.min(ans, 1 + (b + 1));
		// backspace
		for (int back = 1; back <= a; ++back) {
			ans = Math.min(ans, 2 * back + (b - a + 1) + (1. - prod[a - back])
					* (b + 1));
		}
		out.printf("%.15f\n", ans);
	}

	@Override
	public void run() {
		in = new MyScanner();
		try {
			out = new PrintWriter(new File("A-large.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int tests = in.nextInt();
		for (int i = 0; i < tests; ++i) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		in.close();
		out.close();
	}

	public static void main(String[] args) {
		new A().run();
	}

	class MyScanner {
		private BufferedReader br;
		private StringTokenizer st;

		public MyScanner() {
			try {
				br = new BufferedReader(new FileReader("A-large.in"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return false;
				}
			}
			return st != null && st.hasMoreTokens();
		}

		private String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return null;
				}
			}
			return st.nextToken();
		}

		public String nextLine() {
			try {
				st = null;
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}