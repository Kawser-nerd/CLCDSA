import static java.lang.Math.max;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ":");
			solveOneTest();
			System.err.println("done "+test+"/"+testCases);
		}
	}

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		int maxX = nextInt(), maxY = nextInt();
		final int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return r[o2] - r[o1];
			}
		});

		Point[] men = new Point[n];
		Set<Point> interesting = new HashSet<Point>();
		interesting.add(new Point(0, 0));

		for (int it = 0; it < n; it++) {
			int i = order[it];
			int bestX = Integer.MAX_VALUE, bestY = Integer.MAX_VALUE;
			pos: for (Point pos : interesting) {
				int x = pos.x == 0 ? pos.x : pos.x + r[i];
				int y = pos.y == 0 ? pos.y : pos.y + r[i];
				if (x > maxX || y > maxY) {
					continue pos;
				}
				if (x > bestX) {
					continue;
				}
				
				Point pnt = new Point(x, y);
				for (int j = 0; j < it; j++) {
					if (menIntersect(men[order[j]], pnt, r[order[j]], r[i])) {
						continue pos;
					}
				}
				if (bestX > x || bestX == x && bestY > y) {
					bestX = x;
					bestY = y;
				}
			}
			if (bestX == Integer.MAX_VALUE && bestY == Integer.MAX_VALUE) {
				throw new AssertionError();
			}
			Point pnt = new Point(bestX, bestY);
			men[i] = pnt;
			for (int u = 0; u < 2; u++) {
				for (int v = 0; v < 2; v++) {
					int x = pnt.x - r[i] + u * 2 * r[i];
					int y = pnt.y - r[i] + v * 2 * r[i];
					x = max(x, 0);
					y = max(y, 0);
					interesting.add(new Point(x, y));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			out.print(" " + men[i].x + " " + men[i].y);
		}
		out.println();
	}

	static boolean menIntersect(Point p1, Point p2, int r1, int r2) {
		long dx = p1.x - p2.x;
		long dy = p1.y - p2.y;
		long rr = r1 + r2;
		return dx * dx + dy * dy < rr * rr;
	}

	static class Point {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		final int x, y;

		private Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("B.in"));
			out = new PrintWriter("B.out");
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