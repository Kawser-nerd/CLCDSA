import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static long solve() {
		int A = sc.nextInt() - 1;
		int B = sc.nextInt() - 1;
		int K = sc.nextInt() - 1;
		long[][][][] dp = new long[2][2][2][32];
		dp[1][1][1][31] = 1;
		for (int i = 30; i >= 0; --i) {
			int ma = (A >> i) & 1;
			int mb = (B >> i) & 1;
			int mk = (K >> i) & 1;
			for (int ba = 0; ba <= 1; ++ba) {
				for (int bb = 0; bb <= 1; ++bb) {
					int bk = ba & bb;
					dp[0][0][0][i] += dp[0][0][0][i + 1];

					if (bk < mk) {
						dp[0][0][0][i] += dp[0][0][1][i + 1];
					} else if (bk == mk) {
						dp[0][0][1][i] += dp[0][0][1][i + 1];
					}

					int nba = ba < ma ? 0 : 1;
					int nbb = bb < mb ? 0 : 1;

					if (ba <= ma) {
						dp[nba][0][0][i] += dp[1][0][0][i + 1];
						if (bk < mk) {
							dp[nba][0][0][i] += dp[1][0][1][i + 1];
						} else if (bk == mk) {
							dp[nba][0][1][i] += dp[1][0][1][i + 1];
						}
					}

					if (bb <= mb) {
						dp[0][nbb][0][i] += dp[0][1][0][i + 1];
						if (bk < mk) {
							dp[0][nbb][0][i] += dp[0][1][1][i + 1];
						} else if (bk == mk) {
							dp[0][nbb][1][i] += dp[0][1][1][i + 1];
						}
					}

					if (ba <= ma && bb <= mb) {
						dp[nba][nbb][0][i] += dp[1][1][0][i + 1];
						if (bk < mk) {
							dp[nba][nbb][0][i] += dp[1][1][1][i + 1];
						} else if (bk == mk) {
							dp[nba][nbb][1][i] += dp[1][1][1][i + 1];
						}
					}
				}
			}
		}

//		for (int i = 0; i < 5; ++i) {
//			for (int j = 0; j < 2; ++j) {
//				for (int k = 0; k < 2; ++k) {
//					System.err.print("{" + dp[j][k][0][i] + "," + dp[j][k][1][i] + "},");
//				}
//				System.err.println();
//			}
//			System.err.println();
//		}

		long ret = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					ret += dp[i][j][k][0];
				}
			}
		}
		return ret;
	}

}
