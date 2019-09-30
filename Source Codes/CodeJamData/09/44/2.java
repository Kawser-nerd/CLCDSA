import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class BaiD {

	static class Circle {
		double x, y;
		double r;

		Circle(double x, double y, double r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}
	}

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);

		Scanner sc = new Scanner(new FileReader("D-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			System.out.println(test);
			int n = sc.nextInt();
			Circle[] a = new Circle[n];
			for (int i = 0; i < n; ++i)
				a[i] = new Circle(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());

			double res;

			if (n == 1) {
				res = a[0].r;
			} else if (n == 2) {
				res = Math.max(a[0].r, a[1].r);
			} else {

				double L = 0;
				for (int i = 0; i < n; ++i)
					L = Math.max(L, a[i].r);
				double R = 10000;
				for (int kk = 0; kk < 40; ++kk) {
					double M = (L + R) / 2;
					boolean ok = false;
					ArrayList<Long> ar = new ArrayList<Long>();
					for (int i = 0; i < n; ++i) {
						if (ok)
							break;
						for (int j = i + 1; j < n; ++j) {
							double[][] z = get(a[i], a[j], M);
							for (int t = 0; t < z.length; ++t) {
								double x = z[t][0];
								double y = z[t][1];
								long set = 0;
								int dem = 0;
								for (int k = 0; k < n; ++k)
									if (Math.sqrt((x - a[k].x) * (x - a[k].x) + (y - a[k].y) * (y - a[k].y)) <= (M - a[k].r) + eps) {
										set = set | (1L << k);
										++dem;
									}
								if (dem == n - 1) {
									ok = true;
									break;
								}
								ar.add(set);
							}
						}
					}

					long[] z = new long[ar.size()];
					for (int i = 0; i < z.length; ++i)
						z[i] = ar.get(i);
					for (int i = 0; i < z.length; ++i) {
						if (ok)
							break;
						for (int j = i + 1; j < z.length; ++j)
							if ((z[i] | z[j]) == (1L << n) - 1) {
								ok = true;
								break;
							}
					}
					if (ok)
						R = M;
					else
						L = M;
				}
				res = L;
			}
			pw.print("Case #" + test + ": ");
			pw.printf("%.7f", res);
			pw.println();
		}

		sc.close();
		pw.close();
	}

	static final double eps = 1e-8;

	static double[][] get(Circle a, Circle b, double M) {
		double A = 2 * (a.x - b.x);
		double B = 2 * (a.y - b.y);
		double C = (M - b.r) * (M - b.r) - (M - a.r) * (M - a.r) - (a.x - b.x) * (a.x - b.x) - (a.y - b.y) * (a.y - b.y);

		if (Math.abs(A) > eps) {
			double aa = A * A + B * B;
			double bb = -2 * B * C;
			double cc = C * C - A * A * (M - a.r) * (M - a.r);
			double dt = bb * bb - 4 * aa * cc;
			if (Math.abs(dt) <= eps) {
				dt = 0;
			}
			if (Math.abs(dt) >= 0) {
				double y0 = (-bb + Math.sqrt(dt)) / 2 / aa;
				double y1 = (-bb - Math.sqrt(dt)) / 2 / aa;
				double[][] res = new double[][] { { (C - B * y0) / A, y0 }, { (C - B * y1) / A, y1 } };
				for (int i = 0; i < res.length; ++i) {
					res[i][0] += a.x;
					res[i][1] += a.y;
				}
				return res;
			} else
				return new double[0][];
		} else {
			double y = C / B;
			if (y * y <= (M - a.r) * (M - a.r) + eps) {
				double x0 = Math.sqrt((M - a.r) * (M - a.r) + eps - y * y);
				double x1 = -x0;
				double[][] res = new double[][] { { x0, y }, { x1, y } };
				for (int i = 0; i < res.length; ++i) {
					res[i][0] += a.x;
					res[i][1] += a.y;
				}
				return res;
			} else
				return new double[0][];
		}
	}
}