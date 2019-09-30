import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class B {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.print("Case #" + test + ": ");
			solveOneTest();
			System.err.println("done " + test + "/" + testCases);
		}
	}

	static final int[] DX = { 0, 0, 1, 1, -1, -1 };
	static final int[] DY = { -1, 1, 0, 1, 0, -1 };

	private static void solveOneTest() throws IOException {
		int s = nextInt(), n = nextInt();
		int[] xInput = new int[n];
		int[] yInput = new int[n];
		for (int i = 0; i < n; i++) {
			xInput[i] = nextInt();
			yInput[i] = nextInt();
		}

		final int SIZE = 2 * s + 1;
		DSU dsu = new DSU(SIZE * SIZE);
		boolean[][] mark = new boolean[SIZE][SIZE];

		for (int i = 0; i < n; i++) {
			mark[xInput[i]][yInput[i]] = true;
		}

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (mark[i][j]) {
					continue;
				}
				for (int dir = 0; dir < DX.length; dir++) {
					int ni = i + DX[dir];
					int nj = j + DY[dir];
					if (ni < 0 || nj < 0 || ni >= SIZE || nj >= SIZE || mark[ni][nj]) {
						continue;
					}
					dsu.union(i * SIZE + j, ni * SIZE + nj);
				}
			}
		}

		int firstRing = Integer.MAX_VALUE;

		for (int time = n - 1; time >= 0; --time) {
			int x = xInput[time], y = yInput[time];
			for (int dir = 0; dir < DX.length; dir++) {
				int nx = x + DX[dir], ny = y + DY[dir];
				if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE || mark[nx][ny]) {
					continue;
				}
				if (dsu.get(nx * SIZE + ny) != dsu.get(0)) {
					firstRing = time;
				}
			}
			mark[x][y] = false;
			for (int dir = 0; dir < DX.length; dir++) {
				int nx = x + DX[dir], ny = y + DY[dir];
				if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE || mark[nx][ny]) {
					continue;
				}
				dsu.union(x * SIZE + y, nx * SIZE + ny);
			}
		}

		Map<Point, Integer> map = new HashMap<Point, Integer>();
		int firstBridge = Integer.MAX_VALUE;
		int firstFork = Integer.MAX_VALUE;

		SpecialDSU specialDSU = new SpecialDSU(n);
		for (int i = 0; i < n; i++) {
			int x = xInput[i], y = yInput[i];
			int mask = getSidesMask(x, y, s);
			specialDSU.mask[i] = mask;
			for (int dir = 0; dir < DX.length; dir++) {
				int nx = x + DX[dir], ny = y + DY[dir];
				Point p = new Point(nx, ny);
				Integer index = map.get(p);
				if (index == null) {
					continue;
				}
				specialDSU.union(index, i);
			}
			mask = specialDSU.mask[specialDSU.get(i)];
			if (isBridge(mask) || isFork(mask)) {
				if (isBridge(mask)) {
					firstBridge = i;
				}
				if (isFork(mask)) {
					firstFork = i;
				}
				break;
			}
			map.put(new Point(x, y), i);
		}

		int answer = min(firstRing, min(firstBridge, firstFork));
		if (answer == Integer.MAX_VALUE) {
			out.println("none");
			return;
		}

		List<String> what = new ArrayList<String>();
		if (firstBridge == answer) {
			what.add("bridge");
		}
		if (firstFork == answer) {
			what.add("fork");
		}
		if (firstRing == answer) {
			what.add("ring");
		}
		for (int i = 0; i < what.size(); i++) {
			if (i > 0) {
				out.print("-");
			}
			out.print(what.get(i));
		}
		out.println(" in move " + (answer + 1));

	}

	static boolean isBridge(int mask) {
		return Integer.bitCount(mask >> 6) >= 2;
	}

	static boolean isFork(int mask) {
		return Integer.bitCount(mask & ((1 << 6) - 1)) >= 3;
	}

	static int getSidesMask(int x, int y, int s) {
		if (x == 1 && y == 1) {
			return 1 << 6;
		}
		if (x == 1 && y == s) {
			return 1 << 7;
		}
		if (x == s && y == 1) {
			return 1 << 8;
		}
		if (x == s && y == 2 * s - 1) {
			return 1 << 9;
		}
		if (x == 2 * s - 1 && y == s) {
			return 1 << 10;
		}
		if (x == 2 * s - 1 && y == 2 * s - 1) {
			return 1 << 11;
		}

		if (x == 1) {
			return 1 << 0;
		}
		if (y == 1) {
			return 1 << 1;
		}
		if (x == 2 * s - 1) {
			return 1 << 2;
		}
		if (y == 2 * s - 1) {
			return 1 << 3;
		}
		if (y - x == s - 1) {
			return 1 << 4;
		}
		if (x - y == s - 1) {
			return 1 << 5;
		}
		return 0;
	}

	static class DSU {
		int[] p;

		public DSU(int n) {
			p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
		}

		public int get(int i) {
			if (p[i] != i)
				p[i] = get(p[i]);
			return p[i];
		}

		public void union(int i, int j) {
			i = get(i);
			j = get(j);
			if (i == j)
				return;
			p[j] = i;
		}
	}

	static class SpecialDSU {
		int[] p;
		int[] mask;

		public SpecialDSU(int n) {
			p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			mask = new int[n];
		}

		public int get(int i) {
			if (p[i] != i)
				p[i] = get(p[i]);
			return p[i];
		}

		public void union(int i, int j) {
			i = get(i);
			j = get(j);
			if (i == j)
				return;
			p[j] = i;
			mask[i] |= mask[j];
		}
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