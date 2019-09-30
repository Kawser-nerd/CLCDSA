import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
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
	static int modP = 1000000007;

	static Map<Long,Long> memo = new HashMap<>();
	static List<Integer>[] graph;
	static int N, M;
	static int[] maxx, color;

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			N = in.nextInt();
			M = in.nextInt();
			graph = new ArrayList[N];
			graph = Stream.generate(ArrayList::new).limit(N).toArray(List[]::new);

			for (int i = 0; i < M; i++) {
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				graph[a].add(b);
				graph[b].add(a);
			}

			int Q = in.nextInt();
			int[] v = new int[Q];
			int[] d = new int[Q];
			int[] c = new int[Q];
			for (int i = 0; i < Q; i++) {
				v[i] = in.nextInt() - 1;
				d[i] = in.nextInt();
				c[i] = in.nextInt();
			}

			color = new int[N];
			maxx = new int[N];
			Arrays.fill(maxx, -1);
			for (int i = Q - 1; i >= 0; i--) {
				process(v[i], d[i], c[i]);
			}

			for (int i = 0; i < N; i++) {
				out.println(color[i]);
			}
		}

		static void process(int v, int d, int c) {
			if (maxx[v] >= d) return;
			maxx[v] = d;
			if (color[v] == 0) color[v] = c;
			for (int tv : graph[v]) {
				process(tv, d - 1, c);
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

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.