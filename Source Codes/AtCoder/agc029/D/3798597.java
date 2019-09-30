import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	void submit() {
		int r = nextInt();
		int c = nextInt();
		int n = nextInt();
		
		ArrayList<Integer>[] bad = new ArrayList[r];
		for (int i = 0; i < r; i++) {
			bad[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			if (y > x) {
				continue;
			}
			bad[x].add(y);
		}
		
		bs = new long[6000];
		set(0);
		
		for (int i = 1; i < r; i++) {
			for (int pos : bad[i]) {
				if (get(pos) == 1) {
					out.println(i);
					return;
				}
			}
			
			int nBits = Math.min(c, i + 1);
			int ns = (nBits + MASK) >> LOG;
			for (int j = ns - 1; j >= 0; j--) {
				bs[j] |= getWord((j << LOG) - 1);
			}
			
			unset(c);
			for (int pos : bad[i]) {
				unset(pos);
			}
		}
		
		out.println(r);
	}
	
	long[] bs;
	
//	static class BitsetLong {

		static final int LOG = 6;
		static final int SIZE = 1 << LOG;
		static final int MASK = SIZE - 1;

//		private long[] data;

//		public BitsetLong(int n) {
//			data = new long[(n >> LOG) + 2];
//		}

		void set(int i) {
			bs[i >> LOG] |= 1L << (i & MASK);
		}

		void unset(int i) {
			bs[i >> LOG] &= ~(1L << (i & MASK));
		}

		void flip(int i) {
			bs[i >> LOG] ^= 1L << (i & MASK);
		}

		int get(int i) {
			return (int) ((bs[i >> LOG] >>> (i & MASK)) & 1);
		}

		/**
		 * bits [i; i + SIZE) of infinite array with this bitset starting at 0
		 */
		long getWord(int i) {
			if (i <= -SIZE || (i >> LOG) + 1 >= bs.length) {
				return 0;
			}
			int rem = i & MASK;
			int idx = i >> LOG;

			if (rem == 0) {
				return bs[idx];
			}

			long head = idx < 0 ? 0 : (bs[idx] >>> rem);
			long tail = bs[idx + 1] << (SIZE - rem);

			return head | tail;
		}
//	}

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.