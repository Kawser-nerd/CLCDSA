import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();

		PC pc = new PC(n, MOD);

		long[] dp = new long[n + 1];
		{
			int min = Math.min(d, n / a);
			long[] tmp = new long[min + 1];
			tmp[0] = 1;
			for (int k = 1; k <= min; k++) {
				tmp[k] = tmp[k - 1] * pc.C(a * k, a) % MOD;
				tmp[k] *= pc.fact[k - 1];
				tmp[k] %= MOD;
				tmp[k] *= pc.ifact[k];
				tmp[k] %= MOD;
			}

			dp[0] = tmp[0];
			for (int k = c; k <= d && a * k <= n; k++) {
				dp[k * a] = tmp[k];
			}
		}

		for (int i = a + 1; i <= b; i++) {
			for (int j = n; j >= 0; j--) {
				int min = Math.min(d, j / i);
				long[] tmp = new long[min + 1];
				tmp[0] = 1;
				for (int k = 1; k <= min; k++) {
					tmp[k] = tmp[k - 1] * pc.C(j - i * (k - 1), i) % MOD;
					tmp[k] *= pc.fact[k - 1];
					tmp[k] %= MOD;
					tmp[k] *= pc.ifact[k];
					tmp[k] %= MOD;
				}

				for (int k = c; k <= d && i * k <= j; k++) {
					dp[j] += dp[j - i * k] * tmp[k] % MOD;
					dp[j] %= MOD;
				}
			}
		}

		pr.println(dp[n]);
	}

	private static final int MOD = 1_000_000_007;

	@SuppressWarnings("unused")
    private static class PC {
    	// MOD must be prime number.
    	int MOD;
    	// fact[i] : i! % MOD
    	long[] fact;
    	// ifact[i] : 1/i! % MOD
    	long[] ifact;

    	PC(int size, int MOD) {
    		// O(size)
    		// n=size???nCr?????
    		// nHr?n+r-1Cr???????????

    		this.MOD = MOD;

    		fact = new long[size + 1];
    		fact[0] = 1;
    		for (int i = 1; i <= size; i++) {
    			fact[i] = fact[i - 1] * i % MOD;
    		}

    		ifact = new long[size + 1];

    		int loop = MOD - 2;
    		long x = fact[size];
    		ifact[size] = 1;
    		while (loop > 0) {
    			if (loop % 2 == 1) {
    				ifact[size] = ifact[size] * x % MOD;
    			}
    			x = x * x % MOD;
    			loop /= 2;
    		}

    		for (int i = size - 1; i >= 0; i--) {
    			ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    		}

    	}

    	// ?????
    	int C(int n, int r) {
    		if (r > n) {
    			return 0;
    		}

    		return (int)(((fact[n] * ifact[n - r]) % MOD) * ifact[r] % MOD);
    	}

    	// ??
    	int P(int n, int r) {
    		if (r > n) {
    			return 0;
    		}

    		return (int)((fact[n] * ifact[n -r]) % MOD);
    	}

    	// ???????
    	// ???n????????????r????????
    	// 0?????????
    	int H(int n, int r) {
    		if (n == 0 && r == 0) {
    			return 1;
    		}

    		return C(n + r - 1, r);
    	}

    	// ?????(n??????)
    	//   O(r)???????????r?size??????
    	int C2(long n, int r) {
    		long ret = ifact[r];
    		for (int i = 1; i <= r; i++) {
    			long tmp = (n - r + i) % MOD;
    			ret = (ret * tmp) % MOD;
    		}

    		return (int)ret;
    	}

    	// ?2????????
    	// n??????r??????????(??????????)
    	// ?????????????r!S(n,r)???????????
    	// O(r log n)
    	int S(long n, int r) {
    		//????????????????????1/r!?????
    		long ret = 0;
    		for (int i = 1; i <= r; i++) {
    			long tmp = (r - i) % 2 == 0 ? 1 : -1;
    			tmp *= pow(i, n) * C(r, i) % MOD;
    			ret = (ret + tmp + MOD) % MOD;
    		}
    		ret = ret * ifact[r] % MOD;

    		return (int)ret;
    	}

    	long pow(int a, long n) {
    		long loop = n;
    		long ret = 1;
    		long x = a;
    		while (loop > 0) {
    			if (loop % 2 == 1) {
    				ret = ret * x % MOD;
    			}
    			x = x * x % MOD;
    			loop /= 2;
    		}

    		return ret;
    	}

    	// ?????
    	// ????????MOD??
		// ???n=66 : 66C33=7219428434016265740
    	private final static int LIMIT = 66;
    	private static int to;
    	private static long[][] cache;

    	static long CLong(int n, int r) {
    		if (r > n) {
    			return 0;
    		}

    		if (n > LIMIT) {
    			throw new IllegalArgumentException(Integer.toString(n));
    		}

    		if (cache == null) {
    			cache = new long[LIMIT + 1][];
    			cache[0] = new long[1];
    			cache[0][0] = 1;
    			to = 0;
    		}

    		if (cache[n] == null) {
    			for (int i = to + 1; i <= n; i++) {
    				cache[i] = new long[i + 1];
    				for (int j = 0; j <= i; j++) {
    					if (j == 0 || j == i) {
    						cache[i][j] = 1;
    					} else {
    						if (Long.MAX_VALUE - cache[i - 1][j - 1] < cache[i - 1][j]) {
    			    			throw new IllegalArgumentException("Overflow");
    						} else {
    							cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
    						}
    					}
    				}
    			}
    			to = n;
    		}

    		return cache[n][r];
    	}
    }

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		private boolean isPrintable(int ch) {
			return ch >= '!' && ch <= '~';
		}

		private boolean isCRLF(int ch) {
			return ch == '\n' || ch == '\r' || ch == -1;
		}

		private int nextPrintable() {
			try {
				int ch;
				while (!isPrintable(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}

				return ch;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		String next() {
			try {
				int ch = nextPrintable();
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (isPrintable(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		int nextInt() {
			try {
				// parseInt from Integer.parseInt()
				boolean negative = false;
				int res = 0;
				int limit = -Integer.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Integer.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				int multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		long nextLong() {
			try {
				// parseLong from Long.parseLong()
				boolean negative = false;
				long res = 0;
				long limit = -Long.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Long.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				long multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				int ch;
				while (isCRLF(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (!isCRLF(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new NoSuchElementException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}