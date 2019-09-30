import java.awt.geom.Line2D;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/D3";

	FastScanner in;
	PrintWriter out;


	private final int SORT_TYPE_X = 1;
	private final int SORT_TYPE_Y = 2;
	
	private int points_sort_type = -1;
	private double EPS = 1e-9;
	
	double dadd(double a, double b) {
		if (Math.abs(a + b) < EPS * (Math.abs(a) + Math.abs(b))) return 0;
		return a + b;
	}
	
	class SortTypeUndefinedException extends Exception {
		
	}
	
	class Point implements Comparable<Point> {
		double x;
		double y;
		
 		Point(double x, double y) {
 			this.x = x;
 			this.y = y;
		}
		
		Point add(double sx, double sy) {
			return new Point(dadd(x, sx), dadd(y, sy));
		}
		
		Point add(Point p) {
			return add(p.x, p.y);
		}
		
		Point sub(double sx, double sy) {
			return new Point(dadd(x, -sx), dadd(y, -sy));			
		}
		
		Point sub(Point p) {
			return sub(p.x, p.y);
		}
		
		Point mult(double k) {
			return new Point(x * k, y * k);
		}
		
		double dot(Point p) {
			return dadd(x * p.x, y * p.y);
		}

		double det(Point p) {
			return dadd(x * p.y, -y * p.x);
		}
				
		double sin(Point p) {
			double cosVal = cos(p);
			return Math.sqrt(1 - cosVal * cosVal);
		}
		
		double cos(Point p) {
			double res = dot(p) / (abs() * p.abs());
			if (res > 1) return res - EPS;
			if (res < -1) return res + EPS;
			return res;
		}
		
		double abs() {
			return Math.sqrt(dadd(x * x, y * y));
		}
		
		public int compareTo(Point s) {
			try {
				switch (points_sort_type) {
				case SORT_TYPE_X :
					if (x == s.x) return Double.compare(y, s.y);
					return Double.compare(x, s.x);
				case SORT_TYPE_Y :
					if (y == s.y) return Double.compare(x, s.x);
					return Double.compare(y, s.y);
				default :
					throw new SortTypeUndefinedException();
				}
			} catch (SortTypeUndefinedException e) {
				e.printStackTrace();
				System.exit(1);
			}
			
			return -1;
		}

		public String toString() {
			return "(" + x + ", " + y + ")]";
		}
	}
	

	Point calcIntersection(Line2D.Double l1, Line2D.Double l2) {
		if (!l1.intersectsLine(l2)) return null;
		
		double bx = l2.x2 - l2.x1;
		double by = l2.y2 - l2.y1;
		double d1 = Math.abs(bx * (l1.y1 - l2.y1) - by * (l1.x1 - l2.x1));
		double d2 = Math.abs(bx * (l1.y2 - l2.y1) - by * (l1.x2 - l2.x1));
		double t = d1 / (d1 + d2);
		
		double px = l1.x1 + (l1.x2 - l1.x1) * t;
		double py = l1.y1 + (l1.y2 - l1.y1) * t;
		return new Point(px, py);
	}
	
	class Polygon {
		Point[] ps;
		
		Polygon(Point[] ps) {
			this.ps = ps;
		}
		
		int getSize() {
			return ps.length;
		}
		
		double getArea() {
			int n = getSize();
			double res = 0;
			for (int i = 0; i < n; i++) {
				res += (ps[(i + 1) % n].y + ps[i].y) * (ps[i].x - ps[(i + 1) % n].x) / 2.0;    
		    }
			return Math.abs(res);
		}
		
		double getDistance() {
			int n = getSize();
			double res = 0;
			for (int i = 0; i < n; i++) {
				res += ps[i].sub(ps[(i+1)%n]).abs();
			}
			return res;
		}

		Point calcCenterOfGravity() {
			Point res = new Point(0, 0);
			int n = getSize();
			
			for (int i = 0; i < n; i++) {
				res = res.add(ps[i]);
			}
			
			res = res.mult(1.0 / n);
			return res;
		}
		
		Polygon getUpperConvexHull() {
			// points_sort_type = SORT_TYPE_Y;
			// Arrays.sort(ps); 
			int k = 0, n = ps.length;
			Point[] qs = new Point[n * 2];
			
			for (int i = 0; i < n; i++) {
				while (k > 1 && qs[k-1].sub(qs[k-2]).det(ps[i].sub(qs[k-1])) > 0) k--;
				
				qs[k++] = ps[i];
			}
			qs = Arrays.copyOf(qs, k);
			
			return new Polygon(qs);
		}
		
		public String toString() {
			StringBuilder res = new StringBuilder();
			res.append("Polygon : " + ps.length + " <");;
			for (Point p : ps) {
				res.append(p.toString() + ", ");
			}
			res.append(">\n");
			return res.toString();
		}
	}
	
	long[][] calcRangeMax(int[] array) {
		int n = array.length;
		long[] sum = new long[n + 1];
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + array[i]; 
		}
		long[][] res = new long[n+1][n+1];
		for (int i = 0; i < n+1; i++) {
			Arrays.fill(res[i], Long.MIN_VALUE);
		}		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (i > 0) res[i][j] = Math.max(res[i][j], res[i-1][j]);
				if (i - j >= 0) res[i][j] = Math.max(res[i][j], sum[i] - sum[i-j]);
			}
		}
		return res;
	}
	
	long calc(int x, int y) {
		/* naive
		long res = Long.MIN_VALUE;
		for (int i = 0; i <= y; i++) {
			for (int j = 0; j <= x; j++) {
				res = Math.max(res, j * Bmax[y][i] + i * Amax[x][j]);
			}
		}
		return res;
		*/
		Point[] ps = new Point[y];
		for (int j = 1; j <= y; j++) {
			ps[j-1] = new Point(j, Bmax[y][j]);
		}
		Polygon convexHull = new Polygon(ps).getUpperConvexHull();
		int size = convexHull.getSize();
		long[] xs = new long[size];
		long[] ys = new long[size];
		for (int i = 0; i < size; i++) {
			xs[i] = (long) convexHull.ps[i].x;
			ys[i] = (long) convexHull.ps[i].y;
		}

		long res = Long.MIN_VALUE;
		for (int nx = 1; nx <= x; nx++) {
			int lo = 0, hi = size - 1;
			while (hi - lo > 2) {
				int d = (hi - lo) / 3;
				int mid1 = lo + d;
				int mid2 = hi - d;
				if (xs[mid1] * Amax[x][nx] + ys[mid1] * nx < xs[mid2] * Amax[x][nx] + ys[mid2] * nx) 
					lo = mid1;
				else
					hi = mid2;
			}
			for (int j = lo; j <= hi; j++) {
				res = Math.max(res, xs[j] * Amax[x][nx] + ys[j] * nx);
			}
		}
		return res;
	}
	
	int W, H;
	int[] a, b;
	long[][] Amax, Bmax;
	
	public void solve() {
		W = in.nextInt(); H = in.nextInt();
		a = in.nextIntArray(W);
		b = in.nextIntArray(H);
		
		Amax = calcRangeMax(a);
		Bmax = calcRangeMax(b);
		
		int Q = in.nextInt();
		for (int i = 0; i < Q; i++) {
			int x = in.nextInt(), y = in.nextInt();
			System.out.println(calc(x, y));
		}
	}
		
	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);

		solve();
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}