import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int V = sc.nextInt();
		long[] x = new long[N];
		for (int i = 0; i < N; ++i) {
			x[i] = sc.nextLong();
		}

		int cnt = 0;
		int tmp = V;
		while (tmp > 0) {
			++cnt;
			tmp /= 2;
		}
		++cnt;
		int[] Vs = new int[cnt];
		Vs[0] = V;
		for (int i = 1; i < cnt; ++i) {
			Vs[i] = Vs[i - 1] / 2;
		}

		DJSet[] ds = new DJSet[cnt];
		for (int i = 0; i < ds.length; ++i) {
			ds[i] = new DJSet(N);
		}
		for (int i = 0; i < cnt; ++i) {
			for (int j = 0; j + 1 < N; ++j) {
				if (Math.abs(x[j] - x[j + 1]) <= Vs[i]) {
					ds[i].setUinon(j, j + 1);
				}
			}
		}

		int[] dpRight = new int[1 << cnt];
		int[] dpLeft = new int[1 << cnt];

		Arrays.fill(dpLeft, N);
		Arrays.fill(dpRight, -1);

		for (int i = 0; i < (1 << cnt); ++i) {
			for (int nxt = 0; nxt < cnt; ++nxt) {
				if ((i & (1 << nxt)) > 0) {
					continue;
				}
				int ni = i | (1 << nxt);
				dpRight[ni] = Math.max(dpRight[ni], dpRight[i]);
				if (dpRight[i] + 1 < N)
					dpRight[ni] = Math.max(dpRight[ni], ds[nxt].max(dpRight[i] + 1));
			}
		}
		for (int i = 0; i < (1 << cnt); ++i) {
			for (int nxt = 0; nxt < cnt; ++nxt) {
				if ((i & (1 << nxt)) > 0) {
					continue;
				}
				int ni = i | (1 << nxt);
				dpLeft[ni] = Math.min(dpLeft[ni], dpLeft[i]);
				if (dpLeft[i] - 1 >= 0)
					dpLeft[ni] = Math.min(dpLeft[ni], ds[nxt].min(dpLeft[i] - 1));
			}
		}
		int[] ans = new int[N];
		for (int i = 0; i < (1 << cnt); i += 2) {
			int co = ((1 << cnt) - 1) ^ i;
			co -= 1;
			if (dpLeft[co] - dpRight[i] <= 1) {
				Arrays.fill(ans, 1);
				break;
			}
			if (dpLeft[co] - ds[0].max(dpRight[i] + 1) <= 1) {
				++ans[ds[0].min(dpLeft[co] - 1)];
				if (ds[0].max(dpRight[i] + 1) + 1 < N) {
					--ans[ds[0].max(dpRight[i] + 1) + 1];
				}
			}
		}

		for (int i = 1; i < N; ++i) {
			ans[i] += ans[i - 1];
		}

		for (int i = 0; i < N; ++i) {
			if (ans[i] > 0) {
				System.out.println("Possible");
			} else {
				System.out.println("Impossible");
			}
		}
	}

	class DJSet {
		int n;
		int[] upper;
		int[] max;
		int[] min;

		public DJSet(int n) {
			this.n = n;
			upper = new int[n];
			min = new int[n];
			max = new int[n];
			Arrays.fill(upper, -1);
			for (int i = 0; i < n; ++i) {
				max[i] = i;
				min[i] = i;
			}

		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		void setUinon(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (upper[x] < upper[y]) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			min[y] = Math.min(min[y], min[x]);
			max[y] = Math.max(max[y], max[x]);
			upper[y] += upper[x];
			upper[x] = y;
		}

		int max(int x) {
			x = root(x);
			return max[x];
		}

		int min(int x) {
			x = root(x);
			return min[x];
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}