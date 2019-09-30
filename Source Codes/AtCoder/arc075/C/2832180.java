import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = false;

	static void solve() {
		int n = ir.nextInt();
		int k = ir.nextInt();
		long[] a = new long[n + 1];
		for (int i = 0; i < n; i++) {
			a[i + 1] = ir.nextLong() - k;
			a[i + 1] += a[i];
		}
		int[] b = compress(a);
		BinaryIndexedTree bit = new BinaryIndexedTree(n + 1);
		long res = 0;
		for (int i = 0; i <= n; i++) {
			res += bit.sum(b[i] + 1);
			bit.update(b[i], 1);
		}
		out.println(res);
	}

	public static int[] compress(long[] a) {
		int n = a.length;
		long[] r = a.clone();
		Arrays.sort(r);
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = lower_bound(r, 0, n - 1, a[i]);
		return ret;
	}

	public static int lower_bound(long[] a, int fromIndex, int toIndex, long val) {
		if (val > a[toIndex])
			return toIndex + 1;
		if (val <= a[fromIndex])
			return fromIndex;
		int lb = fromIndex - 1, ub = toIndex;
		while (ub - lb > 1) {
			int mid = (ub - lb) / 2 + lb;
			if (a[mid] >= val) {
				ub = mid;
			} else {
				lb = mid;
			}
		}
		return ub;
	}

	static class BinaryIndexedTree {
		// 0-indexed
		private long[] bit;
		private int SIZE;

		public BinaryIndexedTree(int n) {
			bit = new long[n + 1];
			SIZE = n;
		}

		// sum of segment[0,i)
		public long sum(int i) {
			long res = 0;
			while (i > 0) {
				res += bit[i];
				i -= i & -i;
			}
			return res;
		}

		// sum of segment[start,end)
		public long sum(int start, int end) {
			return sum(end) - sum(start);
		}

		public long get(int i) {
			return sum(i + 1) - sum(i);
		}

		public void update(int i, long x) {
			i++;
			while (i <= SIZE) {
				bit[i] += x;
				i += i & -i;
			}
		}

		public int size() {
			return SIZE;
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