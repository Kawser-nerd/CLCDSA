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
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int h = in.nextInt(), w = in.nextInt();
			char[][] s = new char[h][w];
			char[][] ans = new char[h][w];
			for (int i = 0; i < h; i++) {
				Arrays.fill(ans[i], '.');
			}
			for (int i = 0; i < h; i++) {
				s[i] = in.nextString().toCharArray();
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == '.') {
						continue;
					}
					boolean can = true;
					for (int k = 0; k < 8; k++) {
						int nh = i + mh8[k];
						int nw = j + mw8[k];
						if (nh < 0 || nw < 0 || nh >= h || nw >= w) {
							continue;
						}
						if (s[nh][nw] == '#') {
							continue;
						} else {
							can = false;
						}
					}

					if (can) {
						ans[i][j] = '#';
					}
				}
			}

			char[][] tmp = new char[h][w];
			for (int i = 0; i < h; i++) {
				Arrays.fill(tmp[i], '.');
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (ans[i][j] == '#') {
						tmp[i][j] = '#';
						for (int k = 0; k < 8; k++) {
							int nh = i + mh8[k];
							int nw = j + mw8[k];
							if (nh < 0 || nw < 0 || nh >= h || nw >= w) {
								continue;
							}
							tmp[nh][nw] = '#';
						}
					}
				}
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == tmp[i][j]) {
						continue;
					} else {
						out.println("impossible");
						return;
					}
				}
			}

			out.println("possible");
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					out.print(ans[i][j]);
				}
				out.print("\n");
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