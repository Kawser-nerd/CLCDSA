import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.*;
import javax.swing.*;

public class F {
	boolean TIME = true;
	boolean VIS = false;//true;
	Scanner sc;
	
	void solve() {
		p1 = new P(sc.nextDouble(), sc.nextDouble());
		p2 = new P(sc.nextDouble(), sc.nextDouble());
		n = sc.nextInt();
		ps = new P[n];
		rs = new double[n];
		for (int i = 0; i < n; i++) {
			ps[i] = new P(sc.nextDouble(), sc.nextDouble());
			rs[i] = sc.nextDouble();
		}
		double res = 0, sum = 0;
		res = calc(false, false);
		sum += res;
		System.out.printf("%.10f%n", res);
		res = calc(true, false);
		sum += res;
		System.out.printf("%.10f%n", res);
		res = calc(false, true);
		sum += res;
		System.out.printf("%.10f%n", res);
		res = calc(true, true);
		sum += res;
		System.out.printf("%.10f%n", res);
		for (int i = 0; i < n; i++) {
			sum += PI * rs[i] * rs[i];
		}
		debug(sum);
	}
	
	P p1, p2;
	int n;
	P[] ps;
	double[] rs;
	
	double calc(boolean b1, boolean b2) {
		if (n == 0) {
			if (b1 & b2) return 10000;
			else return 0;
		}
		P[] poly = new P[] {new P(0, 0), new P(100, 0), new P(100, 100), new P(0, 100)};
		return rec(poly, b1, b2, 0, 0);
	}
	
	double rec(P[] poly, boolean b1, boolean b2, int i, int j) {
		if (poly.length == 0) return 0;
		if (i == n) return calcArea(poly);
		double res = 0;
		if (j == 0) {
			P[] qs = tanCP(ps[i], rs[i], p1);
			if (b1) {
				res += rec(convexCut(poly, qs[0], qs[1]), b1, b2, i, 1);
				poly = convexCut(poly, qs[1], qs[0]);
				res += rec(convexCut(poly, qs[0], p1), b1, b2, i, 1);
				res += rec(convexCut(poly, p1, qs[1]), b1, b2, i, 1);
			} else {
				poly = convexCut(poly, qs[1], qs[0]);
				poly = convexCut(poly, p1, qs[0]);
				poly = convexCut(poly, qs[1], p1);
				res += rec(poly, b1, b2, i, 1);
			}
		} else {
			P[] qs = tanCP(ps[i], rs[i], p2);
			if (b2) {
				res += rec(convexCut(poly, qs[0], qs[1]), b1, b2, i + 1, 0);
				poly = convexCut(poly, qs[1], qs[0]);
				res += rec(convexCut(poly, qs[0], p2), b1, b2, i + 1, 0);
				res += rec(convexCut(poly, p2, qs[1]), b1, b2, i + 1, 0);
			} else {
				poly = convexCut(poly, qs[1], qs[0]);
				poly = convexCut(poly, p2, qs[0]);
				poly = convexCut(poly, qs[1], p2);
				res += rec(poly, b1, b2, i + 1, 0);
			}
		}
		return res;
	}
	
	double calcArea(P[] poly) {
		double res = 0;
		int m = poly.length;
		for (int i = 0; i < m; i++) {
			P p = poly[i], q = poly[(i + 1) % m];
			res += p.det(q) / 2;
		}
		if (VIS) vis(poly);
		if (abs(res) > EPS) {
			for (int i = 0; i < m; i++) {
				P p = poly[i], q = poly[(i + 1) % m];
				for (int j = 0; j < n; j++) {
					res -= areaCT(rs[j], O.sub(ps[j]), p.sub(ps[j]));
					res -= areaCT(rs[j], p.sub(ps[j]), q.sub(ps[j]));
					res -= areaCT(rs[j], q.sub(ps[j]), O.sub(ps[j]));
				}
			}
		}
		if (VIS) debug(res);
		return res;
	}
	
	double rad(P u, P v) {
		double rad = atan2(u.det(v), u.dot(v));
		return rad;
	}
	
	double areaCT(double r, P p1, P p2) {
		boolean b1 = p1.abs() > r + EPS, b2 = p2.abs() > r + EPS;
		if (b1 && b2) {
			if (crsCS(O, r, p1, p2)) {
				P[] qs = isCL(O, r, p1, p2);
				return (r * r * (rad(p1, p2) - rad(qs[0], qs[1])) + qs[0].det(qs[1])) / 2;
			} else return r * r * rad(p1, p2) / 2;
		} else if (b1) {
			P q = isCL(O, r, p1, p2)[0];
			return (r * r * rad(p1, q) + q.det(p2)) / 2;
		} else if (b2) {
			P q = isCL(O, r, p1, p2)[1];
			return (r * r * rad(q, p2) + p1.det(q)) / 2;
		} else {
			return p1.det(p2) / 2;
		}
	}
	
	boolean crsCS(P c, double r, P p1, P p2) {
		return disSP(p1, p2, c) < r + EPS && (r < c.sub(p1).abs() + EPS || r < c.sub(p2).abs() + EPS);
	}
	
	double disSP(P p1, P p2, P q) {
		if (p2.sub(p1).dot(q.sub(p1)) < EPS) return q.sub(p1).abs();
		if (p1.sub(p2).dot(q.sub(p2)) < EPS) return q.sub(p2).abs();
		return disLP(p1, p2, q);
	}
	
	boolean crsCL(P c, double r, P p1, P p2) {
		return disLP(p1, p2, c) < r + EPS;
	}
	
	P proj(P p1, P p2, P q) {
		return p1.add(p2.sub(p1).mul(p2.sub(p1).dot(q.sub(p1)) / p2.sub(p1).abs2()));
	}
	
	P[] isCL(P c, double r, P p1, P p2) {
		double x = p1.sub(c).dot(p2.sub(p1));
		double y = p2.sub(p1).abs2();
		double d = x * x - y * (p1.sub(c).abs2() - r * r);
		if (d < -EPS) return new P[] {proj(p1, p2, c), proj(p1, p2, c)};
		if (d < EPS) d = 0;
		P q1 = p1.sub(p2.sub(p1).mul(x / y));
		P q2 = p2.sub(p1).mul(sqrt(d) / y);
		return new P[]{q1.sub(q2), q1.add(q2)};
	}
	
	double EPS = 1e-10;
	int sig(double d) {
		return (d < -EPS) ? -1 : (d > EPS) ? 1 : 0;
	}
	P O = new P(0, 0);
	class P implements Comparable<P> {
		double x, y;
		P(double x, double y) {
			this.x = x;
			this.y = y;
		}
		P add(P p) {
			return new P(x + p.x, y + p.y);
		}
		P sub(P p) {
			return new P(x - p.x, y - p.y);
		}
		P mul(double d) {
			return new P(x * d, y * d);
		}
		P div(double d) {
			return new P(x / d, y / d);
		}
		double dot(P p) {
			return x * p.x + y * p.y;
		}
		double det(P p) {
			return x * p.y - y * p.x;
		}
		double abs() {
			return sqrt(abs2());
		}
		double abs2() {
			return x * x + y * y;
		}
		P rot90() {
			return new P(-y, x);
		}
		public int compareTo(P o) {
			int comp = sig(x - o.x);
			if (comp != 0) return comp;
			return sig(y - o.y);
		}
		public String toString() {
			return String.format("(%.2f, %.2f)", x, y);
		}
	}
	
	double disLP(P p1, P p2, P q) {
		return abs(p2.sub(p1).det(q.sub(p1))) / p2.sub(p1).abs();
	}
	
	P isLL(P p1, P p2, P q1, P q2) {
		double d = q2.sub(q1).det(p2.sub(p1));
		if (abs(d) < EPS) return null;
		return p1.add(p2.sub(p1).mul(q2.sub(q1).det(q1.sub(p1)) / d));
	}
	
	P[] tanCP(P c, double r, P p) {
		double x = p.sub(c).abs2();
		double d = x - r * r;
		if (d < EPS) d = 0;
		P q1 = p.sub(c).mul(r * r / x);
		P q2 = p.sub(c).mul(-r * sqrt(d) / x).rot90();
		return new P[]{c.add(q1.sub(q2)), c.add(q1.add(q2))};
	}
	
	P[] convexCut(P[] ps, P p1, P p2) {
		int n = ps.length;
		ArrayList<P> res = new ArrayList<P>();
		for (int i = 0; i < n; i++) {
			int d1 = sig(p2.sub(p1).det(ps[i].sub(p1)));
			int d2 = sig(p2.sub(p1).det(ps[(i + 1) % n].sub(p1)));
			if (d1 >= 0) res.add(ps[i]);
			if (d1 * d2 < 0) res.add(isLL(p1, p2, ps[i], ps[(i + 1) % n]));
		}
		return res.toArray(new P[0]);
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d:%n", o);
			solve();
			System.out.flush();
		}
	}
	
	void vis(P[] poly) {
		int m = poly.length;
		vis.clear();
		for (int i = 0; i < m; i++) {
			vis.g.drawLine(f(poly[i].x), f(poly[i].y), f(poly[(i + 1) % m].x), f(poly[(i + 1) % m].y));
		}
		vis.g.drawArc(f(p1.x) - 2, f(p1.y) - 2, 4, 4, 0, 360);
		vis.g.drawArc(f(p2.x) - 2, f(p2.y) - 2, 4, 4, 0, 360);
		for (int i = 0; i < n; i++) {
			debug(ps[i].y, rs[i]);
			vis.g.drawArc(f(ps[i].x - rs[i]), f(ps[i].y - rs[i]), f(ps[i].x + rs[i]) - f(ps[i].x - rs[i]), f(ps[i].y + rs[i]) - f(ps[i].y - rs[i]), 0, 360);
			vis.g.drawArc(f(ps[i].x) - 2, f(ps[i].y) - 2, 4, 4, 0, 360);
		}
		vis.vis();
	}
	
	int f(double d) {
		return 50 + (int)round(d * 4);
	}
	
	Vis vis = VIS ? new Vis() : null;
	
	class Vis extends JFrame {
		BufferedImage img;
		Graphics2D g;
		boolean stop;
		Vis() {
			img = new BufferedImage(500, 500, BufferedImage.TYPE_INT_RGB);
			g = (Graphics2D)img.getGraphics();
			g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
			clear();
			JComponent c = new JComponent() {
				protected void paintComponent(Graphics g) {
					super.paintComponent(g);
					g.drawImage(img, 0, 0, null);
				}
			};
			c.setPreferredSize(new Dimension(500, 500));
			add(c);
			addMouseListener(new MouseAdapter() {
				public void mouseClicked(MouseEvent e) {
					stop = false;
				}
			});
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			pack();
			setVisible(true);
		}
		void vis() {
			repaint();
			stop = true;
			try {
				while (stop) Thread.sleep(10);
			} catch (Exception e) {
			}
		}
		void clear() {
			g.setColor(Color.WHITE);
			g.fillRect(0, 0, 500, 500);
			g.setColor(Color.BLACK);
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new F().run();
	}
}
