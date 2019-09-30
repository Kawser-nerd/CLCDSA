import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {

	private static int mod = 1000000000 + 7;
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		if (K == 1) {
			System.out.println(1);
			return;
		} else {
			int[][] fif = enumFIF(4000005, mod);
			
			long[][] dp = new long[N + 1][N + 1];
			dp[0][0] = 1L;
			for (int i = 0; i <= N; i ++) {

				for (int j = i; j <= N; j ++) {
					if (i > 0)
						dp[i][j] += dp[i - 1][j];
					if (j > 0) {
						dp[i][j] += C(i + (K - 1) * j - 1, K - 2, mod, fif) * dp[i][j - 1];
					}
					dp[i][j] %= mod;
				}
			}
			
			long ans = dp[N][N];
			
			for(long i = 1; i <= N; i ++) {
				ans = (ans * i) % mod;
			}
			System.out.println(ans);
		}

	}

	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}
	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
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
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}