import java.util.*;

class Edge {
	Node t;
	Edge twin;
	long f, c;
	private Edge(Node t, int f, int c) {
		this.t = t;
		this.f = f;
		this.c = c;
	}
	static void newPair(Node s, Node t, int f, int c) {
		Edge[] pair = new Edge[]{new Edge(t, f, c), new Edge(s, 0, -c)};
		pair[0].twin = pair[1];
		pair[1].twin = pair[0];
		s.offer(pair[0]);
		t.offer(pair[1]);
	}
}

class Node extends LinkedList<Edge> {
	long dist;
	Edge pre;
}

class Graph {
	Graph(int n) {
		nodes = new Node[n];
		for(int i=0; i<n; ++i)
			nodes[i] = new Node();
		dist = new long[n];
	}
	void setS(int s) {
		this.s = s;
	}
	void setT(int t) {
		this.t = t;
	}
	void addE(int s, int t, int f, int c) {
		Edge.newPair(nodes[s], nodes[t], f, c);
	}
	long minC() {
		long ans = 0l;
		List<Edge> path=spfa();
		while(path!=null) {
			long f = path.get(0).f;
			for(Edge e: path)
				f = Math.min(f, e.f);
			for(Edge e: path) {
				ans += f*e.c;
				e.f -= f;
				e.twin.f += f;
			}
			path = spfa();
		}
		return ans;
	}
	List<Edge> spfa() {
		Queue<Node> q = new LinkedList<Node>();
		for(Node v: nodes)
			v.dist = (int)1e9;
		nodes[s].dist = 0;
		nodes[t].pre = null;
		q.offer(nodes[s]);
		while(!q.isEmpty()) {
			Node cur = q.poll();
			for(Edge e: cur) {
				if(e.f==0) continue;
				if(e.t.dist<=cur.dist+e.c)
					continue;
				e.t.dist = cur.dist+e.c;
				e.t.pre = e;
				q.offer(e.t);
			}
		}
		if(nodes[t].pre==null) return null;
		List<Edge> ans = new LinkedList<Edge>();
		Node v = nodes[t];
		while(nodes[s]!=v) {
			ans.add(v.pre);
			v = v.pre.twin.t;
		}
		//System.err.println("Ans has "+ans.size());
		return ans;
	}
	int s, t;
	Node[] nodes;
	long[] dist;
}

public class Main {
	final static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		int T = in.nextInt();
		for(int cas=1; cas<=T; ++cas) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			int[] v = new int[N];
			for(int i=0; i<N; ++i)
				v[i] = in.nextInt();
			Graph g = new Graph(N*2+1);
			g.setS(N*2-1);
			g.setT(N*2);
			g.addE(g.s, 0, E, 0);
			g.addE(0, g.t, E, -v[0]);
			for(int i=1; i<N; ++i) {
				g.addE(i*2-2, i*2-1, E, 0);
				g.addE(i*2-1, i*2, E, 0);
				g.addE(g.s, i*2-1, R, 0);
				g.addE(i*2, g.t, E, -v[i]);
			}
			System.out.println("Case #"+cas+": "+(-g.minC()));
			System.err.println(cas);
		}
	}
}
