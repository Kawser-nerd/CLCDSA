import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class C {
	
	class Edge {
		int from, to, min, max;
		int cost;
		boolean fixed = false;

		Edge(int from, int to, int min, int max, int cost) {
			this.from = from;
			this.to = to;
			this.min = min;
			this.max = max;
			this.cost = cost;
		}
	}
	
	public static final int INF = Integer.MAX_VALUE / 2;
	
	int n, m, p;
	ArrayList<Edge>[] graph;
	Edge[] edges;
	int[] path;

	private void solve() throws Exception {
		n = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			graph[i] = new ArrayList<>();
		}
		m = nextInt();
		p = nextInt();
		edges = new Edge[m];
		for (int i = 0; i < m; ++i) {
			int from = nextInt() - 1, to = nextInt() - 1;
			int min = nextInt(), max = nextInt();
			Edge edge = new Edge(from, to, min, max, max);
			graph[from].add(edge);
			edges[i] = edge;
		}
		path = new int[p];
		for (int i = 0; i < p; ++i) {
			path[i] = nextInt() - 1;
		}
		used = new boolean[n];
		dist = new int[n];
		prev = new int[n];
		prevInd = new int[n];
		totalDist = new int[n];
		for (int pathInd = 0; pathInd < p; ++pathInd) {
			Arrays.fill(totalDist, INF);
			for (Edge e : edges) {
				if (!e.fixed) {
					e.cost = -1;
				}
			}
			edges[path[pathInd]].cost = INF;
			edges[path[pathInd]].fixed = true;
			int len = 0;
			for (int i = pathInd; i >= 0; --i) {
				len += edges[path[i]].min;
				getLength(edges[path[i]].from, -len, false);
				/*if (getLength(edges[path[i]].from, false) < len + d) {
					out.println(path[pathInd] + 1);
					return;
				}*/
			}
			int d = getLength(edges[path[pathInd]].to, 0, true);
			if (d > totalDist[1]) {
				out.println(path[pathInd] + 1);
				return;
			}
		}
		out.println("Looks Good To Me");
	}
	
	boolean[] used;
	int[] totalDist;
	int[] dist;
	int[] prev;
	int[] prevInd;

	private int getLength(int v, int startCost, boolean change) {
		Arrays.fill(used, false);
		Arrays.fill(dist, INF);
		Arrays.fill(prev, -1);
		dist[v] = startCost;
		used[v] = true;
		TreeSet<TT> q = new TreeSet<>();
		q.add(new TT(v, dist[v]));
		while (!q.isEmpty()) {
			TT cur = q.pollFirst();
			if (change && cur.dist > totalDist[cur.v]) {
				continue;
			}
			for (int edgeInd = 0; edgeInd < graph[cur.v].size(); ++edgeInd) {
				Edge e = graph[cur.v].get(edgeInd);
				int len = e.cost;
				if (!e.fixed) {
					if (change) {
						len = e.min;
					} else if (e.cost < 0) {
						len = e.max;
					}
				}
				if (cur.dist + len < dist[e.to]) {
					q.remove(new TT(e.to, dist[e.to]));
					dist[e.to] = cur.dist + len;
					q.add(new TT(e.to, dist[e.to]));
					prev[e.to] = cur.v;
					prevInd[e.to] = edgeInd;
				}
			}
			if (!change) {
				totalDist[cur.v] = Math.min(totalDist[cur.v], cur.dist);
			}
		}
		/*if (change) {
			int tmp = 1;
			while (tmp != v && prev[tmp] != -1) {
				Edge e = graph[prev[tmp]].get(prevInd[tmp]);
				e.cost = e.min;
				tmp = prev[tmp];
			}
		}*/
		return dist[1];
	}
	
	class TT implements Comparable<TT> {
		int v, dist;

		TT(int v, int dist) {
			this.v = v;
			this.dist = dist;
		}

		@Override
		public int compareTo(TT o) {
			if (dist != o.dist) {
				return Integer.compare(dist, o.dist);
			}
			return Integer.compare(v, o.v);
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			TT tt = (TT) o;

			if (dist != tt.dist) return false;
			if (v != tt.v) return false;

			return true;
		}
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}

		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		new C("C").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
