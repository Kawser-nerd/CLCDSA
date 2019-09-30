import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class Deasy {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.println("Case #" + test + ":");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int r = nextInt(), c = nextInt();
		char[][] grid = new char[r][];
		for (int i = 0; i < r; i++) {
			grid[i] = nextToken().toCharArray();
		}

		int maxCave = -1;
		int[] cnt = new int[10];
		boolean[] isLucky = new boolean[10];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] >= '0' && grid[i][j] <= '9') {
					int cave = grid[i][j] - '0';
					maxCave = max(maxCave, cave);
					cnt[cave] = buildGrid(grid, i, j);
					isLucky[cave] = isLucky();
				}
			}
		}
		for (int i = 0; i <= maxCave; i++) {
			out.println(i + ": " + cnt[i] + " " + (isLucky[i] ? "Lucky" : "Unlucky"));
		}
	}

	static boolean isLucky() {
		State initial = new State();
		Set<State> set = new HashSet<State>();
		Queue<State> q = new ArrayDeque<State>();
		set.add(initial);
		q.add(initial);
		while (!q.isEmpty()) {
			State s = q.poll();
			for (State t : new State[] { s.goDown(), s.goLeft(), s.goRight() }) {
				if (t == null) {
					continue;
				}
				if (t.bitSet.cardinality() == 1) {
					return true;
				}
				if (!set.contains(t)) {
					set.add(t);
					q.add(t);
				}
			}
		}
		return false;
	}

	static int buildGrid(char[][] chars, int wantX, int wantY) {
		r = chars.length;
		c = chars[0].length;
		grid = new int[r][c];
		Queue<Integer> q = new ArrayDeque<Integer>();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (chars[i][j] == '#') {
					grid[i][j] = -1;
				} else {
					grid[i][j] = 1;
				}
			}
		}
		grid[wantX][wantY] = 0;
		q.add(wantX * c + wantY);
		int visited = 0;
		while (!q.isEmpty()) {
			int u = q.poll();
			visited++;
			int x = u / c, y = u % c;
			for (int i = 0; i < 3; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
					continue;
				}
				if (grid[nx][ny] <= 0) {
					continue;
				}
				q.add(nx * c + ny);
				grid[nx][ny] = 0;
			}
		}
		return visited;
	}

	static int[] dx = { 0, 0, -1 };
	static int[] dy = { -1, 1, 0 };

	static int[][] grid;
	static int r, c;

	static class State {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((bitSet == null) ? 0 : bitSet.hashCode());
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
			State other = (State) obj;
			if (bitSet == null) {
				if (other.bitSet != null)
					return false;
			} else if (!bitSet.equals(other.bitSet))
				return false;
			return true;
		}

		final BitSet bitSet;

		State() {
			bitSet = new BitSet(grid.length * grid[0].length);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (grid[i][j] == 0) {
						bitSet.set(i * c + j);
					}
				}
			}
		}

		private State(BitSet bitSet) {
			this.bitSet = bitSet;
		}

		State goLeft() {
			BitSet to = new BitSet(r * c);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!bitSet.get(i * c + j)) {
						continue;
					}
					if (j == 0 || grid[i][j - 1] < 0) {
						to.set(i * c + j);
					} else {
						if (grid[i][j - 1] > 0) {
							return null;
						} else {
							to.set(i * c + j - 1);
						}
					}
				}
			}
			return new State(to);
		}

		State goRight() {
			BitSet to = new BitSet(r * c);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!bitSet.get(i * c + j)) {
						continue;
					}
					if (j == c - 1 || grid[i][j + 1] < 0) {
						to.set(i * c + j);
					} else {
						if (grid[i][j + 1] > 0) {
							return null;
						} else {
							to.set(i * c + j + 1);
						}
					}
				}
			}
			return new State(to);
		}

		State goDown() {
			BitSet to = new BitSet(r * c);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!bitSet.get(i * c + j)) {
						continue;
					}
					if (i == r - 1 || grid[i + 1][j] < 0) {
						to.set(i * c + j);
					} else {
						if (grid[i + 1][j] > 0) {
							return null;
						} else {
							to.set((i + 1) * c + j);
						}
					}
				}
			}
			return new State(to);
		}
	}

	// static boolean isLucky(int[][] grid, int wantX, int wantY) {
	// int c = grid[0].length;
	//
	// }

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("D.in"));
			out = new PrintWriter("D.out");
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