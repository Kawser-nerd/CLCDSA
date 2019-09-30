import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	static int[] g;
	static int[] h;
	static int p, q;
	static int[][][] dp;

	public static int[] win(int hp, int saved, int turn, int skip) {
		// i'll drain from saved
		hp = hp - saved * p;
		if (hp <= 0)
			return skip != 0 ? null : new int[] { 1, turn };
		// i'll drain from tower turn
		hp = hp - q * turn;
		if (hp <= 0)
			return skip != 0 ? null : new int[] { 0, 0 };
		// make sure skip is not more than possible
		if (hp - (skip - 1) * q <= 0)
			return null;
		// i'll skip
		hp = hp - skip * q;
		if (hp <= 0)
			return new int[] { 0, 0 };
		while (hp != 0) {
			hp -= p;
			if (hp <= 0)
				return new int[] { 1, 1 };
			hp -= q;
			if (hp <= 0)
				return new int[] { 0, 0 };
		}
		return null;
	}

	public static int f(int i, int turn, int saved) {
		if (i == g.length)
			return 0;
		int hp = h[i];
		int result = 0;
		if (dp[turn][i][saved] != -1)
			return dp[turn][i][saved];
		// choose how much saved attacks to put on this monster
		// choose how much attacks to save
		// recurse
		for (int a = 0; a <= saved && a <= 10; a++) {
			for (int b = 0; b <= 10; b++) {
				int[] winStatus = win(hp, a, turn, b);
				if (winStatus != null) {
					result = Math.max(result,
							f(i + 1, winStatus[1], saved - a + b)
									+ winStatus[0] * g[i]);
				}
			}
		}
		return dp[turn][i][saved] = result;

	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileReader("B.in"));
		PrintWriter out = new PrintWriter("B.out");
		int tc = in.nextInt();
		for (int cc = 1; cc <= tc; cc++) {
			p = in.nextInt();
			q = in.nextInt();
			int n = in.nextInt();
			g = new int[n];
			h = new int[n];
			dp = new int[2][n][n * 15 + 1];
			for (int[][] a : dp)
				for (int[] b : a)
					Arrays.fill(b, -1);
			for (int i = 0; i < n; i++) {
				h[i] = in.nextInt();
				g[i] = in.nextInt();
			}
			System.out.printf("Case #%d: %d\n", cc, f(0, 0, 0));
			out.printf("Case #%d: %d\n", cc, f(0, 0, 0));
		}
		out.close();
	}

}
