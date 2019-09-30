import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
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

		int x, y, z;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			x = in.nextInt(); y = in.nextInt(); z = in.nextInt();
			int u = x + y + z;

			P[] p = new P[u];
			long csum = 0;
			for (int i = 0; i < u; i++) {
				long a = in.nextLong();
				long b = in.nextLong();
				long c = in.nextLong();
				p[i] = new P(a - c, b - c);
				csum += c;
			}

			Arrays.sort(p);

			long[] dp_y = f(p, u);
			long[] dp_x = g(p, u);

			long ans = 0;
			for (int k = 0; k < u-1; k++) {
				ans = Math.max(ans, dp_y[k] + dp_x[k+1] + csum);
			}

			out.println(ans);
		}

		long[] f(P[] p, int u) {
			long[] res = new long[u];
			Arrays.fill(res, -LINF);
			long sum = 0;

			PriorityQueue<Long> q = new PriorityQueue<Long>();
			for (int i = 0; i < u; i++) {
				q.add(p[i].y);
				sum += p[i].y;
				if (y < q.size()) {
					long l = q.remove();
					sum -= l;
				}
				if (q.size() == y) res[i] = sum;
			}
			return res;
		}

		long[] g(P[] p, int u) {
			long[] res = new long[u];
			Arrays.fill(res, -LINF);
			long sum = 0;

			PriorityQueue<Long> q = new PriorityQueue<Long>();
			for (int i = u-1; i >= 0; i--) {
				q.add(p[i].x);
				sum += p[i].x;
				if (x < q.size()) {
					long l = q.remove();
					sum -= l;
				}
				if (q.size() == x) res[i] = sum;
			}
			return res;
		}

	}

	static class P implements Comparable<P> {
		long x, y;

		public P(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(P o) {
			return -Long.compare(o.x- o.y, this.x - this.y);
		}

		@Override
		public String toString() {
			return "P [x=" + x + ", y=" + y + "]";
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