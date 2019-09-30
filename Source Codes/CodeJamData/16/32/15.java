import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			long need = in.nextLong();
			long nneed = need;
			// 1, 1, 2, 4, 8, 16
			long[] res = new long[n];
			res[0] = 1;
			boolean[][] g = new boolean[n][n];
			for (int i = 1; i + 1 < n; i++) {
				for (int j = 0; j < i; j++) {
					g[j][i] = true;
					res[i] += res[j];
				}
			}
			for (int j = n - 2; j >= 0; j--) {
				if (need >= res[j]) {
					g[j][n - 1] = true;
					need -= res[j];
				}
			}
			if (need == 0) {
				out.println("POSSIBLE");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						out.print(g[i][j] ? 1 : 0);
					}
					out.println();
				}
			} else {
				out.println("IMPOSSIBLE");
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