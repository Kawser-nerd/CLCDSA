import java.util.Arrays;
import java.util.Scanner;

class Main {
	int N;
	int C;
	int[] L;

	public void run() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		C = sc.nextInt();
		L = new int[N];
		for (int i = 0; i < N; ++i) {
			L[i] = sc.nextInt();
		}
		Arrays.sort(L);
		int[] ord = new int[N - 1];
		for (int i = 0; i < ord.length; ++i)
			ord[i] = i;

		double ans = 0;
		long[][] dp = new long[N * C + 1][1 << N - 1];
		do {
			for (int i = 0; i < dp.length; ++i)
				for (int j = 0; j < dp[i].length; ++j)
					dp[i][j] = 0;
			dp[L[N - 1] * N - 1][0] = 1;
			for (int i = 0; i < N * C; ++i) {
				if (i % N == 0)
					continue;
				for (int s = 0; s < 1 << N - 1; ++s) {
					for (int j = i - 1; j <= N * C; ++j) {
						if ((s >> i % N - 1) % 2 == 0) {
							dp[Math.min(N * C, Math.max(j, L[ord[i % N - 1]] * N + i - 1))][s
									^ (1 << i % N - 1)] += dp[j][s];
						}
					}
				}
			}
			ans += dp[N * C][(1 << N - 1) - 1];
		} while (nextPermutation(ord));

		for (int i = 2; i <= N - 1; ++i) {
			ans /= i;
		}

		for (int i = 0; i < N - 1; ++i) {
			ans /= C;
		}

		System.out.printf("%.40f", ans);
	}

	boolean nextPermutation(int[] ord) {
		int n = ord.length;
		int i = n - 1;
		while (i > 0 && ord[i - 1] > ord[i])
			--i;
		if (i == 0)
			return false;
		int j = i;
		while (j + 1 < n && ord[i - 1] < ord[j + 1])
			++j;
		{
			ord[i - 1] ^= ord[j];
			ord[j] ^= ord[i - 1];
			ord[i - 1] ^= ord[j];
		}
		int s = i;
		int t = n - 1;
		while (s < t) {
			ord[s] ^= ord[t];
			ord[t] ^= ord[s];
			ord[s] ^= ord[t];
			++s;
			--t;
		}
		return true;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}