import java.io.*;
import java.util.*;

public class C {

	static class Point {
		int id;
		Point next, prev;
		TreeSet<Point> edges;

		Point(int id) {
			this.id = id;
			edges = new TreeSet<C.Point>(new Comp(this));
		}

		public String toString() {
			return Integer.toString(id);
		}
	}

	static class Comp implements Comparator<Point> {
		Point p;

		public Comp(Point p) {
			this.p = p;
		}

		@Override
		public int compare(Point o1, Point o2) {
			if (o1.id < p.id == o2.id < p.id) {
				return o1.id - o2.id;
			}
			if (o1.id > p.id)
				return -1;
			else
				return 1;
		}
	}

	static class Ear {
		Point first, second;

		public Ear(Point first, Point second) {
			this.first = first;
			this.second = second;
		}
	}

	int n;
	int edges;
	Point[] p;
	Queue<Ear> ears;

	Point[] createPoints(int n, int[] begin, int[] end) {
		Point[] p = new Point[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Point(i);
		}
		for (int i = 0; i < n; i++) {
			p[i].next = p[(i + 1) % n];
			p[i].prev = p[(i + n - 1) % n];
		}
		for (int i = 0; i < edges; i++) {
			int u = begin[i], v = end[i];
			p[u].edges.add(p[v]);
			p[v].edges.add(p[u]);
		}
		return p;
	}

	private void solve() throws IOException {
		n = nextInt();
		edges = nextInt();
		int[] begin = new int[edges];
		int[] end = new int[edges];
		for (int i = 0; i < edges; i++) {
			begin[i] = nextInt() - 1;
		}
		for (int i = 0; i < edges; i++) {
			end[i] = nextInt() - 1;
		}
		p = createPoints(n, begin, end);
		int res = getRes();
		p = createPoints(n, begin, end);
		int[] colors = restoreColors(res);
		out.println(res);
		for (int i = 0; i < n; i++) {
			out.print((colors[i] + 1) + " ");
		}
		out.println();
	}

	int getRes() {
		int ate = 0;
		int res = Integer.MAX_VALUE;
		ears = new ArrayDeque<C.Ear>();
		findEars();
		// System.err.println(ears.size());
		// System.err.println("OK");
		while (ate < edges) {
			// System.err.println(ate + " " + edges + " " + ears.size());
			// findEars();
			Ear e = ears.poll();
			Point p = e.first, q = e.second;
			if (!p.edges.contains(q))
				continue;
			// System.err.println("CUTTING EAR " + p.id + " " + q.id);
			int size = 2;
			for (Point t = p.next; t != q; t = t.next) {
				size++;
			}
			// System.err.println("NO MORE EAR");
			res = Math.min(res, size);
			p.edges.remove(q);
			q.edges.remove(p);
			ate++;
			present = p;
			p.next = q;
			q.prev = p;
			if (ate == edges)
				break;
			Point p1 = p;
			while (p1.edges.isEmpty()) {
				p1 = p1.prev;
			}
			findEars1(p1);
		}
		int size = 1;
		for (Point p = present.next; p != present; p = p.next) {
			size++;
		}
		res = Math.min(res, size);
		return res;
	}

	int[] color;
	int colors;

	int[] restoreColors(int res) {
		colors = res;
		color = new int[n];
		Arrays.fill(color, -1);
		ears = new ArrayDeque<C.Ear>();
		findEars();
		color(0);
		return color;
	}

	Point present;

	void color(int ate) {
		if (ate == edges) {
			int col = 0;
			color[present.id] = col;
			for (Point t = present.next; t != present; t = t.next) {
				col = (col + 1) % colors;
				if (t.next != present || col != 0) {
					color[t.id] = col;
				} else {
					color[t.id] = 1;
				}
			}
			return;
		}
		Point p = null, q = null;
		// findEars();
		do {
			Ear e = ears.poll();
			p = e.first;
			q = e.second;
		} while (!p.edges.contains(q));
		ArrayList<Point> cutting = new ArrayList<C.Point>();
		for (Point t = p.next; t != q; t = t.next) {
			cutting.add(t);
		}
		p.edges.remove(q);
		q.edges.remove(p);
		p.next = q;
		q.prev = p;
		present = p;
		if (ate + 1 < edges) {
			Point p1 = p;
			while (p1.edges.isEmpty()) {
				p1 = p1.prev;
			}
			findEars1(p1);
		}
		color(ate + 1);
		int col = -1;
		int havecolors = 2;
		for (Point t : cutting) {
			col = (col + 1) % colors;
			if (havecolors >= colors) {
				while (col == color[t.prev.id] || col == color[t.next.id]) {
					col = (col + 1) % colors;
				}
			} else {
				while (col == color[p.id] || col == color[q.id]) {
					col = (col + 1) % colors;
				}
				havecolors++;
			}
			color[t.id] = col;
			// System.err.println(color[t.id]);
		}
		// System.err.println("END");
	}

	boolean isEar(Point p, Point q) {
		for (Point t = p.next; t != q; t = t.next) {
			if (!t.edges.isEmpty())
				return false;
		}
		return true;
	}

	void findEars1(Point p) {
		if (p.edges.isEmpty())
			return;
		Point q = p.edges.first();
		if (isEar(p, q)) {
			ears.add(new Ear(p, q));
		}
	}

	void findEars() {
		for (int i = 0; i < n; i++) {
			Point p = this.p[i];
			if (p.edges.isEmpty())
				continue;
			Point q = p.edges.first();
			if (isEar(p, q)) {
				ears.add(new Ear(p, q));
			}
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "C-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}