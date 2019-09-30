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

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			P[] p = new P[n];
			for (int i = 0; i < n; i++) {
				int r = in.nextInt();
				int h = in.nextInt();
				p[i] = new P(r, h);
			}

			P[] ps = p.clone();
			Arrays.sort(ps);
			int[] rr = new int[n];
			int[] hh = new int[n];
			for (int i = 0; i < n; i++) {
				rr[i] = ps[i].r;
			}
			for (int i = 0; i < n; i++) {
				hh[i] = ps[i].h;
			}

			for (int i = 0; i < n; i++) {
				int win = lowerBound(rr, p[i].r);
				int draw = 0;
				int lose = n - upperBound(rr, p[i].r);

				int from = lowerBound(rr, p[i].r);
				int to = upperBound(rr, p[i].r);


				int gu = upperBound(hh, 1, from, to) - lowerBound(hh, 1, from, to);
				int ch = upperBound(hh, 2, from, to) - lowerBound(hh, 2, from, to);
				int pa = upperBound(hh, 3, from, to) - lowerBound(hh, 3, from, to);

				if (p[i].h == 1) {
					win += ch;
					lose += pa;
					draw += gu-1;
				} else if (p[i].h == 2) {
					win += pa;
					lose += gu;
					draw += ch-1;
				} else if (p[i].h == 3) {
					win += gu;
					lose += ch;
					draw += pa-1;
				}
				out.printf("%d %d %d\n", win, lose, draw);
			}
		}
	}

	public static int upperBound(int[] a, int obj) {
		int l = 0, r = a.length - 1;
		while (r - l >= 0) {
			int c = (l + r) / 2;
			if (a[c] <= obj) {
				l = c + 1;
			} else {
				r = c - 1;
			}
		}
		return l;
	}

	public static int upperBound(int[] a, int obj, int from, int to) {
		int l = from, r = to - 1;
		while (r - l >= 0) {
			int c = (l + r) / 2;
			if (a[c] <= obj) {
				l = c + 1;
			} else {
				r = c - 1;
			}
		}
		return l;
	}

	public static int lowerBound(int[] a, int obj) {
		int l = 0, r = a.length - 1;
		while (r - l >= 0) {
			int c = (l + r) / 2;
			if (obj <= a[c]) {
				r = c - 1;
			} else {
				l = c + 1;
			}
		}
		return l;
	}

	public static int lowerBound(int[] a, int obj, int from, int to) {
		int l = from, r = to - 1;
		while (r - l >= 0) {
			int c = (l + r) / 2;
			if (obj <= a[c]) {
				r = c - 1;
			} else {
				l = c + 1;
			}
		}
		return l;
	}

	static class P implements Comparable<P> {
		int r, h;

		public P(int r, int h) {
			super();
			this.r = r;
			this.h = h;
		}

		@Override
		public int compareTo(P o) {
			return Integer.compare(this.r, o.r) != 0 ? Integer.compare(this.r, o.r) : Integer.compare(this.h, o.h);
		}

		@Override
		public String toString() {
			return "P [r=" + r + ", h=" + h + "]";
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