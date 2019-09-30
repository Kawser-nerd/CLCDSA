import java.awt.Point;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	static class Solver {

		static int[] DX = new int[] { -1, -1, 0, 1, 1, 0 };
		static int[] DY = new int[] { -1, 0, 1, 1, 0, -1 };
		static final int WALL = -1;
		static final int CORNER = 100;
		int S, M;
		int[] moveX, moveY;
		int[][] prop;
		boolean[][] stone;

		void solve() {
			S = sc.nextInt();
			M = sc.nextInt();
			moveX = new int[M];
			moveY = new int[M];
			prop = new int[S * 2 + 1][S * 2 + 1];
			stone = new boolean[S * 2 + 1][S * 2 + 1];
			int cx = 2 * S;
			int cy = S;
			for (int i = 0; i < 6; ++i) {
				for (int j = 0; j < S; ++j) {
					prop[cx][cy] = WALL;
					cx += DX[i];
					cy += DY[i];
				}
			}
			cx = 2 * S - 1;
			cy = S;
			for (int i = 0; i < 6; ++i) {
				prop[cx][cy] = CORNER;
				for (int j = 0; j < S - 2; ++j) {
					cx += DX[i];
					cy += DY[i];
					prop[cx][cy] = i + 1;
				}
				cx += DX[i];
				cy += DY[i];
			}
			for (int i = 0; i < M; ++i) {
				moveX[i] = sc.nextInt();
				moveY[i] = sc.nextInt();
			}
			for (int i = 0; i < M; ++i) {
				stone[moveX[i]][moveY[i]] = true;
				Connect con = bfs(moveX[i], moveY[i]);
				boolean ring = ring();
				boolean bridge = con.corner >= 2;
				int edgeCount = 0;
				for (int j = 0; j < 6; ++j) {
					if (con.edge[j]) ++edgeCount;
				}
				boolean fork = edgeCount >= 3;
				if (ring) {
					if (bridge) {
						if (fork) {
							System.out.println("bridge-fork-ring in move " + (i + 1));
							return;
						} else {
							System.out.println("bridge-ring in move " + (i + 1));
							return;
						}
					} else {
						if (fork) {
							System.out.println("fork-ring in move " + (i + 1));
							return;
						} else {
							System.out.println("ring in move " + (i + 1));
							return;
						}
					}
				} else {
					if (bridge) {
						if (fork) {
							System.out.println("bridge-fork in move " + (i + 1));
							return;
						} else {
							System.out.println("bridge in move " + (i + 1));
							return;
						}
					} else {
						if (fork) {
							System.out.println("fork in move " + (i + 1));
							return;
						} else {
							;
						}
					}
				}
			}
			System.out.println("none");
		}

		boolean ring() {
			boolean[][] visited = new boolean[S * 2 + 1][S * 2 + 1];
			for (int i = 2; i <= 2 * S - 2; ++i) {
				int start = (i < S ? 2 : 2 + i - S);
				int end = (i < S ? S + i - 2 : 2 * S - 2);
				for (int j = start; j <= end; ++j) {
					if (stone[i][j] || visited[i][j]) continue;
					if (fill(i, j, visited)) {
						return true;
					}
				}
			}
			return false;
		}

		boolean fill(int sx, int sy, boolean[][] visited) {
			boolean ret = true;
			ArrayList<Point> cur = new ArrayList<Point>();
			cur.add(new Point(sx, sy));
			visited[sx][sy] = true;
			while (!cur.isEmpty()) {
				ArrayList<Point> next = new ArrayList<Point>();
				for (Point pos : cur) {
					if (prop[pos.x][pos.y] > 0) {
						ret = false;
					}
					for (int i = 0; i < 6; ++i) {
						int nx = pos.x + DX[i];
						int ny = pos.y + DY[i];
						if (prop[nx][ny] == WALL || stone[nx][ny] || visited[nx][ny]) continue;
						next.add(new Point(nx, ny));
						visited[nx][ny] = true;
					}
				}
				cur = next;
			}
			return ret;
		}

		Connect bfs(int sx, int sy) {
			Connect ret = new Connect();
			ArrayList<Point> cur = new ArrayList<Point>();
			cur.add(new Point(sx, sy));
			boolean[][] visited = new boolean[S * 2 + 1][S * 2 + 1];
			visited[sx][sy] = true;
			while (!cur.isEmpty()) {
				ArrayList<Point> next = new ArrayList<Point>();
				for (Point pos : cur) {
					if (1 <= prop[pos.x][pos.y] && prop[pos.x][pos.y] <= 6) {
						ret.edge[prop[pos.x][pos.y] - 1] = true;
					}
					if (prop[pos.x][pos.y] == CORNER) {
						ret.corner++;
					}
					for (int i = 0; i < 6; ++i) {
						int nx = pos.x + DX[i];
						int ny = pos.y + DY[i];
						if (!stone[nx][ny] || visited[nx][ny] || prop[nx][ny] == WALL) continue;
						next.add(new Point(nx, ny));
						visited[nx][ny] = true;
					}
				}
				cur = next;
			}
			return ret;
		}
	}

	static class Connect {
		boolean[] edge = new boolean[6];
		int corner = 0;
	}

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			solver.solve();
		}
	}
}
