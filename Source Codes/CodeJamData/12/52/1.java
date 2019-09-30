import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Point {
		final int x, y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int hashCode() {
			return x * 1000000007 + y;
		}
		
		public boolean equals(Object obj) {
			if (!(obj instanceof Point)) {
				return false;
			}
			Point p = (Point) obj;
			return x == p.x && y == p.y;
		}
		
		static int DX[] = {1, 1, 0, -1, -1, 0};
		static int DY[] = {0, 1, 1, 0, -1, -1};
		
		Point[] neighbours(int size) {
			Point ans[] = new Point[6];
			for (int d = 0; d < 6; d++) {
				int nx = x + DX[d];
				int ny = y + DY[d];
				if (nx < 0 || nx - ny >= size || nx >= 2 * size - 1 ||
					ny < 0 || ny - nx >= size || ny >= 2 * size - 1) {
					continue;
				}
				ans[d] = new Point(nx, ny);
			}
			return ans;
		}
	}
	
	static class DSU {
		Map<Point, Point> data = new HashMap<Point, Point>();
		Map<Point, Integer> conn = new HashMap<Point, Integer>();
		
		void introduce(Point i) {
			if (data.get(i) != null) {
				throw new AssertionError();
			}
			data.put(i, i);
			conn.put(i, 0);
		}
		
		void adjustConn(Point i, int c) {
			i = get(i);
			conn.put(i, conn.get(i) | c);
		}
		
		int getConn(Point i) {
			return conn.get(get(i));
		}
		
		Point get(Point i) {
			Point ii = data.get(i);
			if (ii == null) {
				throw new AssertionError();
			}
			if (ii == i) {
				return ii;
			}
			ii = get(ii);
			data.put(i, ii);
			return ii;
		}
		
		boolean have(Point i) {
			return data.containsKey(i);
		}
		
		boolean merge(Point i, Point j) {
			i = get(i);
			j = get(j);
			if (!i.equals(j)) {
				data.put(j, i);
				conn.put(i, conn.get(i) | conn.get(j));
				return true;
			}
			return false;
		}
	}
	
//	static void merge(Map<Point, Point> dsu, Point i, Point j) {
//		i = get(dsu, i);
//		j = get(dsu, j);
//		if (i != j) {
//			dsu.put(j, i);
//		}
//	}
//	
//	static boolean conn(Map<Point, Point> dsu, Point i, Point j) {
//		if (i == null || j == null) {
//			return false;
//		}
//		i = get(dsu, i);
//		j = get(dsu, j);
//		return i != null && j != null && i == j;
//	}
	
	static void solve() throws Exception {
//		System.err.println();
//		System.err.println("NEW TEST " + test);
		int size = nextInt();
//		System.err.println("SIZE " + size);
		int n = nextInt();
		Point moves[] = new Point[n];
		for (int i = 0; i < n; i++) {
			moves[i] = new Point(nextInt() - 1, nextInt() - 1);
		}
		DSU dsu = new DSU();
		Point corners[] = {new Point(0, 0), new Point(size - 1, 0),
			new Point(2 * size - 2, size - 1),
			new Point(2 * size - 2, 2 * size - 2),
			new Point(size - 1, 2 * size - 2),
			new Point(0, size - 1)};
		
		for (int i = 0; i < n; i++) {
			Point cur = moves[i];
//			System.err.println("POINT " + cur.x + " " + cur.y);
			dsu.introduce(cur);
			boolean ring = false;
			Point[] ne = cur.neighbours(size);
			int fi = -1;
			for (int j = 0; j < 6; j++) {
				Point next = ne[j];
				if (next == null || !dsu.have(next)) {
					fi = (j + 1) % 6;
					break;
				}
			}
			if (fi < 0) {
				throw new AssertionError();
			}
			for (int j = 0; j < 6; j++) {
				Point next = ne[(j + fi) % 6];
				if (next == null || !dsu.have(next)) {
					continue;
				}
//				System.err.println("NEIGHBOUR " + next.x + " " + next.y);
				if (!dsu.merge(cur, next)) {
					ring = true;
				}
				for (j++; j < 6 && ne[(j + fi) % 6] != null && dsu.have(ne[(j + fi) % 6]); j++) { }
			}
			boolean bridge = false;
			for (int i1 = 0; i1 < 6; i1++) {
				if (!dsu.have(corners[i1])) {
					continue;
				}
				Point p1 = dsu.get(corners[i1]);
				for (int i2 = i1 + 1; i2 < 6; i2++) {
					if (!dsu.have(corners[i2])) {
						continue;
					}
					Point p2 = dsu.get(corners[i2]);
					if (!p1.equals(p2)) {
						continue;
					}
//					System.err.println("BRIDGE " + (i1 + 1) + " " + (i2 + 1));
					bridge = true;
				}
			}
			boolean fork = false;
			if (cur.y == 0 && cur.x > 0 && cur.x < size - 1) {
//				System.err.println("SIDE 1");
				dsu.adjustConn(cur, 1);
			}
			if (cur.x - cur.y == size - 1 && cur.y > 0 && cur.y < size - 1) {
//				System.err.println("SIDE 2");
				dsu.adjustConn(cur, 2);
			}
			if (cur.x == 2 * size - 2 && cur.y > size - 1 && cur.y < 2 * size - 2) {
//				System.err.println("SIDE 3");
				dsu.adjustConn(cur, 4);
			}
			if (cur.y == 2 * size - 2 && cur.x > size - 1 && cur.x < 2 * size - 2) {
//				System.err.println("SIDE 4");
				dsu.adjustConn(cur, 8);
			}
			if (cur.y - cur.x == size - 1 && cur.x > 0 && cur.x < size - 1) {
//				System.err.println("SIDE 5");
				dsu.adjustConn(cur, 16);
			}
			if (cur.x == 0 && cur.y > 0 && cur.y < size - 1) {
//				System.err.println("SIDE 6");
				dsu.adjustConn(cur, 32);
			}
//			System.err.println("MASK " + Integer.toString(dsu.getConn(cur), 2));
			if (Integer.bitCount(dsu.getConn(cur)) >= 3) {
				fork = true;
			}
			if (!ring && !bridge && !fork) {
				continue;
			}
			boolean got = false;
			printCase();
			if (bridge) {
				out.print("bridge");
				got = true;
			}
			if (fork) {
				if (got) {
					out.print('-');
				}
				out.print("fork");
				got = true;
			}
			if (ring) {
				if (got) {
					out.print('-');
				}
				out.print("ring");
			}
			out.println(" in move " + (i + 1));
			return;
		}
		printCase();
		out.println("none");
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}