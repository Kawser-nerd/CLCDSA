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

			int r = in.nextInt(), c = in.nextInt(), k = in.nextInt();
			char[][] s = new char[r][c];
			for (int i = 0; i < r; i++) {
				s[i] = in.nextString().toCharArray();
			}

			int[][] up = new int[r][c];
			int[][] down = new int[r][c];

			for (int j = 0; j < c; j++) {
				for (int i = 0; i < r; i++) {
					int uc = 0;
					int ti = i;
					while (0 <= ti) {
						if (s[ti][j] == 'o') {
							uc++;
						} else {
							break;
						}
						ti--;
					}
					up[i][j] = uc;
				}
			}

			for (int j = 0; j < c; j++) {
				for (int i = 0; i < r; i++) {
					int uc = 0;
					int ti = i;
					while (ti < r) {
						if (s[ti][j] == 'o') {
							uc++;
						} else {
							break;
						}
						ti++;
					}
					down[i][j] = uc;
				}
			}

			long ans = 0;
			for (int i = k-1; i <= r-(k-1)-1; i++) {
				for (int j = k-1; j <= c-(k-1)-1; j++) {
					boolean ok = true;
					for (int mj = 0; mj < k; mj++) {
						if (up[i][j-mj] >= k-mj && down[i][j-mj] >= k-mj && up[i][j+mj] >= k-mj && down[i][j+mj] >= k-mj) {
							continue;
						} else {
							ok = false;
						}
					}
					if (ok) ans++;
				}
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