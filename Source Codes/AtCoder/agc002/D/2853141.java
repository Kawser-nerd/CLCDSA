import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = true;

	static void solve() {
		int n = ir.nextInt();
		int m = ir.nextInt();
		PersistentUnionFind uf = new PersistentUnionFind(n);
		for (int i = 0; i < m; i++)
			uf.unite(ir.nextInt() - 1, ir.nextInt() - 1);
		int q = ir.nextInt();
		while (q-- > 0) {
			int x = ir.nextInt() - 1;
			int y = ir.nextInt() - 1;
			int z = ir.nextInt();
			int lb = 0, ub = m + 1;
			while (ub - lb > 1) {
				int mid = (lb + ub) >>> 1;
				if ((uf.size(x, mid) + (uf.same(x, y, mid) ? 0 : uf.size(y, mid)) < z))
					lb = mid;
				else
					ub = mid;
			}
			out.println(ub);
		}
	}

	static class PersistentUnionFind {

		// node:0-indexed
		// query(time):1-indexed
		int[] time;
		int[] last;
		int cur = 0;
		AL[] size;
		HM[] par;

		private PersistentUnionFind(int n) {
			time = new int[n];
			last = new int[n];
			size = new AL[n];
			par = new HM[n];
			for (int i = 0; i < n; i++) {
				size[i] = new AL();
				size[i].add(new int[] { 0, 1 });
				par[i] = new HM();
				par[i].put(0, -1);
			}
		}

		public int find(int x, int t) {
			if (time[x] <= t && par[x].get(time[x]) >= 0)
				return find(par[x].get(time[x]), t);
			return x;
		}

		public void unite(int x, int y) {
			x = find(x, cur);
			y = find(y, cur);
			cur++;
			if (x == y)
				return;
			int sx = par[x].get(last[x]), sy = par[y].get(last[y]);
			if (sx > sy) {
				int t = x;
				x = y;
				y = t;
			}
			par[x].put(cur, sx + sy);
			last[x] = cur;
			par[y].put(cur, x);
			time[y] = cur;
			size[x].add(new int[] { cur, -(sx + sy) });
		}

		public boolean same(int x, int y, int t) {
			return find(x, t) == find(y, t);
		}

		public int size(int x, int t) {
			x = find(x, t);
			int lb = 0, ub = size[x].size();
			while (ub - lb > 1) {
				int mid = (lb + ub) >>> 1;
				if (size[x].get(mid)[0] <= t)
					lb = mid;
				else
					ub = mid;
			}
			return size[x].get(lb)[1];
		}

		class AL extends ArrayList<int[]> {
		}

		class HM extends HashMap<Integer, Integer> {
		}
	}

	public static void main(String[] args) {
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