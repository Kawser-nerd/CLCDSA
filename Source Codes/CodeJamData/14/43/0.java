import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int W, H, B;
	int[] X0, Y0, X1, Y1;
	
	void read() {
		W = sc.nextInt();
		H = sc.nextInt();
		B = sc.nextInt();
		X0 = new int[B];
		Y0 = new int[B];
		X1 = new int[B];
		Y1 = new int[B];
		for (int i = 0; i < B; i++) {
			X0[i] = sc.nextInt();
			Y0[i] = sc.nextInt();
			X1[i] = sc.nextInt();
			Y1[i] = sc.nextInt();
		}
	}
	
	int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	
	void solve() {
		int[][] g = new int[B + 2][B + 2];
		for (int i = 0; i < g.length; i++) fill(g[i], INF);
		g[B][B + 1] = W;
		for (int i = 0; i < B; i++) {
			g[B][i] = X0[i];
			g[i][B + 1] = W - 1 - X1[i];
			for (int j = 0; j < B; j++) if (i != j) {
				int dx = 0, dy = 0;
				if (X1[i] < X0[j]) dx = X0[j] - X1[i] - 1;
				else if (X1[j] < X0[i]) dx = X0[i] - X1[j] - 1;
				if (Y1[i] < Y0[j]) dy = Y0[j] - Y1[i] - 1;
				else if (Y1[j] < Y0[i]) dy = Y0[i] - Y1[j] - 1;
				g[i][j] = max(dx, dy);
			}
		}
		for (int k = 0; k < g.length; k++) {
			for (int i = 0; i < g.length; i++) {
				for (int j = 0; j < g.length; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		System.out.println(g[B][B + 1]);
	}
	
	void solveSmall() {
		boolean[][] ok = new boolean[W][H];
		for (int i = 0; i < W; i++) for (int j = 0; j < H; j++) ok[i][j] = true;
		for (int i = 0; i < B; i++) {
			for (int x = X0[i]; x <= X1[i]; x++) {
				for (int y = Y0[i]; y <= Y1[i]; y++) {
					ok[x][y] = false;
				}
			}
		}
		V[][] in = new V[W][H], out = new V[W][H];
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < H; j++) {
				in[i][j] = new V();
				out[i][j] = new V();
				if (ok[i][j]) in[i][j].add(out[i][j], 1);
			}
		}
		V s = new V(), t = new V();
		for (int i = 0; i < W; i++) {
			s.add(in[i][0], 1);
			out[i][H - 1].add(t, 1);
		}
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < H; j++) {
				for (int d = 0; d < 4; d++) {
					int i2 = i + dx[d], j2 = j + dy[d];
					if (0 <= i2 && i2 < W && 0 <= j2 && j2 < H) {
						out[i][j].add(in[i2][j2], 1);
					}
				}
			}
		}
		System.out.println(dinic(s, t));
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
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
