import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[][] a = new long[n][2];
		int add = 0;
		for (int i = 0; i < n; ++i) {
			a[i][0] = sc.nextInt() - k;
			a[i][1] = i;
			if (i > 0) {
				a[i][0] += a[i - 1][0];
			}
			if (a[i][0] >= 0) {
				++add;
			}
		}
		Arrays.sort(a, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				return Long.compare(o1[0], o2[0]);
			}
		});

		int[] arr = new int[n];
		int p = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				if (a[i][0] != a[i - 1][0]) {
					++p;
				}
			}
			arr[(int) a[i][1]] = p;
		}
		solve(n, arr, add);
	}

	void solve(int n, int[] arr, int add) {
		int[][] e = new int[n][2];
		for (int i = 0; i < n; ++i) {
			e[i][0] = arr[i];
			e[i][1] = i;
		}
		Arrays.sort(e, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[0] != o2[0]) {
					return Integer.compare(o1[0], o2[0]);
				} else {
					return Integer.compare(o1[1], o2[1]);
				}
			}
		});
		BIT bit = new BIT(n);
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += bit.get(e[i][1]);
			bit.add(e[i][1]);
		}
		System.out.println(ans + add);
	}


	class BIT {
		int n;
		int[] v;

		public BIT(int n) {
			this.n = n;
			v = new int[n + 1];
		}

		void add(int k) {
			++k;
			while (k < v.length) {
				++v[k];
				k += k & -k;
			}
		}

		int get(int k) {
			++k;
			int s = 0;
			while (k > 0) {
				s += v[k];
				k -= k & -k;
			}
			return s;
		}

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}