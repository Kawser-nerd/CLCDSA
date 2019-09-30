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

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			char[][] s = new char[n][n];

			for (int i = 0; i < n; i++) {
				s[i] = in.nextString().toCharArray();
			}

			long ans = 0;
			for (int b = 0; b < n; b++) {
				char[][] t = new char[n][n];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						t[i][j] = s[i][(j+b)%n];
					}
				}

				if (isEqual(t)) {
					ans++;
				}
			}

			out.println(ans*n);

		}
	}

	static boolean isEqual(char[][] s) {

		boolean isEqual = true;
		for (int i = 0; i < s.length; i++) {
			for (int j = 0; j < s.length; j++) {
				if (i == j) {
					continue;
				}
				if (s[i][j] == s[j][i]) {
					continue;
				} else {
					isEqual = false;
				}
			}
		}

		return isEqual;
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