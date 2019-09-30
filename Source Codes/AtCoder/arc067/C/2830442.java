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
		long mod = (long) 1e9 + 7;
		int n = ir.nextInt();
		int a = ir.nextInt();
		int b = ir.nextInt();
		int c = ir.nextInt();
		int d = ir.nextInt();
		long[] f = fact(n, mod);
		long[] fi = factInv(n, mod);
		long[][] dp = new long[b - a + 2][n + 1];
		dp[b - a + 1][0] = 1;
		for (int i = b; i >= a; i--) {
			for (int j = 0; j <= n; j++) {
				dp[i - a][j] = dp[i - a + 1][j];
				if (j < c * i)
					continue;
				long t = 1;
				for (int k = 1; k < c; k++) {
					t *= comb(j - i * (k - 1), i, f, fi, mod);
					t %= mod;
				}
				for (int k = c; k <= Math.min(d, j / i); k++) {
					t *= comb(j - i * (k - 1), i, f, fi, mod);
					t %= mod;
					dp[i - a][j] += (((dp[i - a + 1][j - i * k] * t) % mod) * fi[k]) % mod;
					dp[i - a][j] %= mod;
				}
			}
		}
		out.println(dp[0][n]);
	}

	public static long mod_inverse(long a, long MOD) {
		long[] ret = extgcd(a, MOD);
		return (MOD + ret[0] % MOD) % MOD;
	}

	public static long[] extgcd(long a, long b) {
		long[] ret = new long[3];
		ret[2] = _extgcd(a, b, ret);
		return ret;
	}

	private static long _extgcd(long a, long b, long[] x) {
		long g = a;
		x[0] = 1;
		x[1] = 0;
		if (b != 0) {
			g = _extgcd(b, a % b, x);
			long temp = x[0];
			x[0] = x[1];
			x[1] = temp;
			x[1] -= (a / b) * x[0];
		}
		return g;
	}

	private static long[] fact(int n, long MOD) {
		long[] ret = new long[n + 1];
		ret[0] = 1 % MOD;
		for (int i = 1; i <= n; i++) {
			ret[i] = ret[i - 1] * i;
			ret[i] %= MOD;
		}
		return ret;
	}

	private static long[] factInv(int n, long MOD) {
		long[] ret = new long[n + 1];
		ret[0] = 1;
		for (int i = 1; i <= n; i++) {
			ret[i] = ret[i - 1] * mod_inverse((long) i, MOD) % MOD;
		}
		return ret;
	}

	public static long comb(int n, int m, long[] fact, long[] factInv, long MOD) {
		long ret = fact[n];
		ret *= factInv[m];
		ret %= MOD;
		ret *= factInv[n - m];
		ret %= MOD;
		return ret;
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