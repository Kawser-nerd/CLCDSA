import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	// 30?????

	final double e0 = 8.854187 * 1e-12;// Fm^(-1)
	final double a = 1;// ?????
	final double dt = 0.01;
	double[][][] charge = new double[100000][3][3];
	double[][][] voltage = new double[100000][3][3];
	double thickness = 0.1;
	double k = 1e-3;// ?/k=c,k=?/c ?=10^12 c=10^8,??
	double Z = 120 * Math.PI;
	final long MOD = (long) 1e17 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long W = sc.nextLong();
		long[] v = new long[N];
		long[] w = new long[N];
		long maxV = 0, maxW = 0;
		for (int i = 0; i < N; ++i) {
			v[i] = sc.nextLong();
			w[i] = sc.nextLong();
			maxV = Math.max(maxV, v[i]);
			maxW = Math.max(maxW, w[i]);
		}
		if (N <= 30) {
			long[][] list1 = list(Arrays.copyOfRange(v, 0, N / 2), Arrays.copyOfRange(w, 0, N / 2));
			long[][] list2 = list(Arrays.copyOfRange(v, N / 2, N), Arrays.copyOfRange(w, N / 2, N));
			long ans = 0;
			int p = list2.length - 1;
			for (int i = 0; i < list1.length; ++i) {
				if (list1[i][1] > W)
					break;
				while (list1[i][1] + list2[p][1] > W)
					--p;
				ans = Math.max(ans, list1[i][0] + list2[p][0]);
			}
			System.out.println(ans);
			return;
		} else if (maxV <= 1000) {
			long[] dp = new long[(int) (maxV * N) + 1];
			Arrays.fill(dp, Long.MAX_VALUE / 3);
			dp[0] = 0;
			for (int i = 0; i < N; ++i) {
				for (int j = (int) (dp.length - v[i] - 1); j >= 0; --j) {
					dp[(int) (j + v[i])] = Math.min(dp[(int) (j + v[i])], dp[j] + w[i]);
				}
			}
			long ans = 0;
			for (int i = 0; i < dp.length; ++i) {
				if (dp[i] <= W) {
					ans = Math.max(ans, i);
				}
			}
			System.out.println(ans);
		} else if (maxW <= 1000) {
			long[] dp = new long[(int) (maxW * N) + 1];
			Arrays.fill(dp, -Long.MAX_VALUE / 3);
			dp[0] = 0;
			for (int i = 0; i < N; ++i) {
				for (int j = (int) (dp.length - w[i] - 1); j >= 0; --j) {
					dp[(int) (j + w[i])] = Math.max(dp[(int) (j + w[i])], dp[j] + v[i]);
				}
			}
			long ans = 0;
			for (int i = 0; i <= W; ++i)
				ans = Math.max(ans, dp[i]);
			System.out.println(ans);
		} else {
			throw new AssertionError();
		}

	}

	long[][] list(long[] v, long[] w) {
		int n = v.length;
		long[][] list = new long[1 << n][2];
		for (int s = 0; s < 1 << n; ++s) {
			long val = 0, wei = 0;
			for (int i = 0; i < n; ++i) {
				if (((1 << i) & s) > 0) {
					val += v[i];
					wei += w[i];
				}
			}
			list[s][0] = val;
			list[s][1] = wei;
		}
		Arrays.sort(list, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				return Long.compare(o1[1], o2[1]);
			}
		});
		for (int i = 1; i < 1 << n; ++i) {
			if (list[i][0] < list[i - 1][0]) {
				list[i][0] = list[i - 1][0];
				list[i][1] = list[i - 1][1];
			}
		}
		return list;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}