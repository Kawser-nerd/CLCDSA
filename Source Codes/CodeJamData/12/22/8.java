package round1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1/B-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1/B-small-3.in"), new FileOutputStream("src/round1/B-small-3.out"));
		io = new Kattio(new FileInputStream("src/round1/B-large-0.in"), new FileOutputStream("src/round1/B-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new B().solve(io);
		}
		io.close();
	}

	private static class Coord {
		public int x, y;

		private Coord(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	private static class CoordTime implements Comparable<CoordTime> {
		public Coord coord;
		public int tm;

		private CoordTime(Coord coord, int tm) {
			this.coord = coord;
			this.tm = tm;
		}

		public int compareTo(CoordTime coordTime) {
			return tm - coordTime.tm;
		}
	}

	private int dx[] = new int[] { 1, -1, 0, 0};
	private int dy[] = new int[] { 0, 0, 1, -1};

	private int xsize, ysize, water;
	private int floor[][], ceil[][];
	private boolean visited[][];
	private int[][] earliest;

	private void solve(Kattio io) {
		water = io.getInt();
		ysize = io.getInt();
		xsize = io.getInt();
		floor = new int[ysize][xsize];
		ceil = new int[ysize][xsize];
		visited = new boolean[ysize][xsize];
		earliest = new int[ysize][xsize];
		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < xsize; x++) {
			    ceil[y][x] = io.getInt();
				earliest[y][x] = Integer.MAX_VALUE;
			}
		}
		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < xsize; x++) {
				floor[y][x] = io.getInt();
			}
		}

		// Find start squares
		Queue<Coord> queue = new LinkedList<Coord>();
		PriorityQueue<CoordTime> pq = new PriorityQueue<CoordTime>();

		queue.add(new Coord(0,0));
		pq.add(new CoordTime(new Coord(0,0), 0));
		visited[0][0] = true;
		earliest[0][0] = 0;
		while (queue.size() > 0) {
			Coord c = queue.poll();
			for (int d = 0; d < 4; d++) {
				int nx = c.x + dx[d], ny = c.y + dy[d];
				if (canGo(c.x, c.y, nx, ny, water)) {
					queue.add(new Coord(nx, ny));
					pq.add(new CoordTime(new Coord(nx, ny), 0));
					visited[ny][nx] = true;
					earliest[ny][nx] = 0;
				}
			}
		}

//		for (Coord coord : start) {
//			System.out.print("(" + coord.x + "," + coord.y + ") ");
//		}
//		System.out.println();

		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < xsize; x++) {
				visited[y][x] = false;
			}
		}

		while (pq.size() > 0) {
			CoordTime ct = pq.poll();
			if (visited[ct.coord.y][ct.coord.x]) continue;
			visited[ct.coord.y][ct.coord.x] = true;
			for (int d = 0; d < 4; d++) {
				int nx = ct.coord.x + dx[d], ny = ct.coord.y + dy[d];
				if (nx < 0 || ny < 0 || nx >= xsize || ny >= ysize) continue;
				if (visited[ny][nx]) continue;
				if (!canGo(ct.coord.x, ct.coord.y, nx, ny, 0)) continue;

				int lo = 0, hi = Math.max(0, water - earliest[ct.coord.y][ct.coord.x]) + 1, best = hi;
				while (lo < hi) {
				    int w = (lo + hi) / 2;
					if (canGo(ct.coord.x, ct.coord.y, nx, ny, w)) {
						best = w;
						lo = w + 1;
					} else {
						hi = w;
					}
				}
				lo = best;

				int moveTime = lo - floor[ct.coord.y][ct.coord.x] >= 20 ? 10 : 100;
				int destTime = Math.max(earliest[ct.coord.y][ct.coord.x], water - lo) + moveTime;
				if (destTime < earliest[ny][nx]) {
					earliest[ny][nx] = destTime;
//					System.out.println("Can be at " + nx + "," + ny + " " + destTime);
					pq.add(new CoordTime(new Coord(nx, ny), destTime));
				}
			}
		}
		io.println(earliest[ysize-1][xsize-1] / 10.0);
//		System.out.println();
	}

	private boolean canGo(int x, int y, int nx, int ny, int water) {
		if (nx < 0 || ny < 0 || nx >= xsize || ny >= ysize || visited[ny][nx]) return false;
		int curCeil = ceil[y][x], adjCeil = ceil[ny][nx];
		int curFloor = floor[y][x], adjFloor = floor[ny][nx];
		if (adjCeil - water < 50 || adjCeil - curFloor < 50 || adjCeil - adjFloor < 50) return false;
		if (curCeil - adjFloor < 50) return false;
		return true;
	}
}
