import java.io.*;
import java.util.*;

public class B implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int[] a = new int[n], b = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
			b[i] = in.nextInt();
		}
		int[] level = new int[n];
		int finished = 0;
		int stars = 0;
		int rounds = 0;
		loop: while (finished < n) {
			// make one decision
			++rounds;
			for (int i = 0; i < n; ++i) {
				if (level[i] < 2 && b[i] <= stars) {
					stars += 2 - level[i];
					level[i] = 2;
					++finished;
					continue loop;
				}
			}
			int maxB = -1;
			for (int i = 0; i < n; ++i) {
				if (level[i] < 1 && a[i] <= stars) {
					if (maxB == -1 || b[i] > b[maxB]) {
						maxB = i;
					}
				}
			}
			if (maxB == -1) {
				out.println("Too Bad");
				return;
			}
			++stars;
			level[maxB] = 1;
		}
		out.println(rounds);
	}

	@Override
	public void run() {
		in = new MyScanner();
		try {
			out = new PrintWriter(new File("B-large.out"));
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
		new B().run();
	}

	class MyScanner {
		private BufferedReader br;
		private StringTokenizer st;

		public MyScanner() {
			try {
				br = new BufferedReader(new FileReader("B-large.in"));
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