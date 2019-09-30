import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	void submit() {
		int n = nextInt();
		long c = nextLong();
		long[] xs = new long[n];
		int[] vs = new int[n];
		
		for (int i = 0; i < n; i++) {
			xs[i] = nextLong();
			vs[i] = nextInt();
		}
		
		long ans = go(xs, vs, c);
		
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			long t1 = xs[i];
			xs[i] = xs[j];
			xs[j] = t1;
			
			int t2 = vs[i];
			vs[i] = vs[j];
			vs[j] = t2;
		}
		
		for (int i = 0; i < n; i++) {
			xs[i] = c - xs[i];
		}
		
		out.println(Math.max(ans, go(xs, vs, c)));
	}
	
	long go(long[] xs, int[] vs, long c) {
		long tot = 0;
		for (int v : vs) {
			tot += v;
		}
		long ret = 0;
		
		long bestPref = 0;
		long allPref = 0;
		
		for (int i = 0; i < xs.length; i++) {
			// stay
			ret = Math.max(ret, tot - (c - xs[i]));
			
			// go back
			ret = Math.max(ret, tot - 2 * (c - xs[i]) + bestPref);
			
			tot -= vs[i];
			allPref += vs[i];
			bestPref = Math.max(bestPref, allPref - xs[i]);
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