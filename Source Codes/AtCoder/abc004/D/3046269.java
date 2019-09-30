import static java.lang.Math.*;

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

		int p = 1000;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int R = in.nextInt(), G = in.nextInt(), B = in.nextInt();

			long ans = INF;

			for (int i = -150; i <= 150; i++) {
				ans = min(ans, calc(i, R, G, B));
			}

			out.println(ans);

		}

		long calc(int pos, int R, int G, int B) {

			char[] s = new char[2000];
			Arrays.fill(s, 'x');

			int l = pos+p;
			int r = pos+p;
			while (G > 0) {
				if (s[l] == 'x') {
					s[l] = 'G';
					G--;
				}
				l--;

				if (G <= 0) break;

				if (s[r] == 'x') {
					s[r] = 'G';
					G--;
				}
				++r;
			}

			l = -100+p;
			r = -100+p;
			while (R > 0) {
				if (s[l] == 'x') {
					s[l] = 'R';
					R--;
				}
				l--;

				if (R <= 0) break;

				if (s[r] == 'G') continue;
				if (s[r] == 'x') {
					s[r] = 'R';
					R--;
				}
				++r;
			}

			l = 100+p;
			r = 100+p;
			while (B > 0) {
				if (s[r] == 'x') {
					s[r] = 'B';
					B--;
				}
				++r;

				if (B <= 0) break;

				if (s[l] == 'G') continue;
				if (s[l] == 'x') {
					s[l] = 'B';
					B--;
				}
				l--;
			}

			long ans = 0;
			int gr = -100 + p;
			int gg = 0 + p;
			int gb = 100 + p;

			int Rl = INF, Rr = -INF, Gl = INF, Gr = -INF, Bl = INF, Br = -INF;
			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'R') {
					Rl = min(Rl, i);
					Rr = max(Rr, i);
				}

				if (s[i] == 'G') {
					Gl = min(Gl, i);
					Gr = max(Gr, i);
				}

				if (s[i] == 'B') {
					Bl = min(Bl, i);
					Br = max(Br, i);
				}
			}

			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'R') {
					ans += abs(i - gr);
				}

				if (s[i] == 'G') {
					ans += abs(i - gg);
				}

				if (s[i] == 'B') {
					ans += abs(i - gb);
				}
			}
			return ans;
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