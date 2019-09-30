import java.io.*;
import java.util.*;

public class C implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	int[] next, y;

	void go(int from, int to, int k) {
		if (from >= to) {
			return;
		}
		if (next[from] > to) {			
			go(from + 1, to, k);
			return;
		}
		for (int i = from + 1; i < next[from]; ++i) {
			y[i] = y[next[from]] - (k + 1) * (next[from] - i);
		}
		go(from + 1, next[from], k + 1);
		go(next[from], to, k);
	}

	private void solve() {
		int n = in.nextInt();
		next = new int[n - 1];
		for (int i = 0; i < n - 1; ++i) {
			next[i] = in.nextInt() - 1;
		}
		for (int i = 0; i < n - 2; ++i) {
			for (int j = i + 1; j < n - 1; ++j) {
				if (next[i] > j && next[j] > next[i]) {
					out.println("Impossible");
					return;
				}
			}
		}
		y = new int[n];
		for (int i = 0; i < n; ++i) {
			y[i] = i;
		}
		go(0, n - 1, 1);
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n - 1; ++i) {
			min = Math.min(min, y[i]);
		}
		for (int i = 0; i < n; ++i) {
			out.print((y[i] - min) + " ");
		}
		out.println();
	}

	@Override
	public void run() {
		in = new MyScanner();
		try {
			out = new PrintWriter(new File("C-large.out"));
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
		new C().run();
	}

	class MyScanner {
		private BufferedReader br;
		private StringTokenizer st;

		public MyScanner() {
			try {
				br = new BufferedReader(new FileReader("C-large.in"));
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