import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = false;

	static void solve() {
		int n = ir.nextInt();
		if (n == 3) {
			out.println("2 5 63");
			return;
		}
		if (n == 4) {
			out.println("2 5 20 63");
			return;
		}
		ArrayList<Integer> m = new ArrayList<>();
		m.add(2);
		m.add(3);
		m.add(4);
		for (int i = 6; i <= 30000; i++)
			if (i % 2 == 0 || i % 3 == 0)
				m.add(i);
		if (n % 8 == 4) {
			for (int i = 0; i < n - 1; i++) {
				out.print(m.get(i) + " ");
			}
			out.println(m.get(n + 1));
		} else if (n % 8 == 3) {
			for (int i = 0; i < n; i++) {
				if (i == n - 2)
					continue;
				out.print(m.get(i) + " ");
			}
			out.println(m.get(n));
		}

		else if (n % 8 == 5 || n % 8 == 2) {
			{
				for (int i = 0; i < n - 1; i++) {
					out.print(m.get(i) + " ");
				}
				out.println(m.get(n));
			}
		} else if (n % 8 == 6) {
			for (int i = 0; i < n; i++) {
				if (i == n - 2)
					continue;
				out.print(m.get(i) + " ");
			}
			out.println(m.get(n + 1));
		} else if (n % 8 == 1) {
			for (int i = 0; i < n - 1; i++) {
				out.print(m.get(i) + " ");
			}
			out.println(m.get(n + 2));
		}

		else {
			for (int i = 0; i < n; i++) {
				out.print(m.get(i) + (i == n - 1 ? "\n" : " "));
			}
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