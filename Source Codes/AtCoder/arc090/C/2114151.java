import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Main().run();
	}

	final long MOD = 1_000_000_000 + 7;

	class Edge {
		int src;
		int dst;
		long cost;

		public Edge(int src_, int dst_, long cost_) {
			src = src_;
			dst = dst_;
			cost = cost_;
		}
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int S = sc.nextInt();
		int T = sc.nextInt();
		--S;
		--T;
		ArrayList<Edge>[] g = new ArrayList[N];
		for (int i = 0; i < N; ++i) {
			g[i] = new ArrayList();
		}
		long[][] es = new long[M][];
		for (int i = 0; i < M; ++i) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			long d = sc.nextLong();
			--u;
			--v;
			g[u].add(new Edge(u, v, d));
			g[v].add(new Edge(v, u, d));
			es[i] = new long[] { u, v, d };
		}
		long[][] a = Dijkstra(S, g);
		long[][] b = Dijkstra(T, g);
		long ans = a[1][T] * b[1][S] % MOD;
		long DIST = a[0][T];
		long sub = 0;
		for (int i = 0; i < M; ++i) {
			int u = (int) es[i][0];
			int v = (int) es[i][1];
			long d = es[i][2];
			if (DIST == a[0][u] + d + b[0][v]
					&& 2 * a[0][u] < DIST && DIST < 2 * (a[0][u] + d)) {
				long x = a[1][u] * b[1][v] % MOD;
				x = x * x % MOD;
				sub = (sub + x) % MOD;
			}
			if (DIST == a[0][v] + d + b[0][u] && 2 * a[0][v] < DIST
					&& DIST < 2 * (a[0][v] + d)) {
				long x = a[1][v] * b[1][u] % MOD;
				x = x * x % MOD;
				sub = (sub + x) % MOD;
			}
		}
		for (int i = 0; i < N; ++i) {
			if (DIST == a[0][i] + b[0][i] && a[0][i] == b[0][i]) {
				sub += a[1][i] * b[1][i] % MOD * (a[1][i] * b[1][i] % MOD) % MOD;
				sub %= MOD;
			}
		}
		ans = (ans - sub + MOD) % MOD;
		System.out.println(ans);
	}

	long[][] Dijkstra(int src, ArrayList<Edge>[] g) {
		class S implements Comparable<S> {
			int v;
			long dist;

			public S(int v_, long dist_) {
				v = v_;
				dist = dist_;
			}

			public int compareTo(S arg0) {
				return Long.compare(dist, arg0.dist);
			};
		}

		PriorityQueue<S> pq = new PriorityQueue();
		long[] d = new long[g.length];
		long[] comb = new long[g.length];
		boolean[] vis = new boolean[g.length];
		Arrays.fill(d, Long.MAX_VALUE / 2);
		Arrays.fill(comb, -Long.MAX_VALUE / 2);
		d[src] = 0;
		comb[src] = 1;
		pq.add(new S(src, 0));
		while (!pq.isEmpty()) {
			S s = pq.poll();
			if (vis[s.v])
				continue;
			vis[s.v] = true;
			for (Edge e : g[s.v]) {
				if (d[e.dst] > d[e.src] + e.cost) {
					d[e.dst] = d[e.src] + e.cost;
					comb[e.dst] = comb[e.src];
					pq.add(new S(e.dst, d[e.dst]));
				} else if (d[e.dst] == d[e.src] + e.cost) {
					comb[e.dst] += comb[e.src];
					comb[e.dst] %= MOD;
				}
			}
		}
		long[][] ret = new long[2][];
		ret[0] = d;
		ret[1] = comb;
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.