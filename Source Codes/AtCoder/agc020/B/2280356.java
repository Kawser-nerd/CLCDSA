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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int k = in.nextInt();
			long[] an = in.nextLongArray(k);

			long min = 0;
			long max = 100000000000000000L;

			long left = 0, right = max;
			long mid = (left + right) / 2;

			long v = 0;
			while (left < right) {
				v = g(mid, an);
				if (v >= 2) {
					right = mid;
				} else {
					left = mid + 1;
				}
				mid = (left + right) / 2;
			}
			if (g(mid, an) != 2) {
				out.println(-1);
				return;
			}
			min = mid;

			left = 0;
			right = max;
			mid = (left + right) / 2;

			while (left < right) {
				v = g(mid, an);
				if (v <= 2) {
					left = mid;
				} else {
					right = mid - 1;
				}
				mid = (left + right) / 2;
				if (right == (left + 1)){
					mid++;
				}
			}
			if (g(mid, an) != 2) {
				out.println(-1);
				return;
			}
			max = mid;

			out.println(min + " " + max);


		}

		static long g(long x, long[] an) {
			for (int i = 0; i < an.length; i++) {
				x = f(x, an[i]);
			}
			return x;
		}

		static long f(long x, long p) {
			return x - x % p;
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