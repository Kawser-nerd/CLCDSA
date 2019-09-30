import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	int solve(int[] a, int[] p, int c) {
		int n = a.length;
		int[][] dp = new int[1 << (n - 1)][c * n + 1];
		dp[0][n * a[n - 1]] = 1;

		for (int i = 0; i < c * n; i++) {
			
//			System.err.println(Arrays.deepToString(dp));

			for (int mask = (1 << (n - 1)) - 1; mask >= 0; mask--) {
				for (int ok = i; ok <= c * n; ok++) {
					if (dp[mask][ok] == 0) {
						continue;
					}

					if (i % n != 0) {
						int who = p[i % n - 1];
						if (!test(mask, who)) {
							dp[mask | (1 << who)][Math.min(
									Math.max(ok, i + n * a[who]), c * n)] += dp[mask][ok];
						}
					}

				}
			}
		}

		return dp[(1 << (n - 1)) - 1][c * n];
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void submit() {
		int n = nextInt();
		int c = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);

		int[] p = new int[n - 1];
		for (int i = 0; i < p.length; i++) {
			p[i] = i;
		}

		long good = 0;
		long total = 0;
		long one = BigInteger.valueOf(c).pow(n - 1).intValueExact();

		do {
			good += solve(a, p, c);
			total += one;
		} while (nextPermutation(p));

		out.println(1.0 * good / total);
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

	void preCalc() {

	}

	void stress() {

	}

	void test() {

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