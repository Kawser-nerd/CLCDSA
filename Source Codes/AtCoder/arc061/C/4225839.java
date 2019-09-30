import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.stream.Stream;

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

	static int INF = 1 << 30;
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		TreeMap<Long, Integer> map = new TreeMap<>();
		int id = 0;
		@SuppressWarnings("unchecked")
		public void solve(int testNumber, MyInput in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();

			for (int i = 1; i <= n; i++) {
				addId(f(i, 0));
			}

			TreeSet<Integer> set = new TreeSet<>();
			int[] p = new int[m], q = new int[m], c = new int[m];
			for (int i = 0; i < m; i++) {
				p[i] = in.nextInt();
				q[i] = in.nextInt();
				c[i] = in.nextInt();
				addId(f(p[i], c[i]));
				addId(f(q[i], c[i]));
				set.add(getId(f(p[i], c[i])));
				set.add(getId(f(q[i], c[i])));
			}

			List<P>[] g = new ArrayList[id+1];
			g = Stream.generate(ArrayList::new).limit(id+1).toArray(List[]::new);

			for (int i = 0; i < m; i++) {
				int f = getId(f(p[i], c[i])), t = getId(f(q[i], c[i]));
				g[f].add(new P(t, 0));
				g[t].add(new P(f, 0));
				g[p[i]].add(new P(f, 1));
				g[f].add(new P(p[i], 0));
				g[q[i]].add(new P(t, 1));
				g[t].add(new P(q[i], 0));
			}

			int[] cost = dijkstra(1, g);
			out.println(cost[n] == INF ? -1 : cost[n]);

		}

		long f(int i, int c) {
			return (long)c << 32 | i;
		}

		void addId(long key) {
			if (map.containsKey(key)) return;
			map.put(key, ++id);
		}

		int getId(long key) {
			return map.get(key);
		}


		int[] dijkstra(int from, List<P>[] g) {
			int n = g.length;
			PriorityQueue<P> q = new PriorityQueue<>();
			int[] cost = new int[n];
			Arrays.fill(cost, INF);
			cost[from] = 0;
			q.add(new P(from, cost[from]));

			while (!q.isEmpty()) {

				P pp = q.remove();
				if (pp.cost != cost[pp.node]) continue;
				for (P p : g[pp.node]) {
					if (cost[pp.node] + p.cost < cost[p.node]) {
						cost[p.node] = cost[pp.node] + p.cost;
						q.add(new P(p.node, cost[p.node]));
					}
				}

			}

			return cost;
		}

		class P implements Comparable<P> {
			int node, cost;

			public P(int node, int cost) {
				super();
				this.node = node;
				this.cost = cost;
			}

			@Override
			public String toString() {
				return "P [node=" + node + ", cost=" + cost + "]";
			}

			@Override
			public int compareTo(P o) {
				return Integer.compare(this.cost, o.cost);
			}

			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + node;
				result = prime * result + cost;
				return result;
			}

			@Override
			public boolean equals(Object obj) {
				if (this == obj)
					return true;
				if (obj == null)
					return false;
				if (getClass() != obj.getClass())
					return false;
				P other = (P) obj;
				if (node != other.node)
					return false;
				if (cost != other.cost)
					return false;
				return true;
			}
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