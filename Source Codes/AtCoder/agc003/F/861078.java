import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {

	private static final long MOD = 1000000000 + 7;
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int H = sc.nextInt();
		int W = sc.nextInt();
		long K = sc.nextLong();
		
		char[][] s = new char[H][W];
		long black = 0;
		long wc = 0;
		long hc = 0;
		for (int i = 0; i < H; i ++) {
			String line = sc.next();
			for (int j = 0; j < W; j ++) {
				s[i][j] = line.charAt(j);
				if (s[i][j] == '#') {
					black ++;
					
					if (i > 0 && s[i - 1][j] == '#') {
						hc ++;
					} 
					if (j > 0 && s[i][j - 1] == '#') {
						wc ++;
					}
				}
			}
		}
		
		long he = 0;
		long we = 0;
		for (int i = 0; i < H; i ++) {
			if (s[i][0] == s[i][W - 1] && s[i][0] == '#') {
				we ++;
			}
		}
		for (int j = 0; j < W; j ++) {
			if (s[0][j] == s[H - 1][j] && s[0][j] == '#') {
				he ++;
			}
		}
		
		if (he > 0 && we > 0) {
			System.out.println(1);
			return;
		} else if (he == 0 && we == 0) {
			System.out.println(powMod(black, K - 1, MOD));
		} else {
			long a = black, b, c;
			if (he > 0) {
				b = hc;
				c = he;
			} else {
				b = wc;
				c = we;
			}
			
			long[] ret = powMod(2, new long[]{a, -b + MOD, 0, c}, K - 1);
			System.out.println((ret[0] + ret[1]) % MOD);
		}
	}
	
	public static long[] powMod(int n, long[] x, long k) {
		int m = 63 - Long.numberOfLeadingZeros(k);
		long[] answer = {1, 0, 0, 1};
		for (int i = m; i >= 0; i--) {
			answer = mul(n, answer, answer);
			if (((k >> i) & 1L) == 1L) {
				answer = mul(n, answer, x);
			}
		}
		return answer;
	}
	
	private static long[] mul(int n, long[] a, long[] b) {
		long[] ret = new long[n * n];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				for (int k = 0; k < n; k ++) {
					ret[i * n + j] += a[i * n + k] * b[k * n + j];
					ret[i * n + j] %= MOD;
				}
			}
		}
		return ret;
	}
	
	
	public static long powMod(long x, long k, long mod) {
		int n = 63 - Long.numberOfLeadingZeros(k);
		long answer = 1;
		for (int i = n; i >= 0; i--) {
			answer = (answer * answer) % mod;
			if (((k >> i) & 1L) == 1L) {
				answer = (answer * x) % mod;
			}
		}
		return answer;
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