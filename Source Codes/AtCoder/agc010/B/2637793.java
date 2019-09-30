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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			long[] a = new long[n];
			long[] sa = new long[n];
			long sum = 0;
			for (int i = 0; i < n; i++) {
				long t = in.nextLong();
				a[i] = t;
				sum += t;
			}

			long m = 0;
			if (sum % ((long)n*(n+1)/2) == 0) {
				m = sum / ((long)n*(n+1)/2);
			} else {
				out.println("NO");
				return;
			}

			for (int i = 0; i < n; i++) {
				sa[i] = a[(i+1)%n] - a[i];
			}

			for (int i = 0; i < n; i++) {
				sa[i] -= m;
			}

			long k = 0;
			for (int i = 0; i < n; i++) {
				if (sa[i] <= 0 && sa[i] % n == 0) {
					k -= sa[i] / n;
				} else {
					out.println("NO");
					return;
				}
			}

			out.println(k == m ? "YES" : "NO");
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