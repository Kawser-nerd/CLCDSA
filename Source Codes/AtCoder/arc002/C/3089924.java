import java.io.*;

public class Main {

	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws NumberFormatException, IOException {
		debug = 1 == args.length;
		debug2 = 2 == args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		final String[] rules =
				{"AA", "AB", "AX", "AY",
				 "BA", "BB", "BX", "BY",
				 "XA", "XB", "XX", "XY",
				 "YA", "YB", "YX", "YY"};

		final int N = Integer.parseInt(in.readLine());
		final String is = in.readLine();


		int ans = Integer.MAX_VALUE;

		for (int r = 0; r < rules.length; ++r) {
			for (int l = r + 1; l < rules.length; ++l) {
				if (r == l) {
					continue;
				}
				int[] dp = new int[is.length()];
				for (int i = 0; i < dp.length; ++i) {
					dp[i] = i + 1;
				}
				for (int i = 1; i < dp.length; ++i) {
					for (int rl = 0; rl < 2; ++rl) {
						if (is.regionMatches(i - 1, rl == 0 ? rules[r] : rules[l], 0, 2)) {
							dp[i] = Math.min(dp[i], 1 + (0 <= i - 2 && i - 2 < dp.length ? dp[i - 2] : 0));
						} else {
							dp[i] = Math.min(dp[i], 1 + (0 <= i - 1 && i - 1 < dp.length ? dp[i - 1] : 0));
						}
					}
				}
				ans = Math.min(ans, dp[dp.length - 1]);
			}
		}

		System.out.println(ans);

	}

}