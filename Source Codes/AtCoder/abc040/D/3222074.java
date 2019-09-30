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
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt();
			E[] e = new E[m];
			for (int i = 0; i < m; i++) {
				int a = in.nextInt()-1;
				int b = in.nextInt()-1;
				int y = in.nextInt();
				e[i] = new E(a, b, y);
			}
			Arrays.sort(e);

			int k = in.nextInt();
			Q[] q = new Q[k];
			for (int i = 0; i < k; i++) {
				int v = in.nextInt()-1;
				int w = in.nextInt();
				q[i] = new Q(i, v, w);
			}
			Arrays.sort(q);

			DisjointSet set = new DisjointSet(n);

			int[] ans = new int[k];
			int idx = 0;
			for (Q qq : q) {

				if (idx >= m) {
					ans[qq.i] = set.getSize(qq.v);
					continue;
				}

				if (qq.w < e[idx].y) {
					while (idx < m && qq.w < e[idx].y) {
						set.unite(e[idx].a , e[idx].b);
						idx++;
					}
				}
				ans[qq.i] = set.getSize(qq.v);
			}

			for (int i : ans) {
				out.println(i);
			}

		}

		class E implements Comparable<E> {
			int a, b, y;

			public E(int a, int b, int y) {
				super();
				this.a = a;
				this.b = b;
				this.y = y;
			}

			@Override
			public String toString() {
				return "E [a=" + a + ", b=" + b + ", y=" + y + "]";
			}

			@Override
			public int compareTo(E o) {
				return -Integer.compare(this.y, o.y);
			}
		}

		class Q implements Comparable<Q> {
			int i, v, w;

			public Q(int i, int v, int w) {
				super();
				this.i = i;
				this.v = v;
				this.w = w;
			}

			@Override
			public String toString() {
				return "Q [i=" + i + ", v=" + v + ", w=" + w + "]";
			}

			@Override
			public int compareTo(Q o) {
				return -Integer.compare(this.w, o.w);
			}
		}
	}

	/**
	 * DisjointSet
	 * */
	public static class DisjointSet {

		int[] p, rank, cnt;

		public DisjointSet(int size) {
			p = new int[size];
			rank = new int[size];
			cnt = new int[size];

			for (int j = 0; j < size; j++) {
				makeSet(j);
			}
		}

		private void makeSet(int x) {
			p[x] = x;
			rank[x] = 0;
			cnt[x] = 1;
		}

		public int findSet(int x) {
			return p[x] == x ? x : findSet(p[x]);
		}

		private void link(int x, int y) {
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else if (rank[x] < rank[y]) {
				p[x] = y;
			} else if (rank[x] == rank[y]) {
				p[x] = y;
				rank[y]++;
			}

			if (x != y) {
				cnt[x] = cnt[y] += cnt[x];
			}
		}

		public void unite(int x, int y) {
			link(findSet(x), findSet(y));
		}

		public boolean same(int x, int y) {
			return findSet(x) == findSet(y);
		}

		public int getSize(int x) {
			return cnt[findSet(x)];
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