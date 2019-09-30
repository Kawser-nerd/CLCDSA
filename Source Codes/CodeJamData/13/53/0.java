import java.util.*;
import static java.lang.Math.*;
import java.io.*;

public class C {
	public static void p(Object... args) { System.out.println(Arrays.deepToString(args));}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			N = in.nextInt();
			M = in.nextInt();
			P = in.nextInt();

			G = new ArrayList[N];
			for (int i = 0; i < N; i++)
				G[i] = new ArrayList<Edge>();
			E = new Edge[M];
			for (int i = 0; i < M; i++) {
				int u = in.nextInt() - 1;
				int v = in.nextInt() - 1;
				int a = in.nextInt();
				int b = in.nextInt();
				E[i] = new Edge(u, v, a, b, i);
				G[u].add(E[i]);
			}
			path = new Edge[P];
			for (int i = 0; i < P; i++) {
				int idx = in.nextInt() - 1;
				path[i] = E[idx];
			}
			int low = 0; // low is always possible
			int high = P;
			while (low < high) {
				int mid = (low + high + 1) / 2;
				if (possible(mid)) {
					//					p(mid, "pass");
					low = mid;
				} else {
					//					p(mid, "fail");
					high = mid - 1;
				}
			}
			if (low == P) {
				System.out.format("Case #%d: Looks Good To Me\n", zz);
			} else {
				System.out.format("Case #%d: %d\n", zz, path[low].index + 1);

			}
		}
	}
	static boolean possible(int mid) {
		for (Edge e : E)
			e.cur = e.b;
		long pathcost = 0;
		for (int i = 0; i < mid; i++) {
			path[i].cur = path[i].a;
			pathcost += path[i].a;
		}

		long[] dstart = new long[N];
		Arrays.fill(dstart, Integer.MAX_VALUE);
		dstart[0] = 0;
		while (true) {
			boolean more = false;
			for (Edge e: E) {
				long nc = dstart[e.u] + e.cur;
				if (nc < dstart[e.v]){
					more = true;
					dstart[e.v] = nc;
				}
			}
			if (!more)
				break;
		}

		long[] dend = new long[N];
		Arrays.fill(dend, Integer.MAX_VALUE);
		dend[1] = 0;
		while (true) {
			boolean more = false;
			for (Edge e: E) {
				long nc = dend[e.v] + e.cur;
				if (nc < dend[e.u]){
					more = true;
					dend[e.u] = nc;
				}
			}
			if (!more)
				break;
		}

		int first = path[mid - 1].v;
		if (pathcost > dstart[first]) {
			//			p("\t", "fail first");
			return false;
		}
		//		p(dstart[first], dend[first], dstart[1]);
		if (dstart[first] + dend[first] == dstart[1])
			return true;

		long[] dnew = new long[N];
		for (int i = 0; i < N; i++)
			dnew[i] = dstart[i];

		PriorityQueue<State> pq = new PriorityQueue<C.State>();
		pq.add(new State(first, pathcost));
		boolean[] U = new boolean[N];
		while (pq.size() > 0) {
			State s = pq.poll();
			//			p("dijk", s.at, s.cost);
			if (U[s.at])
				continue;
			U[s.at] = true;
			for (Edge e : G[s.at]) {
				if (e.cur == e.a)
					continue;
				long nc = dnew[s.at] + e.a;
				//				p("\t\t", e.v, dnew[s.at], e.a, dnew[e.v]);
				if (nc < dnew[e.v] || nc == dstart[e.v]) {
					dnew[e.v] = nc;
					pq.add(new State(e.v, nc));
				}
			}
		}
		return U[1];
	}
	static int N, M, P;
	static ArrayList<Edge>[] G;
	static Edge[] E, path;

	static class State implements Comparable<State> {
		int at;
		long cost;
		State(int at, long cost) {
			this.at = at;
			this.cost = cost;
		}
		public int compareTo(State s) {
			if (cost < s.cost)
				return -1;
			if (cost > s.cost)
				return 1;
			return 0;
		}
	}

	static class Edge {
		int u, v, index;
		long a, b, cur;
		Edge(int u, int v, long a, long b, int index) {
			this.u = u;
			this.v = v;
			this.a = a;
			this.b = b;
			this.index = index;
		}
	}
}
