import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] a = new char[H][W];
		ArrayList<Integer>[] g = new ArrayList[H + W];
		for (int i = 0; i < H; ++i) {
			a[i] = sc.next().toCharArray();
		}
		int o = Math.max(H, W);
		MF mf = new MF(2 * o + 3);
		// 2*H*W+1:s
		// 2*H*W+2:t
		int s = 2 * o + 1;
		int t = 2 * o + 2;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (a[i][j] == 'S') {
					mf.ae(s, i, 999999);
					mf.ae(s, o + j, 999999);
				} else if (a[i][j] == 'T') {
					mf.ae(i, t, 999999);
					mf.ae(o + j, t, 999999);
				} else if (a[i][j] == 'o') {
					mf.ae(i, o + j, 1);
					mf.ae(o + j, i, 1);
				}
			}
		}
		int tot = mf.solve(s, t);
		if (tot >= 999999) {
			System.out.println(-1);
		} else {
			System.out.println(tot);
		}
	}

	class MF {
		int n;
		int[][] cap;
		int[][] flow;
		ArrayList<Integer>[] g;

		public MF(int n) {
			this.n = n;
			cap = new int[n][n];
			flow = new int[n][n];
			g = new ArrayList[n];
			for (int i = 0; i < n; ++i) {
				g[i] = new ArrayList<>();
			}
		}

		void ae(int a, int b, int w) {
			cap[a][b] = w;
			g[a].add(b);
		}

		int solve(int s, int t) {
			int tot = 0;
			while (true) {
				int[] pre = new int[n];
				Arrays.fill(pre, -1);
				ArrayDeque<Integer> que = new ArrayDeque<>();
				que.add(s);
				out: while (!que.isEmpty()) {
					int v = que.poll();
					for (int i = 0; i < n; ++i) {
						if (cap[v][i] - flow[v][i] > 0 && pre[i] == -1 && i != s) {
							pre[i] = v;
							que.add(i);
							if (i == t) {
								break out;
							}
						}
					}
				}
				if (pre[t] == -1)
					break;
				int inc = Integer.MAX_VALUE / 16;
				for (int i = t; pre[i] != -1; i = pre[i]) {
					inc = Math.min(inc, cap[pre[i]][i] - flow[pre[i]][i]);
				}
				for (int i = t; pre[i] != -1; i = pre[i]) {
					flow[pre[i]][i] += inc;
					flow[i][pre[i]] -= inc;
				}
				tot += inc;
			}
			return tot;
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.