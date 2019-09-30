import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			int[] xs = new int[n], ys = new int[n], zs = new int[n], ps = new int[n];
			TreeSet<Integer> setx = new TreeSet<Integer>();
			TreeSet<Integer> sety = new TreeSet<Integer>();
			TreeSet<Integer> setz = new TreeSet<Integer>();
			for (int i = 0; i < n; i++) {
				xs[i] = sc.nextInt();
				ys[i] = sc.nextInt();
				zs[i] = sc.nextInt();
				ps[i] = sc.nextInt();
				setx.add(xs[i]);
				sety.add(ys[i]);
				setz.add(zs[i]);
			}
			setx.add(- (1 << 29));
			setx.add(1 << 29);
			sety.add(- (1 << 29));
			sety.add(1 << 29);
			setz.add(- (1 << 29));
			setz.add(1 << 29);
			int[] isx = toi(setx.toArray(new Integer[0]));
			int[] isy = toi(sety.toArray(new Integer[0]));
			int[] isz = toi(setz.toArray(new Integer[0]));
			double res = 1e7;
			/*
			for (int i = 0; i + 1 < isx.length; i++) {
				for (int j = 0; j + 1 < isy.length; j++) {
					for (int k = 0; k + 1 < isz.length; k++) {
						double sx = isx[i], tx = isx[i + 1];
						double sy = isy[j], ty = isy[j + 1];
						double sz = isz[k], tz = isz[k + 1];
						double mx = (sx + tx) / 2;
						double my = (sy + ty) / 2;
						double mz = (sz + tz) / 2;
						Point[][] pss = init();
						pss = convexCut(pss, new Point(sx, sy, sz), new Point(-1, 0, 0));
						pss = convexCut(pss, new Point(sx, sy, sz), new Point(0, -1, 0));
						pss = convexCut(pss, new Point(sx, sy, sz), new Point(0, 0, -1));
						pss = convexCut(pss, new Point(tx, ty, tz), new Point(1, 0, 0));
						pss = convexCut(pss, new Point(tx, ty, tz), new Point(0, 1, 0));
						pss = convexCut(pss, new Point(tx, ty, tz), new Point(0, 0, 1));
						double left = 0, right = 1e7;
						while (right - left > 1e-7 && left < res) {
							double mid = (left + right) / 2;
							Point[][] qss = pss;
							for (int h = 0; h < n; h++) {
								Point p = new Point(0, 0, 0);
								double kp = mid * ps[h];
								if (zs[h] < mz) {
									p.z = 1;
								} else {
									p.z = -1;
								}
								if (ys[h] < my) {
									p.y = 1;
								} else {
									p.y = -1;
								}
								if (xs[h] < mx) {
									p.x = 1;
								} else {
									p.x = -1;
								}
								qss = convexCut(qss, new Point(xs[h] + (xs[h] < mx ? kp : -kp), ys[h], zs[h]), p);
							}
							if (qss.length > 0) right = mid;
							else left = mid;
						}
						res = min(res, right);
					}
				}
			}*/
			Point[][] pss = init();
			double left = 0, right = 1e7;
			while (right - left > 1e-7 && left < res) {
				double mid = (left + right) / 2;
				Point[][] qss = pss;
				for (int h = 0; h < n; h++) {
					for (int xx = -1; xx <= 1; xx += 2) {
						double mx = 1e8 * xx;
						for (int yy = -1; yy <= 1; yy += 2) {
							double my = 1e8 * yy;
							for (int zz = -1; zz <= 1; zz += 2) {
								double mz = 1e8 * zz;
								Point p = new Point(0, 0, 0);
								double kp = mid * ps[h];
								if (zs[h] < mz) {
									p.z = 1;
								} else {
									p.z = -1;
								}
								if (ys[h] < my) {
									p.y = 1;
								} else {
									p.y = -1;
								}
								if (xs[h] < mx) {
									p.x = 1;
								} else {
									p.x = -1;
								}
								qss = convexCut(qss, new Point(xs[h] + (xs[h] < mx ? kp : -kp), ys[h], zs[h]), p);
							}
						}
					}
				}
				if (qss.length > 0) right = mid;
				else left = mid;
			}
			res = min(res, right);
			System.out.printf("%.7f%n", res);
		}
	}
	int[] toi(Integer[] Is) {
		int n = Is.length;
		int[] is = new int[n];
		for (int i = 0; i < n; i++) is[i] = Is[i];
		return is;
	}
	static final double INF = 1e10;
	static final double EPS = 1e-10;
	int signum(double d) {
		return (d < -EPS) ? -1 : (d > EPS) ? 1 : 0;
	}
	class Point implements Comparable<Point> {
		double x, y, z;
		Point(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		Point add(Point p) {
			return new Point(x + p.x, y + p.y, z + p.z);
		}
		Point sub(Point p) {
			return new Point(x - p.x, y - p.y, z - p.z);
		}
		Point mul(double d) {
			return new Point(x * d, y * d, z * d);
		}
		Point div(double d) {
			return new Point(x / d, y / d, z / d);
		}
		double dot(Point p) {
			return x * p.x + y * p.y + z * p.z;
		}
		Point det(Point p) {
			return new Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
		}
		double abs() {
			return sqrt(abs2());
		}
		double abs2() {
			return x * x + y * y + z * z;
		}
		public int compareTo(Point o) {
			int comp = signum(x - o.x);
			if (comp != 0) return comp;
			comp = signum(y - o.y);
			if (comp != 0) return comp;
			return signum(z - o.z);
		}
		public String toString() {
			return String.format("(%.2f, %.2f, %.2f)", x, y, z);
		}
	}
	//平面と直線の交点
	Point isFL(Point p, Point o, Point q1, Point q2) {
		double a = o.dot(q2.sub(p));
		double b = o.dot(q1.sub(p));
		double d = a - b;
		if (signum(d) == 0) return null;
		return q1.mul(a).sub(q2.mul(b)).div(d);
	}
	//法線方向から見て反時計回りの凸包を作る
	//辺上の点を含まない
	//不等号を変えることで辺上の点の選択が可能
	//辺上の点を含む場合、点の重複があってはいけない
	Point[] convexHull2D(Point[] ps, Point o) {
		int n = ps.length, k = 0;
		if (n <= 1) return ps;
		sort(ps);
		Point[] qs = new Point[n * 2];
		for (int i = 0; i < n; qs[k++] = ps[i++]) {
			while (k > 1 && signum(qs[k - 1].sub(qs[k - 2]).det(ps[i].sub(qs[k - 1])).dot(o)) <= 0) k--;
		}
		for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
			while (k > t && signum(qs[k - 1].sub(qs[k - 2]).det(ps[i].sub(qs[k - 1])).dot(o)) <= 0) k--;
		}
		Point[] res = new Point[k - 1];
		System.arraycopy(qs, 0, res, 0, k - 1);
		return res;
	}
	//凸多面体の切断
	//凸多面体を平面poで切断して裏側を残す
	//凸多面体は外から見た時に反時計回りになるようにすること
	Point[][] convexCut(Point[][] pss, Point p, Point o) {
		ArrayList<Point[]> res = new ArrayList<Point[]>();
		ArrayList<Point> sec = new ArrayList<Point>();
		for (Point[] ps : pss) {
			int n = ps.length;
			ArrayList<Point> qs = new ArrayList<Point>();
			boolean dif = false;
			for (int i = 0; i < n; i++) {
				int d1 = signum(o.dot(ps[i].sub(p)));
				int d2 = signum(o.dot(ps[(i + 1) % n].sub(p)));
				if (d1 <= 0) qs.add(ps[i]);
				if (d1 * d2 < 0) {
					Point q = isFL(p, o, ps[i], ps[(i + 1) % n]);
					qs.add(q);
					sec.add(q);
				}
				if (d1 == 0) sec.add(ps[i]);
				else dif = true;
				dif |= signum(o.dot(ps[(i + 1) % n].sub(ps[i]).det(ps[(i + 2) % n].sub(ps[i])))) < 0;
			}
			if (qs.size() > 0 && dif) res.add(qs.toArray(new Point[0]));
		}
		if (sec.size() > 0) res.add(convexHull2D(sec.toArray(new Point[0]), o));
		return res.toArray(new Point[0][]);
	}
	//空間の初期化
	Point[][] init() {
		Point[][] pss = new Point[6][4];
		pss[0][0] = pss[1][0] = pss[2][0] = new Point(-INF, -INF, -INF);
		pss[0][3] = pss[1][1] = pss[5][2] = new Point(-INF, -INF,  INF);
		pss[0][1] = pss[2][3] = pss[4][2] = new Point(-INF,  INF, -INF);
		pss[0][2] = pss[5][3] = pss[4][1] = new Point(-INF,  INF,  INF);
		pss[1][3] = pss[2][1] = pss[3][2] = new Point( INF, -INF, -INF);
		pss[1][2] = pss[5][1] = pss[3][3] = new Point( INF, -INF,  INF);
		pss[2][2] = pss[4][3] = pss[3][1] = new Point( INF,  INF, -INF);
		pss[5][0] = pss[4][0] = pss[3][0] = new Point( INF,  INF,  INF);
		return pss;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
