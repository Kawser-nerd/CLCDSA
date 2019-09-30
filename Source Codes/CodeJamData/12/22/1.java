import static java.lang.Math.max;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ": ");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int height = nextInt();
		int r = nextInt(), c = nextInt();
		int[][] ceiling = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ceiling[i][j] = nextInt();
			}
		}
		int[][] floor = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				floor[i][j] = nextInt();
			}
		}
		boolean[][] canVisit = bfs(floor, ceiling, height);
		TreeSet<QueueItem> queue = new TreeSet<QueueItem>();

		QueueItem[][] dist = new QueueItem[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (canVisit[i][j]) {
					dist[i][j] = new QueueItem(i, j, 0);
					queue.add(dist[i][j]);
				}
			}
		}
		while (!queue.isEmpty()) {
			QueueItem item = queue.pollFirst();
			int x = item.x, y = item.y, d = item.time;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
					continue;
				}
				int h = maxWaterToGo(floor[x][y], ceiling[x][y], floor[nx][ny], ceiling[nx][ny]);
				if (h == Integer.MIN_VALUE) {
					continue;
				}

				int timeToReachH;
				if (h < height - d) {
					timeToReachH = height - h;
				} else {
					timeToReachH = item.time;
					h = max(height - d, 0);
				}

				int timeToGo;
				if (h >= floor[x][y] + 20) {
					timeToGo = 10;
				} else {
					timeToGo = 100;
				}

				int time = timeToReachH + timeToGo;

				if (dist[nx][ny] == null || dist[nx][ny].time > time) {
					if (dist[nx][ny] != null) {
						queue.remove(dist[nx][ny]);
					} else {
						dist[nx][ny] = new QueueItem(nx, ny, time);
					}
					dist[nx][ny].time = time;
					queue.add(dist[nx][ny]);
				}
			}
		}

		int answer = dist[r - 1][c - 1].time;

		out.println(answer / 10 + "." + answer % 10);
	}

	static boolean[][] bfs(int[][] floor, int[][] ceiling, int height) {
		int r = floor.length, c = floor[0].length;
		boolean[][] visited = new boolean[r][c];
		Queue<Integer> queue = new ArrayDeque<Integer>();
		queue.add(0);
		visited[0][0] = true;
		while (!queue.isEmpty()) {
			int u = queue.poll();
			int x = u / c, y = u % c;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
					continue;
				}
				if (visited[nx][ny]) {
					continue;
				}
				if (canGo(floor[x][y], ceiling[x][y], floor[nx][ny], ceiling[nx][ny], height)) {
					visited[nx][ny] = true;
					queue.add(nx * c + ny);
				}
			}
		}
		return visited;
	}

	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static boolean canGo(int f1, int c1, int f2, int c2, int h) {
		return maxWaterToGo(f1, c1, f2, c2) >= h;
	}

	static int maxWaterToGo(int f1, int c1, int f2, int c2) {
		if (c2 - f1 < 50 || c2 - f2 < 50) {
			return Integer.MIN_VALUE;
		}
		if (c1 - f2 < 50) {
			return Integer.MIN_VALUE;
		}
		return c2 - 50;
	}

	static class QueueItem implements Comparable<QueueItem> {
		int x, y;
		int time;

		private QueueItem(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.time = dist;
		}

		@Override
		public int compareTo(QueueItem o) {
			int cmp = time - o.time;
			if (cmp != 0) {
				return cmp;
			}
			cmp = x - o.x;
			if (cmp != 0) {
				return cmp;
			}
			return y - o.y;
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("b.in"));
			out = new PrintWriter("b.out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null)
				return null;
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}