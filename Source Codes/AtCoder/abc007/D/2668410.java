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

		long a, b;
		long[][] memo;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			a = in.nextLong();
			b = in.nextLong();
			char[] sa = String.valueOf(a-1).toCharArray();
			char[] sb = String.valueOf(b).toCharArray();

			memo = new long[sa.length+1][2];
			long san = dfs(0, 1, sa);

			memo = new long[sb.length+1][2];
			long sbn = dfs(0, 1, sb);

			out.println((b-a+1) - (sbn-san));
		}

		long dfs(int i, int tight, char[] s) {
			if (memo[i][tight] > 0) {
				return memo[i][tight];
			}
			if (i == s.length) return 1;

			long ret = 0;
			int d = s[i] - '0';
			for (int e = 0; e <= (tight == 1 ? d : 9); e++) {
				if (e == 4 || e == 9) continue;
				ret += dfs(i+1, (tight == 1 && d == e ? 1 : 0), s);
			}

			return memo[i][tight] = ret;
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