import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	static class ModuloCombinatorics {
		/** maximal needed number, N itself is included **/
		final int N;

		/** prime modulo **/
		final int P;

		/** factorials **/
		final int[] fact;

		/** multiplicative inverses, take care to not touch inv[0] **/
		final int[] inv;

		/** inverse factorials **/
		final int[] invFact;

		public ModuloCombinatorics(int N, int P) {
			this.N = N;
			this.P = P;
			fact = new int[N + 1];
			fact[0] = 1;
			for (int i = 1; i <= N; i++) {
				fact[i] = (int) ((long) i * fact[i - 1] % P);
			}

			inv = new int[N + 1];
			inv[1] = 1;
			for (int i = 2; i <= N; i++) {
				inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
			}

			invFact = new int[N + 1];
			invFact[0] = 1;
			for (int i = 1; i <= N; i++) {
				invFact[i] = (int) ((long) invFact[i - 1] * inv[i] % P);
			}
		}

		public int choose(int n, int k) {
			return (n < 0 || k < 0 || k > n) ? 0 : (int) ((long) fact[n]
					* invFact[k] % P * invFact[n - k] % P);
		}

		/** a^b modulo mod, mod is arbitrary **/
		static public int pow(int a, long b, int mod) {
			if (a < 0 || a >= mod || b < 0) {
				throw new IllegalArgumentException();
			}
			int ret = 1;
			for (; b > 0; b >>= 1) {
				if ((b & 1) == 1) {
					ret = (int) ((long) ret * a % mod);
				}
				a = (int) ((long) a * a % mod);
			}
			return ret;
		}

		/** a^b modulo P **/
		public int pow(int a, long b) {
			return pow(a, b, P);
		}
	}

	static final int P = 1_000_000_007;

	ModuloCombinatorics mc = new ModuloCombinatorics(1_000_010, P);

	int fast(int n) {
		if (n < 5) {
			return slow(n);
		}

		int diff = n - 2;

		long ret = 0;

		for (int twos = diff / 2; twos >= 0; twos--) {
			int ones = diff - twos * 2;

			long total = (long) mc.choose(ones + twos, ones)
					* (ones + twos - 1) % P;

			long total11;
			if (ones < 2) {
				total11 = 0;
			} else {
				total11 = (long) mc.choose(ones + twos - 2, ones - 2)
						* (ones + twos - 1) % P;
			}

			total -= total11;
			if (total < 0) {
				total += P;
			}

			// but those on the edge can be two
			total += 2 * mc.choose(ones + twos, ones) % P;

			int len = ones + twos + 1;

			ret += total * mc.fact[len - 1] % P * mc.fact[n - 1 - len] % P
					* len % P;
		}

		return (int) (ret % P);
	}

	int slow(int n) {
		int[] p = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			p[i] = i;
		}

		int ret = 0;

		do {
			int[] done = new int[n];
			int left = n;

			for (int v : p) {
				if (left != 0) {
					ret++;
				}
				left -= (1 - done[v]) + (1 - done[v + 1]);
				done[v] = done[v + 1] = 1;
			}
		} while (nextPermutation(p));

		return ret;
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr <= 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	void submit() {
		out.println(fast(nextInt()));
	}

	void test() {
		for (int n = 2; n <= 12; n++) {
			System.err.println(slow(n) + " " + fast(n));
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