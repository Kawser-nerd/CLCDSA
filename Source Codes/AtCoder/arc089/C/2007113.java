import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
		ProblemE solver = new ProblemE();
		solver.solve(1, in, out);
		out.close();
	}

	static class ProblemE {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int a = in.nextInt();
			int b = in.nextInt();
			int[][] d = new int[a + 1][b + 1];
			for (int x = 1; x <= a; x++) {
				for (int y = 1; y <= b; y++) {
					d[x][y] = in.nextInt();
				}
			}

			final int N = 101;
			int[][] f = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int x = 1; x <= a; x++) {
						for (int y = 1; y <= b; y++) {
							f[i][j] = Math.max(f[i][j], d[x][y] - i * x - j * y);
						}
					}
				}
			}

			for (int x = 1; x <= a; x++) {
				for (int y = 1; y <= b; y++) {
					int cur = Integer.MAX_VALUE;
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							cur = Math.min(cur, i * x + j * y + f[i][j]);
						}
					}
					if (cur != d[x][y]) {
						out.println("Impossible");
						return;
					}
				}
			}

			out.println("Possible");
			int m = 2 * (N - 1) + N * N;
			out.println((2 * N) + " " + m);
			for (int i = 0; i + 1 < N; i++) {
				out.println((i + 1) + " " + (i + 2) + " X");
				out.println((N + i + 1) + " " + (N + i + 2) + " Y");
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					out.println((i + 1) + " " + (2 * N - j) + " " + f[i][j]);
				}
			}
			out.println(1 + " " + (2 * N));
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
					st = new StringTokenizer(in.readLine());
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