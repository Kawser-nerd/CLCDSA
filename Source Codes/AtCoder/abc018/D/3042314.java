import static java.lang.Math.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
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

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int N = in.ni(), M = in.ni(), P = in.ni(), Q = in.ni(), R = in.ni();

			T[] tt = new T[R];
			for (int i = 0; i < R; i++) {
				int x = in.ni()-1, y = in.ni()-1, z = in.ni();
				tt[i] = new T(x, y, z);
			}

			long ans = 0;
			for (int i = 0; i < 1 << N; i++) {
				if (Integer.bitCount(i) != P) continue;
				long tmp = 0;

				Integer[] v = new Integer[M];
				for (int j = 0; j < v.length; j++) {
					v[j] = new Integer(0);
				}

				for (int j = 0; j < N; j++) {
					if (((i >> j) & 1) == 1) {
						for (T t : tt) {
							if (t.x == j) {
								v[t.y] += t.z;
							}
						}
					}
				}

				Arrays.sort(v, Comparator.reverseOrder());

				for (int j = 0; j < min(Q, v.length); j++) {
					tmp += v[j];
				}

				ans = Math.max(ans, tmp);
			}

			out.println(ans);
		}

		class T {
			int x, y, z;

			public T(int x, int y, int z) {
				super();
				this.x = x;
				this.y = y;
				this.z = z;
			}

			@Override
			public String toString(){
				return x + ":" + y + ":" + z;
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

		public int ni() {
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
				res[i] = ni();
			}
			return res;
		}

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = ni() - 1;
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