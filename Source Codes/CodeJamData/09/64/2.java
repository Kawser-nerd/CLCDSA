import java.io.*;
import java.util.*;
import java.math.*;

public class BaiD {

	static class Point {
		double x, y;

		Point() {
		}

		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		double dist(Point p) {
			return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		}
	}

	static final double eps = 1e-7;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("D.out"));
		// Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		int ntest = sc.nextInt();

		for (int test = 1; test <= ntest; ++test) {

			int n = sc.nextInt();
			Point[] a = new Point[n];
			int[] r = new int[n];
			int[] s = new int[n];

			for (int i = 0; i < n; ++i) {
				a[i] = new Point();
				a[i].x = sc.nextDouble();
				a[i].y = sc.nextDouble();
				r[i] = sc.nextInt();
				s[i] = sc.nextInt();
			}

			int best = 0;

			for (int b = 0; b < (1 << n); ++b) {
				boolean ok = true;
				for (int i = 0; i < n; ++i)
					if ((b & (1 << i)) == 0)
						for (int j = 0; j < n; ++j)
							if ((b & (1 << j)) != 0) {
								if (r[j] >= a[i].dist(a[j]) - eps)
									ok = false;
							}
				if (ok) {
					// System.out.println(b);
					int z = 0;
					for (int i = 0; i < n; ++i)
						if ((b & (1 << i)) != 0)
							z += s[i];
					best = Math.max(best, z);
				}
			}

			pw.print("Case #" + test + ": ");
			pw.print(best);
			pw.println();
		}

		pw.close();
		sc.close();
	}
}
