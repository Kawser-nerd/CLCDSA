import java.util.ArrayList;
import java.util.Collections;
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
		int R = sc.nextInt();
		int C = sc.nextInt();
		int N = sc.nextInt();
		int[][] f = new int[R][C];
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (i != 0) f[i][j]++;
				if (i != R - 1) f[i][j]++;
				if (j != 0) f[i][j]++;
				if (j != C - 1) f[i][j]++;
			}
		}
		ArrayList<Integer> c1 = new ArrayList<>();
		ArrayList<Integer> c2 = new ArrayList<>();
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if ((i + j) % 2 == 0) {
					c1.add(f[i][j]);
				} else {
					c2.add(f[i][j]);
				}
			}
		}
		Collections.sort(c1);
		Collections.sort(c2);
		int ret1 = 0;
		for (int i = 0; i < Math.min(R * C - N, c1.size()); ++i) {
			ret1 += c1.get(c1.size() - 1 - i);
		}
		int ret2 = 0;
		for (int i = 0; i < Math.min(R * C - N, c2.size()); ++i) {
			ret2 += c2.get(c2.size() - 1 - i);
		}
		return (R - 1) * C + R * (C - 1) - Math.max(ret1, ret2);
	}

}
