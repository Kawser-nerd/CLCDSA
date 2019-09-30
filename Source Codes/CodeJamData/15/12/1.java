import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int b = in.nextInt();
			int n = in.nextInt();
			int[] m = new int[b];
			for (int i = 0; i < b; i++) {
				m[i] = in.nextInt();
			}
			final long MAX = (long) 1e16;
			long left = -1, right = MAX;
			while (right - left > 1) {
				long mid = (left + right) / 2;
				long sum = 0;
				for (int i = 0; i < b; i++) {
					sum += 1 + mid / m[i];
					if (sum > MAX) {
						sum = MAX;
					}
				}
				if (sum < n) {
					left = mid;
				} else {
					right = mid;
				}
			}
			long cntStarted = 0;
			long sum = 0;
			for (int i = 0; i < b; i++) {
				cntStarted += 1 + left / m[i];
				if (sum > MAX) {
					sum = MAX;
				}
			}
			if (left == 0) {
				cntStarted = 0;
			}
			boolean found = false;
			for (int i = 0; i < b; i++) {
				if (right % m[i] == 0) {
					cntStarted++;
				}
				if (cntStarted == n) {
					out.println((i + 1));
					found = true;
					break;
				}
			}
			if (!found) {
				throw new AssertionError();
			}
			System.err.println((t + 1) + "/" + tc + " done");
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