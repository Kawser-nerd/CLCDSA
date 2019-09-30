import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int h = in.nextInt(), w = in.nextInt();
			int[][] sumw = new int[h+1][w+1];
			int[][] sumb = new int[h+1][w+1];

			int[][] white = new int[h+1][w+1];
			int[][] black = new int[h+1][w+1];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if ((i + j) % 2 == 0) {
						black[i][j] = in.nextInt();
					} else {
						white[i][j] = in.nextInt();
					}
				}
			}

			for (int i = 0; i < h+1; i++) {
				for (int j = 0; j < w+1; j++) {
					sumw[i][j] = white[i][j];
					if (i > 0) sumw[i][j] += sumw[i-1][j];
					if (j > 0) sumw[i][j] += sumw[i][j-1];
					if (i > 0 && j > 0) sumw[i][j] -= sumw[i-1][j-1];

					sumb[i][j] = black[i][j];
					if (i > 0) sumb[i][j] += sumb[i-1][j];
					if (j > 0) sumb[i][j] += sumb[i][j-1];
					if (i > 0 && j > 0) sumb[i][j] -= sumb[i-1][j-1];
				}
			}

			int ans = 0;
			for (int i = 0; i < h; i++) {
				for (int j = i; j < h; j++) {
					for (int k = 0; k < w; k++) {
						for (int l = k; l < w; l++) {
							if (get(i, k, j, l, sumw) == get(i, k, j, l, sumb)) {
								ans = Math.max(ans, (j-i+1) * (l-k+1));
							}
						}
					}
				}
			}

			out.println(ans);

		}

		int get(int x1, int y1, int x2, int y2, int[][] sum) {
			int res = sum[x2][y2];
			if (x1 > 0) res -= sum[x1-1][y2];
			if (y1 > 0) res -= sum[x2][y1-1];
			if (x1 > 0 && y1 > 0) res += sum[x1-1][y1-1];
			return res;
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}

		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public long[] nextLongArrayDec(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}

		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}