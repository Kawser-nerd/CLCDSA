import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[N];
		int[] cnt = new int[N + 1];
		int[] cum = new int[2 * N + 1];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
			++cnt[A[i]];
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < cnt[i]; ++j) {
				++cum[i - j + N];
			}
		}

		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			if (cum[i + N] == 0)
				++ans;
		}
		for (int i = 0; i < M; ++i) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			--x;
			int tmp = x;
			x = A[x];
			A[tmp] = y;
			--cum[N + x - (cnt[x] - 1)];
			if (cum[N + x - (cnt[x] - 1)] < 0) {
				throw new AssertionError();
			}
			if (x - (cnt[x] - 1) >= 1 && cum[N + x - (cnt[x] - 1)] == 0) {
				++ans;
			}
			--cnt[x];
			++cnt[y];
			++cum[N + y - (cnt[y] - 1)];
			if (y - (cnt[y] - 1) >= 1 && cum[N + y - (cnt[y] - 1)] == 1) {
				--ans;
			}
			System.out.println(ans);
		}

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}