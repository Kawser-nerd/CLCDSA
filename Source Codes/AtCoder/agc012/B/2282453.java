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

	static class TaskX {

		public List<Integer>[] graph;
		public int[] color;
		public int[] maxx;

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
			for (int i = 0; i < m; i++) {
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				graph[a].add(b);
				graph[b].add(a);
			}

			int q = in.nextInt();
			color = new int[n];
			int[] v = new int[q], d = new int[q], c = new int[q];
			for (int i = 0; i < q; i++) {
				v[i] = in.nextInt() - 1;
				d[i] = in.nextInt();
				c[i] = in.nextInt();
			}

			maxx = new int[n];
			Arrays.fill(maxx, -1);
			for (int i = q - 1; i >= 0; i--) {
				process(v[i], d[i], c[i]);
			}

			for (int i = 0; i < n; i++) {
				out.println(color[i]);
			}

		}

		public void process(int v, int dist, int c) {
			if (dist <= maxx[v]) return;
			maxx[v] = dist;
			if (color[v] == 0) color[v] = c;
			for (int next : graph[v]) {
				process(next, dist - 1, c);
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