import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class TideGoesIn {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("tide.in"));
		PrintWriter out = new PrintWriter("tide.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve(in, out);
		}
		out.close();
	}

	static final double EPS = 1e-8;

	static void solve(Scanner in, PrintWriter out) {
		int h = in.nextInt();
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] ceiling = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ceiling[i][j] = in.nextInt();
			}
		}
		int[][] floor = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				floor[i][j] = in.nextInt();
			}
		}
		Queue<Vertex> bfs = new ArrayDeque<Vertex>();
		bfs.add(new Vertex(0, 0, 0));
		boolean[][] wasBFS = new boolean[n][m];
		final int[] DX = { 1, 0, -1, 0 };
		final int[] DY = { 0, 1, 0, -1 };
		wasBFS[0][0] = true;
		while (!bfs.isEmpty()) {
			Vertex v = bfs.poll();
			for (int dir = 0; dir < 4; dir++) {
				int x = v.x + DX[dir];
				int y = v.y + DY[dir];
				if (x < 0
						|| y < 0
						|| x >= n
						|| y >= m
						|| min(ceiling[x][y], ceiling[v.x][v.y])
								- max(h, max(floor[x][y], floor[v.x][v.y])) < 50
						|| wasBFS[x][y]) {
					continue;
				}
				wasBFS[x][y] = true;
				bfs.add(new Vertex(0, x, y));
			}
		}
		Vertex[][] all = new Vertex[n][m];
		NavigableSet<Vertex> q = new TreeSet<Vertex>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				all[i][j] = new Vertex(wasBFS[i][j] ? 0
						: Double.POSITIVE_INFINITY, i, j);
				if (wasBFS[i][j]) {
					q.add(all[i][j]);
				}
			}
		}
		boolean[][] was = new boolean[n][m];
		while (!q.isEmpty()) {
			Vertex v = q.pollFirst();
			was[v.x][v.y] = true;
			for (int dir = 0; dir < 4; dir++) {
				int x = v.x + DX[dir];
				int y = v.y + DY[dir];
				if (x < 0 || y < 0 || x >= n || y >= m) {
					continue;
				}
				if (x < 0
						|| y < 0
						|| x >= n
						|| y >= m
						|| min(ceiling[x][y], ceiling[v.x][v.y])
								- max(floor[x][y], floor[v.x][v.y]) < 50
						|| was[x][y]) {
					continue;
				}
				double currentWater = h - v.time * 10;
				double neededWater = min(
						min(ceiling[x][y], ceiling[v.x][v.y]) - 50,
						currentWater);
				double wait = (currentWater - neededWater) / 10.;
				double goTime;
				if (neededWater - floor[v.x][v.y] >= 20 - EPS) {
					goTime = 1;
				} else {
					goTime = 10;
				}
				double comeTime = v.time + wait + goTime;
				if (all[x][y].time > comeTime) {
					q.remove(all[x][y]);
					all[x][y].time = comeTime;
					q.add(all[x][y]);
				}
			}
		}
		out.println(all[n - 1][m - 1].time);
	}

	static class Vertex implements Comparable<Vertex> {
		double time;
		int x;
		int y;

		public Vertex(double time, int x, int y) {
			super();
			this.time = time;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Vertex o) {
			int c = Double.compare(time, o.time);
			if (c != 0) {
				return c;
			}
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}

	}

}
