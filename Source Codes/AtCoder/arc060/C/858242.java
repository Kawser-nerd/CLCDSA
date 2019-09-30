import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		long[] x = sc.nextLongList(N);
		long L = sc.nextLong();
		

		int[][] r = new int[36][N];
		
		for (int i = 0; i < N; i ++) {
			int left = i + 1;
			int right = N - 1;
			
			while (left <= right) {
				int j = (left + right) / 2;
				if (x[j] <= x[i] + L) {
					left = j + 1;
				} else {
					right = j - 1;
				}
			}
			
			r[0][i] = right;
		}
		
		for (int k = 0; k < 35; k ++) {
			for (int i = 0; i < N; i ++) {
				r[k + 1][i] = r[k][r[k][i]];
			}
		}

		StringBuilder sb = new StringBuilder();
		
		int Q = sc.nextInt();
		for (int i = 0; i < Q; i ++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			
			long left = 0;
			long right = 1000000000;
			while (left <= right) {
				long y = (left + right) / 2;
				
				int now = a;
				for (int k = 34; k >= 0; k --) {
					if (((y >> k) & 1) == 1) {
						now = r[k][now];
					}
				}
				if (now >= b) {
					right = y - 1;
				} else {
					left = y + 1;
				}
			}
			
			sb.append(left);
			sb.append("\n");
		}
		System.out.println(sb);
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