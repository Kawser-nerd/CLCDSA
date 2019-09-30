import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	final long MODULO = (long) (1e9 + 7);
	int n;
	int m;
	int[] c;
	int[] l;
	int[] r;

	void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		int[] s = new int[n];
		char[] S = sc.next().toCharArray();
		l = new int[m];
		r = new int[n];
		for (int i = 0; i < n; ++i) {
			r[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			s[i] = (S[i] == '0' ? 0 : 1);
		}
		for (int i = 0; i < m; ++i) {
			l[i] = sc.nextInt();
			--l[i];
			r[l[i]] = Math.max(r[l[i]], sc.nextInt() - 1);
		}
		for (int i = 1; i < n; ++i) {
			r[i] = Math.max(r[i - 1], r[i]);
		}
		c = new int[n];
		for (int i = 0; i < n; ++i) {
			c[i] = (i > 0 ? c[i - 1] : 0) + s[i];
		}
		memo = new long[n][n];
		for (int i = 0; i < memo.length; ++i) {
			for (int j = 0; j < memo[i].length; ++j) {
				memo[i][j] = -1;
			}
		}
		System.out.println(f(0, c[r[0]]));
	}

	long[][] memo;

	long f(int l, int curC) {
		if (r[l] - (l - 1) < curC)
			return memo[l][curC] = 0;
		if (l == n - 1) {
			if (curC > 1)
				throw new AssertionError();
			return memo[l][curC] = 1;
		}
		if (memo[l][curC] != -1)
			return memo[l][curC];
		long ret = 0;
		if (!(r[l] - (l - 1 + 1) < curC)) {
			ret += f(l + 1, curC + c[r[l + 1]] - c[r[l]]);
		}
		if (!(curC == 0)) {
			ret += f(l + 1, curC - 1 + c[r[l + 1]] - c[r[l]]);
		}
		ret %= MODULO;
		return memo[l][curC] = ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}