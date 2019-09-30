import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = false;

	static void solve() {
		int n = ir.nextInt();
		int m = ir.nextInt();
		int s = ir.nextInt() - 1;
		int[][] r = new int[m][2];
		for (int i = 0; i < m; i++) {
			r[i][0] = ir.nextInt() - 1;
			r[i][1] = ir.nextInt() - 1;
			if (r[i][0] > r[i][1]) {
				int t = r[i][0];
				r[i][0] = r[i][1];
				r[i][1] = t;
			}
		}
		Arrays.sort(r, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		ArrayList<Integer> ret = new ArrayList<>();
		UnionFindTree uf = new UnionFindTree(n);
		int p = m - 1;
		for (int i = n - 1; i >= 0; i--) {
			while (p >= 0 && r[p][0] == i) {
				uf.unite(r[p][0], r[p][1]);
				p--;
			}
			if (i <= s && uf.same(i, s)) {
				ret.add(i);
			}
		}
		for (int i = 0; i < ret.size(); i++) {
			out.println(ret.get(ret.size() - 1 - i)+1);
		}
	}

	static class UnionFindTree {

		private int[] par;
		private int[] rank;

		public UnionFindTree(int size) {
			par = new int[size];
			rank = new int[size];
			for (int i = 0; i < size; i++) {
				par[i] = i;
				rank[i] = 0;
			}
		}

		private int find(int x) {
			if (par[x] == x)
				return x;
			else
				return par[x] = find(par[x]);
		}

		public void unite(int x, int y) {
			x = find(x);
			y = find(y);
			if (x == y)
				return;
			else if (rank[x] > rank[y])
				par[y] = x;
			else {
				par[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}

		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
	}

	public static void main(String[] args) throws Exception {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}

	static void tr(Object... o) {
		if (debug)
			out.println(Arrays.deepToString(o));
	}
}