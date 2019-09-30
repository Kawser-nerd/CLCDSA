import java.io.*;
import java.util.*;
import java.math.*;

public class Triangle implements Runnable {

	public static void main(String[] args) {
		new Thread(new Triangle()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
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

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	String FNAME = "triangle";

	class Point {
		public Point(int nextInt, int nextInt2) {
			x = nextInt;
			y = nextInt2;
		}

		int x, y;
	}

	private void solve() throws IOException {
		int n = nextInt();
		all: for (int test = 0; test < n; test++) {
			out.print("Case #" + (test + 1) + ": ");
			Point[] t1 = new Point[3];
			Point[] t2 = new Point[3];
			for (int j = 0; j < t1.length; j++) {
				t1[j] = new Point(nextInt(), nextInt());
			}
			for (int j = 0; j < t1.length; j++) {
				t2[j] = new Point(nextInt(), nextInt());
			}
			double eps = 1e-9;
			count: for (int j = 0; j < t2.length; j++) {
				double a = dist(t2[j], t2[(j + 1) % 3]) / dist(t1[0], t1[1]);
				if (a > 1 + eps) {
					continue;
				}
				for (int k = 0; k < t2.length; k++) {
					if (Math.abs(dist(t2[(j + k) % 3], t2[(j + k + 1) % 3]) - a
							* dist(t1[k], t1[(k + 1) % 3])) > eps) {
						continue count;
					}
				}
				int x1 = t1[1].x - t1[0].x;
				int y1 = t1[1].y - t1[0].y;
				int x2 = t2[1].x - t2[0].x;
				int y2 = t2[1].y - t2[0].y;
				double al = -Math.atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2);
				double dx = t2[j].x - a * Math.cos(al) * t1[0].x - a
						* Math.sin(al) * t1[0].y;
				double dy = t2[j].y + a * Math.sin(al) * t1[0].x - a
						* Math.cos(al) * t1[0].y;
				for (int i = 0; i < t2.length; i++) {
					if (Math.abs(t2[(j + i) % 3].x - a * Math.cos(al) * t1[i].x
							- a * Math.sin(al) * t1[i].y - dx) > eps
							|| (t2[(j + i) % 3].y + a * Math.sin(al) * t1[i].x
									- a * Math.cos(al) * t1[i].y - dy) > eps) {
						continue count;
					}
				}
				double a11 = a * Math.cos(al) - 1;
				double a22 = a * Math.cos(al) - 1;
				double a12 = a * Math.sin(al);
				double a21 = -a * Math.sin(al);
				if (Math.abs(a11 * a22 - a21 * a12) < eps) {
					continue;
				}
				double y = (a21 * dx - a11 * dy) / (a11 * a22 - a21 * a12);
				double x = -(a22 * dx - a12 * dy) / (a11 * a22 - a21 * a12);
				out.println(x + " " + y);
				continue all;
			}
			out.println("No Solution");
		}
	}

	private double dist(Point p1, Point p2) {
		return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p2.y - p1.y)
				* (p2.y - p1.y));
	}

}
