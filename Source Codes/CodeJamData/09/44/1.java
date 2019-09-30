import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import java.math.*;
import java.util.*;

public class D {
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt();
		P[] ps = new P[n];
		double[] rs = new double[n];
		double left = 0, right = 1e5;
		for (int i = 0; i < n; i++) {
			ps[i] = new P(sc.nextDouble(), sc.nextDouble());
			rs[i] = sc.nextDouble();
			left = max(left, rs[i]);
		}
		for (int i = 0; i < 50; i++) {
			double mid = (left + right) / 2;
			List<BigInteger> list = new ArrayList<BigInteger>();
			for (int j = 0; j < n; j++) {
				BigInteger b = ZERO;
				b = b.setBit(j);
				for (int k = 0; k < n; k++) if (ps[j].sub(ps[k]).abs() + rs[k] < mid + EPS) b = b.setBit(k);
				list.add(b);
				for (int k = 0; k < j; k++) {
					for (P p : isCC(ps[j], mid - rs[j], ps[k], mid - rs[k])) {
						b = ZERO;
						b = b.setBit(j).setBit(k);
						for (int a = 0; a < n; a++) if (p.sub(ps[a]).abs() + rs[a] < mid + EPS) b = b.setBit(a);
						list.add(b);
					}
				}
			}
			boolean ok = false;
			BigInteger[] bs = list.toArray(new BigInteger[0]);
			int m = bs.length;
			loop : for (int j = 0; j < m; j++) {
				for (int k = 0; k <= j; k++) if (bs[j].or(bs[k]).bitCount() == n) {
					ok = true;
					break loop;
				}
			}
			if (ok) {
				right = mid;
			} else {
				left = mid;
			}
		}
		System.out.printf("%.10f%n", right);
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
		P rot90() {
			return new P(-y, x);
		}
		public String toString() {
			return String.format("(%.2f, %.2f)", x, y);
		}
	}
	
	double EPS = 1e-10;
	
	P[] isCC(P c1, double r1, P c2, double r2) {
		double x = c1.sub(c2).abs2();
		double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
		double d = r1 * r1 / x - y * y;
		if (d < -EPS) return new P[0];
		if (d < EPS) d = 0;
		P q1 = c1.add(c2.sub(c1).mul(y));
		P q2 = c2.sub(c1).mul(sqrt(d)).rot90();
		return new P[]{q1.sub(q2), q1.add(q2)};
	}
	
	void run() {
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			debug(o);
			System.out.printf("Case #%d: ", o);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}
