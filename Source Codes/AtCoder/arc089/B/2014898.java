import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().execMain();
	}

	protected void execMain() {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int K = scan.nextInt();
		int[] x = new int[N];
		int[] y = new int[N];
		// ????????
		for (int i = 0; i < N; i++) {
			x[i] = scan.nextInt() % (2 * K);
			y[i] = scan.nextInt() % (2 * K);
			// ??????
			if (scan.next().equals("W")) {
				y[i] += K;
				y[i] %= (2 * K);
			}
			int[] p = pos(x[i], y[i], K);
			x[i] = p[0];
			y[i] = p[1];
		}

//		int[][] count = new int[2 * K][3 * K];		// x?pos????????????2?????
		int[][] count = new int[3 * K][3 * K];	// x?pos?????????????????
		// ?????????????????????????????????????????????????
		for (int i = 0; i < N; i++) {
			++count[x[i]] [y[i]];
			--count[x[i]] [y[i] + K];
			--count[x[i] + K] [y[i]];
			++count[x[i] + K] [y[i] + K];
		}
		// ??????????
		// ???????
		for (int i = 0; i < count.length; ++i) {
			for (int j = 1; j < count[i].length; ++j) {		// ?
				count[j][i] += count[j - 1][i];
			}
		}

		// ???????????????
		for (int i = 0; i < count[0].length; ++i) {
			for (int j = 1; j < count.length; ++j) {		// ?
				count[i][j] += count[i][j - 1];
			}
		}

		// ??????????????????
		for (int i = 0; i < count.length; ++i) {
			for (int j = 0; j < count[i].length; ++j) {
				if (j < 2 * K && i < K)
					continue;
				int[] pos = pos(j, i, K);
				count[pos[1]][pos[0]] += count[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < K; ++i) {		// x????????????????????????
			for (int j = 0; j < 2 * K; ++j) {
				ans = Math.max(ans, count[i][j]);
			}
		}
		System.out.println(ans);
	}


	protected int[] pos(int x, int y, int K) {
		x %= (2 * K);
		y %= (2 * K);
		// ???????????
		if (y >= K) {
			x += K;
			y += K;
			x %= (2 * K);
			y %= (2 * K);
		}

		int[] p = {x, y};
		return p;
	}

}