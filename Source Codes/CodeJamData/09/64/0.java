import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
	boolean TIME = false;
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt();
		int[] xs = new int[n], ys = new int[n], rs = new int[n], ps = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = sc.nextInt();
			ys[i] = sc.nextInt();
			rs[i] = sc.nextInt();
			ps[i] = sc.nextInt();
		}
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis(xs[i] - xs[j], ys[i] - ys[j]) <= rs[i] * rs[i]) {
					g[i][j] = true;
				}
			}
		}
		V[] vs = new V[n];
		for (int i = 0; i < n; i++) vs[i] = new V();
		V s = new V(), t = new V();
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (ps[i] < 0) vs[i].add(t, -ps[i]);
			else {
				res += ps[i];
				s.add(vs[i], ps[i]);
			}
			for (int j = 0; j < n; j++) if (i != j && g[i][j]) {
				vs[i].add(vs[j], INF);
			}
		}
		System.out.println(res - dinic(s, t));
//		int res = 0;
//		for (int i = 0; i < 1 << n; i++) {
//			boolean ok = true;
//			int tmp = 0;
//			for (int j = 0; j < n; j++) if ((i >> j & 1) != 0) {
//				for (int k = 0; k < n; k++) if (g[j][k]) {
//					if ((i >> k & 1) == 0) {
//						ok = false;
//					}
//				}
//				tmp += ps[j];
//			}
//			if (ok) {
//				res = max(res, tmp);
//			}
//		}
//		System.out.println(res);
	}
	
	int INF = 1 << 29;
	int dinic(V s, V t) {
		int flow = 0;
		for (int p = 1; ; p++) {
			Queue<V> que = new LinkedList<V>();
			s.level = 0;
			s.p = p;
			que.offer(s);
			while (!que.isEmpty()) {
				V v = que.poll();
				v.iter = v.es.size() - 1;
				for (E e : v.es) if (e.to.p < p && e.cap > 0) {
					e.to.level = v.level + 1;
					e.to.p = p;
					que.offer(e.to);
				}
			}
			if (t.p < p) return flow;
			for (int f; (f = dfs(s, t, INF)) > 0; ) flow += f;
		}
	}
	int dfs(V v, V t, int f) {
		if (v == t) return f;
		for (; v.iter >= 0; v.iter--) {
			E e = v.es.get(v.iter);
			if (v.level < e.to.level && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					e.rev.cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	class V {
		ArrayList<E> es = new ArrayList<E>();
		int level, p, iter;
		void add(V to, int cap) {
			E e = new E(to, cap), rev = new E(this, 0);
			e.rev = rev; rev.rev = e;
			es.add(e); to.es.add(rev);
		}
	}
	class E {
		V to;
		E rev;
		int cap;
		E(V to, int cap) {
			this.to = to;
			this.cap = cap;
		}
	}
	
	int dis(int x, int y) {
		return x * x + y * y;
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
		new D().run();
	}
}
