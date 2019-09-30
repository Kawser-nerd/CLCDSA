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

	static int INF = 1 << 26;
	static int MOD = 998244353;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {
		int maxN = 100010;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), c = in.nextInt();
			long[][] imos = new long[c][2*maxN];
			for (int i = 0; i < n; i++) {
				int s = in.nextInt()*2, t = in.nextInt()*2, ci = in.nextInt()-1;
				imos[ci][s-1]++;
				imos[ci][t+1]--;
			}

			for (int i = 0; i < c; i++) {
				for (int j = 0; j < 2*maxN-1; j++) {
					imos[i][j+1] += imos[i][j];
				}
			}

			int ans = 0;
			for (int i = 0; i < 2*maxN; i++) {
				int tmp = 0;
				for (int j = 0; j < c; j++) {
					if (imos[j][i] > 0) tmp++;
				}
				ans = Math.max(ans, tmp);
			}

			out.println(ans);

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