import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		ProblemE solver = new ProblemE();
		solver.solve(1, in, out);
		out.close();
	}

	static class ProblemE {
		final int MOD = (int) (1e9 + 7);

		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			List<Edge>[] edges = new List[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<>();
			}
			int m = in.nextInt();
			int s = in.nextInt() - 1;
			int t = in.nextInt() - 1;
			for (int i = 0; i < m; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				int c = in.nextInt();
				edges[a].add(new Edge(b, c));
				edges[b].add(new Edge(a, c));
			}

			long[] distS = new long[n];
			int[] waysS = new int[n];
			shortestPaths(s, edges, distS, waysS);
			long[] distT = new long[n];
			int[] waysT = new int[n];
			shortestPaths(t, edges, distT, waysT);

			int[] waysShortest = new int[n];
			for (int i = 0; i < n; i++) {
				if (distS[i] + distT[i] != distS[t]) {
					// Not on a shortest path.
					continue;
				}
				waysShortest[i] = (int) ((long) waysS[i] * waysT[i] % MOD);
			}

			long ans = (long) waysShortest[t] * waysShortest[t] % MOD;

			// Do not meet at a vertex.
			for (int i = 0; i < n; i++) {
				if (distS[i] + distT[i] != distS[t]) {
					// Not on a shortest path.
					continue;
				}
				if (distS[i] == distT[i]) {
					ans = (ans - (long) waysShortest[i] * waysShortest[i]) % MOD;
					if (ans < 0) {
						ans += MOD;
					}
				}
			}

			// Do not meet on an edge.
			for (int i = 0; i < n; i++) {
				for (Edge e : edges[i]) {
					int j = e.dst;
					if (distS[i] + e.length + distT[j] != distS[t]) {
						// Not on a shortest path.
						continue;
					}
					long l1 = distS[i];
					long r1 = distS[j];
					long l2 = distT[j];
					long r2 = distT[i];
					if (Math.max(l1, l2) < Math.min(r1, r2)) {
						long cur = (long) waysS[i] * waysT[j] % MOD * waysS[i] % MOD * waysT[j] % MOD;
						ans -= cur;
						if (ans < 0) {
							ans += MOD;
						}
					}
				}
			}

			out.println(ans);
		}

		private long[] shortestPaths(int s, List<Edge>[] edges, long[] dist, int[] ways) {
			final long infinity = Long.MAX_VALUE / 2;
			Arrays.fill(dist, infinity);
			dist[s] = 0;
			ways[s] = 1;
			PriorityQueue<Vertex> pq = new PriorityQueue<>();
			pq.offer(new Vertex(s, 0));
			while (!pq.isEmpty()) {
				Vertex ver = pq.poll();
				int v = ver.v;
				if (ver.dist != dist[v]) {
					continue;
				}
				for (Edge e : edges[v]) {
					int u = e.dst;
					if (dist[u] > dist[v] + e.length) {
						dist[u] = dist[v] + e.length;
						ways[u] = ways[v];
						pq.offer(new Vertex(u, dist[u]));
					} else if (dist[u] == dist[v] + e.length) {
						ways[u] += ways[v];
						if (ways[u] >= MOD) {
							ways[u] -= MOD;
						}
					}
				}
			}
			return dist;
		}

		class Vertex implements Comparable<Vertex> {
			int v;
			long dist;

			Vertex(int v, long dist) {
				this.v = v;
				this.dist = dist;
			}

			public int compareTo(Vertex o) {
				if (dist != o.dist) {
					return dist < o.dist ? -1 : 1;
				}
				return 0;
			}

		}

		class Edge {
			int dst;
			int length;

			Edge(int dst, int length) {
				this.dst = dst;
				this.length = length;
			}

		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.