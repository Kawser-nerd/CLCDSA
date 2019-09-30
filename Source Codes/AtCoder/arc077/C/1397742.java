import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt() - 1;
		}
		long[] d1 = new long[m + 1];
		long[] d2 = new long[m + 1];
		for (int i = 0; i + 1 < n; ++i) {
			int t = a[i + 1];
			int s = a[i];
			if (s <= t) {
				d1[0] += t - s;
				d1[s + 1] -= t - s;

				d1[s + 1] += t + 1;
				d1[t + 1] -= t + 1;
				d2[s + 1] += -1;
				d2[t + 1] -= -1;

				d1[t + 1] += t - s;
				d1[m] -= t - s;
			} else {
				
				d1[0] += t + 1;
				d1[t + 1] -= t + 1;
				d2[0] += -1;
				d2[t + 1] -= -1;

				d1[t + 1] += m + t - s;
				d1[s + 1] -= m + t - s;

				d1[s + 1] += t + m + 1;
				d1[m] -= t + m + 1;
				d2[s + 1] += -1;
				d2[m] -= -1;

			}
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i < m; ++i) {
			if (i > 0) {
				d1[i] += d1[i - 1];
				d2[i] += d2[i - 1];
			}
		}
		for (int i = 0; i < m; ++i) {
			ans = Math.min(ans, d1[i] + d2[i] * i);
		}
		System.out.println(ans);
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

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			long n = 0;
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

		public int nextInt() {
			return (int) nextLong();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}