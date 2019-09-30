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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[][] d = new int[n+1][n+1];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					d[i][j] = in.nextInt();
				}
			}

			int[][] sum = new int[n+1][n+1];

			// 2?????
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + d[i][j];
				}
			}

			// ???????????(??????)
			int[] ans = new int[n*n+1];
			for (int y1 = 1; y1 <= n; y1++) for (int y2 = y1; y2 <= n; y2++) {
				for (int x1 = 1; x1 <= n; x1++) for (int x2 = x1; x2 <= n; x2++) {
					int total = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
					int area = (y2-y1+1)*(x2-x1+1);
					ans[area] = Math.max(ans[area], total);
				}
			}

			for (int i = 0; i < n*n; i++) {
				ans[i+1] = Math.max(ans[i], ans[i+1]);
			}

			// ?????
			int q = in.nextInt();
			int[] p = in.nextIntArray(q);
			for (int i = 0; i < q; i++) {
				out.println(ans[p[i]]);
			}


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

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}