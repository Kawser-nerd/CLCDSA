import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int[] x = sc.nextIntList(N);
		int M = sc.nextInt();
		long K = sc.nextLong();
		int[] a = sc.nextIntList(M);
		a = Arrays.stream(a).map(v -> v - 1).toArray();

		//E'[x_{a_i}] = 1/2(E[2 * x_{a_i-1} - x_{a_i}] + E[2 * x_{a_i+1} - x_{a_i}])
		//E'[x_{a_i}] = E[x_{a_i-1}] + E[x_{a_i+1}] - E[x_{a_i}]
	
		double[] y = new double[N];
		for (int i = 0; i < N; i ++) {
			y[i] = x[i];
		}

		double[] dy = new double[N - 1];
		for (int i = 0; i < N - 1; i ++) {
			dy[i] = y[i + 1] - y[i];
		}

		int[] v = new int[N - 1];
		int[] to = new int[N - 1];
		for (int i = 0; i < N - 1; i ++) {
			v[i] = i;
			to[i] = i;
		}
		for (int b : a) {
			int tmp = v[b];
			v[b] = v[b - 1];
			v[b - 1] = tmp;
			
		}

		for (int i = 63 - Long.numberOfLeadingZeros(K); i >= 0; i--) {
			to = mul(to, to);
			if (((K >> i) & 1L) == 1L) {
				to = mul(to, v);
			}
		}
		dy = mul(to, dy);
		
		for (int i = 1; i < N; i ++) {
			y[i] = dy[i - 1] + y[i - 1];
		}
		StringBuilder sb = new StringBuilder();
		for (double d : y) {
			sb.append(String.format("%.9f%n", d));
		}
		System.out.println(sb);
	}

	private static int[] mul(int[] a, int[] b) {
		int n = a.length;
		int[] ret = new int[n];
		for (int i = 0; i < n; i ++) {
			ret[i] = a[b[i]];
		}
		return ret;
	}

	private static double[] mul(int[] a, double[] dy) {
		int n = a.length;
		double[] ret = new double[n];
		for (int i = 0; i < n ; i ++) {
			ret[i] = dy[a[i]];
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