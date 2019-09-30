import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int n;
	String[] A, B;
	
	void read() {
		n = sc.nextInt();
		A = new String[n];
		B = new String[n];
		for (int i = 0; i < n; i++) {
			A[i] = sc.next();
			B[i] = sc.next();
		}
	}
	
	TreeMap<String, Integer> id(String[] S) {
		TreeMap<String, Integer> id = new TreeMap<String, Integer>();
		for (String s : S) {
			if (!id.containsKey(s)) id.put(s, id.size());
		}
		return id;
	}
	
	void solve() {
		TreeMap<String, Integer> idA = id(A), idB = id(B);
		V s = new V(), t = new V();
		V[] vs = new V[idA.size()], us = new V[idB.size()];
		for (int i = 0; i < vs.length; i++) {
			vs[i] = new V();
			s.add(vs[i], 1);
		}
		for (int i = 0; i < us.length; i++) {
			us[i] = new V();
			us[i].add(t, 1);
		}
		for (int i = 0; i < n; i++) {
			vs[idA.get(A[i])].add(us[idB.get(B[i])], 1);
		}
		int flow = dinic(s, t);
		int cover = idA.size() + idB.size() - flow;
		System.out.println(n - cover);
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
