import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long MODULO = 1_000_000_000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] e = new int[n][3];
		for (int i = 0; i < n; ++i) {
			e[i][0] = sc.nextInt();// x
			e[i][1] = sc.nextInt();// v
			e[i][2] = -1;
		}
		Arrays.sort(e, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
			}
		});
		for (int i = 0; i < n; ++i) {
			e[i][2] = i;
		}

		Arrays.sort(e, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});

		int[][] min = new int[n][2];
		int[][] max = new int[n][2];
		for (int i = 0; i < n; ++i) {
			min[i][0] = Integer.MAX_VALUE;
			max[i][0] = -Integer.MAX_VALUE;
			min[i][1] = -1;
			max[i][1] = -1;
		}
		for (int i = 0; i < n; ++i) {
			if (i == 0 || max[i - 1][0] < e[i][1]) {
				max[i][0] = e[i][1];
				max[i][1] = e[i][2];
			} else {
				max[i][0] = max[i - 1][0];
				max[i][1] = max[i - 1][1];
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1 || min[i + 1][0] > e[i][1]) {
				min[i][0] = e[i][1];
				min[i][1] = e[i][2];
			} else {
				min[i][0] = min[i + 1][0];
				min[i][1] = min[i + 1][1];
			}
		}
		long[] f = new long[n];
		long s = 0;
		int t = 0;
		for (int i = 0; i < n; ++i) {
			while (min[i][1] - max[t][1] > 1) {
				s = (s - f[t] + MODULO) % MODULO;
				++t;
			}
			f[i] = s;
			if (min[i][1] == min[0][1]) {
				++f[i];
			}
			s += f[i];
			s %= MODULO;
			f[i] %= MODULO;
		}
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			if (max[n - 1][1] == max[i][1]) {
				ans += f[i];
			}
			while (ans >= MODULO) {
				ans -= MODULO;
			}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}