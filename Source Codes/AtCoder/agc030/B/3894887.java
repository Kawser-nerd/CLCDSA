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
		long l = ir.nextLong();
		int n = ir.nextInt();
		long[] x = ir.nextLongArray(n);
		long[] sum = new long[n + 1];
		for (int i = 1; i <= n; i++) {
			sum[i] = x[i - 1];
			sum[i] += sum[i - 1];
		}
		long res = Math.max(l - x[0], x[n - 1]);
		long t = 0;
		for (int i = n - 1; i > n / 2; i--) {
			t += (l - x[i]) * 2;
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n]) - Math.min(l - x[i], x[i - 1]));
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n - 1]) - x[i - 1]);
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n + 1]) - (l - x[i]));
		}
		if (n % 2 == 0) {
			t += (l - x[n / 2]) * 2;
			res = Math.max(res, t + 2 * sum[n / 2] - Math.min(l - x[n / 2], x[n / 2 - 1]));
			res = Math.max(res, t + 2 * (sum[n / 2] - sum[1]) - (l - x[n / 2]));
		}
		long[] y = new long[n];
		for (int i = 0; i < n; i++) {
			y[i] = l - x[n - 1 - i];
		}
		for (int i = 1; i <= n; i++) {
			sum[i] = y[i - 1];
			sum[i] += sum[i - 1];
		}
		t = 0;
		for (int i = n - 1; i > n / 2; i--) {
			t += (l - y[i]) * 2;
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n]) - Math.min(l - y[i], y[i - 1]));
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n - 1]) - y[i - 1]);
			res = Math.max(res, t + 2 * (sum[i] - sum[2 * i - n + 1]) - (l - y[i]));
		}
		if (n % 2 == 0) {
			t += (l - y[n / 2]) * 2;
			res = Math.max(res, t + 2 * sum[n / 2] - Math.min(l - y[n / 2], y[n / 2 - 1]));
			res = Math.max(res, t + 2 * (sum[n / 2] - sum[1]) - (l - y[n / 2]));
		}
		out.println(res);
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