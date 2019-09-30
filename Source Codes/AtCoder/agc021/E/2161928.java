import java.io.*;
import java.util.*;

public class Main {

	static final int P = 998244353;

	ModuloCombinatorics mc = new ModuloCombinatorics(1000000, P);

	int solve(int n, int k) {
		// System.err.println(n + " " + k);
		int ans = 0;

		for (int plus = 0; plus <= k; plus++) {
			int minus = k - plus;
			if (plus < minus || plus < n) {
				continue;
			}
			int same = Math.max(n - (plus - minus), 0);
			if (same > minus) {
				throw new AssertionError();
			}

			int maxNeg = minus - same;
			ans += go(plus, plus == minus ? minus - 1 : minus, maxNeg);
			if (ans >= P) {
				ans -= P;
			}
		}
		return ans;
	}

	int go(int p, int q, int bad) {
		int newSum = p + q;
		int newDiff = -2 * (bad + 1) - (p - q);
		int x = (newSum + newDiff) / 2;
		int y = (newSum - newDiff) / 2;
		int ret = mc.choose(p + q, p);
		if (x >= 0 && y >= 0) {
			ret -= mc.choose(x + y, x);
			if (ret < 0) {
				ret += P;
			}
		}
		return ret;
	}

	void submit() {
		out.println(solve(nextInt(), nextInt()));
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

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		solve(1, 3);
		for (int n = 1; n <= 10; n++) {
			for (int k = 1; k <= 10; k++) {
				solve(n, k);
			}
		}
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}