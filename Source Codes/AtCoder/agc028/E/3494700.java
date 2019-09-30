import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	static class RangeMax {
		int[] a;
		int n;

		public RangeMax(int n, int init) {
			this.n = n;
			a = new int[2 * n];
			Arrays.fill(a, init);
		}

		int get(int ql, int qr) {
			int res = Integer.MIN_VALUE;
			for (int l = ql + n, r = qr + n; l < r; l >>= 1, r >>= 1) {
				if ((l & 1) == 1) {
					res = Math.max(res, a[l++]);
				}
				if ((r & 1) == 1) {
					res = Math.max(res, a[--r]);
				}
			}
			return res;
		}

		void update(int p, int value) {
			p += n;

			// modify a[p] as needed
			a[p] = Math.max(a[p], value);

			for (/* a[p] = value */; p > 1; p >>= 1) {
				a[p >> 1] = Math.max(a[p], a[p ^ 1]);
			}
		}
		
		void set(int p, int value) {
			p += n;

			// modify a[p] as needed
			a[p] = value;

			for (/* a[p] = value */; p > 1; p >>= 1) {
				a[p >> 1] = Math.max(a[p], a[p ^ 1]);
			}
		}

	}

	void submit() {
		int n = nextInt();
		int[] p = new int[n];
		int[] inv = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
			inv[p[i]] = i;
		}

		RangeMax evenPos = new RangeMax(n, 0);
		RangeMax oddPos = new RangeMax(n, Integer.MIN_VALUE);

		boolean[] big = new boolean[n];
		int max = -1;
		int bigLeft = 0;
		for (int i = 0; i < n; i++) {
			max = Math.max(max, p[i]);
			big[i] = max == p[i];
			bigLeft += big[i] ? 1 : 0;
		}

		for (int val = n - 1; val >= 0; val--) {
			int pos = inv[val];
			
			int evenOld = evenPos.get(pos, n);
			int oddOld = oddPos.get(pos, n);
			
			if (big[pos]) {
				evenPos.update(pos, 2 + evenOld);
				oddPos.update(pos, 2 + oddOld);
			} else {
				evenPos.update(pos, 1 + oddOld);
				oddPos.update(pos, 1 + evenOld);
			}
		}
		
		RangeMax evenVal = new RangeMax(n, 0);
		RangeMax oddVal = new RangeMax(n, 0);
		
		for (int i = 0; i < n; i++) {
//			System.err.println(evenPos.get(i, i + 1) + " " + evenPos.get(i, i + 1));
			evenVal.set(p[i], evenPos.get(i, i + 1));
			oddVal.set(p[i], oddPos.get(i, i + 1));
		}
		
		int c0 = 0, c1 = 0;
		int m0 = -1, m1 = -1;
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < n; i++) {
			if (big[i]) {
				bigLeft--;
			}
			evenVal.set(p[i], Integer.MIN_VALUE);
			oddVal.set(p[i], Integer.MIN_VALUE);
			
			int newM0 = Math.max(m0, p[i]);
			int newC0 = c0 + (newM0 == p[i] ? 1 : 0);
			
			int need1 = newC0 - c1 + bigLeft;
			boolean can;
			if (need1 <= 0) {
				can = need1 == 0;
			} else {
				RangeMax use = (need1 % 2 == 0) ? evenVal : oddVal;
				can = use.get(m1 + 1, n) >= need1;
			}
			
			if (!can) {
				int need2 = c1 - newC0 + bigLeft;
				if (need2 <= 0) {
					can = need2 == 0;
				} else {
					RangeMax use = (need2 % 2 == 0) ? evenVal : oddVal;
					can = use.get(newM0 + 1, n) >= need2;
				}
			}
			
			if (can) {
				c0 = newC0;
				m0 = newM0;
				sb.append('0');
				continue;
			}
			
			if (i != 0) {
				sb.append('1');
				m1 = Math.max(m1, p[i]);
				c1 += m1 == p[i] ? 1 : 0;
				continue;
			}
			
			int newC1 = c1 + 1;
			int newM1 = Math.max(m1, p[i]);
			
			need1 = c0 - newC1 + bigLeft;
			can = false;
			if (need1 <= 0) {
				can = need1 == 0;
			} else {
				RangeMax use = (need1 % 2 == 0) ? evenVal : oddVal;
				can = use.get(newM1 + 1, n) >= need1;
			}
			
			if (!can) {
				int need2 = newC1 - c0 + bigLeft;
				if (need2 <= 0) {
					can = need2 == 0;
				} else {
					RangeMax use = (need2 % 2 == 0) ? evenVal : oddVal;
					can = use.get(m0 + 1, n) >= need2;
				}
			}
			
			if (can) {
				sb.append('1');
				m1 = Math.max(m1, p[i]);
				c1 += m1 == p[i] ? 1 : 0;				
			} else {
				out.println(-1);
				return;
			}
			
		}
		
		out.println(sb.toString());

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