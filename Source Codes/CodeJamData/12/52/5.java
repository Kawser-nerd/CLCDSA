import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "b";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int s = nextInt();
			int m = nextInt();
			Cell[][] a = new Cell[2 * s - 1][2 * s - 1];
			for (int x = 0; x < s; x++) {
				for (int z = 0; z < 2 * s - 1 - x; z++) {
					a[z][x + z] = new Cell(z, x + z);
					if (x != 0) {
						a[x + z][z] = new Cell(x + z, z);
					}
				}
			}
			int[] mx = new int[m];
			int[] my = new int[m];
			for (int i = 0; i < my.length; i++) {
				mx[i] = nextInt() - 1;
				my[i] = nextInt() - 1;
			}
			int n = 0;
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] != null) {
						a[i][j].num = n++;
					}
				}
			}
			int[] px = new int[n];
			int[] py = new int[n];
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] != null) {
						px[a[i][j].num] = i;
						py[a[i][j].num] = j;
					}
				}
			}

			Union white = new Union(n);
			Union black = new Union(n);
			for (int i = 1; i + 1 < s; i++) {
				a[0][i].edge = true;
				white.flag[a[0][i].num][6] = true;
				black.flag[a[0][i].num][6] = true;
				a[i][0].edge = true;
				white.flag[a[i][0].num][7] = true;
				black.flag[a[i][0].num][7] = true;
				a[0 + i][s - 1 + i].edge = true;
				white.flag[a[0 + i][s - 1 + i].num][8] = true;
				black.flag[a[0 + i][s - 1 + i].num][8] = true;
				a[s - 1 + i][0 + i].edge = true;
				white.flag[a[s - 1 + i][0 + i].num][9] = true;
				black.flag[a[s - 1 + i][0 + i].num][9] = true;
				a[2 * s - 2 - i][2 * s - 2].edge = true;
				white.flag[a[2 * s - 2 - i][2 * s - 2].num][10] = true;
				black.flag[a[2 * s - 2 - i][2 * s - 2].num][10] = true;
				a[2 * s - 2][2 * s - 2 - i].edge = true;
				white.flag[a[2 * s - 2][2 * s - 2 - i].num][11] = true;
				black.flag[a[2 * s - 2][2 * s - 2 - i].num][11] = true;
			}
			a[0][0].corner = true;
			white.flag[a[0][0].num][0] = true;
			black.flag[a[0][0].num][0] = true;
			a[0][s - 1].corner = true;
			white.flag[a[0][s - 1].num][1] = true;
			black.flag[a[0][s - 1].num][1] = true;
			a[s - 1][0].corner = true;
			white.flag[a[s - 1][0].num][2] = true;
			black.flag[a[s - 1][0].num][2] = true;
			a[2 * s - 2][2 * s - 2].corner = true;
			white.flag[a[2 * s - 2][2 * s - 2].num][3] = true;
			black.flag[a[2 * s - 2][2 * s - 2].num][3] = true;
			a[2 * s - 2][s - 1].corner = true;
			white.flag[a[2 * s - 2][s - 1].num][4] = true;
			black.flag[a[2 * s - 2][s - 1].num][4] = true;
			a[s - 1][2 * s - 2].corner = true;
			white.flag[a[s - 1][2 * s - 2].num][5] = true;
			black.flag[a[s - 1][2 * s - 2].num][5] = true;

			int bridge = m + 1;
			int fork = m + 1;
			int ring = m + 1;

			for (int turn = 0; turn < mx.length; turn++) {
				int x = mx[turn];
				int y = my[turn];

				a[x][y].white = true;

				union(white, a, x, y, 1, 1);
				union(white, a, x, y, -1, -1);
				union(white, a, x, y, 1, 0);
				union(white, a, x, y, 0, 1);
				union(white, a, x, y, -1, 0);
				union(white, a, x, y, 0, -1);

				int num = white.get(a[x][y].num);

				int corners = 0;
				int edges = 0;

				for (int i = 0; i < 12; i++) {
					if (white.flag[num][i]) {
						if (i < 6) {
							corners++;
						} else {
							edges++;
						}
					}
				}

				if (corners >= 2) {
					bridge = Math.min(bridge, turn + 1);
				}
				if (edges >= 3) {
					fork = Math.min(fork, turn + 1);
				}

			}

			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] == null || a[i][j].white) {
						continue;
					}
					int x = i;
					int y = j;
					union2(black, a, x, y, 1, 1);
					union2(black, a, x, y, -1, -1);
					union2(black, a, x, y, 1, 0);
					union2(black, a, x, y, 0, 1);
					union2(black, a, x, y, -1, 0);
					union2(black, a, x, y, 0, -1);
				}
			}

			for (int turn = mx.length - 1; turn >= 0; turn--) {
				int x = mx[turn];
				int y = my[turn];

				a[x][y].white = false;

				boolean unreachable = false;

				unreachable |= check(black, a, x, y, 1, 1);
				unreachable |= check(black, a, x, y, -1, -1);
				unreachable |= check(black, a, x, y, 1, 0);
				unreachable |= check(black, a, x, y, 0, 1);
				unreachable |= check(black, a, x, y, -1, 0);
				unreachable |= check(black, a, x, y, 0, -1);

				union2(black, a, x, y, 1, 1);
				union2(black, a, x, y, -1, -1);
				union2(black, a, x, y, 1, 0);
				union2(black, a, x, y, 0, 1);
				union2(black, a, x, y, -1, 0);
				union2(black, a, x, y, 0, -1);

				boolean unr = check(black, a, x, y, 0, 0);

				if (unreachable && !unr) {
					ring = Math.min(ring, turn + 1);
				}

			}

			int win = Math.min(bridge, Math.min(fork, ring));
			if (win > m) {
				out.println("none");
			} else {
				boolean first = true;
				if (bridge == win) {
					if (!first) {
						out.print("-");
					}
					first = false;
					out.print("bridge");
				}
				if (fork == win) {
					if (!first) {
						out.print("-");
					}
					first = false;
					out.print("fork");
				}
				if (ring == win) {
					if (!first) {
						out.print("-");
					}
					first = false;
					out.print("ring");
				}
				out.println(" in move " + win);
			}

		}
	}

	private void union2(Union black, Cell[][] a, int x, int y, int dx, int dy) {
		if (0 <= x + dx && 0 <= y + dy && x + dx < a.length
				&& y + dy < a.length && a[x + dx][y + dy] != null
				&& !a[x + dx][y + dy].white) {
			black.union(a[x][y].num, a[x + dx][y + dy].num);
		}
	}

	private boolean check(Union black, Cell[][] a, int x, int y, int dx, int dy) {
		if (0 <= x + dx && 0 <= y + dy && x + dx < a.length
				&& y + dy < a.length && a[x + dx][y + dy] != null
				&& !a[x + dx][y + dy].white) {
			boolean good = true;
			int num = a[x + dx][y + dy].num;
			for (int i = 0; i < black.flag[num].length; i++) {
				good &= !black.getFlag(num, i);
			}
			return good;
		}
		return false;
	}

	private void union(Union white, Cell[][] a, int x, int y, int dx, int dy) {
		if (0 <= x + dx && 0 <= y + dy && x + dx < a.length
				&& y + dy < a.length && a[x + dx][y + dy] != null
				&& a[x + dx][y + dy].white) {
			white.union(a[x][y].num, a[x + dx][y + dy].num);
		}
	}

	class Union {

		public Union(int n) {
			u = new int[n];
			for (int i = 0; i < u.length; i++) {
				u[i] = i;
			}
			r = new int[n];
			flag = new boolean[n][12];
		}

		public boolean getFlag(int x, int i) {
			x = get(x);
			return flag[x][i];
		}

		public void union(int x, int y) {
			x = get(x);
			y = get(y);
			if (x == y) {
				return;
			}
			if (r[x] == r[y]) {
				r[x]++;
			}
			if (r[x] > r[y]) {
				u[y] = x;
				for (int i = 0; i < flag[y].length; i++) {
					flag[x][i] |= flag[y][i];
				}
			} else {
				u[x] = y;
				for (int i = 0; i < flag[y].length; i++) {
					flag[y][i] |= flag[x][i];
				}
			}
		}

		private int get(int x) {
			if (u[x] != x) {
				u[x] = get(u[x]);
			}
			return u[x];
		}

		int[] u;
		int[] r;
		boolean[][] flag;

	}

	class Cell {
		public Cell(int x, int y) {
			this.x = x;
			this.y = y;
		}

		int x, y;
		int num;
		boolean corner;
		boolean edge;
		boolean white;
	}
}
