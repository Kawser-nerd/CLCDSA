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

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			char[] s1 = in.nextString().toCharArray();
			char[] s2 = in.nextString().toCharArray();


			List<Integer> tmp = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (s1[i] == s2[i]) {
					tmp.add(1);
				} else {
					tmp.add(2);
					i++;
				}
			}
			Integer[] a = tmp.toArray(new Integer[0]);
			int len = a.length;

			long ans = a[0] == 1 ? 3 : 6;
			for (int i = 1; i < len; i++) {
				if (a[i-1] == 1 && a[i] == 1) {
					ans *= 2;
					ans %= MOD;
				} else if (a[i-1] == 1 && a[i] == 2) {
					ans *= 2;
					ans %= MOD;
				} else if (a[i-1] == 2 && a[i] == 1) {
					ans *= 1;
					ans %= MOD;
				} else if (a[i-1] == 2 && a[i] == 2) {
					ans *= 3;
					ans %= MOD;
				}
			}
			out.println(ans % MOD);

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