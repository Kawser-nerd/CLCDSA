import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	int n;
	long mo = 1_000_000_000 + 7;
	long[] fac = new long[3000000];
	long[] ifac = new long[3000000];
	long[] inv = new long[3000000];
	{
		fac[0] = 1;
		for (int i = 1; i < fac.length; ++i) {
			fac[i] = i * fac[i - 1] % mo;
		}
		inv[1] = 1;
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = mo - inv[(int) (mo % i)] * (mo / i) % mo;
		}
		ifac[0] = 1;
		for (int i = 1; i < ifac.length; ++i) {
			ifac[i] = ifac[i - 1] * inv[i] % mo;
		}
	}

	long comb(int n, int k) {
		return fac[n] * ifac[n - k] % mo * ifac[k] % mo;
	}

	long g(int k) {
		if (2 * k < n)
			return 0;
		int a = 2 * k - n;
		int b = n - k;
		return comb(a - 1 + b, b - 1) * fac[k] % mo * fac[n - 1 - k] % mo;
	}

	long f(int k) {
		return (g(k) - g(k - 1) + mo) % mo;
	}

	void run() {
		Scanner sc = new Scanner();
		n = (int) sc.nextLong();
		long ans = 0;
		for (int i = (n + 1) / 2; i <= n - 1; ++i) {
			ans = (ans + f(i) * i % mo) % mo;
		}
		System.out.println(ans);
	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a % mo) {
			if (n % 2 == 1) {
				ret = ret * a % mo;
			}
		}
		return ret;
	}

	long inv(long a) {
		return pow(a, mo - 2);
	}

	public static void main(String[] args) {
		new Main().run();
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
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}