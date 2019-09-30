import static java.lang.Math.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
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

			int n = in.nextInt();
			long[] x = new long[n], y = new long[n];
			long[] u = new long[n], v = new long[n];

			for (int i = 0; i < n; i++) {
				x[i] = in.nextLong();
				y[i] = in.nextLong();
				u[i] = x[i] - y[i];
				v[i] = x[i] + y[i];
			}

			long d = 0;
			Arrays.sort(u);
			Arrays.sort(v);
			d = (max(d, u[n-1]-u[0], v[n-1]-v[0]) + 1)/ 2;

			List<P> list = new ArrayList<>();
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					list.add(new P(u[0] + d * (i == 0 ? 1 : -1), v[0] + d * (j == 0 ? 1 : -1)));
					list.add(new P(u[n-1] + d * (i == 0 ? 1 : -1), v[n-1] + d * (j == 0 ? 1 : -1)));
				}
			}

			for (int i = 0; i < list.size(); i++) {
				boolean ok = true;
				long k = -1;
				long px = (  list.get(i).u + list.get(i).v) / 2;
				long py = (- list.get(i).u + list.get(i).v) / 2;

				for (int j = 0; j < n; j++) {
					long dist = abs(x[j] - px) + abs(y[j] - py);
					if (k == -1) {
						k = dist;
					}
					if (k != dist) {
						ok = false;
						break;
					}
				}
				if (ok) {
					out.printf("%d %d\n", px, py);
					return;
				}
			}
		}
	}

	static class P {
		long u, v;

		public P(long u, long v) {
			super();
			this.u = u;
			this.v = v;
		}

		@Override
		public String toString() {
			return "P [u=" + u + ", v=" + v + "]";
		}

	}

	static long max(long... n) {
		long ret = n[0];
		for (int i = 0; i < n.length; i++) {
			ret = Math.max(ret, n[i]);
		}
		return ret;
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

		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
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

		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}