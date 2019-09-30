import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			int[][] g = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(g[i], -1);
			}
			for (int i = 0; i < m; i++) {
				int u = in.nextInt()-1, v = in.nextInt()-1, l = in.nextInt();
				g[u][v] = l;
				g[v][u] = l;
			}

			int ans = INF;
			for (int j = 0; j < g[0].length; j++) {
				if (g[0][j] == -1) {
					continue;
				}
				int s = j;
				int c = g[0][j];
				int tmps = j;
				int tmpc = g[0][j];

				g[0][j] = -1;
				g[j][0] = -1;

				int[] cost = new int[n];
				Arrays.fill(cost, INF);
				PriorityQueue<Integer> q = new PriorityQueue<Integer>();
				q.add(s);
				cost[s] = c;

				while (!q.isEmpty()) {
					int f = q.remove();
					for (int t = 0; t < g[f].length; t++) {
						if (g[f][t] == -1) continue;
						if (cost[f] + g[f][t] < cost[t]) {
							cost[t] = cost[f] + g[f][t];
							q.add(t);
						}
					}
				}

				ans = Math.min(ans, cost[0]);

				g[0][tmps] = tmpc;
				g[tmps][0] = tmpc;

			}

			out.println(ans == INF ? -1 : ans);

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