import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static List<Edge>[] list;
	static long[] dist;

	static class Edge {
		int to;
		long cost;
		public Edge(int to, long cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		list = new ArrayList[n];
		dist = new long[n];
		for(int i = 0; i < n; i++) list[i] = new ArrayList<Edge>();
		for(int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			long c = sc.nextLong();
			list[a].add(new Edge(b, c));
			list[b].add(new Edge(a, c));
		}
		int q = sc.nextInt();
		int k = sc.nextInt() - 1;
		dfs(k, -1, 0);
		for(int i = 0; i < q; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			System.out.println(dist[x] + dist[y]);
		}
	}

	static void dfs(int v, int p, long d) {
		dist[v] = d;
		for(Edge e : list[v]) {
			if(e.to != p) {
				dfs(e.to, v, d + e.cost);
			}
		}
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.