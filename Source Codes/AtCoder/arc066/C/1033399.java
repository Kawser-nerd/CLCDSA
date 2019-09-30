import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();

		long[] A = new long[N + 1];
		long[] B = new long[N + 1];
		boolean[] p = new boolean[N + 1];
		p[1] = true;

		for (int i = 1; i <= N; i++) {
			if (i > 1) {
				p[i] = sc.next().equals("+");
			}
			A[i] = sc.nextLong();

			B[i] = A[i] * (p[i] ? 1 : -1);
		}

		long[][] dp = new long[N + 1][3];
		for (long[] v : dp) Arrays.fill(v, Long.MIN_VALUE / 2);
		dp[0][0] = 0;

		for (int i = 0; i < N; i++) {
			if (p[i + 1]) {
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][0] + A[i + 1]);
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][1] + A[i + 1]);
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][2] + A[i + 1]);

				dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][1] - A[i + 1]);
				dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][2] - A[i + 1]);

				dp[i + 1][2] = Math.max(dp[i + 1][2], dp[i][2] + A[i + 1]);

			} else {
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][0] - A[i + 1]);
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][1] - A[i + 1]);
				dp[i + 1][0] = Math.max(dp[i + 1][0], dp[i][2] - A[i + 1]);

				dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][0] - A[i + 1]);
				dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][1] + A[i + 1]);
				dp[i + 1][1] = Math.max(dp[i + 1][1], dp[i][2] + A[i + 1]);

				dp[i + 1][2] = Math.max(dp[i + 1][2], dp[i][1] + A[i + 1]);
				dp[i + 1][2] = Math.max(dp[i + 1][2], dp[i][2] + A[i + 1]);
			}
		}
		long max = Long.MIN_VALUE / 2;
		max = Math.max(dp[N][0], max);
		max = Math.max(dp[N][1], max);
		max = Math.max(dp[N][2], max);

		System.out.println(max);
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