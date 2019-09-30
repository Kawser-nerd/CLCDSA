import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	final int[] dx = new int[] { 1, -1, 0, 0 };
	final int[] dy = new int[] { 0, 0, 1, -1 };

	void run() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		char[][] A = new char[H][W];
		for (int i = 0; i < H; ++i) {
			A[i] = sc.next().toCharArray();
		}
		int sh = -1, sw = -1;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (A[i][j] == 'S') {
					sh = i;
					sw = j;
				}
			}
		}

		int[][] d = new int[H][W];
		for (int i = 0; i < d.length; ++i) {
			for (int j = 0; j < d[i].length; ++j) {
				d[i][j] = Integer.MAX_VALUE / 16;
			}
		}
		d[sh][sw] = 0;
		class P {
			int h, w;

			public P(int h, int w) {
				this.h = h;
				this.w = w;
			}
		}

		ArrayDeque<P> que = new ArrayDeque<>();
		que.add(new P(sh, sw));
		while (!que.isEmpty()) {
			P p = que.poll();
			for (int i = 0; i < 4; ++i) {
				P np = new P(p.h + dy[i], p.w + dx[i]);
				if (!movable(np.h, np.w, A))
					continue;
				if (d[np.h][np.w] > d[p.h][p.w] + 1 && d[p.h][p.w] + 1 <= K) {
					d[np.h][np.w] = d[p.h][p.w] + 1;
					que.add(np);
				}
			}
		}

		int ans = Integer.MAX_VALUE / 16;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (d[i][j] > K)
					continue;
				ans = Math.min(ans, 1 + (f(i, j, H, W) + K - 1) / K);
			}
		}
		System.out.println(ans);
	}

	int f(int h, int w, int H, int W) {
		int ret = Integer.MAX_VALUE / 16;
		ret = Math.min(ret, h);
		ret = Math.min(ret, H - 1 - h);
		ret = Math.min(ret, w);
		ret = Math.min(ret, W - 1 - w);
		return ret;
	}

	boolean movable(int h, int w, char[][] map) {
		if (h < 0 || w < 0 || h >= map.length || w >= map[0].length) {
			return false;
		}
		if (map[h][w] == '#') {
			return false;
		}
		return true;
	}

	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}