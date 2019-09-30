import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.stream.Stream;

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
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		@SuppressWarnings("unchecked")
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), k = in.nextInt();
			List<Integer>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);

			int[] a = new int[n], b = new int[n];
			for (int i = 0; i < n-1; i++) {
				a[i] = in.nextInt()-1;
				b[i] = in.nextInt()-1;
				g[a[i]].add(b[i]);
				g[b[i]].add(a[i]);
			}

			int count = INF;
			if (k % 2 == 0) {

				for (int i = 0; i < n; i++) {
					Queue<Integer> q = new ArrayDeque<>();
					boolean[] used = new boolean[n];
					int[] cost = new int[n];
					Arrays.fill(cost, INF);

					q.add(i);
					used[i] = true;
					cost[i] = 0;

					int tmp = 0;
					while (!q.isEmpty()) {
						int now = q.remove();

						for (int to : g[now]) {
							if (used[to]) continue;
							cost[to] = cost[now] + 1;
							if (cost[to] > k / 2) tmp++;
							used[to] = true;
							q.add(to);
						}
					}

					count = Math.min(count, tmp);
				}

			} else {

				for (int i = 0; i < n-1; i++) {
					Queue<Integer> q = new ArrayDeque<>();
					boolean[] used = new boolean[n];
					int[] cost = new int[n];
					Arrays.fill(cost, INF);

					q.add(a[i]);
					used[a[i]] = true;
					cost[a[i]] = 0;

					while (!q.isEmpty()) {
						int now = q.remove();

						for (int to : g[now]) {
							if (used[to]) continue;
							cost[to] = cost[now] + 1;
							used[to] = true;
							q.add(to);
						}
					}

					q.add(b[i]);
					Arrays.fill(used, false);
					used[b[i]] = true;
					cost[b[i]] = 0;

					while (!q.isEmpty()) {
						int now = q.remove();

						for (int to : g[now]) {
							if (used[to]) continue;
							if (cost[now] + 1 < cost[to]) {
								cost[to] = cost[now] + 1;
								used[to] = true;
								q.add(to);
							}
						}
					}

					int tmp = 0;
					for (int j = 0; j < n; j++) {
						if (cost[j] > k/2) tmp++;
					}

					count = Math.min(count, tmp);
				}
			}

			out.println(count);

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

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}

		public int[] nextIntArray1Index(int n) {
			int[] res = new int[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextInt();
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

		public long[] nextLongArrayDec(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}

		public long[] nextLongArray1Index(int n) {
			long[] res = new long[n + 1];
			for (int i = 0; i < n; i++) {
				res[i + 1] = nextLong();
			}
			return res;
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}