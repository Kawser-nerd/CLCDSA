import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int k = in.nextInt();
			int c = in.nextInt();
			int S = in.nextInt();
			if (k == 1) {
				out.println("1");
			} else {
				int need = 1 + (k - 1) / c;
				if (need <= S) {
					long[] powers = new long[c + 1];
					powers[0] = 1;
					for (int i = 1; i <= c; i++) {
						powers[i] = powers[i - 1] * k;
					}
					int[][] res = new int[need][c];
					int it = 0;
					for (int i = 0; i < need; i++) {
						for (int j = 0; j < c; j++) {
							res[i][j] = it++ % k;
						}
					}
					for (int i = 0; i < need; i++) {
						long val = 1;
						for (int j = 0; j < c; j++) {
							val += powers[j] * res[i][j];
						}
						out.print(val + " ");
					}
					out.println();
				} else {
					out.println("IMPOSSIBLE");
				}
			}
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D.out"));

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
		new D().run();
	}
}