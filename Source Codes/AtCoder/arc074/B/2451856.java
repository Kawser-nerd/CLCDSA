import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
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
			long[] left = in.nextLongArray(n);
			long[] center = in.nextLongArray(n);
			long[] right = in.nextLongArray(n);

			PriorityQueue<Long> f = new PriorityQueue<>((e1, e2) -> {return e1.compareTo(e2);});
			PriorityQueue<Long> b = new PriorityQueue<>((e1, e2) -> {return -e1.compareTo(e2);});

			for (int i = 0; i < n; i++) {
				f.add(left[i]);
			}

			for (int i = 0; i < n; i++) {
				b.add(right[i]);
			}

			long[] sumL = new long[n+1];
			long[] sumR = new long[n+1];

			sumL[0] = f.stream().mapToLong(i -> i).sum();
			sumR[0] = b.stream().mapToLong(i -> i).sum();

			for (int k = 0; k < n; k++) {
				f.add(center[k]);
				sumL[k+1] = sumL[k] - f.remove() + center[k];
			}

			for (int k = 0; k < n; k++) {
				b.add(center[n-1-k]);
				sumR[k+1] = sumR[k] - b.remove() + center[n-1-k];
			}

			long ans = Long.MIN_VALUE;
			for (int i = 0; i < n+1; i++) {
				ans = Math.max(ans, sumL[i]-sumR[n-i]);
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