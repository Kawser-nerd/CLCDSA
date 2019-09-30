import static java.lang.Math.*;

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


			int n = in.nextInt();
			double d = in.nextDouble();
			double x = in.nextDouble(), y = in.nextDouble();

			double xlc = 0, xrc = 0, ylc = 0, yrc = 0;

			// input & validation
			if (x % d == 0) {
				if (x < 0) {
					xlc = abs(x/d);
				} else {
					xrc = abs(x/d);
				}
			} else {
				out.println(0.0);
				return;
			}
			if (y % d == 0) {
				if (y < 0) {
					ylc = abs(y/d);
				} else {
					yrc = abs(y/d);
				}
			} else {
				out.println(0.0);
				return;
			}

			if (xlc > n || xrc > n || ylc > n || yrc > n) {
				out.println(0.0);
				return;
			}

			// MainProcess
			double count = n - (xlc + xrc + ylc + yrc);

			if (count % 2 == 1) {
				out.println(0.0);
				return;
			}
			int rev = (int)count/2;

			double ans = 0.0;

			for (int i = 0; i <= rev; i++) {

				double t_xlc = xlc;
				double t_xrc = xrc;
				double t_ylc = ylc;
				double t_yrc = yrc;

				for (int j = 0; j < i; j++) {
					t_xlc++; t_xrc++;
				}
				for (int k = rev-i-1; k >= 0; k--) {
					t_ylc++; t_yrc++;
				}

				double tmp = 1.0;
				long N = 1;
				for (int l = 1; l <= t_xlc; l++, N++) {
					tmp *= N;
					tmp /= l;
					tmp /= 4.0;
				}

				for (int l = 1; l <= t_xrc; l++, N++) {
					tmp *= N;
					tmp /= l;
					tmp /= 4.0;
				}

				for (int l = 1; l <= t_ylc; l++, N++) {
					tmp *= N;
					tmp /= l;
					tmp /= 4.0;
				}

				for (int l = 1; l <= t_yrc; l++, N++) {
					tmp *= N;
					tmp /= l;
					tmp /= 4.0;
				}

				ans += tmp;
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