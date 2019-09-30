import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;

	long[] e, s;
	long[][] d;
	
	public void solve() throws IOException {
		int n = in.nextInt(), q = in.nextInt();
		e = new long[n];
		s = new long[n];
		for (int i = 0; i < n; i++) {
			e[i] = in.nextLong();
			s[i] = in.nextLong();
		}
		d = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = in.nextLong();
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][k] != -1 && d[k][j] != -1) {
						if (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j]) {
							d[i][j] = d[i][k] + d[k][j];
						}
					}
				}
			}
		}
		for (int test = 0; test < q; test++) {
			int from = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			double[] dist = new double[n];
			final double inf = Double.POSITIVE_INFINITY;
			Arrays.fill(dist, inf);
			boolean[] was = new boolean[n];
			dist[from] = 0;
			while (true) {
				int u = -1;
				for (int i = 0; i < n; i++) {
					if (!was[i] && dist[i] != inf) {
						if (u == -1 || dist[i] < dist[u]) {
							u = i;
						}
					}
				}
				if (u == -1) {
					break;
				}
				was[u] = true;
				for (int j = 0; j < n; j++) {
					if (d[u][j] != -1 && e[u] >= d[u][j]) {
						dist[j] = Math.min(dist[j], dist[u] + d[u][j] * 1.0 / s[u]);
					}
				}
			}
			out.print(dist[to] + " ");
		}
		out.println();
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
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

	public static void main(String[] arg) {
		new C().run();
	}
}