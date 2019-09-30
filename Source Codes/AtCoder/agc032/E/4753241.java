import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int slow(int[] a, int m) {
		Arrays.sort(a);
		int n = a.length / 2;
		outer: for (int rgh = n; rgh >= 0; rgh--) {
			int ret = 0;
			for (int i = 0; i < rgh; i++) {
				int sum = a[2 * n - 1 - i] + a[2 * n - 1 - (2 * rgh - 1 - i)]
						- m;
				if (sum < 0) {
					continue outer;
				}
				ret = Math.max(ret, sum);
			}

			for (int i = 0; i < n - rgh; i++) {
				ret = Math.max(ret, a[i] + a[2 * (n - rgh) - 1 - i]);
			}
			return ret;
		}
		throw new AssertionError();
	}

	int fast(int[] a, int m) {
		int n = a.length / 2;

		Arrays.sort(a);

		int[] lft = new int[2 * n];

		for (int i = 2 * n - 1, j = 0; i >= 0; i--) {
			while (j < 2 * n && a[i] + a[j] < m) {
				j++;
			}
			lft[i] = j;
		}

		int maxRed = n;

		for (int red = 1; red <= n; red++) {
			int idx = 2 * n - red;
			if (lft[idx] >= idx) {
				maxRed = Math.min(maxRed, red - 1);
				break;
			}
			int val = (2 * n - idx + (2 * n - lft[idx]) - 1) / 2;
			maxRed = Math.min(maxRed, val);
			if (maxRed == red) {
				break;
			}
		}

		int ret = 0;
		for (int i = 0; i < n - maxRed; i++) {
			ret = Math.max(ret, a[i] + a[2 * (n - maxRed) - 1 - i]);
		}
		for (int i = 0; i < maxRed; i++) {
			ret = Math.max(ret, a[2 * n - 1 - i]
					+ a[2 * n - 1 - (2 * maxRed - 1 - i)] - m);
		}

		return ret;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			a[i] = nextInt();
		}
		out.println(fast(a, m));
	}

	void test() {
		int[] a = { 0, 1, 1, 1 };
		int m = 2;
		out.println(fast(a, m));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int m = rand(1, C);
			int[] a = new int[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				a[i] = rand(0, m - 1);
			}
			if (fast(a, m) != slow(a, m)) {
				System.err.println(Arrays.toString(a) + " " + m);
				System.err.println(fast(a, m));
				System.err.println(slow(a, m));
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
	static final int C = 20;

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