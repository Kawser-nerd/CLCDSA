import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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

		int n, m;
		long[] s = new long[1<<n];
		boolean[][] mat;
		long[] memo;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			n = in.nextInt();
			m = in.nextInt();
			mat = new boolean[n][n];
			memo = new long[1<<n];
			Arrays.fill(memo, -1);

			for (int i = 0; i < m; i++) {
				int x = in.nextInt()-1, y = in.nextInt()-1;
				mat[x][y] = true;
			}

			long ans = rec((1<<n) - 1);
			out.println(ans);
		}

		long rec(int state) {

			if (memo[state] != -1) {
				return memo[state];
			}

			if (Integer.bitCount(state) == 0) {
				return 1;
			}

			long ret = 0;

			for (int i = 0; i < n; i++) {
				if (((state >> i) & 1) == 1) {
					boolean ok = true;
					for (int j = 0; j < n; j++) {

						if (i == j) continue;
						if (((state >> j) & 1) == 1) {
							if (mat[i][j]) {
								ok = false;
							}
						}
					}

					if (ok) {
						ret += rec(state - (1<<i));
					}
				}
			}
			return memo[state] = ret;
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

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}