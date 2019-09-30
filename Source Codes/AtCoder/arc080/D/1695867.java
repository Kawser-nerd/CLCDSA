import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int min_cost_flow(int s, int t, ArrayList<Edge>[] g) {
		class Vertice implements Comparable<Vertice> {
			int id;
			long dist;

			public Vertice(int id, long dist) {
				this.id = id;
				this.dist = dist;
			}

			public int compareTo(Vertice o) {
				return Long.compare(this.dist, o.dist);
			};
		}

		int n = g.length;

		int min_cost = 0;
		g[t].add(new Edge(t, s, (1 << 30), 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				Edge e = g[i].get(j);
				g[e.src].get(j).rev_id = g[e.dst].size();
				g[e.dst].add(new Edge(e.dst, e.src, 0, -e.cost));
				g[e.dst].get(g[e.dst].size() - 1).rev_id = j;
			}
		}

		long[] potential = new long[n];
		int[] excess = new int[n];
		for (int i = 0; i < n; i++) {
			for (Edge e : g[i]) {
				if (e.cost < 0) {
					e.add_flow(e.cap);
					excess[e.dst] += e.flow;
					excess[e.src] -= e.flow;
					g[e.dst].get(e.rev_id).add_flow(-e.cap);
					min_cost += e.cost * e.flow;
				}
			}
		}

		ArrayList<Integer> sink_v = new ArrayList<>();
		ArrayDeque<Integer> source_v = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			if (excess[i] < 0)
				sink_v.add(i);
			else if (excess[i] > 0)
				source_v.add(i);
		}
		while (!source_v.isEmpty()) {

			PriorityQueue<Vertice> priority_queue = new PriorityQueue<>();
			int[] pre_v = new int[n];
			int[] pre_e = new int[n];
			long[] dist = new long[n];
			Arrays.fill(pre_v, -1);
			Arrays.fill(pre_e, -1);
			Arrays.fill(dist, 1L << 60);
			int source = source_v.poll();
			dist[source] = 0;
			pre_v[source] = -1;
			pre_e[source] = -1;
			boolean[] looked = new boolean[n];

			priority_queue.add(new Vertice(source, 0));

			while (!priority_queue.isEmpty()) {
				int v = priority_queue.poll().id;
				if (looked[v])
					continue;
				else
					looked[v] = true;
				for (int i = 0; i < g[v].size(); i++) {
					Edge e = g[v].get(i);
					if (e.residue > 0) {
						if (dist[e.dst] > dist[v] + e.cost - potential[v] + potential[e.dst]) {
							dist[e.dst] = dist[v] + e.cost - potential[v] + potential[e.dst];

							priority_queue.add(new Vertice(e.dst, dist[e.dst]));
							pre_v[e.dst] = v;
							pre_e[e.dst] = i;
							looked[e.dst] = false;
						}
					}
				}
			}
			int sink = -1;
			for (int i = 0; i < sink_v.size(); i++) {
				if (pre_v[sink_v.get(i)] != -1) {
					sink = sink_v.get(i);
					sink_v.remove(i);
					break;
				}
			}
			if (sink == -1) {
				source_v.add(source);
				continue;
			}

			for (int i = 0; i < n; i++) {
				if (dist[i] < (1L << 60))
					potential[i] -= dist[i];
				else
					potential[i] -= (1 << 30);
			}

			int delta = Math.min(Math.abs(excess[source]), Math.abs(excess[sink]));

			for (int i = sink; i != source; i = pre_v[i]) {
				delta = Math.min(delta, g[pre_v[i]].get(pre_e[i]).residue);
			}
			for (int i = sink; i != source; i = pre_v[i]) {
				Edge e = g[pre_v[i]].get(pre_e[i]);
				e.add_flow(delta);
				g[i].get(e.rev_id).add_flow(-delta);
				min_cost += delta * e.cost;
			}
			excess[sink] += delta;
			excess[source] -= delta;
			if (excess[sink] < 0)
				sink_v.add(sink);
			if (excess[source] > 0)
				source_v.add(source);

		}

		return min_cost;
	}

	class Edge {
		int src;
		int dst;
		int cap;
		int cost;
		int residue;
		int flow = 0;
		int rev_id = -1;

		Edge(int src, int dst, int cap, int cost) {
			this.src = src;
			this.dst = dst;
			this.cap = cap;
			this.cost = cost;
			residue = this.cap - flow;
		}

		void add_flow(int flow) {
			this.flow += flow;
			residue = cap - this.flow;
		}

	}

	boolean[] isPrime = new boolean[1_000_000_3];
	{
		Arrays.fill(isPrime, true);
		isPrime[0] = false;
		isPrime[1] = false;
		for (int i = 2; i < isPrime.length; ++i) {
			if (isPrime[i]) {
				for (int j = 2 * i; j < isPrime.length; j += i) {
					isPrime[j] = false;
				}
			}
		}
		isPrime[2] = false;
	}

	void solve(int n, int[] x) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j + 1 < n && x[j] + 1 == x[j + 1]) {
				++j;
			}
			list.add(x[i]);
			list.add(x[j] + 1);
			i = j;
		}
		x = new int[list.size()];
		int even = 0, odd = 0;
		for (int i = 0; i < x.length; ++i) {
			x[i] = list.get(i);
			if (x[i] % 2 == 0)
				++even;
			else
				++odd;
		}
		int[][] dist = new int[list.size()][list.size()];
		for (int i = 0; i < dist.length; ++i) {
			for (int j = 0; j < dist[i].length; ++j) {
				if (i == j)
					continue;
				int v = Math.abs(x[i] - x[j]);
				if (v % 2 == 1) {// ??????
					if (isPrime[v])
						dist[i][j] = 1;// ???????
					else
						dist[i][j] = Integer.MAX_VALUE / 3;
				} else if (v % 2 == 0) {// ?????????????.(????2=5-3,4=9-5)
					dist[i][j] = 2;
				}
			}
		}
		ArrayList<Edge>[] g = new ArrayList[list.size() + 2];
		for (int i = 0; i < g.length; ++i) {
			g[i] = new ArrayList<>();
		}
		int src = g.length - 2;
		int dst = g.length - 1;
		for (int i = 0; i < dist.length; i++) {
			for (int j = 0; j < dist[i].length; j++) {
				if (x[i] % 2 == 0 && x[j] % 2 == 1 && isPrime[Math.abs(x[i] - x[j])])
					g[i].add(new Edge(i, j, 1, -dist[i][j]));
			}
		}
		for (int i = 0; i < list.size(); ++i) {
			if (x[i] % 2 == 0)
				g[src].add(new Edge(src, i, 1, 0));
			else
				g[i].add(new Edge(i, dst, 1, 0));
		}
		int ret = 0;
		int c = -min_cost_flow(src, dst, g);
		ret = c + (even - c) / 2 * 2 + (odd - c) / 2 * 2;
		if ((even - c) % 2 == 1)
			ret += 3;
		System.out.println(ret);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextInt();
		}
		solve(n, x);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.