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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int k = in.nextInt();
			long[] an = new long[n+1];
			for (int i = 1; i < n + 1; i++) {
				an[i] = in.nextLong();
			}

			long[] rui = new long[n+1];
			if (an[1] > 0) {
				rui[1] = an[1];
			}
			for (int i = 2; i < n + 1; i++) {
				if (an[i] > 0) {
					rui[i] += rui[i-1]+an[i];
				} else {
					rui[i] += rui[i-1];
				}
			}

			long ans = 0;
			for (int i = 1; i <= n + 1 - k; i++) {
				long tmp = 0;
				tmp += rui[i-1] - rui[0];
				tmp += rui[n] - rui[i+k-1];

				long inside = 0;
				for (int j = i; j < i + k; j++) {
					inside += an[j];
				}
				if (inside > 0) {
					tmp += inside;
				}
				ans = Math.max(ans, tmp);
			}
			out.println(ans);

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