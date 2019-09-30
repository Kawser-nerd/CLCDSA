import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class C {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {

			out.println("Case #" + casito + ":");
			new C().solve();
		}
		out.close();
	}

	private Object solve() throws Exception {
		int N = ni();

		Point[] ps = new Point[N];
		for (int i = 0; i < N; i++) {
			ps[i] = new Point(ni(), ni());
		}
		if(N <=3){
			for(int i =0;i<N;i++)
				out.println(0);
			return null;
		}
		for (int i = 0; i < N; i++) {
			List<Point> list = new ArrayList<Point>();
			for (int j = 0; j < N; j++)
				if (i != j)
					list.add(ps[j]);
			Vec v = new Vec(ps[i], list.get(0));

			List<Double> angles = new ArrayList<Double>();
			angles.add(0.0);
			for (int index = 1; index < list.size(); index++) {
				angles.add(v.angle(list.get(index)));
			}
			Collections.sort(angles);
			int ret = 0;
			int lo = 0;
			int hi = 1;
			while (lo < list.size()) {
				while (hi != lo
						&& ok( angles.get(lo), angles.get(hi))) {
					hi= (hi+1) % list.size();
				}
				ret = Math.max(ret, hi > lo? hi - lo : list.size() - (lo - hi));
				lo++;
			}
			out.println(list.size()-ret);
		}
		return null;

	}

	private boolean ok(double start, double end) {
		if( start > end)
			end += 2.0 * Math.PI;
		return end - start < Math.PI + 1e-9;
	}

	class Line implements Comparable<Line> {

		// ax+by+c==0
		// siempre a o b es 1
		double EPS = 1e-9;
		double a;
		double b;
		double c;
		double angle; // (0,pi]

		private Line() {
		}

		public Line(Point p1, Point p2) {
			if (Math.abs(p1.x - p2.x) < EPS) {
				this.a = 1;
				this.b = 0;
				this.c = -p1.x;
			} else {
				this.a = -(p1.y - p2.y) / (p1.x - p2.x);
				this.b = 1;
				this.c = -(p1.x * a + p1.y);
			}
			this.angle = angle();
		}

		boolean isParallel(Line other) {
			return (Math.abs(a - other.a) < EPS)
					&& (Math.abs(b - other.b) < EPS);
		}

		boolean same(Line other) {
			return (isParallel(other) && Math.abs(c - other.c) < EPS);
		}

		// requiere !this.isParallel(other)
		Point intersect(Line other) {

			double x = (other.b * c - b * other.c)
					/ (other.a * b - a * other.b);
			double y = -1;

			if (Math.abs(b) > EPS) {
				y = -(a * x + c) / b;
			} else {
				y = -(other.a * x + other.c) / other.b;
			}
			return new Point(x, y);
		}

		Line parallel(Point p) {
			Line ret = new Line();
			ret.a = a;
			ret.b = b;
			ret.c = -(a * p.x + b * p.y);
			return ret;
		}

		Line perpendicular(Point p) {
			Line ret = new Line();
			if (Math.abs(a) > EPS) {
				ret.b = 1;
				ret.a = -b / a;
			} else {
				ret.a = 1;
				ret.b = 0;
			}
			ret.c = 0;
			return ret.parallel(p);
		}

		boolean isPerpendicular(Line other) {
			return Math.abs(Math.abs(this.angle - other.angle) - Math.PI / 2.0) < EPS;
		}

		public double angle() {
			double ret = Math.atan2(-a, b);
			return (ret <= 0.0 ? Math.PI + ret : ret);
		}

		@Override
		public int compareTo(Line o) {
			if (o.angle - angle > EPS)
				return -1;
			if (angle - o.angle > EPS)
				return 1;
			if (o.c - c < EPS)
				return -1;
			if (c - o.c > EPS)
				return 1;
			return 0;
		}

	}

	public class Vec implements Comparable<Vec> {
		double EPS = 1e-7;
		Point src;
		Point dst;
		double angle;

		public Vec(Point src, Point dst) {
			super();
			this.src = src;
			this.dst = dst;
			this.angle = angle();
		}

		private double angle() {
			double ret = Math.atan2(dst.y - src.y, dst.x - src.x);
			if (ret < 0)
				ret = 2.0 * Math.PI + ret;
			return ret;
		}

		public double angle(Point p) {
			return parse(Math.atan2(p.y - src.y, p.x - src.x) - angle);
		}

		private double parse(double d) {
			while (d < 0)
				d += Math.PI * 2.0;
			while (d > Math.PI * 2.0)
				d -= Math.PI * 2.0;
			return d;
		}

		// anda?
		public Line line(double add) {
			double new_angle = parse(angle + add);
			if (Math.abs(new_angle - Math.PI / 2.0) < EPS)
				return new Line(src, new Point(src.x, src.y + 1.0));

			if (Math.abs(new_angle - (3.0 * Math.PI) / 2.0) < EPS)
				return new Line(src, new Point(src.x, src.y + 1.0));

			return new Line(src, new Point(src.x + 1.0, src.y
					+ Math.tan(new_angle)));
		}

		// right =1, same =0, left =-1
		public int position(Point p) {
			double cross = (p.x - dst.x) * (src.y - dst.y) - (p.y - dst.y)
					* (src.x - dst.x);
			if (Math.abs(cross) < EPS)
				return 0;
			if (cross > 0) {
				return -1;
			} else {
				return 1;
			}
		}

		// requiere position(p) == 0
		// antes de src =-1, despues de dst =1, en el medio ( con src y dst) 0
		public int inside(Point p) {
			if (src.same(p) || dst.same(p))
				return 0;
			if (Math.abs(Math.atan2(src.y - p.y, src.x - p.x)
					- Math.atan2(dst.y - src.y, dst.x - src.x)) < EPS)
				return -1;
			if (Math.abs(Math.atan2(p.y - dst.y, p.x - dst.x)
					- Math.atan2(dst.y - src.y, dst.x - src.x)) < EPS)
				return 1;
			return 0;
		}

		@Override
		public int compareTo(Vec o) {
			int res = src.compareTo(o.src);
			if (res != 0)
				return res;
			return dst.compareTo(o.dst);
		}
	}

	public class Point implements Comparable<Point> {
		double EPS = 1e-9;
		double x, y;

		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public boolean same(Point other) {
			if (this == other)
				return true;
			return Math.abs(x - other.x) < EPS && Math.abs(y - other.y) < EPS;
		}

		public double dist(Point p) {
			return Math.hypot(x - p.x, y - p.y);
		}

		@Override
		public int compareTo(Point o) {
			if (Math.abs(x - o.x) > EPS)
				return Double.compare(x, o.x);
			if (Math.abs(y - o.y) > EPS)
				return Double.compare(y, o.y);
			return 0;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}

	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "C"; //
	static String loc = "/home/miguel/workspace/CodeJam/round_1A/src"; //

	static void configure() throws Exception {

		File file = new File(loc);
		File[] paths = file.listFiles();
		List<File> input = new ArrayList<File>();
		for (File f : paths) {
			String s = f.getName();
			if (s.startsWith(name_class) && s.endsWith(".in"))
				input.add(f);
		}

		if (input.isEmpty()) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		} else {
			File last_file = input.get(0);
			for (File f : input) {
				if (f.lastModified() > last_file.lastModified())
					last_file = f;
			}

			in = new BufferedReader(new FileReader(last_file.toString()));
			System.err.println("LEYENDO DE ARCHIVO");

		}
		FileWriter fw = new FileWriter(loc + "/output.txt");
		out = new PrintWriter(fw);

	}

	static StringTokenizer strTok = new StringTokenizer("");

	static String nextToken() throws IOException {
		while (!strTok.hasMoreTokens())
			strTok = new StringTokenizer(in.readLine());
		return strTok.nextToken();
	}

	static int ni() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nl() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nd() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int[] nia(int size) throws IOException {
		int[] ret = new int[size];
		for (int i = 0; i < size; i++)
			ret[i] = ni();
		return ret;
	}

	static long[] nla(int size) throws IOException {
		long[] ret = new long[size];
		for (int i = 0; i < size; i++)
			ret[i] = nl();
		return ret;
	}

	static double[] nda(int size) throws IOException {
		double[] ret = new double[size];
		for (int i = 0; i < size; i++)
			ret[i] = nd();
		return ret;
	}

}