import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

	private static long mod = 1000000000 + 7;

	public static void main(String[] args) {
		 FastScanner sc = new FastScanner();
		 int N = sc.nextInt();
		 int K = sc.nextInt();
		 
		 long[] divs = enumDiv(N);
		 long[] dp = new long[2000];

		 long ret = 0;
		 for (int i = 0; i < divs.length; i ++) {
			 dp[i] = powMod(K, (divs[i] + 1) / 2, mod);
			 
			 for (int j = 0; j < i; j ++) {
				 if (divs[i] % divs[j] == 0) {
					 dp[i] += mod - dp[j];
					 dp[i] %= mod;
				 }
			 }

			 if (divs[i] % 2 == 0) {
				 ret += dp[i] * divs[i] / 2;
			 } else {
				 ret += dp[i] * divs[i];
			 }
			 ret %= mod;
		 }

		 System.out.println(ret);
		
	}

	private static long[] enumDiv(long n) {
		long[] ret = new long[2000];
		int ptr = 0;

		for (long i = 1; i * i <= n; i ++) {
			if (n % i == 0) {
				ret[ptr ++] = i;
				
				if (i * i != n) {
					ret[ptr ++] = n / i;
				}
			}
		}
		ret = Arrays.copyOf(ret, ptr);
		Arrays.sort(ret);
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