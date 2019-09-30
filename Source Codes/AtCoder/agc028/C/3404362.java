import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
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
			List<P> A = new ArrayList<>();
			List<P> B = new ArrayList<>();
			long asum = 0, bsum = 0;
			for (int i = 0; i < n; i++) {
				long a = in.nextLong();
				long b = in.nextLong();
				A.add(new P(a, i));
				B.add(new P(b, i));
				asum += a;
				bsum += b;
			}

			long ans = min(asum, bsum);

			List<P> list = new ArrayList<>();
			list.addAll(A);
			list.addAll(B);
			Collections.sort(list);

			long tmp1 = 0;
			boolean ok1 = false;
			int[] count = new int[n];
			for (int i = 0; i < n; i++) {
				tmp1 += list.get(i).c;
				if (++count[list.get(i).num] >= 2) ok1 = true;
			}
			if (!ok1) tmp1 = LINF;


			long tmp2 = 0;
			boolean ok2 = false;
			count = new int[n];
			for (int i = 0; i < n-1; i++) {
				tmp2 += list.get(i).c;
				if (++count[list.get(i).num] >= 2) ok2 = true;
			}
			tmp2 += list.get(n).c;
			if (++count[list.get(n).num] >= 2) ok2 = true;
			if (!ok2) tmp2 = LINF;

			long tmp3 = 0;
			boolean ok3 = false;
			count = new int[n];
			for (int i = 0; i < n-1; i++) {
				tmp3 += list.get(i).c;
				if (++count[list.get(i).num] >= 2) ok3 = true;
			}
			tmp3 += list.get(n+1).c;
			if (++count[list.get(n+1).num] >= 2) ok3 = true;
			if (!ok3) tmp3 = LINF;


			long tmp4 = 0;
			boolean ok4 = false;
			count = new int[n];
			for (int i = 0; i < n-2; i++) {
				tmp4 += list.get(i).c;
				if (++count[list.get(i).num] >= 2) ok4 = true;
			}
			tmp4 += list.get(n-1).c;
			tmp4 += list.get(n).c;
			if (++count[list.get(n-1).num] >= 2) ok4 = true;
			if (++count[list.get(n).num] >= 2) ok4 = true;

			if (!ok4) tmp4 = LINF;

			ans = min(ans, tmp1, tmp2, tmp3, tmp4);
			out.println(ans);

		}

	}

	static long min(long... n) {
		long ret = n[0];
		for (int i = 0; i < n.length; i++) {
			ret = Math.min(ret, n[i]);
		}
		return ret;
	}

	static class P implements Comparable<P> {
		long c;
		int num;

		public P(long c, int num) {
			super();
			this.c = c;
			this.num = num;
		}

		@Override
		public int compareTo(P o) {
			return Long.compare(this.c, o.c);
		}

		@Override
		public String toString() {
			return "P [c=" + c + ", num=" + num + "]";
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