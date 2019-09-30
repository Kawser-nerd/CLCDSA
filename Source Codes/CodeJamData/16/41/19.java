import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);
	static char[] cs = { 'P', 'R', 'S' };
	static String[][] dp = new String[3][13];

	public static void main(String[] args) {
		dp[0][0] = "P";
		dp[1][0] = "R";
		dp[2][0] = "S";
		for (int i = 1; i < dp[0].length; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[j][i] = dp[j][i - 1] + dp[(j + 1) % 3][i - 1];
				String o = dp[(j + 1) % 3][i - 1] + dp[j][i - 1];
				if (o.compareTo(dp[j][i]) < 0) dp[j][i] = o;
			}
		}
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			System.out.println(solve());
		}
	}

	static String solve() {
		int N = sc.nextInt();
		int R = sc.nextInt();
		int P = sc.nextInt();
		int S = sc.nextInt();
		String ret = null;
		for (int i = 0; i < 3; ++i) {
			int[] c = new int[3];
			for (char ch : dp[i][N].toCharArray()) {
				if (ch == 'P') c[0]++;
				if (ch == 'R') c[1]++;
				if (ch == 'S') c[2]++;
			}
			if (c[0] == P && c[1] == R && c[2] == S) {
				ret = dp[i][N];
			}
		}

		return ret == null ? "IMPOSSIBLE" : ret;
	}
}
