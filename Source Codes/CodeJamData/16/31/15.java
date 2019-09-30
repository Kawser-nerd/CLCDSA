import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int getMax(int[] a) {
		int r = 0;
		for (int i = 1; i < a.length; i++) {
			if (a[i] > a[r]) {
				r = i;
			}
		}
		a[r]--;
		return r;
	}

	void check(int[] a) {
		int sum = 0;
		for (int i : a) {
			sum += i;
		}
		for (int i : a) {
			if (i * 2 > sum) {
				throw new AssertionError();
			}
		}
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int sum = 0;
			for (int x : a) {
				sum += x;
			}
			while (sum > 0) {
				int id1 = getMax(a);
				sum--;
				out.print((char) ('A' + id1));
				if (sum % 2 != 0) {
					int id2 = getMax(a);
					sum--;
					out.print((char) ('A' + id2));
				}
				out.print(" ");
				check(a);
			}
			out.println();
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

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
		new A().run();
	}
}