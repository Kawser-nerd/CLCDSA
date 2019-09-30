import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[] a = in.nextIntArray(n);
			int[] b = in.nextIntArray(n);

			boolean same = true;
			for (int i = 0; i < n; i++) {
				if (a[i] != b[i]) {
					same = false;
					break;
				}
			}
			if (same) {
				out.println(0);
				return;
			}

			for (int i = 0; i < n; i++) {
				if (b[i] != 0) {
					same = false;
				}
			}
			if (same) {
				out.println(2);
				return;
			}

			Set<Integer> set = new HashSet<>();
			for (int i = 1; i <= 50; i++) {
				set.add(i);
			}

			long ans = 0;
			for (int k = 50; k >= 1; k--) {

				// ???????
				long[][] g = new long[51][51];
				for (int l = 0; l < 51; l++) {
					for (int m = 0; m < 51; m++) {
						if (l == m) {
							g[l][m] = 0;
						} else {
							g[l][m] = INF;
						}
					}
				}

				// k??????
				boolean need = false;
				set.remove((Integer)k);

				// ??????????
				for (int i : set) {
					for (int j = 0; j < 51; j++) {
						g[j][j%i] = 1;
					}
				}

				// ??????????
				for (int K = 0; K < 51; K++) {
					for (int I = 0; I < 51; I++) {
						for (int J = 0; J < 51; J++) {
							g[I][J] = Math.min(g[I][J], g[I][K]+g[K][J]);
						}
					}
				}

				// a[i] -> b[i] ????????????
				for (int i = 0; i < n; i++) {
					if (g[a[i]][b[i]] == INF) {
						need = true;
						break;
					}
				}
				if (need) {
					ans += (long)1 << k;
					set.add(k);
				}
			}

			out.println(set.size() == 50 ? -1 : ans);

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