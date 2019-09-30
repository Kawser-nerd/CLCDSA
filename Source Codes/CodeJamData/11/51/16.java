import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void solve() {
		int W = sc.nextInt(), L = sc.nextInt(), U = sc.nextInt(), G = sc.nextInt();
		P[] ps = new P[L + U];
		for (int i = 0; i < L; i++) ps[i] = new P(sc.nextDouble(), sc.nextDouble());
		for (int i = 0; i < U; i++) ps[L + U - i - 1] = new P(sc.nextDouble(), sc.nextDouble());
		double area = area(ps) / G;
		for (int i = 0; i < G - 1; i++) {
			double lb = 0, ub = W;
			for (int j = 0; j < 100; j++) {
				double mid = (lb + ub) / 2;
				P p1 = new P(mid, 0), p2 = new P(mid, 1);
				P[] qs = convexCut(ps, p1, p2);
				if (area(qs) < area) lb = mid;
				else ub = mid;
			}
			System.out.printf("%.10f%n", ub);
			ps = convexCut(ps, new P(ub, 1), new P(ub, 0));
		}
	}
	
	double EPS = 1e-10;
	int sig(double d) {
		return (d < -EPS) ? -1 : (d > EPS) ? 1 : 0;
	}
	
	class P {
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
		public String toString() {
			return String.format("(%.2f, %.2f)", x, y);
		}
	}
	
	double area(P[] ps) {
		int n = ps.length;
		double area = 0;
		for (int i = 0; i < n; i++) {
			area += ps[i].det(ps[(i + 1) % n]);
		}
		return area;
	}
	
	P isLL(P p1, P p2, P q1, P q2) {
		double d = q2.sub(q1).det(p2.sub(p1));
		if (abs(d) < EPS) return null;
		return p1.add(p2.sub(p1).mul(q2.sub(q1).det(q1.sub(p1)) / d));
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
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d:%n", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
