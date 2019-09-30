//Using jts from http://www.vividsolutions.com/jts/download.htm
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

import com.vividsolutions.jts.geom.Coordinate;
import com.vividsolutions.jts.geom.Geometry;
import com.vividsolutions.jts.geom.GeometryFactory;
import com.vividsolutions.jts.geom.LinearRing;
import com.vividsolutions.jts.geom.Polygon;

public class D {

	String filename = "D-small-attempt0";

	class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

		public double dist(Point b) {
			return Math.sqrt((this.x - b.x) * (this.x - b.x) + (this.y - b.y) * (this.y - b.y));
		}

	}

	class Circle {
		public Circle(double x1, double y1, double r) {
			Coordinate center = new Coordinate(x1, y1);
			GeometryFactory factory = new GeometryFactory();
			int NMAX = 100000;
			r = r * Math.sqrt(2 * Math.PI / NMAX / Math.sin(2 * Math.PI / NMAX));
			Coordinate[] coords = new Coordinate[NMAX + 1];

			for (int i = 0; i < NMAX; ++i) {
				double alpha = 2 * Math.PI / NMAX * i;
				coords[i] = new Coordinate(center.x + r * Math.cos(alpha), center.y + r * Math.sin(alpha));
			}
			coords[NMAX] = coords[0];
			Polygon pol2 = factory.createPolygon(factory.createLinearRing(coords), null);
			polygon = pol2;
		}

		public Geometry getGeometry() {
			return polygon;
		}

		private Geometry polygon;
	}

	double solve2(double x1, double y1, double r1, double x2, double y2, double r2) {
		Geometry c1 = new Circle(x1, y1, r1).polygon;
		Geometry c2 = new Circle(x2, y2, r2).polygon;
		Geometry c12 = c1.intersection(c2);
		return c12.getArea();
	}

	// double solve2(double x1, double y1, double r1, double x2, double y2, double r2) {
	// double xa = -((y2 - y1)
	// * sqrt(-y2
	// * y2
	// * y2
	// * y2
	// + 4
	// * y1
	// * y2
	// * y2
	// * y2
	// + (-6 * y1 * y1 - 2 * x2 * x2 + 4 * x1 * x2 - 2 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1)
	// * y2
	// * y2
	// + (4 * y1 * y1 * y1 + (4 * x2 * x2 - 8 * x1 * x2 + 4 * x1 * x1 - 4 * r2 * r2 - 4 * r1 * r1)
	// * y1) * y2 - y1 * y1 * y1 * y1
	// + (-2 * x2 * x2 + 4 * x1 * x2 - 2 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1) * y1 * y1 - x2 * x2
	// * x2 * x2 + 4 * x1 * x2 * x2 * x2 + (-6 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1) * x2 * x2
	// + (4 * x1 * x1 * x1 + (-4 * r2 * r2 - 4 * r1 * r1) * x1) * x2 - x1 * x1 * x1 * x1
	// + (2 * r2 * r2 + 2 * r1 * r1) * x1 * x1 - r2 * r2 * r2 * r2 + 2 * r1 * r1 * r2 * r2 - r1 * r1
	// * r1 * r1) + (-x2 - x1) * y2 * y2 + (2 * x2 + 2 * x1) * y1 * y2 + (-x2 - x1) * y1 * y1 - x2
	// * x2 * x2 + x1 * x2 * x2 + (x1 * x1 + r2 * r2 - r1 * r1) * x2 - x1 * x1 * x1 + (r1 * r1 - r2 * r2) * x1)
	// / (2 * y2 * y2 - 4 * y1 * y2 + 2 * y1 * y1 + 2 * x2 * x2 - 4 * x1 * x2 + 2 * x1 * x1);
	// double ya = ((x2 - x1)
	// * sqrt(-y2 * y2 + 2 * y1 * y2 - y1 * y1 - x2 * x2 + 2 * x1 * x2 - x1 * x1 + r2 * r2 + 2 * r1 * r2 + r1
	// * r1)
	// * sqrt(y2 * y2 - 2 * y1 * y2 + y1 * y1 + x2 * x2 - 2 * x1 * x2 + x1 * x1 - r2 * r2 + 2 * r1 * r2 - r1
	// * r1) + y2 * y2 * y2 - y1 * y2 * y2
	// + (-y1 * y1 + x2 * x2 - 2 * x1 * x2 + x1 * x1 - r2 * r2 + r1 * r1) * y2 + y1 * y1 * y1 + (x2 * x2 - 2
	// * x1 * x2 + x1 * x1 + r2 * r2 - r1 * r1)
	// * y1)
	// / (2 * y2 * y2 - 4 * y1 * y2 + 2 * y1 * y1 + 2 * x2 * x2 - 4 * x1 * x2 + 2 * x1 * x1);
	// double xb = ((y2 - y1)
	// * sqrt(-y2
	// * y2
	// * y2
	// * y2
	// + 4
	// * y1
	// * y2
	// * y2
	// * y2
	// + (-6 * y1 * y1 - 2 * x2 * x2 + 4 * x1 * x2 - 2 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1)
	// * y2
	// * y2
	// + (4 * y1 * y1 * y1 + (4 * x2 * x2 - 8 * x1 * x2 + 4 * x1 * x1 - 4 * r2 * r2 - 4 * r1 * r1)
	// * y1) * y2 - y1 * y1 * y1 * y1
	// + (-2 * x2 * x2 + 4 * x1 * x2 - 2 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1) * y1 * y1 - x2 * x2
	// * x2 * x2 + 4 * x1 * x2 * x2 * x2 + (-6 * x1 * x1 + 2 * r2 * r2 + 2 * r1 * r1) * x2 * x2
	// + (4 * x1 * x1 * x1 + (-4 * r2 * r2 - 4 * r1 * r1) * x1) * x2 - x1 * x1 * x1 * x1
	// + (2 * r2 * r2 + 2 * r1 * r1) * x1 * x1 - r2 * r2 * r2 * r2 + 2 * r1 * r1 * r2 * r2 - r1 * r1
	// * r1 * r1) + (x2 + x1) * y2 * y2 + (-2 * x2 - 2 * x1) * y1 * y2 + (x2 + x1) * y1 * y1 + x2 * x2
	// * x2 - x1 * x2 * x2 + (-x1 * x1 - r2 * r2 + r1 * r1) * x2 + x1 * x1 * x1 + (r2 * r2 - r1 * r1) * x1)
	// / (2 * y2 * y2 - 4 * y1 * y2 + 2 * y1 * y1 + 2 * x2 * x2 - 4 * x1 * x2 + 2 * x1 * x1);
	// double yb = -((x2 - x1)
	// * sqrt(-y2 * y2 + 2 * y1 * y2 - y1 * y1 - x2 * x2 + 2 * x1 * x2 - x1 * x1 + r2 * r2 + 2 * r1 * r2 + r1
	// * r1)
	// * sqrt(y2 * y2 - 2 * y1 * y2 + y1 * y1 + x2 * x2 - 2 * x1 * x2 + x1 * x1 - r2 * r2 + 2 * r1 * r2 - r1
	// * r1) - y2 * y2 * y2 + y1 * y2 * y2
	// + (y1 * y1 - x2 * x2 + 2 * x1 * x2 - x1 * x1 + r2 * r2 - r1 * r1) * y2 - y1 * y1 * y1 + (-x2 * x2 + 2
	// * x1 * x2 - x1 * x1 - r2 * r2 + r1 * r1)
	// * y1)
	// / (2 * y2 * y2 - 4 * y1 * y2 + 2 * y1 * y1 + 2 * x2 * x2 - 4 * x1 * x2 + 2 * x1 * x1);
	// Point a = new Point(xa, ya);
	// Point b = new Point(xb, yb);
	// Point p1 = new Point(x1, y1);
	// Point p2 = new Point(x1, y1);
	// double a1 = alpha(p1, a, b);
	// double a2 = alpha(p2, a, b);
	// return r1 * a1 + r2 * a2;
	// }

	double alpha(Point c, Point a, Point b) {
		return Math.acos((c.dist(a) + c.dist(b) - a.dist(b)) / (2 * c.dist(a) * c.dist(b)));
	}

	private void solve2() {
		int n = nextInt();
		int m = nextInt();
		Point[] p = new Point[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		for (int i = 0; i < m; i++) {
			Point q = new Point(nextInt(), nextInt());
			out.printf(Locale.US, " %.7f", solve2(p[0].x, p[0].y, p[0].dist(q), p[1].x, p[1].y, p[1].dist(q)));
		}
		out.println();
	}

	void solve() {
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ":");
			solve2();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	public void run() {
		try {
			br = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				String s = br.readLine();
				if (s == null) {
					return null;
				}
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Integer.parseInt(nextToken());
	}

	public static void main(String[] args) {
		new D().run();
	}
}
