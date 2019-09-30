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
	static int modP = 1000000007;

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[] tn = in.nextIntArray(n);
			int[] vn = in.nextIntArray(n);
			int T = 0;
			for (int i = 0;i < n; i++) T += tn[i];

			int m = 2 * T + 1;

			double[] maxV = new double[m];
//			int prt = 1;
//			for (int i = 0; i < n; i++) {
//				for (int k = 0 ; k < 2 * tn[i]; k++, prt++) {
//					maxV[prt] = vn[i];
//				}
//			}
			Arrays.fill(maxV, Double.MAX_VALUE);
			maxV[0] = maxV[m - 1] = 0;

			int tmpSum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= 2 * tn[i]; j++) {
					maxV[tmpSum + j] = Math.min(maxV[tmpSum + j], vn[i]);
				}
				tmpSum += 2 * tn[i];
			}

			maxV[0] = 0;
			for (int i = 0; i < m - 1; i++) {
				maxV[i+1] = Math.min(maxV[i] + 0.5, maxV[i+1]);
			}

			maxV[m - 1] = 0;
			for (int i = m - 1; i > 0; i--) {
				maxV[i-1] = Math.min(maxV[i] + 0.5, maxV[i-1]);
			}

			double sum = 0;
			for (int i = 0; i < m - 1; i++) {
				sum += (maxV[i+1] + maxV[i]) * 0.5 / 2;
			}
			out.println(String.format("%.12f", sum));

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