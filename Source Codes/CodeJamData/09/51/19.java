import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Task implements Runnable {
	private static String id = "a";
	private static int dx[] = {1, 0, -1, 0};
	private static int dy[] = {0, 1, 0, -1};

	private Scanner in;
	private PrintWriter out;

	private class Box {
		private int x, y;

		private Box(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) {
				return true;
			}
			if (o == null || getClass() != o.getClass()) {
				return false;
			}

			Box box = (Box) o;

			if (x != box.x) {
				return false;
			}
			if (y != box.y) {
				return false;
			}

			return true;
		}

		@Override
		public int hashCode() {
			int result = x;
			result = 31 * result + y;
			return result;
		}
	}

	private class Position {
		private Set<Box> s = new HashSet<Box>();

		@Override
		public boolean equals(Object o) {
			if (this == o) {
				return true;
			}
			if (o == null || getClass() != o.getClass()) {
				return false;
			}

			Position position = (Position) o;

			if (s != null ? !s.equals(position.s) : position.s != null) {
				return false;
			}

			return true;
		}

		@Override
		public int hashCode() {
			return s != null ? s.hashCode() : 0;
		}

		private boolean isValid() {
			if (s.size() == 1)
				return true;
			int e = 0;
			for (Box b : s) {
				int d = 0;
				Box c = new Box(b.x, b.y);
				for (int i = 0; i < 4; i++) {
					c.x += dx[i];
					c.y += dy[i];
					if (s.contains(c))
						d++;
					c.x -= dx[i];
					c.y -= dy[i];
				}
				if (d == 0)
					return false;
				e += d;
			}
			return e / 2 >= s.size() - 1;
		}

		private Position copy() {
			Position c = new Position();
			for (Box b : s)
				c.s.add(new Box(b.x, b.y));
			return c;
		}
	}

	private Map<Position, Integer> ans = new HashMap<Position, Integer>();
	private int r, c, result;
	private char[][] t;

	private void init() {
		try {
			in = new Scanner(new File(id + ".in"));
			out = new PrintWriter(id + ".out");
		} catch (FileNotFoundException ignored) {
		}
	}

	private void read() {
		r = in.nextInt();
		c = in.nextInt();
		t = new char[r + 2][c + 2];
		for (int i = 0; i < r; i++) {
			String s = in.next();
			System.arraycopy(s.toCharArray(), 0, t[i + 1], 1, c);
			t[i + 1][0] = '#';
			t[i + 1][c + 1] = '#';
		}
		Arrays.fill(t[0], '#');
		Arrays.fill(t[r + 1], '#');
	}

	private boolean checkMove(Position p, Box b, int d) {
		Box bb = new Box(b.x, b.y);
		bb.x += dx[d];
		bb.y += dy[d];
		if (p.s.contains(bb) || t[bb.x][bb.y] == '#')
			return false;
		bb.x -= 2 * dx[d];
		bb.y -= 2 * dy[d];
		if (p.s.contains(bb) || t[bb.x][bb.y] == '#')
			return false;
		return true;
	}

	private void solve()  {
		ans.clear();
		Position start = new Position();
		Position finish = new Position();
		r += 2;
		c += 2;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (t[i][j] == 'x' || t[i][j] == 'w')
					finish.s.add(new Box(i, j));
				if (t[i][j] == 'o' || t[i][j] == 'w')
					start.s.add(new Box(i, j));
			}
		}
		List<List<Position>> p = new ArrayList<List<Position>>();
		p.add(new ArrayList<Position>());
		p.get(0).add(start);
		ans.put(start, 0);
		result = -1;
		for (int cp = 0; cp < p.size(); cp++) {
			for (Position pos : p.get(cp)) {
				Position cc = pos.copy();
				if (cc.equals(finish)) {
					result = cp;
					return;
				}
				Position dd = cc.copy();
				for (Box bb1 : cc.s) {
					Box b1 = new Box(bb1.x, bb1.y);
					for (int j = 0; j < 4; j++) {
						if (checkMove(cc, b1, j)) {
							dd.s.remove(b1);
							b1.x += dx[j];
							b1.y += dy[j];
							dd.s.add(b1);
							if (dd.isValid()) {
								if (!ans.containsKey(dd)) {
									if (p.size() == cp + 1) {
										p.add(new ArrayList<Position>());
									}
									p.get(cp + 1).add(dd.copy());
									ans.put(dd.copy(), cp + 1);
								}
								dd.s.remove(b1);
								b1.x -= dx[j];
								b1.y -= dy[j];
								dd.s.add(b1);
								continue;
							}
							Position ee = dd.copy();
							for (Box bb2 : dd.s) {
								Box b2 = new Box(bb2.x, bb2.y);
								for (int k = 0; k < 4; k++) {
									if (checkMove(dd, b2, k)) {
										ee.s.remove(b2);
										b2.x += dx[k];
										b2.y += dy[k];
										ee.s.add(b2);
										if (ee.isValid()) {
											if (!ans.containsKey(ee)) {
												while (p.size() <= cp + 2) {
													p.add(new ArrayList<Position>());
												}
												p.get(cp + 2).add(ee.copy());
												ans.put(ee.copy(), cp + 2);
											}
										}
										ee.s.remove(b2);
										b2.x -= dx[k];
										b2.y -= dy[k];
										ee.s.add(b2);
									}
								}
							}
							dd.s.remove(b1);
							b1.x -= dx[j];
							b1.y -= dy[j];
							dd.s.add(b1);
						}
					}
				}
			}
		}
	}

	private void write(int t) {
		out.println("Case #" + t + ": " + result);
	}

	public void run() {
		init();
		int nt = in.nextInt();
		for (int i = 0; i < nt; i++) {
			read();
			solve();
			write(i + 1);
		}
		out.close();
	}

	public static void main(String[] args) {
		new Thread(new Task()).start();
	}
}
