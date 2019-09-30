import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	
	PrintWriter out;
	
	int N;
	String[] eng, fre;
	String[][] ss;
	
	void read(Scanner sc) {
		N = sc.nextInt();
		sc.nextLine();
		eng = sc.nextLine().split(" ");
		fre = sc.nextLine().split(" ");
		ss = new String[N - 2][];
		for (int i = 0; i < N - 2; i++) {
			ss[i] = sc.nextLine().split(" ");
		}
	}
	
	void add(TreeMap<String, Integer> map, String s) {
		if (!map.containsKey(s)) map.put(s, map.size());
	}
	
	void solve() {
		TreeMap<String, Integer> ids = new TreeMap<String, Integer>();
		for (String s : eng) add(ids, s);
		for (String s : fre) add(ids, s);
		for (String[] a : ss) for (String s : a) add(ids, s);
		int n = ids.size();
		V[] xs = new V[n], ys = new V[n];
		V s = new V(), t = new V();
		for (int i = 0; i < n; i++) {
			xs[i] = new V();
			ys[i] = new V();
			xs[i].add(ys[i], INF);
			s.add(xs[i], 1);
			ys[i].add(t, 1);
		}
		for (String a : eng) {
			xs[ids.get(a)].add(t, INF);
		}
		for (String a : fre) {
			s.add(ys[ids.get(a)], INF);
		}
		for (String[] aa : ss) {
			V w = new V();
			for (String s1 : aa) {
				int v = ids.get(s1);
				xs[v].add(w, INF);
				w.add(ys[v], INF);
			}
		}
		out.println(dinic(s, t) - n);
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
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static int __ID = 0;
	public static boolean __ERROR = false;
	
	public static void main(String[] args) {
		int pN = 1;
		if (args.length == 0) {
			try {
				System.setIn(new BufferedInputStream(new FileInputStream(C.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final C[] solvers = new C[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new C();
			outs[i] = new StringWriter();
			solvers[i].out = new PrintWriter(outs[i]);
			solvers[i].out.printf("Case #%d: ", i + 1);
			solvers[i].read(sc);
		}
		Thread[] ts = new Thread[pN];
		for (int i = 0; i < pN; i++) {
			ts[i] = new Thread() {
				@Override
				public void run() {
					for (;;) {
						int id;
						synchronized (C.class) {
							if (__ID == caseN) return;
							id = __ID++;
						}
						try {
							solvers[id].solve();
						} catch (RuntimeException e) {
							__ERROR = true;
							System.err.printf("Error in case %d:%n", id + 1);
							e.printStackTrace();
						}
						solvers[id].out.flush();
						solvers[id] = null;
					}
				}
			};
			ts[i].start();
		}
		for (int i = 0; i < pN; i++) {
			try {
				ts[i].join();
			} catch (InterruptedException e) {
				i--;
				continue;
			}
		}
		for (int i = 0; i < caseN; i++) {
			out.print(outs[i].toString());
		}
		if (__ERROR) out.printf("%nError occured!!!%n");
	}
	
}
