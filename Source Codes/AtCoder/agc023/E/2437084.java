import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

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

		int inverse(int x) {
			return x <= N ? inv[x] : P
					- (int) ((long) (P / x) * inverse(P % x) % P);
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

	ModuloCombinatorics mc = new ModuloCombinatorics(100_000, P);
	int inv2 = mc.inverse(2);

	int solve(int[] a) {
		int n = a.length;
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[a[i]]++;
		}

		for (int i = n - 2; i >= 0; i--) {
			c[i] += c[i + 1] - 1;
		}

		for (int x : c) {
			if (x <= 0) {
				return 0;
			}
		}

		int[] d = new int[n];
		int[] z = new int[n];
		for (int i = 0; i < n; i++) {
			int prv = i == 0 ? 1 : d[i - 1];
			int mlt = (int) ((long) (c[i] - 1) * mc.inv[c[i]] % P);
			int dz;
			if (mlt == 0) {
				dz = 1;
				mlt = 1;
			} else {
				dz = 0;
			}
			z[i] = dz + (i == 0 ? 0 : z[i - 1]);
			d[i] = (int) ((long) prv * mlt % P);
		}

		int k = z[n - 1] + 1;

		List<Integer>[] ids = new List[k];
		for (int i = 0; i < k; i++) {
			ids[i] = new ArrayList<>();
		}

		int[] whereIdx = new int[n];

		for (int i = 0; i < n; i++) {
			ids[z[a[i]]].add(i);
			whereIdx[i] = ids[z[a[i]]].size() - 1;
		}

		Integer[] order = IntStream.range(0, n).boxed().toArray(Integer[]::new);
		Arrays.sort(order, Comparator.comparing((Integer x) -> -a[x])
				.thenComparing(Comparator.reverseOrder()));

		int[][] fens = new int[k][];
		for (int i = 0; i < k; i++) {
			fens[i] = new int[ids[i].size()];
		}

		long ret = 0;
		// times #1/2 of perms

		int[][] fens2 = new int[k][];
		for (int i = 0; i < k; i++) {
			fens2[i] = new int[ids[i].size()];
		}

		int[] justFen = new int[n];

		long totalInv = 0;

		long bad = 0;

		for (int i : order) {
			int bin = z[a[i]];
			long denom = mc.inverse(d[a[i]]);

			{

				int idx = ids[bin].size() - 1 - whereIdx[i];

				ret += get(fens[bin], idx) * denom % P;

				add(fens[bin], idx, d[a[i]]);
			}

			{
				totalInv += get(justFen, i);
				add(justFen, i, 1);

				int idx = whereIdx[i];
				bad += get(fens2[bin], idx) * denom % P;
				add(fens2[bin], idx, d[a[i]]);
			}

		}

		ret %= P;
		bad %= P;

		bad = bad * inv2 % P;
		bad = Math.floorMod(totalInv - bad, P);

		ret = ret * inv2 % P;

		ret += bad;
		if (ret >= P) {
			ret -= P;
		}

		for (int x : c) {
			ret = ret * x % P;
		}

		return (int) ret;
	}

	int slow(int[] a) {
		int n = a.length;
		int[] p = IntStream.range(0, n).toArray();
		int ans = 0;
		outer: do {
			for (int i = 0; i < n; i++) {
				if (p[i] > a[i]) {
					continue outer;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (p[i] > p[j]) {
						ans++;
					}
				}
			}
		} while (nextPermutation(p));
		return ans;
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

	void add(int[] fen, int pos, int delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
			if (fen[i] >= P) {
				fen[i] -= P;
			}
		}
	}

	int get(int[] fen, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return (int) (ret % P);
	}

	void test() {
		System.err.println(solve(new int[] { 3, 3, 2, 3 }));
		System.err.println(slow(new int[] { 3, 3, 2, 3 }));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(0, n - 1);
			}
			System.err.println(Arrays.toString(a));
			if (solve(a) != slow(a)) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}
	
	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}
		out.println(solve(a));
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
	static final int C = 9;

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