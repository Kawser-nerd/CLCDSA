import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	int P;

	int pow(int a, int b, int mod) {
		long ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = ret * a % mod;
			}
			a = (int) ((long) a * a % mod);
		}
		return (int) ret;
	}

	void submit() {
		int n = nextInt();
		P = nextInt();

		int[][] dp = new int[n + 1][];
		dp[0] = new int[] { 1 };
		for (int i = 1; i <= n; i++) {
			dp[i] = new int[i + 1];
			for (int j = 0; j <= i; j++) {
				long tmp = 0;
				if (j != i) {
					tmp = (long) dp[i - 1][j] * (j + 1);
				}
				if (j != 0) {
					tmp += dp[i - 1][j - 1];
				}
				dp[i][j] = (int) (tmp % P);
			}
		}

		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int) ((long) i * fact[i - 1] % P);
		}

		long ans = 0;

		long[] pp2 = new long[n + 1];
		pp2[0] = 2;
		for (int i = 1; i <= n; i++) {
			pp2[i] = pp2[i - 1] * pp2[i - 1] % P;
		}

		long[] p2 = new long[n * n];
		p2[0] = 1;
		for (int i = 1; i < p2.length; i++) {
			p2[i] = 2 * p2[i - 1] % P;
		}

		for (int bad = 0; bad <= n; bad++) {
			long mult = (long) fact[n] * pow(fact[bad], P - 2, P) % P
					* pow(fact[n - bad], P - 2, P) % P;
			if ((bad & 1) == 1) {
				mult = P - mult;
			}

			long main = 0;
			for (int g = 0; g <= bad; g++) {

				main += p2[(n - bad) * g] * pp2[n - bad] % P * dp[bad][g] % P;

			}
			main %= P;

			ans += main * mult % P;
		}

		out.println(ans % P);

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