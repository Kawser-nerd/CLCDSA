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

			long[][] d = new long[n][n];
			long[][] input = new long[n][n];

			for (int from = 0; from < n; from++) {
				for (int to = 0; to < n; to++) {
					long a = in.nextLong();
					d[from][to] = a;
					input[from][to] = a;
				}
			}

			warshallFloyd(d);

			for (int from = 0; from < n; from++) {
				for (int to = 0; to < n; to++) {
					if (d[from][to] != input[from][to]) {
						out.println(-1);
						return;
					}
				}
			}

			long cost = 0;
			for (int from = 0; from < n; from++) {
				for (int to = from + 1; to < n; to++) {
					for (int middle = 0; middle < n; middle++) {
						if (middle == from || middle == to) {
							continue;
						}
						if (d[from][middle] + d[middle][to] == d[from][to]) {
							input[from][to] = -1;
						}
					}
				}
			}

			for (int from = 0; from < n; from++) {
				for (int to = from + 1; to < n; to++) {
					if (input[from][to] != -1) {
						cost += input[from][to];
					}
				}
			}
			out.println(cost);
		}

	}

	static void warshallFloyd(long[][] d) {
		int INF = Integer.MAX_VALUE;
		int len = d.length;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (d[j][i] == INF) continue;
				for (int k = 0; k < len; k++) {
					if (d[i][k] == INF) continue;
					d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
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