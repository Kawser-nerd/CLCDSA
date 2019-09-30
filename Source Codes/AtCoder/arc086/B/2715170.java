import static java.lang.Math.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		long[] a;
		int n;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			n = in.nextInt();
			a = new long[n];
			long min = INF;
			long max = -INF;
			int min_idx = -1;
			int max_idx = -1;

			for (int i = 0; i < n; i++) {
				long ai = in.nextLong();
				if (ai < min) {
					min = ai;
					min_idx = i;
				}
				if (max < ai) {
					max = ai;
					max_idx = i;
				}
				a[i] = ai;
			}

			if (isAllZero()) {
				out.println(0);
				return;
			}

			boolean pos = false;
			boolean neg = false;

			List<Integer> from = new ArrayList<>();
			List<Integer> to = new ArrayList<>();

			if (max * min <= 0) {
				if (abs(min) <= abs(max)) {
					pos = true;
					for (int i = 0; i < n; i++) {
						from.add(max_idx);
						to.add(i);
//						out.printf("%d %d\n", max_idx, i);
					}
				} else {
					neg = true;
					for (int i = 0; i < n; i++) {
						from.add(min_idx);
						to.add(i);
//						out.printf("%d %d\n", min_idx, i);
					}
				}
			} else {
				if (0 < min) {
					pos = true;
				} else if (max < 0) {
					neg = true;
				}
			}

			if (pos) {
				for (int i = 1; i < n; i++) {
//					out.printf("%d %d\n", i-1, i);
					from.add(i-1);
					to.add(i);
				}
			}

			if (neg) {
				for (int i = n-2; i >= 0; i--) {
//					out.printf("%d %d\n", i+1, i);
					from.add(i+1);
					to.add(i);
				}
			}

			out.println(from.size());
			for (int i = 0; i < from.size(); i++) {
				out.printf("%d %d\n", from.get(i)+1, to.get(i)+1);
			}
		}

		boolean isAllZero() {
			boolean same = true;
			for (long i : a) {
				if (i != 0) {
					same = false;
					break;
				}
			}
			return same;
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