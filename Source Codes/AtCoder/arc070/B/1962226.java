import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Main main = new Main();
		main.solveD();
	}

	private void solveD() throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		int left = 0;
		int right;
		for (right = N - 1; right >= 0 && a[right] >= K; right--);
		right++;
		while (left < right) {
			int current = (left + right) / 2;
			if (judge(current, a, K)) {
				left = current + 1;
			} else {
				right = current;
			}
		}
		System.out.println(left);
	}

	private boolean judge(int current, int[] a, int K) {
		int N = a.length;
		boolean[][] dp = new boolean[N + 1][];
		for (int i = 0; i <= N; i++) {
			dp[i] = new boolean[K];
		}
		dp[0][0] = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				if (dp[i][j]) {
					dp[i + 1][j] = true;
				}
			}
			if (current == i) {
				continue;
			}
			for (int j = 0; j < K; j++) {
				if (j - a[i] >= 0 && dp[i][j-a[i]]) {
					dp[i + 1][j] = true;
				}
			}
		}
		for (int i = K - 1; i >= K - a[current]; i--) {
			if (dp[N][i]) {
				return false;
			}
		}
		return true;
	}
}