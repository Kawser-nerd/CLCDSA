import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	public void run() {
		solver();
	}

	void solver() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		long[] a = new long[n];
		long[] sum = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
			sum[i] = (i > 0 ? sum[i - 1] : 0) + a[i];
		}
		if (sum[n - 1] == k) {
			System.out.println(1);
			return;
		}
		long INF = Long.MAX_VALUE / 3;
		long[][] f = new long[n][n];
		for (int i = 0; i < f.length; ++i) {
			for (int j = 0; j < f[i].length; ++j) {
				f[i][j] = INF;
			}
		}
		// f[i][j]:=??i?j+1???????????????
		f[0][0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				f[i][j] = Math.min(f[i][j], f[i - 1][j]);
			}
			for (int j = 1; j < n; ++j) {
				if (f[i - 1][j - 1] == INF)
					continue;
				// f[i-1][j-1] / sum[i-1] < x / sum[i]
				// f[i-1][j-1]/sum[i-1]*sum[i] + 1=x
				long x = f[i - 1][j - 1] * sum[i] / sum[i - 1] + 1;
				while (f[i - 1][j - 1] * sum[i] >= x * sum[i - 1])
					++x;
				if (x - f[i - 1][j - 1] <= a[i]) {
					f[i][j] = Math.min(f[i][j], x);
				}
			}
		}

		long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (f[n - 1][i] <= k)
				ans = Math.max(ans, i + 1);
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}