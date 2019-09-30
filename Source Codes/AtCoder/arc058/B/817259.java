import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	private static long mod = 1000000000 + 7;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int H = sc.nextInt();
		int W = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();

		System.out.println(solve2(H, W, A, B));
	}

	private static long solve2(int H, int W, int A, int B) {
		int h = H - A - 1;
		int w = B;
		long ret = 0;
		long x = C(h + w, w);
		long y = C(W - 1 - B + A, W - 1 - w);

		for (int i = w; i < W; i++) {
			// ret += C(h + w, i) * C(W - 1 - B + A, W - 1 - i);
			ret += x * y;

			int n = i + 1;
			x *= (h + w - n + 1) * inverse(n) % mod;
			y *= inverse((W - 1 - B + A) - (W - 1 - n)) * (W - 1 - n + 1) % mod;
			x %= mod;
			y %= mod;
			ret %= mod;
		}
		return ret;
	}

	public static long C(long n, long r) {
		long comb = 1;
		for (int i = 0; i < r; i++) {
			comb = (comb * (n - i)) % mod;
			comb = (comb * inverse(r - i)) % mod;
		}
		return comb;
	}

	public static long[] extgcd(long a, long b) {
		long u = 1;
		long v = 0;
		long x = 0;
		long y = 1;

		while (a > 0) {
			long q = b / a;
			x -= q * u;
			y -= q * v;
			b -= q * a;

			long tmp;
			tmp = x;
			x = u;
			u = tmp;
			tmp = y;
			y = v;
			v = tmp;
			tmp = b;
			b = a;
			a = tmp;
		}

		return new long[] { b, x, y };
	}

	public static long inverse(long n) {
		long[] gcd = extgcd(n, mod);
		if (gcd[0] == 1) {
			return (gcd[1] + mod) % mod;
		} else {
			return 0;
		}
	}
}

class FastScanner {
	public static String debug = null;

	private final InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
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

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean isEOS() {
		return this.eos;
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

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}