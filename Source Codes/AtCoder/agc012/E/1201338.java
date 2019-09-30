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
		int[][] toRight = new int[cnt][N];
		int[][] toLeft = new int[cnt][N];
		for (int i = 0; i < cnt; ++i) {
			for (int j = 0; j < N; ++j) {
				toRight[i][j] = j;
				toLeft[i][j] = j;
			}
		}
		for (int i = 0; i < cnt; ++i) {
			for (int j = N - 2; j >= 0; --j) {
				if (x[j + 1] - x[j] <= Vs[i]) {
					toRight[i][j] = toRight[i][j + 1];
				}
			}
		}

		for (int i = 0; i < cnt; ++i) {
			for (int j = 1; j < N; ++j) {
				if (x[j] - x[j - 1] <= Vs[i]) {
					toLeft[i][j] = toLeft[i][j - 1];
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
					dpRight[ni] = Math.max(dpRight[ni], toRight[nxt][dpRight[i] + 1]);
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
					dpLeft[ni] = Math.min(dpLeft[ni], toLeft[nxt][dpLeft[i] - 1]);
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
			if (dpLeft[co] - toRight[0][dpRight[i] + 1] <= 1) {
				++ans[toLeft[0][dpLeft[co] - 1]];
				if (toRight[0][dpRight[i] + 1] + 1 < N) {
					--ans[toRight[0][dpRight[i] + 1] + 1];
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

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}