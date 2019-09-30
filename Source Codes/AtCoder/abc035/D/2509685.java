import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int t = sc.nextInt();
		int[] x = new int[n];
		for(int i = 0 ; i < n ; i++) x[i] = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		for(int i = 0 ; i < m ; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;
			c[i] = sc.nextInt();
		}
		List<Dijkstra.Edge>[] edges = new ArrayList[n];
		List<Dijkstra.Edge>[] backEdges = new ArrayList[n];
		for(int i = 0 ; i < n ; i++) {
			edges[i] = new ArrayList<>();
			backEdges[i] = new ArrayList<>();
		}
		for(int i = 0 ; i < m ; i++) {
			edges[a[i]].add(new Dijkstra.Edge(a[i], b[i], c[i]));
			backEdges[b[i]].add(new Dijkstra.Edge(b[i], a[i], c[i]));
		}
		int[] dist = Dijkstra.dijkstra(n, edges, 0);
		int[] backDist = Dijkstra.dijkstra(n, backEdges, 0);
		long ans = 0;
		for(int i = 0 ; i < n ; i++) {
			long total = (long)dist[i] + (long)backDist[i];
			if(ans < x[i] * (t - total)) ans = (long)x[i] * (t - total);
		}
		System.out.println(ans);
	}
}

class Dijkstra {
	static int[] dijkstra(int n, List<Edge>[] edges, int st) {
		boolean[] fixed = new boolean[n];
		int[] dist = new int[n];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[st] = 0;
		Queue<Edge> q = new PriorityQueue<>();
		q.add(new Edge(st, st, 0));
		while (!q.isEmpty()) {
			Edge e = q.poll();
			if (fixed[e.end]) continue;
			fixed[e.end] = true;
			for (Edge ei : edges[e.end]) {
				if (!fixed[ei.end] && dist[ei.end] > dist[e.end] + ei.cost) {
					dist[ei.end] = dist[e.end] + ei.cost;
					q.add(new Edge(e.end, ei.end, dist[ei.end]));
				}
			}
		}
		return dist;
	}

	static class Edge implements Comparable<Edge> {
		int st, end, cost;

		public Edge(int st, int end, int cost) {
			this.st = st;
			this.end = end;
			this.cost = cost;
		}

		public int compareTo(Edge e) {
			return this.cost - e.cost;
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.