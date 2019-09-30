import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyInput in = new MyInput(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 28;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		int h, w;
		public void solve(int testNumber, MyInput in, PrintWriter out) {

			h = in.nextInt(); w = in.nextInt();
			Dinic dinic = new Dinic(h + w + 2);

			char[][] s = in.next2DChars(h, w);
			int src = h + w, dst = h + w + 1;

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (s[i][j] == 'S') {
						dinic.addEdge(src, i, INF);
						dinic.addEdge(src, h + j, INF);
					}
					if (s[i][j] == 'T') {
						dinic.addEdge(i, dst, INF);
						dinic.addEdge(h + j, dst, INF);
					}
					if (s[i][j] == 'o') {
						dinic.addEdge(i, h + j, 1);
						dinic.addEdge(h + j, i, 1);
					}
				}
			}

			int ans = dinic.maxFlow(src, dst);
			out.println(ans >= INF ? -1 : ans);

		}

		class Dinic {

			private class Edge {
				int to, cap, rev;

				public Edge(int to, int cap, int rev) {
					this.to = to;
					this.cap = cap;
					this.rev = rev;
				}
			}

			ArrayList<ArrayList<Edge>> g;
			int[] level, iter;

			public Dinic(int V) {
				g = new ArrayList<>(V);
				for (int i = 0; i < V; i++) g.add(new ArrayList<>());
				level = new int[V];
				iter = new int[V];
			}

			void addEdge(int from, int to, int capacity) {
				g.get(from).add(new Edge(to, capacity, g.get(to).size()));
				g.get(to).add(new Edge(from, 0, g.get(from).size() -1));
			}

			void bfs(int s) {
				Arrays.fill(level, -1);
				ArrayDeque<Integer> q = new ArrayDeque<>();
				level[s] = 0;
				q.add(s);

				while (!q.isEmpty()) {
					int v = q.poll();
					for (Edge e : g.get(v)) {
						if (e.cap > 0 && level[e.to] < 0) {
							level[e.to] = level[v] + 1;
							q.add(e.to);
						}
					}
				}
			}

			int dfs(int v, int t, int f) {
				if (v == t) return f;
				for (int i = iter[v]; i < g.get(v).size(); i++) {
					Edge e = g.get(v).get(i);
					if (e.cap > 0 && level[v] < level[e.to]) {
						int d = dfs(e.to, t, Math.min(f, e.cap));
						if (d > 0) {
							e.cap -= d;
							g.get(e.to).get(e.rev).cap += d;
							return d;
						}
					}
				}
				return 0;
			}

			int maxFlow(int s, int t) {
				int flow = 0;
				while (true) {
					bfs(s);
					if (level[t] < 0) return flow;
					Arrays.fill(iter, 0);
					int f;
					while ((f = dfs(s, t, Integer.MAX_VALUE)) > 0) {
						flow += f;
					}
				}
			}
		}

		int f(int i,int j) {
			return i * w + j;
		}

		boolean isInside(int i, int j) {
			return 0 <= i && i < h && 0 <= j && j < w;
		}
	}

	static class MyInput {
		private final BufferedReader in;
		private static int pos;
		private static int readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static char[] str = new char[500 * 8 * 2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static {
			for (int i = 0; i < 10; i++) {
				isDigit['0' + i] = true;
			}
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			isLineSep['\r'] = isLineSep['\n'] = true;
		}

		public MyInput(InputStream is) {
			in = new BufferedReader(new InputStreamReader(is));
		}

		public int read() {
			if (pos >= readLen) {
				pos = 0;
				try {
					readLen = in.read(buffer);
				} catch (IOException e) {
					throw new RuntimeException();
				}
				if (readLen <= 0) {
					throw new MyInput.EndOfFileRuntimeException();
				}
			}
			return buffer[pos++];
		}

		public int nextInt() {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			int i = 0;
			int ret = 0;
			if (str[0] == '-') {
				i = 1;
			}
			for (; i < len; i++)
				ret = ret * 10 + str[i] - '0';
			if (str[0] == '-') {
				ret = -ret;
			}
			return ret;
		}

		public long nextLong() {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			int i = 0;
			long ret = 0;
			if (str[0] == '-') {
				i = 1;
			}
			for (; i < len; i++)
				ret = ret * 10 + str[i] - '0';
			if (str[0] == '-') {
				ret = -ret;
			}
			return ret;
		}

		public char nextChar() {
			while (true) {
				final int c = read();
				if (!isSpace[c]) {
					return (char) c;
				}
			}
		}

		public String nextString() {
			return new String(nextChars());
		}

		public char[] nextChars() {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			return Arrays.copyOf(str, len);
		}

		public char[][] next2DChars(int h, int w) {
			char[][] s = new char[h][w];
			for (int i = 0; i < h; i++) {
				s[i] = nextChars();
			}
			return s;
		}

		int reads(int len, boolean[] accept) {
			try {
				while (true) {
					final int c = read();
					if (accept[c]) {
						break;
					}
					if (str.length == len) {
						char[] rep = new char[str.length * 3 / 2];
						System.arraycopy(str, 0, rep, 0, str.length);
						str = rep;
					}
					str[len++] = (char) c;
				}
			} catch (MyInput.EndOfFileRuntimeException e) {
			}
			return len;
		}

		public int[] nextIntArray(final int n) {
			final int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[] nextIntArray1Index(final int n) {
			final int[] res = new int[n + 1];
			for (int i = 1; i < n + 1; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[] nextIntArrayDec(final int n) {
			final int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
			}
			return res;
		}

		public long[] nextLongArray(final int n) {
			final long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public long[] nextLongArray1Index(final int n) {
			final long[] res = new long[n + 1];
			for (int i = 1; i < n + 1; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public long[] nextLongArrayDec(final int n) {
			final long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong() - 1;
			}
			return res;
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public double[] nextDoubleArray(int n) {
			double[] res = new double[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

		static class EndOfFileRuntimeException extends RuntimeException {
		}

	}

}