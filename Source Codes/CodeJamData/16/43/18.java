import java.util.Scanner;

public class C {
	static Scanner sc = new Scanner(System.in);
	static int R, C;
	static int[] pair;
	static int[] ans;
	static int[] DR = { 1, 0, -1, 0 };
	static int[] DC = { 0, 1, 0, -1 };

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.println("Case #" + i + ": ");
			solve();
		}
	}

	static int simulate(int[] f, int r, int c, int d) {
		while (0 <= r && r < R && 0 <= c && c < C) {
			boolean m = (f[r] & (1 << c)) == 0;
			d ^= 1;
			if (!m) {
				d ^= 2;
			}
			r += DR[d];
			c += DC[d];
		}
		if (r < 0) return c;
		if (c == C) return C + r;
		if (r == R) return R + C + (C - 1 - c);
		if (c < 0) return R + C + C + (R - 1 - r);
		return -1;
	}

	static void rec(int[] f, int idx) {
		if (ans != null) return;
		if (idx == f.length) {
			boolean ok = true;
			for (int i = 0; i < pair.length; i += 2) {
				int ar;
				if (pair[i] < C) {
					ar = simulate(f, 0, pair[i], 0);
				} else if (pair[i] < R + C) {
					ar = simulate(f, pair[i] - C, C - 1, 3);
				} else if (pair[i] < R + C + C) {
					ar = simulate(f, R - 1, C - 1 - (pair[i] - R - C), 2);
				} else {
					ar = simulate(f, R - 1 - (pair[i] - R - C - C), 0, 1);
				}
				if (ar != pair[i + 1]) ok = false;
			}
			if (ok) ans = f.clone();
			return;
		}
		for (int i = 0; i < (1 << C); ++i) {
			f[idx] = i;
			rec(f, idx + 1);
		}
	}

	static void solve() {
		R = sc.nextInt();
		C = sc.nextInt();
		pair = new int[(R + C) * 2];
		for (int i = 0; i < (R + C) * 2; ++i) {
			pair[i] = sc.nextInt() - 1;
		}
		int[] f = new int[R];
		ans = null;
		rec(f, 0);
		if (ans == null) {
			System.out.println("IMPOSSIBLE");
		} else {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					System.out.print((ans[i] & (1 << j)) != 0 ? '/' : '\\');
				}
				System.out.println();
			}
		}
	}
}
