import java.util.*;

public class Main
{
	public static void main(String[] args) {
		new Main().run();
	}

	List<Collection<ROmino>> ominoes = new ArrayList<>();

	void gen() {
		ominoes.add(Arrays.asList(new ROmino(new Omino())));
		for (int i = 1; i < 7; i++) {
			Set<ROmino> s = new HashSet<>();
			ominoes.add(s);
			for (ROmino o : ominoes.get(i-1)) {
				o.extend(s);
			}
		}
	}

	void run() {
		Scanner in = new Scanner(System.in);
		gen();
		int ts = in.nextInt();
		for (int ti = 1; ti <= ts; ti++) {
			String ans;
			if (possible(in.nextInt(), in.nextInt(), in.nextInt())) {
				ans = "GABRIEL";
			} else {
				ans = "RICHARD";
			}
			System.out.println("Case #" + ti + ": " + ans);
		}
	}

	void dump(Omino o, int R, int C) {
		int rs = Math.max(o.bound().y + 1, R);
		int cs = Math.max(o.bound().x + 1, C);
		for (int r = 0; r < rs; r++) {
			for (int c = 0; c < cs; c++) {
				System.err.print(o.points.contains(new Point(c, r)) ? 'X' : r < R && c < C ? 'o' : ' ');
			}
			System.err.println();
		}
	}

	void dump(int x, int r, int c) {
		dump(ominoes.get(x-1).iterator().next().omino, r, c);
	}

	boolean possible(int x, int r, int c) {
		//System.err.println();
		//System.err.println("X = " + x + ", size = " + r + "*" + c + " = " + r*c);
		if (r*c % x != 0 || x >= 7) {
			if (x >= 7) {
				//System.err.println("X is big, can make a loop");
			} else {
				//System.err.println("Board size not a multiple of X");
				//dump(x, r, c);
			}
			return false;
		} else if (r >= x + 2 && c >= x + 2) {
			//System.err.println("Lots of spare room! Gabriel wins!");
			//dump(x, r, c);
			return true;
		}
		for (ROmino o : ominoes.get(x-1)) {
			if (!possible(o.omino, r, c) && !possible(o.omino, c, r)) {
				//System.err.println("Found omino that doesn't fit");
				//dump(o.omino, r, c);
				return false;
			}
		}
		//System.err.println("All ominoes possible! Gabriel wins!");
		//dump(x, r, c);
		return true;
	}

	boolean possible(Omino o, int xs, int ys) {
		Point bound = o.bound();
		for (int dx = 0; dx + bound.x < xs; dx++) {
			for (int dy = 0; dy + bound.y < ys; dy++) {
				if (possible(o, xs, ys, dx, dy)) {
					return true;
				}
			}
		}
		return false;
	}

	boolean possible(Omino o, int xs, int ys, int dx, int dy) {
		boolean[][] board = new boolean[xs][ys];
		for (Point p : o.points) {
			board[p.x+dx][p.y+dy] = true;
		}
		return flood(board, o.points.size());
	}

	boolean flood(boolean[][] board, int size) {
		for (int x = 0; x < board.length; x++) {
			for (int y = 0; y < board[x].length; y++) {
				if (!board[x][y]) {
					if (flood(board, x, y) % size != 0) {
						return false;
					}
				}
			}
		}
		return true;
	}

	int flood(boolean[][] board, int x, int y) {
		if (x < 0 || y < 0 || x >= board.length || y >= board[x].length || board[x][y]) {
			return 0;
		}
		int c = 1;
		board[x][y] = true;
		for (int i = 0; i < 4; i++) {
			c += flood(board, x+Point.dx[i], y+Point.dy[i]);
		}
		return c;
	}
}

class Omino
{
	final Set<Point> points = new HashSet<>();

	Omino() { points.add(new Point(0,0)); }

	Omino(Omino omino, Point p) {
		int dx = Math.max(-p.x, 0), dy = Math.max(-p.y, 0);
		points.add(p.update(dx, dy));
		for (Point q : omino.points) {
			points.add(q.update(dx, dy));
		}
	}

	Omino(Set<Point> s, Transform t) {
		int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
		for (Point p : s) {
			minX = Math.min(minX, t.x(p));
			minY = Math.min(minY, t.y(p));
		}
		for (Point p : s) {
			points.add(new Point(t.x(p) - minX, t.y(p) - minY));
		}
	}

	public Point bound() {
		int maxX = 0, maxY = 0;
		for (Point p : points) {
			maxX = Math.max(maxX, p.x);
			maxY = Math.max(maxY, p.y);
		}
		return new Point(maxX, maxY);
	}

	@Override public boolean equals(Object o) { return o instanceof Omino && points.equals(((Omino) o).points); }
	@Override public int hashCode() { return points.hashCode(); }
	@Override public String toString() { return points.toString(); }
}

class ROmino
{
	final Omino omino;

	ROmino(Omino omino) { this.omino = omino; }

	Omino[] rotations() {
		Omino[] rots = new Omino[Transform.transforms.length];
		for (int i = 0; i < rots.length; i++) {
			rots[i] = new Omino(omino.points, Transform.transforms[i]);
		}
		return rots;
	}

	void extend(Set<ROmino> out) {
		for (Point p : omino.points) {
			for (Point q : p.nbrs()) {
				if (!omino.points.contains(q)) {
					out.add(new ROmino(new Omino(omino, q)));
				}
			}
		}
	}

	@Override public boolean equals(Object o) { return o instanceof ROmino && Arrays.asList(rotations()).contains(((ROmino) o).omino); }
	@Override public int hashCode() { int h = 0; for (Omino o : rotations()) h += o.hashCode(); return h; }
	@Override public String toString() { return omino.toString(); }
}

class Point
{
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};
	final int x, y;
	Point(int x, int y) { this.x = x; this.y = y; }
	@Override public boolean equals(Object o) { return o instanceof Point && x == ((Point) o).x && y == ((Point) o).y; }
	@Override public int hashCode() { return x * 107 + y; }
	@Override public String toString() { return String.format("(%d, %d)", x, y); }
	Point[] nbrs() { Point[] r = new Point[4]; for (int i = 0; i < 4; i++) r[i] = update(dx[i], dy[i]); return r; }
	Point update(int dx, int dy) { return (dx != 0 || dy != 0) ? new Point(x+dx, y+dy) : this; }
}

class Transform
{
	static Transform[] transforms = new Transform[] {
		new Transform(1,0,0,1),
		new Transform(-1,0,0,1),
		new Transform(1,0,0,-1),
		new Transform(-1,0,0,-1),
		new Transform(0,1,1,0),
		new Transform(0,-1,1,0),
		new Transform(0,1,-1,0),
		new Transform(0,-1,-1,0)
	};
	static Transform diag = new Transform(0,1,1,0);
	final int x1, x2, y1, y2;
	Transform(int x1, int x2, int y1, int y2) { this.x1 = x1; this.x2 = x2; this.y1 = y1; this.y2 = y2; }
	int x(Point p) { return x1 * p.x + x2 * p.y; }
	int y(Point p) { return y1 * p.x + y2 * p.y; }
}
