import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		int n = sc.nextInt();
		int a = sc.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}

		// x[i]??????j????k????????
		long[][] dp = new long[n + 1][n * 50 + 1];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j > 0; j--) {
				for (int k = n * 50; k >= x[i]; k--) {
					dp[j][k] += dp[j - 1][k - x[i]];
				}
			}
		}

		long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dp[i][a * i];
		}
		out.println(ans);
		out.flush();
	}

	static int dp(int i, int j) {
		return 1;
	}

}

class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (ptr < buflen) return true;
		else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) return false;
		}
		return true;
	}

	private byte readByte() {
		if (hasNextByte()) return buffer[ptr++];
		return -1;
	}

	private boolean isPrintableChar(byte c) {
		return '!' <= c && c <= '~';
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		byte b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public int nextInt() {
		if (!hasNext()) throw new NoSuchElementException();
		int n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) throw new NumberFormatException();
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

	public long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) throw new NumberFormatException();
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
}