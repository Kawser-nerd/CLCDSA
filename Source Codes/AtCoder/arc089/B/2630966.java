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

			int n = in.nextInt(), k = in.nextInt();
			int[][] mat = new int[4*k+1][4*k+1];
			int[][] sum = new int[4*k+1][4*k+1];
			for (int i = 0; i < n; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				String c = in.nextString();

				if (c.equals("W")) {
					y += k;
				}

				mat[x%(2*k)][y%(2*k)]++;
			}

			for (int x = 0; x <= 4*k; x++) {
				for (int y = 0; y <= 4*k; y++) {
					mat[x][y] = mat[x%(2*k)][y%(2*k)];
				}
			}

			for (int i = 0; i <= 4*k; i++) {
				for (int j = 0; j <= 4*k; j++) {
					sum[i][j] = mat[i][j];
					if (j-1 >= 0) sum[i][j] += sum[i][j-1];
					if (i-1 >= 0) sum[i][j] += sum[i-1][j];
					if (i-1 >= 0 && j-1 >= 0) sum[i][j] -= sum[i-1][j-1];
				}
			}

			int ans = 0;
			for (int x = 0; x <= 2*k; x++) {
				for (int y = 0; y <= 2*k; y++) {
					int tmp = 0;
					tmp += get(x, y, x+k-1, y+k-1, sum);
					tmp += get(x+k, y+k, x+2*k-1, y+2*k-1, sum);
					ans = Math.max(ans, tmp);
				}
			}

			out.println(ans);
		}

	}
	static int get(int x1, int y1, int x2, int y2, int[][] sum) {

		int res = sum[x2][y2];
		if (x1 > 0) res -= sum[x1-1][y2];
		if (y1 > 0) res -= sum[x2][y1-1];
		if (x1 > 0 && y1 > 0) res += sum[x1-1][y1-1];

		return res;
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