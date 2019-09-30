import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		char[] w = sc.next().toCharArray();
		int n = w.length;

		char c = w[0];
		boolean flg = false;
		for (int i = 1; i < n; i ++) {
			if (c != w[i]) {
				flg = true;
				break;
			}
		}
		if (!flg) {
			System.out.println(n);
			System.out.println(1);
			return;
		}
		
		char[] rw = new char[n];
		for (int i = 0; i < n; i ++) {
			rw[i] = w[n - i - 1];
		}

		boolean[] g = calc(w);
		boolean[] rg = calc(rw);

		if (g[n]) {
			System.out.println(1);
			System.out.println(1);
			return;
		} else {
			int ans = 0;
			for (int i = 1; i < n; i ++) {
				if (g[i] && rg[n - i]) {
					ans ++;
				}
			}
			System.out.println(2);
			System.out.println(ans);
		}
	}
	
	private static boolean[] calc(char[] str) {
		int n = str.length;
		int[] z = z(str);
		
		boolean[] G = new boolean[n + 1];
		Arrays.fill(G, true);
		for (int p = 1; p < n; p ++) {
			for (int k = 2; (k - 1) * p <= z[p]; k ++) {
				G[k * p] = false;
			}
		}
		return G;
	}
	
	public static int[] z(char[] str) {
		int n = str.length;
		int[] A = new int[n];
		A[0] = n;
		int i = 1, j = 0;
		while (i < n) {
			while (i + j < n && str[j] == str[i + j])
				++j;
			A[i] = j;
			if (j == 0) {
				++i;
				continue;
			}
			int k = 1;
			while (i + k < n && k + A[k] < j) {
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