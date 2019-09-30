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
		char[] s = ir.next().toCharArray();
		char[] t = ir.next().toCharArray();
		int[] sct = new int[s.length + 1];
		int[] tct = new int[t.length + 1];
		for (int i = 0; i < s.length; i++) {
			sct[i + 1] += sct[i];
			if (s[i] == 'A')
				sct[i + 1]++;
		}
		for (int i = 0; i < t.length; i++) {
			tct[i + 1] += tct[i];
			if (t[i] == 'A')
				tct[i + 1]++;
		}
		int q = ir.nextInt();
		while (q-- > 0) {
			int a = ir.nextInt();
			int b = ir.nextInt();
			int c = ir.nextInt();
			int d = ir.nextInt();
			int sa = sct[b] - sct[a - 1];
			int sb = b - a + 1 - sa;
			int ta = tct[d] - tct[c - 1];
			int tb = d - c + 1 - ta;
			sa %= 3;
			sb %= 3;
			ta %= 3;
			tb %= 3;
			while (sa >= 2 || sb >= 2) {
				sb += sa / 2;
				sa %= 2;
				sa += sb / 2;
				sb %= 2;
			}
			while (ta >= 2 || tb >= 2) {
				tb += ta / 2;
				ta %= 2;
				ta += tb / 2;
				tb %= 2;
			}
			if (sa == 1 && sb == 1)
				sa = sb = 0;
			if (ta == 1 && tb == 1)
				ta = tb = 0;
			out.println(sa == ta && sb == tb ? "YES" : "NO");
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