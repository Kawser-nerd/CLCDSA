import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "D-small-attempt0";
	final double eps = 1e-8;

	public void solve() throws Exception {
		DecimalFormat df = new DecimalFormat("0.0000000000");
		int ntests = iread();
		for (int ntest = 1; ntest <= ntests; ntest++) {
			int N = iread();
			point[] points = new point[N];
			for (int i = 0; i < N; i++)
				points[i] = new point(iread(), iread(), iread());
			if (N == 1) {
				out.write("Case #" + ntest + ": " + df.format(points[0].r)
						+ "\n");
				continue;
			}

			ArrayList<point> test = new ArrayList<point>();
			for (int i = 0; i < N; i++)
				for (int j = i + 1; j < N; j++)
					test.add(line(points[i], points[j]));
			for (int i = 0; i < N; i++)
				test.add(points[i]);
			for (int i = 0; i < N; i++)
				for (int j = i + 1; j < N; j++)
					for (int k = j + 1; k < N; k++)
						test.add(circle(points[i], points[j], points[k]));
			double ans = Double.MAX_VALUE;
			for (int i = 0; i < test.size(); i++)
				for (int j = i + 1; j < test.size(); j++) {
					point p1 = test.get(i);
					point p2 = test.get(j);
					boolean flag = true;
					double rad = Math.max(p1.r, p2.r);
					for (int k = 0; k < N; k++) {
						if (p1.distTo(points[k]) > rad - points[k].r + eps
								&& p2.distTo(points[k]) > rad - points[k].r
										+ eps)
							flag = false;
					}
					if (flag) {
						ans = Math.min(ans, rad);
					}
				}
			out.write("Case #" + ntest + ": " + df.format(ans) + "\n");
		}
	}

	point line(point a, point b) {
		double dx = b.x - a.x;
		double dy = b.y - a.y;
		double R = a.distTo(b);
		dx /= R;
		dy /= R;
		point p = new point(0, 0, (R + a.r + b.r) / 2.0);
		double u = p.r - a.r;
		p.x = a.x + dx * u;
		p.y = a.y + dy * u;
		return p;
	}

	point circle(point a, point b, point c) {
		double left = 0.0, right = a.distTo(b) + b.distTo(c);
		double dx = b.x - a.x;
		double dy = b.y - a.y;
		double R = a.distTo(b);
		dx /= R;
		dy /= R;
		point p = new point(0, 0, 0);
		point res = new point(0, 0, 0);
		while (left + eps < right) {
			double rad = (left + right) / 2.0;
			double r1 = a.r + rad;
			double r2 = b.r + rad;
			double r3 = c.r + rad;

			boolean flag = false;
			if (r1 < R + r2 && r2 < R + r1 && R < r1 + r2) {
				double u = (r1 * r1 - r2 * r2 + R * R) / (2 * R);
				double v = Math.sqrt(r1 * r1 - u * u);
				p.x = a.x + u * dx - v * dy;
				p.y = a.y + u * dy + v * dx;
				if (p.distTo(c) <= R) {
					res.x = p.x;
					res.y = p.y;
					res.r = rad;
					flag = true;
				}
				p.x = a.x + u * dx + v * dy;
				p.y = a.y + u * dy - v * dx;
				if (p.distTo(c) <= R) {
					res.x = p.x;
					res.y = p.y;
					res.r = rad;
					flag = true;
				}
			}
			if (flag)
				right = rad;
			else
				left = rad;
		}
		return res;
	}

	class point {
		double x, y, r;

		public point(double x, double y, double r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}

		double distTo(point p) {
			return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}