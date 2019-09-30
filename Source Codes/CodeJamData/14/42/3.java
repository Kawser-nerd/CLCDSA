import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	class Some implements Comparable<Some> {
		int pos, val;

		public Some(int pos, int val) {
			super();
			this.pos = pos;
			this.val = val;
		}

		@Override
		public int compareTo(Some arg0) {
			return Integer.compare(val, arg0.val);
		}

	}

	void solveTestCase() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		Some[] b = new Some[n];
		for (int i = 0; i < n; i++)
			b[i] = new Some(i, a[i]);
		Arrays.sort(b);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int val = b[i].val;
			int min = Integer.MAX_VALUE;
			{
				int tmp = 0;
				for (int j = b[i].pos; j >= 0; j--)
					if (a[j] > val)
						tmp++;
				min = Math.min(min, tmp);
			}
			{
				int tmp = 0;
				for (int j = b[i].pos; j < n; j++)
					if (a[j] > val)
						tmp++;
				min = Math.min(min, tmp);
			}
			res += min;
		}
		out.println(res);
	}

	void solve() {
		int testNumber = in.nextInt();
		for (int test = 1; test <= testNumber; test++) {
			System.err.println(test);
			out.print("Case #" + test + ": ");
			solveTestCase();
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}
