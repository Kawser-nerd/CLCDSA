import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	boolean TIME = true;
	Scanner sc;
	
	class ListP extends ArrayList<P> {
	}
	
	void solve() {
		int n = sc.nextInt();
		P[] ps = new P[n];
		for (int i = 0; i < n; i++) {
			ps[i] = new P(sc.nextLong(), sc.nextLong());
		}
		double res = Double.POSITIVE_INFINITY;
		int N = 20;
		ListP[] lists = new ListP[n];
		for (int i = 0; i < n; i++) {
			lists[i] = new ListP();
			lists[i].add(new P(0, i));
		}
		E[] es = cand(ps);
		for (E e : es) {
			long d = dis2(ps[e.u], ps[e.v]);
			lists[e.u].add(new P(d, e.v));
			lists[e.v].add(new P(d, e.u));
		}
		int[][] is = new int[n][N];
		for (int i = 0; i < n; i++) {
			Collections.sort(lists[i]);
			int m = min(N, lists[i].size());
			for (int j = 0; j < m; j++) {
				is[i][j] = (int)lists[i].get(j).y;
			}
		}
		debug();
		for (int i1 = 0; i1 < n; i1++) {
			for (int j2 = 0; j2 < N; j2++) {
				int i2 = is[i1][j2];
				if (i2 < 0) break;
				for (int j3 = 0; j3 < N; j3++) {
					int i3 = is[i2][j3];
					if (i3 < 0) break;
					if (i1 != i2 && i2 != i3 && i3 != i1) {
						double d = dis(ps[i1], ps[i2]) + dis(ps[i2], ps[i3]) + dis(ps[i3], ps[i1]);
						if (res > d) res = d;
					}
				}
			}
		}
		System.out.printf("%.10f%n", res);
	}
	
	double dis(P p1, P p2) {
		double x = p1.x - p2.x;
		double y = p1.y - p2.y;
		return sqrt(x * x + y * y);
	}
	
	long dis2(P p1, P p2) {
		long x = p1.x - p2.x;
		long y = p1.y - p2.y;
		return x * x + y * y;
	}
	
	int[] dx = {-1, -1, 1, 1}, dy = {-1, 1, 1, -1};
	E[] cand(P[] ps) {
		int n = ps.length;
		this.ps = ps;
		qs = new int[n];
		ArrayList<E> res = new ArrayList<E>();
		for (int k = 0; k < 4; k++) {
			for (int d = 1; d <= 3; d += 2) {
				mp = new P(dx[k], dy[k]);
				sp = new P(dx[(k + d) % 4], dy[(k + d) % 4]);
				P fp = new P((mp.x + sp.x) / 2, (mp.y + sp.y) / 2);
				P[] ls = new P[n];
				for (int i = 0; i < n; i++) ls[i] = new P(ps[i].dot(fp), i);
				sort(ls);
				int[] is = new int[n];
				for (int i = 0; i < n; i++) is[i] = (int)ls[i].y;
				fill(qs, -1);
				rec(is, is.clone(), 0, n);
				for (int i = 0; i < n; i++) if (qs[i] >= 0) {
					res.add(new E(i, qs[i]));
				}
			}
		}
		return res.toArray(new E[0]);
	}
	P[] ps;
	int[] qs;
	P mp, sp;
	void rec(int[] is, int[] js, int s, int t) {
		int n = t - s, m = (s + t) / 2;
		if (n > 1) {
			rec(js, is, s, m);
			rec(js, is, m, t);
			for (int i = s, j = m, p = s, q = -1; p < t; p++) {
				if (j == t || i < m && ps[js[i]].dot(sp) < ps[js[j]].dot(sp)) {
					is[p] = js[i++];
					if (q >= 0 && (qs[is[p]] < 0 || ps[qs[is[p]]].dot(mp) > ps[q].dot(mp))) {
						qs[is[p]] = q;
					}
				} else {
					is[p] = js[j++];
					if (q < 0 || ps[q].dot(mp) > ps[is[p]].dot(mp)) q = is[p];
				}
			}
		}
	}
	class P implements Comparable<P> {
		long x, y;
		P(long x, long y) {
			this.x = x;
			this.y = y;
		}
		long dot(P p) {
			return x * p.x + y * p.y;
		}
		public int compareTo(P o) {
			if (x < o.x) return -1;
			if (x > o.x) return 1;
			return 0;
		}
	}
	class E {
		int v, u;
		E(int v, int u) {
			this.v = v;
			this.u = u;
		}
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
