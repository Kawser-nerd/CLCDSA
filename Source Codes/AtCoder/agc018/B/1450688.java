import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = sc.nextInt();
				--a[i][j];
			}
		}

		boolean[] invalid = new boolean[m];
		int ans = Integer.MAX_VALUE;
		for (int t = 0; t < m; ++t) {
			int[] cnt = new int[m];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (invalid[a[i][j]])
						continue;
					++cnt[a[i][j]];
					break;
				}
			}
			int max = 0;
			for (int i = 0; i < m; ++i) {
				max = Math.max(max, cnt[i]);
			}
			ans = Math.min(ans, max);
			for (int i = 0; i < m; ++i) {
				if (cnt[i] == max) {
					invalid[i] = true;
					break;
				}
			}
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}