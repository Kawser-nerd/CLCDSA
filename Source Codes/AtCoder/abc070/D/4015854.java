import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static final long INF = 100000000000000l;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;
    static long[] d;
    static int N;
	static ArrayList<Edge>[] adj;
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int[] a = new int[N - 1];
		int[] b = new int[N - 1];
		long[] c = new long[N - 1];
		d = new long[N];
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
		adj = new ArrayList[N];
		for(int i = 0; i < N; i++) {
			adj[i] = new ArrayList<Edge>();
		}
		for(int i = 0; i < N - 1; i++) {
			adj[a[i]].add(new Edge(a[i], b[i], c[i]));
			adj[b[i]].add(new Edge(b[i], a[i], c[i]));
		}
		dijkstra(K);
		for(int i = 0; i < Q; i++) {
			long ans = d[x[i]] + d[y[i]];
			System.out.println(ans);
		}
	}
	static void dijkstra(int K){
		Queue<Node> pq = new PriorityQueue<Node>(new MyComparator());
		int[] color = new int[N];
		for(int i = 0; i < N; i++) {
			d[i] = INF;
			color[i] = WHITE;
		}
		d[K] = 0;
		pq.add(new Node(K, 0l));
		while(!pq.isEmpty()) {
			Node f = pq.poll();
			int u = f.id;
			color[u] = BLACK;
			if(d[u] < f.cost) continue;
			for(int j = 0; j < adj[u].size(); j++) {
				int v = adj[u].get(j).to;
				if(color[v] == BLACK) continue;
				d[v] = d[u] + adj[u].get(j).cost;
				pq.add(new Node(v, d[v]));
				color[v] = GRAY;
			}
		}
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
	static class Edge{
		int from, to;
		long cost;
		public Edge(int from, int to, long cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
	}
}