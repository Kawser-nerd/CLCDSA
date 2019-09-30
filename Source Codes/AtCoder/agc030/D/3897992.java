import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	static final int P = 1_000_000_007;
	static final long INV2 = (P + 1) / 2;

	void submit() {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[][] dp = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = a[i] > a[j] ? 1 : 0;
			}
		}

		int[] tmp1 = new int[n];
		int[] tmp2 = new int[n];

		int initQ = q;

		while (q-- > 0) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;

			int sum = (int) (INV2 * (dp[x][y] + dp[y][x]) % P);

			for (int i = 0; i < n; i++) {
				if (i != x && i != y) {
					// if (i != y) {
					// d_x[i] = (int) (INV2 * (dp[i][x] + dp[i][y]) % P);
					// dx_[i] = (int) (INV2 * (dp[x][i] + dp[y][i]) % P);
					tmp1[i] = (int) (INV2 * (dp[i][x] + dp[i][y]) % P);
					tmp2[i] = (int) (INV2 * (dp[x][i] + dp[y][i]) % P);
					// } else {
					// d_x[i] = dx_[i] = sum;
					// }
				}
			}

			for (int i = 0; i < n; i++) {
				if (i == x || i == y) {
					continue;
				}
				dp[i][x] = dp[i][y] = tmp1[i];
				dp[x][i] = dp[y][i] = tmp2[i];
			}

			dp[x][y] = dp[y][x] = sum;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += dp[i][j];
				if (ans >= P) {
					ans -= P;
				}
			}
		}

		for (int i = 0; i < initQ; i++) {
			ans *= 2;
			if (ans >= P) {
				ans -= P;
			}
		}

		out.println(ans);
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}