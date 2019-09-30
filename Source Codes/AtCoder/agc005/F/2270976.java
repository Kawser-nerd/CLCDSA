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

	static class CompV {

		double[] re, im;

		void add(CompV o) {
			for (int i = 0; i < re.length; i++) {
				re[i] += o.re[i];
				im[i] += o.im[i];
			}
		}

		static CompV times(CompV a, CompV b) {
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			double[] re = new double[aRe.length];
			double[] im = new double[aRe.length];

			for (int i = 0; i < aRe.length; i++) {
				re[i] = aRe[i] * bRe[i] - aIm[i] * bIm[i];
				im[i] = aRe[i] * bIm[i] + aIm[i] * bRe[i];
			}

			return new CompV(re, im);
		}

		static CompV plus(CompV a, CompV b) {
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			double[] re = new double[aRe.length];
			double[] im = new double[aRe.length];

			for (int i = 0; i < aRe.length; i++) {
				re[i] = aRe[i] + bRe[i];
				im[i] = aIm[i] + bIm[i];
			}

			return new CompV(re, im);
		}

		/**
		 * @return a + bi
		 */
		static CompV packFFT(CompV a, CompV b) {
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			double[] re = new double[aRe.length];
			double[] im = new double[aRe.length];
			for (int i = 0; i < aRe.length; i++) {
				re[i] = aRe[i] - bIm[i];
				im[i] = aIm[i] + bRe[i];
			}
			return new CompV(re, im);
		}

		/**
		 * for real-valued a and b restores FFT(a) and FFT(b) from FFT(a + bi)
		 */
		void unpackFFT(CompV a, CompV b) {
			int n = re.length;
			double[] aRe = a.re;
			double[] aIm = a.im;
			double[] bRe = b.re;
			double[] bIm = b.im;
			for (int i = 0; i < n; i++) {
				int j = i == 0 ? 0 : n - i;
				aRe[i] = (re[i] + re[j]) * 0.5;
				aIm[i] = (im[i] - im[j]) * 0.5;
				bRe[i] = (im[i] + im[j]) * 0.5;
				bIm[i] = (re[j] - re[i]) * 0.5;
			}
		}

		public CompV(double[] re, double[] im) {
			this.re = re;
			this.im = im;
		}

		public CompV(int len) {
			re = new double[len];
			im = new double[len];
		}
	}

	static final int L = (int) Math.sqrt(P);
	static final int L2 = L * L;

	public static int[] multFaster(int[] a, int[] b) {
		int len = nextPowerOf2(a.length + b.length - 1);

		double[] p1 = new double[len];
		double[] q1 = new double[len];
		for (int i = 0; i < a.length; i++) {
			p1[i] = a[i] % L;
			q1[i] = a[i] / L;
		}

		double[] p2 = new double[len];
		double[] q2 = new double[len];
		for (int i = 0; i < b.length; i++) {
			p2[i] = b[i] % L;
			q2[i] = b[i] / L;
		}

		CompV p1p2Pack = new CompV(p1, p2);
		CompV q1q2Pack = new CompV(q1, q2);

		fft(p1p2Pack, false);
		fft(q1q2Pack, false);

		CompV fp1 = new CompV(len);
		CompV fp2 = new CompV(len);
		p1p2Pack.unpackFFT(fp1, fp2);

		CompV fq1 = new CompV(len);
		CompV fq2 = new CompV(len);
		q1q2Pack.unpackFFT(fq1, fq2);

		CompV back0 = CompV.times(fp1, fp2);

		CompV back1 = CompV.times(fp1, fq2);
		back1.add(CompV.times(fq1, fp2));

		CompV back2 = CompV.times(fq1, fq2);

		CompV back01 = CompV.packFFT(back0, back1);

		fft(back01, true);
		fft(back2, true);

		int[] ret = new int[len];

		for (int i = 0; i < len; i++) {
			long v0 = Math.round(back01.re[i]) % P;
			long v1 = Math.round(back01.im[i]) % P * L % P;
			long v2 = Math.round(back2.re[i]) % P * L2 % P;
			ret[i] = (int) ((v0 + v1 + v2) % P);
		}

		return ret;
	}

	public static void fft(CompV v, boolean invert) {
		double[] a = v.re;
		double[] b = v.im;
		int n = a.length;
		int logN = Integer.numberOfTrailingZeros(n);
		prepareArrays(logN);
		int[] rev = rev2D[logN];

		for (int i = 0; i < n; i++) {
			int j = rev[i];
			if (i < j) {
				double t = a[i];
				a[i] = a[j];
				a[j] = t;
				t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
		}

		double conj = invert ? -1 : 1;

		for (int len = 2, row = 0; len <= n; len <<= 1, row++) {
			int halfLen = len >> 1;
			double[] multReArr = powRe[row];
			double[] multImArr = powIm[row];
			for (int i = 0; i < n; i += len) {
				
				for (int j1 = i, j2 = i + halfLen, k = 0; k < halfLen; j1++, j2++, k++) {
					double uA = a[j1];
					double uB = b[j1];

					double multRe = multReArr[k];
					double multIm = multImArr[k] * conj;

					double vA = a[j2] * multRe - b[j2] * multIm;
					double vB = a[j2] * multIm + b[j2] * multRe;
					a[j1] = uA + vA;
					b[j1] = uB + vB;
					a[j2] = uA - vA;
					b[j2] = uB - vB;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n; i++) {
				a[i] /= n;
				b[i] /= n;
			}
		}
	}

	static double[][] powRe = { { 1 } };
	static double[][] powIm = { { 0 } };
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

		int oldN = powRe.length;

		if (oldN >= n) {
			return;
		}

		powRe = Arrays.copyOf(powRe, n);
		powIm = Arrays.copyOf(powIm, n);

		for (int i = oldN; i < n; i++) {
			double angle = Math.PI / (1 << i);

			double multRe = Math.cos(angle);
			double multIm = Math.sin(angle);

			double[] toRe = powRe[i] = new double[1 << i];
			double[] toIm = powIm[i] = new double[1 << i];

			double[] fromRe = powRe[i - 1];
			double[] fromIm = powIm[i - 1];

			for (int j = 0; j < 1 << i; j += 2) {
				double re = fromRe[j >> 1];
				double im = fromIm[j >> 1];

				toRe[j] = re;
				toIm[j] = im;
				toRe[j + 1] = re * multRe - im * multIm;
				toIm[j + 1] = re * multIm + im * multRe;
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