import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		long A = sc.nextLong();
		long B = sc.nextLong();
		long M = sc.nextLong();

		long D = gcd(A, B);
		
		long[] rec1 = {10, 1};
		long[] rec2 = {powMod(10, D, M), 1};

		long[] init = {0};

		long a = rec(init, rec1, A, M);
		long b = rec(init, rec2, B / D, M);
		
		System.out.println(a * b % M);
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
	
	public static long gcd(long a, long b) {
		if (a > b) {
			long tmp = a;
			a = b;
			b = tmp;
		}
		while (a != 0) {
			long c = a;
			a = b % c;
			b = c;
		}
		return b;
	}
	
	

	public static long rec(long[] init, long[] arr, long k, long mod) {
		if (init.length == arr.length) {
			arr = Arrays.copyOf(arr, arr.length + 1);
		}
		int n = init.length;
		if (k < n) {
			return init[(int)k];
		}
		
		long[][] mat = new long[n + 1][n + 1];
		for (int i = 0; i < n - 1; i ++) {
			mat[i][i + 1] = 1;
		}
		for (int i = 0; i <= n; i ++) {
			mat[n - 1][i] = arr[i];
		}
		mat[n][n] = 1;
		
		mat = powMod(mat, k - n + 1, mod);
		long ret = 0;
		for (int i = 0; i < n; i ++) {
			ret += mat[n - 1][i] * init[i];
		}
		ret += mat[n - 1][n];
		return ret;
	}

	public static long[][] powMod(long[][] mat, long k, long mod) {
		int start = 63 - Long.numberOfLeadingZeros(k);
		int n = mat.length;

		long[][] answer = new long[n][n];
		for (int i = 0; i < n; i ++) {
			answer[i][i] = 1;
		}
		for (int i = start; i >= 0; i--) {
			
			answer = mul(answer, answer, mod);
			if (((k >> i) & 1L) == 1L) {
				answer = mul(answer, mat, mod);
			}
		}
		return answer;
	}
	
	public static long[][] mul(long[][] a, long[][] b, long mod) {
		int n = a.length;
		long[][] ret = new long[n][n];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				for (int k = 0; k < n; k ++) {
					ret[i][j] += a[i][k] * b[k][j];
					ret[i][j] %= mod;
				}
			}
		}
		return ret;
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