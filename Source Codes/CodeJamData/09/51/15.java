import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class A {
    final String fn = "A-large";

    class Point implements Comparable<Point> {
	int x, y;

	public Point(int x, int y) {
	    this.x = x;
	    this.y = y;
	}

	@Override
	public int compareTo(Point o) {
	    if (x < o.x)
		return -1;
	    if (x > o.x)
		return 1;
	    return y - o.y;
	}

	@Override
	public boolean equals(Object obj) {
	    Point p = (Point) obj;
	    return x == p.x && y == p.y;
	}

	@Override
	public String toString() {
	    return "(" + x + ", " + y + ")";
	}
    }

    class State {
	Point[] p;
	int hash;
	boolean danger;

	public State(ArrayList<Point> al) {
	    p = new Point[al.size()];
	    for (int i = 0; i < p.length; i++) {
		p[i] = al.get(i);
	    }
	    checkConnect();
	    makeHash();
	}

	public State(State s) {
	    p = new Point[s.p.length];
	    for (int i = 0; i < p.length; i++) {
		p[i] = s.p[i];
	    }
	}

	void makeHash() {
	    Arrays.sort(p);
	    hash = 0;
	    for (int i = 0; i < p.length; i++) {
		hash *= 43;
		hash += 17 * p[i].x + p[i].y;
	    }
	}

	@Override
	public int hashCode() {
	    return hash;
	}

	@Override
	public boolean equals(Object obj) {
	    return Arrays.equals(p, ((State) obj).p);
	}

	public void draw(boolean[][] map, boolean b) {
	    for (int i = 0; i < p.length; i++) {
		map[p[i].x][p[i].y] = b;
	    }
	}

	public void checkConnect() {
	    boolean[][] d = new boolean[p.length][p.length];
	    for (int i = 0; i < d.length; i++) {
		for (int j = 0; j < d.length; j++) {
		    if (Math.abs(p[i].x - p[j].x) + Math.abs(p[i].y - p[j].y) <= 1)
			d[i][j] = true;
		}
	    }
	    for (int k = 0; k < d.length; k++) {
		for (int i = 0; i < d.length; i++) {
		    for (int j = 0; j < d.length; j++) {
			d[i][j] |= d[i][k] && d[k][j];
		    }
		}
	    }
	    // System.err.println(Arrays.deepToString(d));
	    danger = false;
	    for (int i = 0; i < d.length; i++) {
		for (int j = 0; j < d.length; j++) {
		    if (!d[i][j]) {
			danger = true;
			return;
		    }
		}
	    }
	}

	@Override
	public String toString() {
	    return danger + Arrays.toString(p);
	}

    }

    final int[] DX = { -1, 1, 0, 0 };
    final int[] DY = { 0, 0, -1, 1 };

    boolean[][] map;

    private void solve() throws IOException {
	int r = nextInt();
	int c = nextInt();
	ArrayList<Point> alfrom = new ArrayList<Point>();
	ArrayList<Point> alto = new ArrayList<Point>();
	map = new boolean[r][c];
	for (int i = 0; i < r; i++) {
	    String s = br.readLine();
	    for (int j = 0; j < c; j++) {
		if (s.charAt(j) == 'x') {
		    alto.add(new Point(i, j));
		} else if (s.charAt(j) == 'o') {
		    alfrom.add(new Point(i, j));
		} else if (s.charAt(j) == 'w') {
		    alto.add(new Point(i, j));
		    alfrom.add(new Point(i, j));
		} else if (s.charAt(j) == '#') {
		    map[i][j] = true;
		}
	    }
	}
	State from = new State(alfrom);
	State to = new State(alto);
	Queue<State> q = new LinkedList<State>();
	q.add(from);
	Map<State, Integer> u = new HashMap<State, Integer>();
	u.put(from, 0);
	System.err.println(" from = " + from);
	System.err.println(" to = " + to);
	int it = 0;
	while (!q.isEmpty()) {
	    it++;
	    State v = q.poll();
	    int dist = u.get(v);
	    // System.err.println(v);
	    if (v.equals(to)) {
		System.err.println(dist);
		System.err.println("\t\t\tit = " + it);
		out.println(dist);
		return;
	    }
	    v.draw(map, true);
	    for (int i = 0; i < v.p.length; i++) {
		for (int d = 0; d < DX.length; d++) {
		    if (!busy(v.p[i].x + DX[d], v.p[i].y + DY[d])
			    && !busy(v.p[i].x - DX[d], v.p[i].y - DY[d])) {
			State n = new State(v);
			n.p[i] = new Point(v.p[i].x + DX[d], v.p[i].y + DY[d]);
			n.checkConnect();
			if (n.danger && v.danger) {
			    continue;
			}
			n.makeHash();
			// System.err.println("." + n + " " + n.hash);
			if (u.containsKey(n)) {
			    continue;
			}
			u.put(n, dist + 1);
			q.add(n);
		    }
		}
	    }

	    v.draw(map, false);
	}
	System.err.println(-1);
	System.err.println("\t\t\tit = " + it);
	out.println(-1);
    }

    boolean busy(int x, int y) {
	if (x < 0 || x >= map.length || y < 0 || y >= map[0].length)
	    return true;
	return map[x][y];
    }

    PrintWriter out;
    BufferedReader br;
    StringTokenizer st;

    private void run() {
	try {
	    br = new BufferedReader(new FileReader(fn + ".in"));
	    out = new PrintWriter(fn + ".out");
	    int t = nextInt();
	    for (int i = 1; i <= t; i++) {
		System.err.println("Case #" + i + ": ");
		out.print("Case #" + i + ": ");
		solve();
	    }
	    out.close();
	} catch (IOException e) {
	    e.printStackTrace();
	    System.exit(1);
	}
    }

    String nextToken() {
	try {
	    while (st == null || !st.hasMoreTokens()) {
		st = new StringTokenizer(br.readLine());
	    }
	    return st.nextToken();
	} catch (IOException e) {
	    return "";
	}
    }

    int nextInt() {
	return Integer.parseInt(nextToken());
    }

    public static void main(String[] args) {
	new A().run();
    }
}
