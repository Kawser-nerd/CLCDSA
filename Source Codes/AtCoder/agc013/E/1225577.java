import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();

	}

	final long MODULO = 1_000_000_000 + 7;
	final long[][] A = { { 1, 0, 1 }, { 2, 1, 2 }, { 1, 1, 2 } };
	final long[][] B = { { 1, 0, 0 }, { 2, 1, 0 }, { 1, 1, 1 } };

	void solve(long n, int m, int[] x) {
		long[][] a = { { 1 }, { 2 }, { 1 } };
		if (m == 0)
			a = mul(pow(A, n - 1), a);
		else {
			a = mul(pow(A, x[0] - 1), a);
			a = mul(B, a);
		}
		for (int i = 1; i < m; ++i) {
			a = mul(pow(A, (x[i] - 1) - x[i - 1]), a);
			a = mul(B, a);
		}
		if (m > 0)
			a = mul(pow(A, (n - 1) - x[m - 1]), a);
		System.out.println(a[2][0]);
	}

	void run() throws IOException {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		int m = sc.nextInt();
		int[] x = new int[m];
		for (int i = 0; i < m; ++i) {
			x[i] = sc.nextInt();
		}
		solve(n, m, x);
	}

	long[][] mul(long[][] a, long[][] b) {
		long[][] ret = new long[a.length][b[0].length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < b[i].length; ++j) {
				for (int k = 0; k < a[i].length; ++k) {
					ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MODULO;
				}
			}
		}
		return ret;
	}

	long[][] pow(long[][] a, long n) {
		long[][] ret = new long[a.length][a.length];
		for (int i = 0; i < ret.length; ++i) {
			ret[i][i] = 1;
		}
		long[][] pow = new long[a.length][a.length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < a[i].length; ++j) {
				pow[i][j] = a[i][j];
			}
		}
		for (; n > 0; n >>= 1, pow = mul(pow, pow)) {
			if (n % 2 == 1) {
				ret = mul(ret, pow);
			}
		}
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}