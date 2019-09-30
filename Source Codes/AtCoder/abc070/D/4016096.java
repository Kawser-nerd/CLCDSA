import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N - 1];
		int[] b = new int[N - 1];
		long[] c = new long[N - 1];
		for(int i = 0; i < N - 1; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;
			c[i] = sc.nextLong();
		}
		int Q = sc.nextInt();
		int K = sc.nextInt() - 1;
		int[] x = new int[Q];
		int[] y = new int[Q];
		for(int i = 0; i < Q; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
		}
		sc.close();
		long[] d = dijkstra(N, K, a, b, c, true);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < Q; i++) {
			long ans = d[x[i]] + d[y[i]];
			sb.append(ans).append("\n");
		}
		System.out.print(sb.toString());
	}
	/**
	 * ??????? (????????)
	 * @param N ???
	 * @param t ??
	 * @param from, to ?
	 * @param cost ?????
	 * @param flag true ?????? false ?????
	 * @return d t ???????????
	 */
	public static long[] dijkstra(int N, int t, int[] from, int[] to, long[] cost, boolean flag) {
		final int WHITE = 0;
	    final int GRAY = 1;
	    final int BLACK = 2;
	    final long INF = 100000000000000l;
		long[] d = new long[N];
		int[] color = new int[N];
		@SuppressWarnings("unchecked")
		ArrayList<Node>[] adj = new ArrayList[N];
		for(int i = 0; i < N; i++) {
			d[i] = INF;
			color[i] = WHITE;
			adj[i] = new ArrayList<Node>();
		}
		int E = from.length;
		for(int i = 0; i < E; i++) {
			adj[from[i]].add(new Node(to[i], cost[i]));
			if(flag)adj[to[i]].add(new Node(from[i], cost[i]));

		}
		Queue<Node> pq = new PriorityQueue<Node>(new MyComparator());
		d[t] = 0;
		pq.add(new Node(t, 0l));
		while(!pq.isEmpty()) {
			Node f = pq.poll();
			int u = f.id;
			color[u] = BLACK;
			if(d[u] < f.cost) continue;
			for(int j = 0; j < adj[u].size(); j++) {
				int v = adj[u].get(j).id;
				if(color[v] == BLACK) continue;
				d[v] = d[u] + adj[u].get(j).cost;
				pq.add(new Node(v, d[v]));
				color[v] = GRAY;
			}
		}
		return d;
	}
	static class Node{
		int id;
		long cost;
		public Node(int id, long cost) {
			this.id = id;
			this.cost = cost;
		}
	}
	static class MyComparator implements Comparator<Node>{
		@Override
        public int compare(Node v1, Node v2) {
			if(v1.cost < v2.cost) {
				return -1;
			}else if(v1.cost == v2.cost) {
				return 0;
			}else {
				return 1;
			}
		}
	}
}