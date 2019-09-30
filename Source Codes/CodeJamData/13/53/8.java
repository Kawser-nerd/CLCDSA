import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N, M, P;
	int[] from, to;
	long[] min, max;
	int[] path;
	
	void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		P = sc.nextInt();
		from = new int[M];
		to = new int[M];
		min = new long[M];
		max = new long[M];
		for (int i = 0; i < M; i++) {
			from[i] = sc.nextInt() - 1;
			to[i] = sc.nextInt() - 1;
			min[i] = sc.nextInt();
			max[i] = sc.nextInt();
		}
		path = new int[P];
		for (int i = 0; i < P; i++) path[i] = sc.nextInt() - 1;
	}
	
	V[] vs;
	
	void solve() {
		vs = new V[N];
		for (int i = 0; i < N; i++) vs[i] = new V(i);
		for (int i = 0; i < M; i++) {
			vs[from[i]].add(new E(vs[to[i]], min[i], max[i]));
		}
		for (int i = 0; i < P; i++) {
			if (!check(i)) {
				System.out.println(path[i] + 1);
				return;
			}
		}
		System.out.println("Looks Good To Me");
	}
	
	boolean check(int i) {
		long[] minD = dij1(i), maxD = dij2(i);
		boolean[] can = new boolean[N];
		for (int j = 0; j < N; j++) can[j] = minD[j] <= maxD[j];
//		debug(i, can);
//		debug(minD);
//		debug(maxD);
		int s = to[path[i]];
		if (!can[s]) return false;
		boolean[] visit = new boolean[N];
		visit[s] = true;
		Queue<Integer> que = new LinkedList<>();
		que.offer(s);
		while (!que.isEmpty()) {
			int v = que.poll();
			if (v == to[path[P - 1]]) return true;
			for (E e : vs[v]) if (!visit[e.to.id] && can[e.to.id]) {
				visit[e.to.id] = true;
				que.offer(e.to.id);
			}
		}
		return false;
	}
	
	class V extends ArrayList<E> {
		int id;
		long min;
		V(int id) {
			this.id = id;
		}
	}
	
	class E {
		V to;
		long min, max;
		E(V to, long min, long max) {
			this.to = to;
			this.min = min;
			this.max = max;
		}
	}
	
	long INF = 1L << 60;
	
	long[] dij1(int i) {
		for (V v : vs) v.min = INF;
		PriorityQueue<Entry> que = new PriorityQueue<>();
		long tmp = 0;
		for (int j = 0; j <= i; j++) tmp += min[path[j]];
		vs[to[path[i]]].min = tmp;
		que.offer(new Entry(vs[to[path[i]]], tmp));
		while (!que.isEmpty()) {
			Entry f = que.poll();
			if (f.v.min < f.d) continue;
			for (E e : f.v) {
				long d = f.d + e.min;
				if (e.to.min > d) {
					e.to.min = d;
					que.offer(new Entry(e.to, d));
				}
			}
		}
		long[] res = new long[N];
		for (int j = 0; j < N; j++) res[j] = vs[j].min;
		return res;
	}
	
	long[] dij2(int i) {
		for (V v : vs) v.min = INF;
		PriorityQueue<Entry> que = new PriorityQueue<>();
		long tmp = 0;
		for (int j = 0; j <= i; j++) {
			if (vs[from[path[j]]].min > tmp) {
				vs[from[path[j]]].min = tmp;
				que.offer(new Entry(vs[from[path[j]]], tmp));
				tmp += min[path[j]];
			}
		}
		while (!que.isEmpty()) {
			Entry f = que.poll();
			if (f.v.min < f.d) continue;
			for (E e : f.v) {
				long d = f.d + e.max;
				if (e.to.min > d) {
					e.to.min = d;
					que.offer(new Entry(e.to, d));
				}
			}
		}
		long[] res = new long[N];
		for (int j = 0; j < N; j++) res[j] = vs[j].min;
		return res;
	}
	
	class Entry implements Comparable<Entry> {
		V v;
		long d;
		Entry(V v, long d) {
			this.v = v;
			this.d = d;
		}
		@Override
		public int compareTo(Entry o) {
			return Long.signum(d - o.d);
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
