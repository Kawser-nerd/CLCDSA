import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;
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
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	@SuppressWarnings("unchecked")
	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			long t = in.nextLong();
			int[] value = in.nextIntArray(n);

			List<P>[] g = new ArrayList[n];
			List<P>[] gg = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
			gg = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);

			for (int i = 0; i < m; i++) {
				int a = in.nextInt()-1;
				int b = in.nextInt()-1;
				long c = in.nextLong();
				g[a].add(new P(a, b, c));
				gg[b].add(new P(b, a, c));
			}

			PriorityQueue<P> q = new PriorityQueue<>((o1, o2) -> (int)o1.w - (int)o2.w);
			long[] cost1 = new long[n];
			Arrays.fill(cost1, INF);

			cost1[0] = 0;
			for (P p : g[0]) {
				q.add(p);
			}

			while (!q.isEmpty()) {

				P p = q.remove();

				if (cost1[p.from] + p.w < cost1[p.to]) {
					cost1[p.to] =  cost1[p.from] + p.w;
					for (P pt : g[p.to]) {
						q.add(pt);
					}
				}
			}

			q = new PriorityQueue<>((o1, o2) -> (int)o1.w - (int)o2.w);
			long[] cost2 = new long[n];
			Arrays.fill(cost2, INF);

			cost2[0] = 0;
			for (P p : gg[0]) {
				q.add(p);
			}

			while (!q.isEmpty()) {

				P p = q.remove();

				if (cost2[p.from] + p.w < cost2[p.to]) {
					cost2[p.to] =  cost2[p.from] + p.w;
					for (P pt : gg[p.to]) {
						q.add(pt);
					}
				}
			}

			long ans = -1;
			for (int i = 0; i < n; i++) {
				long time = t - (cost1[i] + cost2[i]);
				ans = Math.max(ans, time * value[i]);
			}

			out.println(ans);

		}

		static class P {
			int from, to;
			long w;

			public P(int from, int to, long w) {
				super();
				this.from = from;
				this.to = to;
				this.w = w;
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