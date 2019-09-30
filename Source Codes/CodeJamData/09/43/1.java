import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	Scanner sc;
	
	void solve() {
		int n = sc.nextInt(), k = sc.nextInt();
		int[][] is = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				is[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j + 1 < n; j++) {
				if (is[j][0] > is[j + 1][0]) {
					int[] t = is[j]; is[j] = is[j + 1]; is[j + 1] = t;
				}
			}
		}
		V[] vs = new V[n], us = new V[n];
		for (int i = 0; i < n; i++) {
			vs[i] = new V();
			us[i] = new V();
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ok(is[i], is[j])) vs[i].add(us[j]);
			}
		}
		System.out.println(n - hopcroftKarp(vs));
	}
	
	int hopcroftKarp(V[] vs) {
		for (int match = 0;;) {
			Queue<V> que = new LinkedList<V>();
			for (V v : vs) v.level = -1;
			for (V v : vs) if (v.pair == null) {
				v.level = 0;
				que.offer(v);
			}
			while (!que.isEmpty()) {
				V v = que.poll();
				for (V u : v) {
					V w = u.pair;
					if (w != null && w.level < 0) {
						w.level = v.level + 1;
						que.offer(w);
					}
				}
			}
			for (V v : vs) v.used = false;
			int d = 0;
			for (V v : vs) if (v.pair == null && dfs(v)) d++;
			if (d == 0) return match;
			match += d;
		}
	}
	boolean dfs(V v) {
		v.used = true;
		for (V u : v) {
			V w = u.pair;
			if (w == null || !w.used && v.level < w.level && dfs(w)) {
				v.pair = u;
				u.pair = v;
				return true;
			}
		}
		return false;
	}
	class V extends ArrayList<V> {
		V pair;
		int level;
		boolean used;
		void connect(V v) {
			add(v);
			v.add(this);
		}
	}
	
	boolean ok(int[] is, int[] js) {
		int n = is.length;
		for (int i = 0; i < n; i++) {
			if (is[i] == js[i]) return false;
		}
		for (int i = 0; i + 1 < n; i++) {
			if (is[i] > js[i] && is[i + 1] < js[i + 1]) return false;
			if (is[i] < js[i] && is[i + 1] > js[i + 1]) return false;
		}
		return true;
	}
	
	void run() {
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
