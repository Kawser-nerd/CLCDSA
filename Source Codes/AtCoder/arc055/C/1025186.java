import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		char[] s = sc.next().toCharArray();
		int n = s.length;
		char[] rs = Arrays.copyOf(s, n);
		rev(rs);


		int[] z = z(s);
		int[] rz = z(rs);
		long ret = 0;
		
		for (int i = 1; i < n; i ++) {
			if (i > n - i) {
				int a = z[i];
				int c = rz[n - i];
	
				int x = Math.min(n - i - 1, a);
				int y = Math.min(n - i - 1, c);
				
				if (x < 1 || y < 1) continue;
				if (x + y >= n - i) {
					ret += Math.min(x + y - (n - i) + 1, (n - i - 1));
				}
			}
			
		}
		System.out.println(ret);
	}
	
	private static void rev(char[] a) {
		for (int i = 0, j = a.length - 1; i < j; i ++, j --) {
			char c = a[i];
			a[i] = a[j];
			a[j] = c;
		}
	}

	public static int[] z(char[] str) {
		int[] A = new int[str.length];
		A[0] = str.length;
		int i = 1, j = 0;
		while (i < str.length) {
			while (i + j < str.length && str[j] == str[i + j])
				++j;
			A[i] = j;
			if (j == 0) {
				++i;
				continue;
			}
			int k = 1;
			while (i + k < str.length && k + A[k] < j) {
				A[i + k] = A[k];
				++k;
			}
			i += k;
			j -= k;
		}
		return A;
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