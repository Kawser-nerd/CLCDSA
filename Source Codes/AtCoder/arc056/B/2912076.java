import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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
	static long LINF = 1L << 55;
	static int MOD = 1000000007;
	static int[] mh4 = { 0, -1, 1, 0 };
	static int[] mw4 = { -1, 0, 0, 1 };
	static int[] mh8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] mw8 = { -1, 0, 1, -1, 1, -1, 0, 1 };

	static class TaskX {

		@SuppressWarnings("unchecked")
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt(), m = in.nextInt(), s = in.nextInt()-1;
			P[] p = new P[m];
			List<Integer>[] g = new ArrayList[n];
			g = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
			for (int i = 0; i < m; i++) {
				int u = in.nextInt()-1, v = in.nextInt()-1;
				if (u > v) {
					int tmp = u;
					u = v;
					v = tmp;
				}
				p[i] = new P(u, v);
			}

			Arrays.sort(p);

			for (int i = 0; i < m; i++) {
				int u = p[i].f;
				int v = p[i].t;
				g[u].add(v);
			}

			DisjointSet set = new DisjointSet(n);

			ArrayList<Integer> list = new ArrayList<>();
			for (int i = s; i >= 0; i--) {
				for (int to : g[i]) {
					set.unite(to, i);
				}
				if (set.same(i, s)) list.add(i);
			}

			Collections.sort(list);

			for (int i : list) {
				out.println(i+1);
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

			public void link(int x, int y) {
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

		class P implements Comparable<P> {
			int f, t;

			public P(int f, int t) {
				super();
				this.f = f;
				this.t = t;
			}

			@Override
			public int compareTo(P o) {

				if (this.f == o.f) {
					return this.t - o.t;
				} else {
					return this.f - o.f;
				}
			}

			@Override
			public String toString() {
				return f +":" + t;
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

		public int[] nextIntArrayDec(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt() - 1;
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

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}
	}

}