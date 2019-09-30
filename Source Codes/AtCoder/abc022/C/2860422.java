import java.util.*;
import java.util.stream.*;

public class Main {
	static final int INF = 100000000;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		List<Edge> list = new ArrayList<>();
		int[][] route = new int[n][n];
		for (int[] arr : route) {
			Arrays.fill(arr, INF);
		}
		for (int i = 0; i < n; i++) {
			route[i][i] = 0;
		}
		for (int k = 0; k < m; k++) {
			int u = in.nextInt() - 1, v = in.nextInt() - 1, l = in.nextInt();
			if (u == 0 || v == 0) {
				list.add(new Edge(u == 0 ? v : u, l));
			} else {
				route[u][v] = route[v][u] = l;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					route[x][y] = Math.min(route[x][y], route[x][k] + route[k][y]);
				}
			}
		}
		int ans = INF;
		for (Edge a : list) {
			for (Edge b : list) {
				if (a.to != b.to && route[a.to][b.to] != INF) {
					ans = Math.min(ans, route[a.to][b.to] + a.cost + b.cost);
				}
			}
		}
		System.out.println(ans == INF ? -1 : ans);
	}
}

class Edge {
	int to, cost;

	public Edge(int to, int cost) {
		this.to = to;
		this.cost = cost;
	}
}