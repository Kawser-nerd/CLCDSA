import java.io.*;
import java.util.*;

public class D implements Runnable {

	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;

	StringTokenizer st;

	PrintWriter out;

	public final String FN = "D-small";

	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			int T = nextInt();
			for (int i = 0; i < T; i++) {
				solve(i + 1);
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
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

	double eps = 1e-6;

	class Circle {
		double x;
		double y;
		double r;

		Circle(int x_, int y_, int r_) {
			x = x_;
			y = y_;
			r = r_;
		}

		Circle(Circle a, Circle b) {
			if (a == b) {
				x = a.x;
				y = a.y;
				r = a.r;
				return;
			}
			double d = a.dist(b);
			double R = (d + a.r + b.r) / 2;
			x = (a.x * (R - b.r) + b.x * (R - a.r)) / d;
			y = (a.y * (R - b.r) + b.y * (R - a.r)) / d;
			r = R;
		}

		boolean contains(Circle a) {
			return this.dist(a) + a.r - eps <= r;
		}

		double dist(Circle cc) {
			return Math.sqrt((x - cc.x) * (x - cc.x) + (y - cc.y) * (y - cc.y));
		}

		public String toString() {
			return "= " + x + " " + y + " " + r;
		}
	}

	private void solve(int T) throws IOException {
		int N = nextInt();
		Circle a[] = new Circle[N];
		for (int i = 0; i < a.length; i++) {
			a[i] = new Circle(nextInt(), nextInt(), nextInt());
		}
		double res = Double.POSITIVE_INFINITY;
		for (int i = 0; i < a.length; i++) {
			for (int j = i; j < a.length; j++) {
				for (int k = i; k < a.length; k++) {
					lastfor: for (int l = k; l < a.length; l++) {
						Circle c1 = new Circle(a[i], a[j]);
						Circle c2 = new Circle(a[k], a[l]);
						double r = Math.max(c1.r, c2.r);
						c1.r = r;
						c2.r = r;
						for (int m = 0; m < a.length; m++) {
							if (!c1.contains(a[m]) && !c2.contains(a[m])) {
								continue lastfor;
							}
						}
						res = Math.min(res, r);
					}
				}
			}
		}
		out.println("Case #"+T+": "+res);
	}
}