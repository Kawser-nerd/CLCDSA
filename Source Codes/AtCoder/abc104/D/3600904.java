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
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			char[] s = in.nextString().toCharArray();
			int n = s.length;
			long[] a = new long[n], c = new long[n], q = new long[n];
			for (int i = 0; i < n; i++) {
				if (s[i] == 'A') a[i] += 1;
				if (s[i] == 'C') c[i] += 1;
				if (s[i] == '?') q[i] += 1;
			}
			for (int i = 1; i < n; i++) {
				a[i] += a[i-1];
				c[i] += c[i-1];
				q[i] += q[i-1];
			}

			long ans = 0;
			for (int i = 1; i < n-1; i++) {
				if (s[i] == 'B') {
					ans += a[i-1] * (c[n-1] - c[i]) * power(3, q[n-1], MOD);
					ans %= MOD;
					if (q[n-1] - q[i] > 0) {
						ans += a[i-1] * (q[n-1] - q[i]) * power(3, q[n-1]-1, MOD);
						ans %= MOD;
					}
					if (q[i] > 0) {
						ans += q[i-1] * (c[n-1] - c[i]) * power(3, q[n-1]-1, MOD);
						ans %= MOD;
					}
					if (q[n-1] - q[i] > 0 && q[i] > 0) {
						ans += q[i-1] * (q[n-1] - q[i]) * power(3, q[n-1]-2, MOD);
						ans %= MOD;
					}
				} else if (s[i] == '?') {
					if (q[n-1] > 0) {
						ans += a[i-1] * (c[n-1] - c[i]) * power(3, q[n-1]-1, MOD);
						ans %= MOD;
					}
					if (q[n-1] - q[i] > 0 && q[n-1] > 1) {
						ans += a[i-1] * (q[n-1] - q[i]) * power(3, q[n-1]-2, MOD);
						ans %= MOD;
					}
					if (q[i-1] > 0 && q[n-1] > 1) {
						ans += q[i-1] * (c[n-1] - c[i]) * power(3, q[n-1]-2, MOD);
						ans %= MOD;
					}
					if (q[n-1] - q[i-1] > 0 && q[i] > 0 && q[n-1] > 2) {
						ans += q[i-1] * (q[n-1] - q[i]) * power(3, q[n-1]-3, MOD);
						ans %= MOD;
					}
				}
			}

			out.println(ans);
		}
	}

	static long power(long a, long e, long modP) {
		long ret = 1;
		for (; e > 0; e /= 2) {
			if (e % 2 != 0) {
				ret = (ret * a) % modP;
			}
			a = (a * a) % modP;
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