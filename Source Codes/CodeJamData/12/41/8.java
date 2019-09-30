import java.io.*;
import java.util.*;

public class A implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int[] d = new int[n], l = new int[n];
		for (int i = 0; i < n; ++i) {
			d[i] = in.nextInt();
			l[i] = in.nextInt();
		}
		int full = in.nextInt();		
		int[] len = new int[n];
		len[0] = d[0];
		int p = 0;
		int maxDist = 2 * d[0];
		for (int i = 1; i < n; ++i) {
			if (maxDist < d[i]) {
				break;
			}
			while (d[p] + len[p] < d[i]) {
				++p;
			}
			len[i] = Math.min(l[i], d[i] - d[p]);
			maxDist = Math.max(maxDist, d[i] + len[i]);
		}
		out.println(maxDist >= full ? "YES" : "NO");
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