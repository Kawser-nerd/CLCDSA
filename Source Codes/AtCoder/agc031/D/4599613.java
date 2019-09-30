import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int[] solve() {
		int n = nextInt();
		int b = nextInt() - 1;
		int[] p = new int[n];
		int[] q = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		for (int i = 0; i < n; i++) {
			q[i] = nextInt() - 1;
		}

		if (b == 0) {
			return p;
		}

		int k = (b - 1) / 6;

		int head, tail;
		int[] mid;

		if (b == 6 * k + 1) {
			head = tail = k;
			mid = q;
		} else if (b == 6 * k + 2) {
			head = tail = k;
			mid = mult(inv(p), q);
		} else if (b == 6 * k + 3) {
			head = tail = k;
			mid = mult(inv(q), mult(inv(p), q));
		} else if (b == 6 * k + 4) {
			head = k;
			tail = k + 1;
			mid = inv(q);
		} else if (b == 6 * k + 5) {
			head = k;
			tail = k + 1;
			mid = mult(inv(q), p);
		} else if (b == 6 * k + 6) {
			head = k;
			tail = k + 1;
			mid = mult(mult(inv(q), p), q);
		} else {
			throw new AssertionError();
		}

		// QpqP
		int[] headBlock = mult(mult(mult(inv(q), p), q), inv(p));

		int[] tailBlock = inv(headBlock);

		int[] ret = mult(mult(pow(headBlock, head), mid), pow(tailBlock, tail));

		return ret;
	}

	char flip(char c) {
		if (Character.isLowerCase(c)) {
			return Character.toUpperCase(c);
		} else {
			return Character.toLowerCase(c);
		}
	}

	String inverse(String a) {
		StringBuilder sb = new StringBuilder();
		for (int i = a.length() - 1; i >= 0; i--) {
			sb.append(flip(a.charAt(i)));
		}
		return sb.toString();
	}

	String simplify(String a) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < a.length(); i++) {
			// sb.append(flip(a.charAt(i)));
			if (sb.length() > 0
					&& flip(a.charAt(i)) == sb.charAt(sb.length() - 1)) {
				sb.deleteCharAt(sb.length() - 1);
			} else {
				sb.append(a.charAt(i));
			}
		}
		return sb.toString();
	}

	String f(String a, String b) {
		return simplify(inverse(a) + b);
	}

	int[] inv(int[] p) {
		int[] q = new int[p.length];
		for (int i = 0; i < p.length; i++) {
			q[p[i]] = i;
		}
		return q;
	}

	int[] mult(int[] a, int[] b) {
		int[] c = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			c[i] = b[a[i]];
		}
		return c;
	}

	int[] pow(int[] a, int b) {
		int[] ret = IntStream.range(0, a.length).toArray();
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = mult(ret, a);
			}
			a = mult(a, a);
		}
		return ret;
	}

	void test() {
		String[] a = new String[250];
		a[0] = "p";
		a[1] = "q";
		for (int i = 2; i < a.length; i++) {
			a[i] = f(a[i - 2], a[i - 1]);
		}

		for (int i = 0; i < a.length; i++) {
			// System.err.println(i + " " + a[i].length());
			// if (a[i].length() != i) {
			// System.err.println(i);
			// }
			// System.err.println(i + " " + a[i]);
			String s = a[i];
			int beg = 0;
			while (beg + 4 <= s.length()
					&& s.substring(beg, beg + 4).equals("QpqP")) {
				beg += 4;
			}
			// System.err.println(i + " " + s.substring(beg));

			int end = s.length();
			while (end - 4 >= 0 && s.substring(end - 4, end).equals("pQPq")) {
				end -= 4;
			}

			System.err.println(i + " " + beg / 4 + " " + (s.length() - end) / 4
					+ " " + s.substring(beg, end));
		}
	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}
	
	void submit() {
		int[] ans = solve();
		for (int x : ans) {
			out.print(x + 1 + " ");
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