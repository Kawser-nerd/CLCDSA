import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
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
	static int[] mh9 = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };
	static int[] mw9 = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			long h = in.nextLong(), w = in.nextLong();
			int n = in.nextInt();
			Map<P, Integer> map = new HashMap<>();
			long[] a = new long[n], b = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextLong();
				b[i] = in.nextLong();
				for (int j = 0; j < 9; j++) {
					if (1 < a[i] + mh9[j] && a[i] + mh9[j] < h && 1 < b[i] + mw9[j] && b[i] + mw9[j] < w) {
						map.merge(new P(a[i] + mh9[j], b[i] + mw9[j]), 1, Integer::sum);
					}
				}
			}

			long[] ans = new long[10];
			ans[0] = (h-2) * (w-2) - map.size();
			for (P p : map.keySet()) {
				int cnt = map.get(p);
				ans[cnt]++;
			}

			for (long i : ans) {
				out.println(i);
			}
		}
	}

	static class P {
		long first, second;

		public P(long first, long second) {
			super();
			this.first = first;
			this.second = second;
		}

		@Override
		public String toString() {
			return "P [first=" + first + ", second=" + second + "]";
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (first ^ (first >>> 32));
			result = prime * result + (int) (second ^ (second >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			P other = (P) obj;
			if (first != other.first)
				return false;
			if (second != other.second)
				return false;
			return true;
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