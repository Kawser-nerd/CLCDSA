import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		final int N = 13;
		String[][] res = new String[3][N];
		res[0][0] = "P";
		res[1][0] = "R";
		res[2][0] = "S";
		for (int layer = 1; layer < N; layer++) {
			for (int need = 0; need < 3; need++) {
				String s1 = res[need][layer - 1], s2 = res[(need + 1) % 3][layer - 1];
				if (s1.compareTo(s2) < 0) {
					res[need][layer] = s1 + s2;
				} else {
					res[need][layer] = s2 + s1;
				}
			}
		}
		System.err.println(res[0][1]);
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int r = in.nextInt();
			int p = in.nextInt();
			int s = in.nextInt();
			String result = null;
			for (int v = 0; v < 3; v++) {
				int cntR = 0, cntP = 0, cntS = 0;
				for (char c : res[v][n].toCharArray()) {
					if (c == 'R')
						cntR++;
					if (c == 'P')
						cntP++;
					if (c == 'S')
						cntS++;
				}
				if (cntR == r && cntP == p && cntS == s) {
					if (result == null || result.compareTo(res[v][n]) > 0) {
						result = res[v][n];
					}
				}
			}
			out.println(result == null ? "IMPOSSIBLE" : result);
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