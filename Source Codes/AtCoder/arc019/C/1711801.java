import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int[] di = new int[] { 1, -1, 0, 0 };
	int[] dj = new int[] { 0, 0, 1, -1 };

	boolean valid(int i, int j, int r, int c) {
		if (i < 0 || j < 0 || i >= r || j >= c) {
			return false;
		} else {
			return true;
		}
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		char[][] map = new char[r][c];
		int[] G = new int[2];
		int[] C = new int[2];
		int[] S = new int[2];
		for (int i = 0; i < r; ++i) {
			map[i] = sc.next().toCharArray();
			for (int j = 0; j < c; ++j) {
				if (map[i][j] == 'C') {
					C[0] = i;
					C[1] = j;
				} else if (map[i][j] == 'G') {
					G[0] = i;
					G[1] = j;
				} else if (map[i][j] == 'S') {
					S[0] = i;
					S[1] = j;
				}
			}
		}
		int[][][] dc = dist(r, c, k, map, C[0], C[1]);
		int[][][] dg = dist(r, c, k, map, G[0], G[1]);
		int[][][] ds = dist(r, c, k, map, S[0], S[1]);
		int[][][] dsg = new int[r][c][k + 1];
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int p = 0; p <= k; ++p) {
					dsg[i][j][p] = Integer.MAX_VALUE / 4;
				}
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int p = 0; p <= k; ++p) {
					for (int q = 0; q <= k; ++q) {
						int aux = 0;
						if (map[i][j] == 'E')
							++aux;
						if (p + q - aux > k || p + q - aux < 0)
							continue;
						dsg[i][j][p + q - aux] = Math.min(dsg[i][j][p + q - aux], ds[i][j][p] + dg[i][j][q]);
					}
				}
			}
		}

		int ans = Integer.MAX_VALUE / 4;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int p = 0; p <= k; ++p) {
					int aux = 0;
					if (map[i][j] == 'E')
						++aux;
					if (k - p + aux < 0 || k - p + aux > k)
						continue;
					ans = Math.min(ans, dsg[i][j][p] + 2 * dc[i][j][k - p + aux]);
				}
			}
		}
		System.out.println(ans >= 10000 ? -1 : ans);
	}

	int[][][] dist(int r, int c, int k, char[][] map, int si, int sj) {
		int[][][] d = new int[r][c][k + 1];
		for (int i = 0; i < d.length; ++i) {
			for (int j = 0; j < d[i].length; ++j) {
				for (int l = 0; l < d[i][j].length; ++l) {
					d[i][j][l] = Integer.MAX_VALUE / 4;
				}
			}
		}
		d[si][sj][0] = 0;
		ArrayDeque<int[]> que = new ArrayDeque<>();
		que.add(new int[] { si, sj, 0 });
		while (!que.isEmpty()) {
			int[] state = que.pollFirst();
			for (int i = 0; i < 4; ++i) {
				int ni = state[0] + di[i];
				int nj = state[1] + dj[i];
				if (!valid(ni, nj, r, c))
					continue;
				if (map[ni][nj] != 'T' && map[ni][nj] != 'E') {
					if (d[ni][nj][state[2]] > d[state[0]][state[1]][state[2]] + 1) {
						d[ni][nj][state[2]] = d[state[0]][state[1]][state[2]] + 1;
						que.addLast(new int[] { ni, nj, state[2] });
					}
				} else if (map[ni][nj] == 'T') {
					continue;
				} else if (map[ni][nj] == 'E') {
					if (state[2] + 1 <= k && d[ni][nj][state[2] + 1] > d[state[0]][state[1]][state[2]] + 1) {
						d[ni][nj][state[2] + 1] = d[state[0]][state[1]][state[2]] + 1;
						que.addLast(new int[] { ni, nj, state[2] + 1 });
					}
				}
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int l = 1; l <= k; ++l) {
					d[i][j][l] = Math.min(d[i][j][l], d[i][j][l - 1]);
				}
			}
		}
		return d;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}