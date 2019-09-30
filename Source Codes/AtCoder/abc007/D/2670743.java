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

	static class TaskX {

		long[][] memo;
		char[] sa;
		char[] sb;

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			long a = in.nextLong(), b = in.nextLong();
			sa = String.valueOf(a-1).toCharArray();
			sb = String.valueOf(b).toCharArray();

			out.println(b-a+1-dfs(0, 1, sb, true)+dfs(0, 1, sa, true));

		}

		long dfs(int i, int tight, char[] s, boolean isFirst) {
			if (isFirst) {
				memo = new long[20][2];
				for (int j = 0; j < 20; j++) {
					Arrays.fill(memo[j], -1);
				}
			}
			if (memo[i][tight] >= 0) {
				return memo[i][tight];
			}
			if (i == s.length) return 1;

			long ret = 0;
			int d = s[i]-'0';
			for (int e = 0; e <= (tight == 1 ? d : 9); e++) {
				if (e == 4 || e == 9) continue;
				ret += dfs(i+1, tight == 1 && d == e ? 1 : 0, s, false);
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