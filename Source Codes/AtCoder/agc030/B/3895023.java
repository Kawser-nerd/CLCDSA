import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	void submit() {
		int len = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		long ret = go(a, n, len);
		ret = Math.max(ret, a[n - 1]);
		ret = Math.max(ret, len - a[0]);

		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[n - 1 - i] = len - a[i];
		}

		ret = Math.max(ret, go(b, n, len));

		out.println(ret);
	}

	long go(int[] a, int n, int len) {
		int[] arr = new int[2 * n + 1];
		int ptr = 0;
		for (int i = 0; i < n; i++) {
			arr[ptr++] = a[i] - len;
		}
		arr[ptr++] = 0;
		for (int i = 0; i < n; i++) {
			arr[ptr++] = a[i];
		}

		long[] pref = new long[arr.length + 1];
		for (int i = 0; i < arr.length; i++) {
			pref[i + 1] = pref[i] + arr[i];
		}

		long ret = Long.MIN_VALUE;

		for (int l = 1; l < n; l++) {
			int totL = n - l;
			int totR = l;
			// going left

			// end left
			{
				int pickR = Math.min(totR, totL - 1);
				long one = pref[l + pickR + 1] - pref[l];
				long two = pref[l + n + 1] - pref[l + n + 1 - pickR];
				ret = Math.max(ret, 2 * (two - one) + arr[l]);
			}

			// end right
			{
				int pickR = Math.min(totR, totL);
				long one = pref[l + pickR] - pref[l];
				long two = pref[l + n + 1] - pref[l + n + 1 - pickR];
				ret = Math.max(ret, 2 * (two - one) - arr[l + n]);
			}

		}
		return ret;
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