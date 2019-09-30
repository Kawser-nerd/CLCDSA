import java.util.Arrays;
import java.util.Scanner;

public class Main {

	final long MOD = 1_000_000_000 + 7;
	long[][] comb = new long[1000][1000];
	{
		comb[0][0] = 1;
		for (int i = 1; i < comb.length; ++i) {
			for (int j = 0; j <= i; ++j) {
				comb[i][j] = comb[i - 1][j] + (j > 0 ? comb[i - 1][j - 1] : 0);
				if (comb[i][j] >= MOD)
					comb[i][j] -= MOD;
			}
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int d = sc.nextInt();
		int l = sc.nextInt();
		System.out.println(solve(r, c, x, y, d, l));
	}

	long solve(int r, int c, int x, int y, int d, int l) {
		long ans = 0;
		for (int s = 0; s < 1 << 4; ++s) {
			int area = x * y;
			for (int u = 0; u < x; ++u) {
				for (int v = 0; v < y; ++v) {
					boolean flag = false;
					if ((s & 1) > 0) {
						flag |= u == 0;
					}
					if (((s >> 1) & 1) > 0) {
						flag |= u == x - 1;
					}
					if (((s >> 2) & 1) > 0) {
						flag |= v == 0;
					}
					if (((s >> 3) & 1) > 0) {
						flag |= v == y - 1;
					}
					if (flag)
						--area;
				}
			}
			if (!(area >= d + l))
				continue;
			long tmp = comb[area][d + l] % MOD * comb[d + l][l] % MOD;
			ans = ans + (long) (MOD + Math.pow(-1, Integer.bitCount(s)) * tmp) % MOD;
			ans %= MOD;
		}
		ans = ans * (r - x + 1) % MOD * (c - y + 1) % MOD;
		return ans;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}