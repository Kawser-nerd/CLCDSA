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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static int h, w;
	static long[][] a, memo;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			h = in.nextInt(); w = in.nextInt();
			a = new long[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					a[i][j] = in.nextLong();
				}
			}

			memo = new long[h][w];
			for (int i = 0; i < h; i++) {
				Arrays.fill(memo[i], -INF);
			}

			long ans = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ans = ans % MOD + dfs(i, j);
				}
			}

			out.println(ans);

		}

		static long dfs(int i, int j) {

			if (memo[i][j] != -INF) {
				return memo[i][j];
			}

			long ret = 1;

			if (i-1 >= 0 && a[i][j] < a[i-1][j]) {
				ret += dfs(i-1, j) % MOD;
			}
			if (i+1 < h && a[i][j] < a[i+1][j]) {
				ret += dfs(i+1, j) % MOD;
			}
			if (j-1 >= 0 && a[i][j] < a[i][j-1]) {
				ret += dfs(i, j-1) % MOD;
			}
			if (j+1 < w && a[i][j] < a[i][j+1]) {
				ret += dfs(i, j+1) % MOD;
			}

			return memo[i][j] = ret % MOD;
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

	static void print(int[][] dp) {
		int n = dp.length;
		int m = dp[0].length;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(dp[i][j] + " ");
			}
			System.out.print("\n");
		}
		System.out.print("\n");
	}

}