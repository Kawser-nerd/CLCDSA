import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int[][] x = new int[5][5];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				x[i][j] = sc.nextInt();
			}
		}

		int[] dp = new int[0x1 << 25];
		dp[0] = 1;
		for (int mask = 0; mask < (0x1 << 25) - 1; mask++) {
			if (dp[mask] == 0) {
				continue;
			}

			int i = Integer.bitCount(mask);
			for (int j = 0; j < 25; j++) {
				if ((mask & 0x1 << j) != 0) {
					continue;
				}

				int jx = j % 5;
				int jy = j / 5;

				if (x[jy][jx] != i + 1 && x[jy][jx] != 0) {
					continue;
				}

				if (isOK(jx, jy, mask)) {
					int nmask = mask | 0x1 << j;
					dp[nmask] += dp[mask];
					dp[nmask] %= MOD;
				}
			}
		}

		pr.println(dp[(0x1 << 25) - 1]);

	}

	private static boolean isOK(int jx, int jy, int mask) {
		return isOKx(jx, jy, mask) && isOKy(jx, jy, mask);
	}

	private static boolean isOKx(int jx, int jy, int mask) {
		int lx = jx - 1;
		int rx = jx + 1;
		if (lx < 0 || rx >= 5) {
			return true;
		}
		int ltmp = 0x1 << (lx + jy * 5);
		int rtmp = 0x1 << (rx + jy * 5);
		if ((mask & ltmp) == 0 && (mask & rtmp) == 0) {
			return true;
		}
		if ((mask & ltmp) != 0 && (mask & rtmp) != 0) {
			return true;
		}

		return false;
	}

	private static boolean isOKy(int jx, int jy, int mask) {
		int uy = jy - 1;
		int dy = jy + 1;
		if (uy < 0 || dy >= 5) {
			return true;
		}
		int utmp = 0x1 << (jx + uy * 5);
		int dtmp = 0x1 << (jx + dy * 5);
		if ((mask & utmp) == 0 && (mask & dtmp) == 0) {
			return true;
		}
		if ((mask & utmp) != 0 && (mask & dtmp) != 0) {
			return true;
		}

		return false;
	}

	private static final int MOD = 1_000_000_007;

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}