import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] edgeCost = new int[n][n];
			for (int[] arr : edgeCost) {
				Arrays.fill(arr, -1);
			}
			int totalCost = 0;
			for (int i = 0; i < m; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				int c = in.nextInt();
				edgeCost[a][b] = c;
				edgeCost[b][a] = c;
				totalCost += c;
			}

			int[] compCost = new int[1 << n];
			for (int mask = 0; mask < 1 << n; mask++) {
				for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) == 0) {
						continue;
					}
					for (int j = i + 1; j < n; j++) {
						if ((mask & (1 << j)) == 0) {
							continue;
						}
						if (edgeCost[i][j] >= 0) {
							compCost[mask] += edgeCost[i][j];
						}
					}
				}
			}

			int[][] d = new int[n][1 << n];
			for (int[] arr : d) {
				Arrays.fill(arr, -1);
			}
			for (int mask = 0; mask < 1 << n; mask++) {
				if ((mask & (1 << 0)) > 0) {
					d[0][mask] = compCost[mask];
				}
			}
			int full = (1 << n) - 1;
			for (int mask = 0; mask < 1 << n; mask++) {
				for (int root = 0; root < n; root++) {
					if ((mask & (1 << root)) == 0) {
						continue;
					}
					if (d[root][mask] < 0) {
						continue;
					}
					int others = full ^ mask;
					for (int addMask = others; addMask > 0; addMask = (addMask - 1) & others) {
						for (int nRoot = 0; nRoot < n; nRoot++) {
							if ((addMask & (1 << nRoot)) == 0) {
								continue;
							}
							if (edgeCost[root][nRoot] < 0) {
								continue;
							}
							int nMask = mask | addMask;
							d[nRoot][nMask] = Math.max(d[nRoot][nMask], d[root][mask] + edgeCost[root][nRoot] + compCost[addMask]);
						}
					}
				}
			}

			out.println(totalCost - d[n - 1][full]);
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}