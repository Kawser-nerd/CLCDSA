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

		int[][] ans;
		int[][] s;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			s = new int[n][m];
			for (int i = 0; i < n; i++) {
				char[] tmp = in.nextString().toCharArray();
				for (int j = 0; j < tmp.length; j++) {
					s[i][j] = tmp[j] - '0';
				}
			}

			ans = new int[n][m];

			calc(0, 0, n-1, m-1);

			for (int i = 0; i < n; i++) {
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < m; j++) {
					sb.append(ans[i][j]);
				}
				out.println(sb.toString());
			}

		}

		void calc(int sh, int sw, int gh, int gw) {

			if (sh == gh || sw == gw || gh - sh == 1 || gw - sw == 1) {
				return;
			}

			// ?
			for (int i = sw; i <= gw; i++) {
				if (s[sh][i] > 0) {
					ans[sh+1][i] += s[sh][i];
					s[sh+2][i] -= s[sh][i];
					s[sh+1][i-1] -= s[sh][i];
					s[sh+1][i+1] -= s[sh][i];
				}
			}

			// ?
			for (int i = sh; i <= gh; i++) {
				if (s[i][gw] > 0) {
					ans[i][gw-1] += s[i][gw];
					s[i+1][gw-1] -= s[i][gw];
					s[i-1][gw-1] -= s[i][gw];
					s[i][gw-2] -= s[i][gw];
				}
			}

			// ?
			for (int i = sw; i <= gw; i++) {
				if (s[gh][i] > 0) {
					ans[gh-1][i] += s[gh][i];
					s[gh-2][i] -= s[gh][i];
					s[gh-1][i-1] -= s[gh][i];
					s[gh-1][i+1] -= s[gh][i];
				}
			}

			// ?
			for (int i = sh; i <= gh; i++) {
				if (s[i][sw] > 0) {
					ans[i][sw+1] += s[i][sw];
					s[i+1][sw+1] -= s[i][sw];
					s[i-1][sw+1] -= s[i][sw];
					s[i][sw+2] -= s[i][sw];
				}
			}

			calc(sh+1, sw+1, gh-1, gw-1);
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