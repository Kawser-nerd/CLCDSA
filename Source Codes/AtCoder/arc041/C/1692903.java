import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int n;
	int L;
	long[] x;
	int[] d;
	long[] w;

	public void run() {
		Scanner sc = new Scanner();
		n = sc.nextInt();
		L = sc.nextInt();
		x = new long[n];
		d = new int[n];
		w = new long[n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextInt();
			d[i] = sc.next().equals("L") ? -1 : 1;
			w[i] = 1;
		}
		long ret = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (d[i] == 1 && d[i + 1] == 1) {
				ret += (x[i + 1] - x[i] - 1) * w[i];
				w[i + 1] += w[i];
				x[i] = -1;
			}
		}

		for (int i = n - 1; i >= 1; --i) {
			if (d[i] == -1 && d[i - 1] == -1) {
				ret += (x[i] - x[i - 1] - 1) * w[i];
				w[i - 1] += w[i];
				x[i] = -1;
			}
		}

		int p = 0;
		for (int i = 0; i < n; ++i)
			if (x[i] != -1)
				++p;
		long[] x2 = new long[p];
		int[] d2 = new int[p];
		long[] w2 = new long[p];
		p = 0;
		for (int i = 0; i < n; ++i) {
			if (x[i] != -1) {
				x2[p] = x[i];
				d2[p] = d[i];
				w2[p] = w[i];
				++p;
			}
		}

		int src = 0;
		int dst = p - 1;
		if (d2[src] == -1) {
			ret += (x2[src] - 1) * w2[src];
			++src;
		}
		if (d2[dst] == 1) {
			ret += (L - x2[dst]) * w2[dst];
			--dst;
		}

		for (int i = src; i <= dst; i += 2) {
			ret += Math.max(w2[i], w2[i + 1]) * (x2[i + 1] - x2[i] - 1);
		}
		System.out.println(ret);
	}

	class Scanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[ptr++];
			else
				return -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
		}

		public boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}