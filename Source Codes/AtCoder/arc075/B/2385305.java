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
	static int modP = 1000000007;

	static int n;
	static long a, b;
	static long[] h;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {


			n = in.nextInt();
			a = in.nextLong();
			b = in.nextLong();
			h = in.nextLongArray(n);

			int l = 0, r = 1000000009;
			while (r - l > 1) {
				int m = l + (r - l) / 2;

				if (can(m)) {
					r = m;
				} else {
					l = m;
				}
			}
			out.println(r);

		}
	}
	static boolean can(int k) {
		long d = a - b;
		long need = 0;
		for (int i = 0; i < n; i++) {
			long x = h[i];
			x -= k * b;
			if (x <= 0) {
				continue;
			}
			need += (x + d - 1) / d;
		}
		return need <= k;
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