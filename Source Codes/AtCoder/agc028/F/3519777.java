import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	void submit() {
		int n = nextInt();
		int[][] a = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j) == '#' ? 0 : s.charAt(j) - '0';
			}
		}

		int[][] dp = new int[n + 1][n + 1];
		int[][] left = new int[n + 1][n + 1];
		int[][] right = new int[n + 1][n + 1];

		for (int i = 0; i <= n; i++) {
			Arrays.fill(left[i], n);
			Arrays.fill(right[i], -1);
		}

		long ans = 0;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {

				if (a[i][j] == 0) {

					for (int k = i; k < n; k++) {
						left[j][k] = n;
						right[j][k] = -1;
					}

					continue;
				}

				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];

				// do shit

				if (a[i + 1][j] != 0 && a[i][j + 1] != 0) {
					int delta = 0;
					int last = -1;
					for (int k = i + 1; k < n; k++) {
						if (right[j][k] >= left[j + 1][k]
								&& left[j + 1][k] > last) {
							delta += dp[k][left[j + 1][k]];
						}
						last = right[j][k];
					}
					dp[i][j] -= delta;
				}

				left[j][i] = right[j][i] = j;

				for (int k = i; k < n; k++) {
					left[j][k] = Math.min(left[j][k], left[j + 1][k]);
					right[j][k] = Math.max(right[j][k], right[j + 1][k]);
				}

				ans += (long) dp[i][j] * a[i][j];
				dp[i][j] += a[i][j];

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