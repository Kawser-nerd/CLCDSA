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
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			char[] s = in.nextString().toCharArray();
			char[] t = in.nextString().toCharArray();
			int[] sumSA = new int[s.length+1];
			int[] sumSB = new int[s.length+1];
			int[] sumTA = new int[t.length+1];
			int[] sumTB = new int[t.length+1];

			for (int i = 0; i < s.length; i++) {
				if (s[i] == 'A') {
					sumSA[i+1] = sumSA[i] + 1;
					sumSB[i+1] = sumSB[i];
				} else {
					sumSB[i+1] = sumSB[i] + 1;
					sumSA[i+1] = sumSA[i];
				}
			}

			for (int i = 0; i < t.length; i++) {
				if (t[i] == 'A') {
					sumTA[i+1] = sumTA[i] + 1;
					sumTB[i+1] = sumTB[i];
				} else {
					sumTB[i+1] = sumTB[i] + 1;
					sumTA[i+1] = sumTA[i];
				}
			}


			int q = in.nextInt();
			for (int i = 0; i < q; i++) {
				int a = in.nextInt();
				int b = in.nextInt();
				int c = in.nextInt();
				int d = in.nextInt();

				long csa = sumSA[b] - sumSA[a-1];
				long csb = sumSB[b] - sumSB[a-1];

				long cta = sumTA[d] - sumTA[c-1];
				long ctb = sumTB[d] - sumTB[c-1];

				if ((csb + csa*2)%3 == (ctb + cta*2)%3) {
					out.println("YES");
				} else {
					out.println("NO");
				}
			}
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