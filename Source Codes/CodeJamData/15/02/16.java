import java.util.Scanner;

public class B {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static int solve() {
		int D = sc.nextInt();
		int[] P = new int[D];
		for (int i = 0; i < D; ++i) {
			P[i] = sc.nextInt();
		}
		int ans = 9999;
		for (int i = 1; i <= 1000; ++i) {
			int move = 0;
			int len = 0;
			for (int j = 0; j < D; ++j) {
				if (P[j] <= i) {
					len = Math.max(len, P[j]);
				} else {
					move += (P[j]-1) / i;
					len = i;
				}
			}
			ans = Math.min(ans, move + len);
		}

		return ans;
	}

}
