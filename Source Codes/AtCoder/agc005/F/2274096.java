import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	int[] next;
	int[] head;
	int[] to;

	int[] b;
	int n;

	void submit() {
		n = nextInt();
		// n = 9;

		next = new int[2 * n - 2];
		head = new int[n];
		to = new int[2 * n - 2];
		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			// int v = i;
			// int u = i + 1;

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		b = new int[n + 1];
		b[n] = n;
		dfs(0, 0);

		for (int i = 0; i < b.length; i++) {
			b[i] = Math.floorMod(b[i], P);
		}

		ModuloCombinatorics mc = new ModuloCombinatorics(n + 1, P);
		for (int i = 0; i <= n; i++) {
			b[i] = (int) ((long) b[i] * mc.fact[i] % P);
		}

		int[] c = new int[n + 1];
		for (int i = 0; i < c.length; i++) {
			c[i] = mc.invFact[i];
		}

		// System.err.println(Arrays.toString(reverse(b)));
		// System.err.println(Arrays.toString(c));
		int[] ans = multFaster(reverse(b), c);
		ans = reverse(Arrays.copyOf(ans, n + 1));
		// System.err.println(Arrays.toString(ans));
		for (int i = 1; i <= n; i++) {
			out.println((long) ans[i] * mc.invFact[i] % P);
		}
	}

	int[] reverse(int[] a) {
		int[] b = a.clone();
		for (int i = 0, j = b.length - 1; i < j; i++, j--) {
			int tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
		}
		return b;
	}

	static final int P = 924844033;

	static int nextPowerOf2(int x) {
		return x == 1 ? 1 : Integer.highestOneBit(x - 1) << 1;
	}

	static final int L = (int) Math.sqrt(P);
	static final int L2 = L * L;

	static double[][] foo(int[] intV, int len) {
		// pack into one complex vector
		double[] f = new double[len << 1];
		for (int i = 0; i < intV.length; i++) {
			f[i << 1] = intV[i] % L;
			f[i << 1 | 1] = intV[i] / L;
		}

		fft(f, false);

		// unpack
		double[] f1 = new double[len << 1];
		double[] f2 = new double[len << 1];

		// LEN MUST BE A POWER OF 2!!!
		int zzz = (len << 1) - 1;
		for (int i = 0; i < len << 1; i += 2) {
			int j = (-i) & zzz;
			f1[i] = .5 * (f[i] + f[j]);
			f1[i + 1] = .5 * (f[i + 1] - f[j + 1]);
			f2[i] = .5 * (f[i + 1] + f[j + 1]);
			f2[i + 1] = .5 * (f[j] - f[i]);
		}

		return new double[][] { f1, f2 };
	}

	public static int[] multFaster(int[] a, int[] b) {
		int len = nextPowerOf2(a.length + b.length - 1);
		int len2 = len << 1;

		double[][] fA = foo(a, len);
		double[][] fB = foo(b, len);

		double[][] invF = new double[2][len2];

		for (int ia = 0; ia < 2; ia++) {
			for (int ib = 0; ib < 2; ib++) {

				double[] r = invF[(ia + ib) >> 1];
				double[] p = fA[ia];
				double[] q = fB[ib];

				if (((ia + ib) & 1) == 0) {
					for (int i = 0; i < len2; i += 2) {
						r[i] += p[i] * q[i] - p[i + 1] * q[i + 1];
						r[i + 1] += p[i] * q[i + 1] + p[i + 1] * q[i];
					}

				} else {
					for (int i = 0; i < len2; i += 2) {
						r[i] -= p[i] * q[i + 1] + p[i + 1] * q[i];
						r[i + 1] += p[i] * q[i] - p[i + 1] * q[i + 1];
					}
				}

			}
		}

		fft(invF[0], true);
		fft(invF[1], true);

		int[] ret = new int[len];

		for (int i = 0; i < len2; i += 2) {
			long v0 = Math.round(invF[0][i]) % P;
			long v1 = Math.round(invF[0][i + 1]) % P * L % P;
			long v2 = Math.round(invF[1][i]) % P * L2 % P;
			ret[i >> 1] = (int) ((v0 + v1 + v2) % P);
		}

		return ret;
	}

	public static void fft(double[] v, boolean invert) {
		int n2 = v.length;
		int n = n2 >> 1;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = rev2D[logN];

		for (int i = 0; i < n2; i += 2) {
			int j = rev[i >> 1] << 1;
			if (i < j) {
				double t = v[i];
				v[i] = v[j];
				v[j] = t;
				t = v[i + 1];
				v[i + 1] = v[j + 1];
				v[j + 1] = t;
			}
		}

		double conj = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			double[] pow = pow2D[row];
			for (int i = 0; i < n; i += len) {
				for (int j1 = i << 1, j2 = j1 + len, k = 0; k < len; j1 += 2, j2 += 2, k += 2) {
					double uA = v[j1];
					double uB = v[j1 + 1];

					double mRe = pow[k];
					double mIm = pow[k + 1] * conj;

					double vA = v[j2] * mRe - v[j2 + 1] * mIm;
					double vB = v[j2] * mIm + v[j2 + 1] * mRe;

					v[j1] = uA + vA;
					v[j1 + 1] = uB + vB;
					v[j2] = uA - vA;
					v[j2 + 1] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n2; i++) {
				v[i] /= n;
			}
		}
	}

	static double[][] pow2D = { { 1, 0 } };
	static int[][] rev2D = {};

	static void prepareArrays(int n) {
		if (rev2D.length < n + 1) {
			rev2D = Arrays.copyOf(rev2D, n + 1);
		}

		if (rev2D[n] == null) {
			int[] tmp = rev2D[n] = new int[1 << n];
			for (int i = 0; i < (1 << n); i++) {
				tmp[i] = (tmp[i >> 1] >> 1) | ((i & 1) << (n - 1));
			}
		}

		int oldN = pow2D.length;

		if (oldN >= n) {
			return;
		}

		pow2D = Arrays.copyOf(pow2D, n);

		for (int i = oldN; i < n; i++) {
			double angle = Math.PI / (1 << i);

			double mRe = Math.cos(angle);
			double mIm = Math.sin(angle);

			double[] dst = pow2D[i] = new double[2 << i];
			double[] src = pow2D[i - 1];

			for (int j = 0; j < 1 << i; j += 2) {
				double re = src[j];
				double im = src[j + 1];

				dst[j << 1] = re;
				dst[j << 1 | 1] = im;
				dst[j << 1 | 2] = re * mRe - im * mIm;
				dst[j << 1 | 3] = re * mIm + im * mRe;
			}
		}
	}

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

	int dfs(int v, int p) {
		int ret = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u != p) {
				int sz = dfs(u, v);
				b[sz]--;
				b[n - sz]--;
				ret += sz;
			}
		}
		return ret;
	}

	void preCalc() {

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
		preCalc();
		// System.err.println(3 + 5 ^ 7);
		// System.err.println((3 + 5) ^ 7);
		// System.err.println(3 + (5 ^ 7));
		submit();
		// System.err.println(Arrays.toString(multFaster(new int[] { 1, 1 },
		// new int[] { 1, 0 })));
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