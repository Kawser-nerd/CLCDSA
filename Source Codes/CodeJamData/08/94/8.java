import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	BufferedReader br;
	PrintWriter pw;

	private void solve() throws Exception {
		br = new BufferedReader(new FileReader("d.in"));
		pw = new PrintWriter("d.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
			System.out.println(test);
		}

		br.close();
		pw.close();
	}

	int[] dx = {0, 0, 1, -1};
	int[] dy = {1, -1, 0, 0};
	int[] bdir = {1, 0, 3, 2};

	int n, m;
	char[][] c;
	boolean[][][] b;
	int[][][] cost;
	boolean[][] r;
	int[][] d, d2, p;
	int rem, result;
	int now, all;
	int[] qx, qy;

	void prebfs() {
		now = 0;
		all = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (r[i][j] && c[i][j] == 'T') {
					qx[all] = i;
					qy[all] = j;
					d[i][j] = 0;
					all++;
				} else {
					d[i][j] = -1;
				}
			}
		}
		while (now < all) {
			int x = qx[now];
			int y = qy[now];
			now++;
			for (int dir = 0; dir < 4; dir++) {
				if (!b[x][y][dir]) {
					continue;
				}
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] != '.') {
					if (d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						qx[all] = nx;
						qy[all] = ny;
						all++;
					}
				}
			}
		}
	}

	int bfs(int x0, int y0, boolean mark, boolean reachT) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				d2[i][j] = -1;
			}
		}
		d2[x0][y0] = 0;
		now = 0;
		all = 1;
		qx[0] = x0;
		qy[0] = y0;
		while (now < all) {
			int x = qx[now];
			int y = qy[now];
			if (d[x][y] != -1) {
				break;
			}
			now++;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] != '.') {
					if (d2[nx][ny] == -1) {
						d2[nx][ny] = d2[x][y] + 1;
						p[nx][ny] = dir;
						qx[all] = nx;
						qy[all] = ny;
						all++;
					}
				}
			}
		}

		int res = 1000000;
		int ri = 0;
		int rj = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != '.' && d[i][j] != -1 && d2[i][j] != -1) {
					int dst = (d[i][j] + 1 + d[i][j] + d2[i][j]) * (d2[i][j]) / 2;
					if (dst < res) {
						ri = i;
						rj = j;
						res = dst;
					}
				}
			}
		}

		if (mark) {
			result += res;
			while (ri != x0 || rj != y0) {
				int dir = p[ri][rj];
				rem--;
				int x = ri - dx[dir];
				int y = rj - dy[dir];
				b[x][y][dir] = true;
				b[ri][rj][bdir[dir]] = true;
				ri = x;
				rj = y;
				r[ri][rj] = true;
			}
		}

		return res;
	}

	private void runtest() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		c = new char[n][];
		qx = new int[n * m];
		qy = new int[n * m];
		int tc = 0;
		rem = 0;
		for (int i = 0; i < n; i++) {
			c[i] = br.readLine().toCharArray();
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'T') {
					tc++;
				}
				if (c[i][j] != '.') {
					rem++;
				}
			}
		}

		b = new boolean[n][m][4];
		cost = new int[n][m][4];
		r = new boolean[n][m];
		d = new int[n][m];
		d2 = new int[n][m];
		p = new int[n][m];
		r[0][0] = true;
		rem--;
		result = 0;
		System.out.println(n + " " + m);
		for (int tnum = 1; tnum < tc; tnum++) {
//			System.out.println(tc - tnum);
			int mi = -1;
			int mj = 0;
			int mr = 1000000;
			prebfs();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (c[i][j] == 'T' && !r[i][j]) {
						int dist = bfs(i, j, false, true);
						if (dist < mr) {
							mr = dist;
							mi = i;
							mj = j;
						}
					}
				}
			}

			if (mi != -1) {
				bfs(mi, mj, true, true);
			}
		}

		while (rem > 0) {
//			System.out.println(rem);
			int mi = -1;
			int mj = 0;
			int mr = 1000000;
			prebfs();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (c[i][j] != '.' && !r[i][j]) {
						int dist = bfs(i, j, false, false);
						if (dist < mr) {
							mr = dist;
							mi = i;
							mj = j;
						}
					}
				}
			}
			if (mi != -1) {
				bfs(mi, mj, true, false);
			}
		}

		pw.println(result);
	}

}
