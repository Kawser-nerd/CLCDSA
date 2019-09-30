import java.util.*;

public class Main {
	static class MaxFlow {
		//dinic
		public class Edge {
			int to, cap, rev;

			public Edge(int to, int cap, int rev) {
				this.to = to;
				this.cap = cap;
				this.rev = rev;
			}
		}

		int V;
		ArrayList<ArrayList<Edge>> G;
		int[] level;
		int[] iter;
		public final int INF = 1000000000;
		
		public MaxFlow(int V) {
			this.V = V;
			G = new ArrayList<ArrayList<Edge>>();
			for(int i=0; i<V; i++)
				G.add(new ArrayList<Edge>());
			level = new int[V];
			iter = new int[V];
		}
		
		public void addEdge(int from, int to, int cap) {
			G.get(from).add(new Edge(to, cap, G.get(to).size()));
			G.get(to).add(new Edge(from, 0, G.get(from).size()-1));
		}
		
		void bfs(int s) {
			Arrays.fill(level, -1);
			Queue<Integer> que = new LinkedList<Integer>();
			level[s] = 0;
			que.add(s);
			while(!que.isEmpty()) {
				int v = que.remove();
				for(int i=0; i<G.get(v).size(); i++) {
					Edge e = G.get(v).get(i);
					if(e.cap>0 && level[e.to]<0) {
						level[e.to] = level[v] + 1;
						que.add(e.to);
					}
				}
			}
		}
		
		int dfs(int v, int t, int f) {
			if(v==t) return f;
			for(; iter[v]<G.get(v).size(); iter[v]++) {
				Edge e = G.get(v).get(iter[v]);
				if(e.cap>0 && level[v] < level[e.to]) {
					int d = dfs(e.to, t, Math.min(f, e.cap));
					if(d>0) {
						e.cap -= d;
						G.get(e.to).get(e.rev).cap += d;
						return d;
					}
				}
			}
			return 0;
		}
		
		int getMaxFlow(int s, int t) {
			int flow = 0;
			while(true) {
				bfs(s);
				if(level[t]<0)
					return flow;
				
				Arrays.fill(iter, 0);
				int f;
				while((f = dfs(s, t, INF)) > 0) {
					flow += f;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		
		boolean[][] leaf = new boolean[H][W];
		int sx=0,sy=0,tx=0,ty=0;
		for(int i=0; i<H; i++) {
			char[] c = sc.next().toCharArray();
			for(int j=0; j<W; j++) {
				if(c[j]!='.') {
					leaf[i][j] = true;
					if(c[j]=='S') {
						sy = i;
						sx = j;
					} else if(c[j]=='T') {
						ty = i;
						tx = j;
					}
				}
			}
		}
		if(sx==tx || sy==ty) {
			System.out.println(-1);
			sc.close();
			return;
		}
		
		MaxFlow mf = new MaxFlow(H*W*2);
		
		for(int i=0; i<H; i++) {
			ArrayList<Integer> list = new ArrayList<>();
			for(int j=0; j<W; j++)
				if(leaf[i][j])
					list.add(j);
			for(int j : list)
				for(int k : list)
					if(j!=k)
						mf.addEdge((i*W+j)*2+1, (i*W+k)*2, 1);
		}
		for(int i=0; i<W; i++) {
			ArrayList<Integer> list = new ArrayList<>();
			for(int j=0; j<H; j++)
				if(leaf[j][i])
					list.add(j);
			for(int j : list)
				for(int k : list)
					if(j!=k)
						mf.addEdge((j*W+i)*2+1, (k*W+i)*2, 1);
		}
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++)
				if(leaf[i][j])
					mf.addEdge((i*W+j)*2, (i*W+j)*2+1, 1);
		}
		
		System.out.println(mf.getMaxFlow((sy*W+sx)*2+1, (ty*W+tx)*2));
		sc.close();
	}
}