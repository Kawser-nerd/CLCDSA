import java.util.*;
import java.io.*;

public class Main {

	class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

	}

	int mod = 1000000007;

	List<Edge>[] graph;

	long[] distS, countS, distT, countT;

	class Vertex implements Comparable<Vertex> {
		int id;
		long dist;

		public Vertex(int id, long dist) {
			super();
			this.id = id;
			this.dist = dist;
		}

		@Override
		public int compareTo(Vertex o) {
			if (dist != o.dist) {
				return Long.compare(dist, o.dist);
			}
			return id - o.id;
		}
	}

	void calc(long[] dist, long[] count, int s) {
		long INF = Long.MAX_VALUE / 3;
		Arrays.fill(dist, INF);
		dist[s] = 0;
		TreeSet<Vertex> q = new TreeSet<>();
		q.add(new Vertex(s, dist[s]));
		count[s] = 1;
		while (!q.isEmpty()) {
			Vertex cur = q.pollFirst();
			for (int t = 0; t < graph[cur.id].size(); t++) {
				Edge e = graph[cur.id].get(t);
				if (cur.dist + e.cost < dist[e.to]) {
					Vertex v = new Vertex(e.to, dist[e.to]);
					q.remove(v);
					v.dist = dist[e.to] = cur.dist + e.cost;
					count[e.to] = count[cur.id];
					q.add(v);
				} else if (cur.dist + e.cost == dist[e.to]) {
					count[e.to] += count[cur.id];
					if (count[e.to] >= mod) {
						count[e.to] -= mod;
					}
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		graph = new List[n];
		int s = in.nextInt() - 1, t = in.nextInt() - 1;

		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1, cost = in.nextInt();
			graph[from].add(new Edge(to, cost));
			graph[to].add(new Edge(from, cost));
		}

		distS = new long[n];
		distT = new long[n];
		countS = new long[n];
		countT = new long[n];
		calc(distS, countS, s);
		calc(distT, countT, t);

		long result = countS[t] * countS[t] % mod;
		long distST = distT[s];
		if (distST % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (distS[i] + distT[i] == distST && distS[i] * 2 == distST) {
					result -= countS[i] * countS[i] % mod * countT[i] % mod * countT[i] % mod;
					if (result < 0) {
						result += mod;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (Edge e : graph[i]) {
				int from = i, to = e.to;
				if (distS[from] + e.cost + distT[to] == distST && 2 * distS[from] < distST && 2 * distT[to] < distST) {
					result -= countS[from] * countS[from] % mod * countT[to] % mod * countT[to] % mod;
					if (result < 0) {
						result += mod;
					}
				}
			}
		}

		out.println(result);
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.