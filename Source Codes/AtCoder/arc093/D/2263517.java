import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

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

		if (ptr == 0) {
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

	static final int P = 1_000_000_007;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	int solve(int n, int[] a) {
		int ans = 0;

		int[] dp = new int[1 << n];
		dp[0] = 1;
		for (int i = a.length - 1; i >= 0; i--) {
			int x = a[i];
			for (int mask = (1 << n) - 1; mask >= 0; mask--) {
				for (int j = 0; j < n; j++) {
					if (test(mask, j)) {
						continue;
					}
					int free = (1 << n) - 1 - x - mask;
					int take = (1 << j) - 1;
					if (take > free) {
						continue;
					}
					dp[mask | (1 << j)] += (int) ((long) fact[free]
							* invFact[take] % P * invFact[free - take] % P
							* dp[mask] % P);
					if (dp[mask | (1 << j)] >= P) {
						dp[mask | (1 << j)] -= P;
					}
				}
			}
		}

		int[] rest = new int[1 << n];
		for (int i = 0; i < (1 << n); i++) {
			rest[i] = fact[i];
			for (int j = 0; j < n; j++) {
				if (test(i, j)) {
					rest[i] = (int) ((long) rest[i] * invFact[1 << j] % P);
				}
			}
		}

		int all = (1 << n) - 1;

		for (int i = 1; i < 1 << n; i++) {
			int delta = (int) ((long) rest[all ^ i] * dp[i] % P);
			if (Integer.bitCount(i) % 2 == 1) {
				ans += delta;
				if (ans >= P) {
					ans -= P;
				}
			} else {
				ans -= delta;
				if (ans < 0) {
					ans += P;
				}
			}
		}

		ans = (int) ((long) ans * (1 << n) % P);
		for (int i = 0; i < n; i++) {
			ans = (int) ((long) ans * fact[1 << i] % P);
		}

		int total = fact[1 << n];

		ans = total - ans;
		if (ans < 0) {
			ans += P;
		}
		return ans;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt() - 1;
		}
		out.println(solve(n, a));
	}

	int[] fact;
	int[] invFact;

	void preCalc() {
		ModuloCombinatorics mc = new ModuloCombinatorics((1 << 16) + 10, P);
		fact = mc.fact;
		invFact = mc.invFact;
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

	void test() {
		boolean[] bad = new boolean[8];
		bad[2] = bad[3] = bad[6] = true;

		int[] p = new int[8];
		for (int i = 0; i < 8; i++) {
			p[i] = i;
		}

		int ret = 0;

		int[] arr = new int[8];

		do {
			int[] tmp = p.clone();
			int where = 0;
			while (p[where] != 0) {
				where++;
			}
			while (tmp.length > 1) {
				int[] nxt = new int[tmp.length / 2];
				for (int i = 0; i < tmp.length; i += 2) {
					nxt[i / 2] = win(tmp[i], tmp[i + 1], bad);
				}
				tmp = nxt;
			}
			if (tmp[0] == 0) {
				ret++;
				arr[where]++;
			}
		} while (nextPermutation(p));
		System.err.println(ret);
		System.err.println(Arrays.toString(arr));
	}

	int win(int p1, int p2, boolean[] bad) {
		if (p1 > p2) {
			int tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		if (p1 == 0) {
			return bad[p2] ? p2 : 0;
		}
		return p1;
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