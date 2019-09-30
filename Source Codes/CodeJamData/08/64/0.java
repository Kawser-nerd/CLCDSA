import java.io.*;
import java.util.*;
import java.math.*;
public class D {
	//static boolean[][] ok;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = sc.nextInt();
		tests: for (int t=1; t<=T; t++) {
			System.out.print("Case #"+t+": ");
			int N = sc.nextInt();
			Node[] big = new Node[N];
			for (int i=0; i<N; i++) {
				big[i] = new Node();
				big[i].ref=i;
			}
			for (int j=0; j<N-1; j++) {
				int a = sc.nextInt(), b = sc.nextInt(); a--; b--;
				big[a].adj.add(big[b]);
				big[b].adj.add(big[a]);
			}


			int M = sc.nextInt();
			Node[] small = new Node[M];
			for (int i=0; i<M; i++) {
				small[i] = new Node();
				small[i].ref=i;
			}
			for (int j=0; j<M-1; j++) {
				int a = sc.nextInt(), b = sc.nextInt(); a--; b--;
				small[a].adj.add(small[b]);
				small[b].adj.add(small[a]);
			}
			small[0].maketree(null);

			//ok = new boolean[N][M];
			for (int k=0; k<N; k++) {
				//System.out.println("Tryingt o match with big "+k);
				big[k].maketree(null);
				// do they match

				if (match(big[k],small[0])) {
					System.out.println("YES");
					continue tests;
				}
				for (int j=0; j<N; j++) if (big[j].parent!=null) big[j].adj.add(big[j].parent);
			}
			System.out.println("NO");
		}
	}
	static boolean match(Node big, Node small) {
		//System.out.println("Matching "+big.ref+" "+small.ref);
		if (small.adj.size()==0) return true;
		int numnodes = big.adj.size()+small.adj.size()+2;
		int[][] adj = new int[numnodes][numnodes];
		//System.out.println("Big size is "+big.adj.size()+" and "+small.adj.size());
		for (int i=0; i<big.adj.size(); i++)
		for (int j=0; j<small.adj.size(); j++) {
			adj[i][j+big.adj.size()] = match(big.adj.get(i),small.adj.get(j))?1:0;
			//if (adj[i][j+big.adj.size()]==1) System.out.println("Can join "+big.adj.get(i).ref+" "+small.adj.get(j).ref);
		}
		for (int i=0; i<big.adj.size(); i++) adj[numnodes-2][i]=1;
		for (int i=0; i<small.adj.size(); i++) adj[i+big.adj.size()][numnodes-1]=1;

		int ret = maxflow(adj,numnodes-2,numnodes-1,numnodes);
		//System.out.println("Max flow is "+ret);
		boolean ans = ret==small.adj.size();
		//System.out.println(big.ref+" "+small.ref+" "+ans);
		return ans;
	}

static int maxflow(int[][] adj, int first, int last, int numnodes) {
	int flow = 0;
	while (true) {
		int cap = bfs(adj,first,last,numnodes);
		if (cap==0) break;
		flow+=cap;
	}
	return flow;
}

static int bfs(int[][] adj, int first, int last, int numnodes) {
	boolean[] seen = new boolean[numnodes];
	int[] from = new int[numnodes];
	Arrays.fill(from,-1);
	LinkedList<Integer> list = new LinkedList<Integer>();
	list.add(first);
	seen[first] = true;
	loop: while (list.size()>0) {
		int where = list.remove();
		for (int i=0; i<numnodes; i++) {
			if (!seen[i] && adj[where][i]>0) {
				list.add(i);
				seen[i] = true;
				from[i] = where;
				if (i==last) break loop;
			}
		}
	}
	int where = last;
	int cap = Integer.MAX_VALUE;
	while (from[where]!=-1) {
		cap = Math.min(cap,adj[from[where]][where]);
		where = from[where];
	}
	where = last;
	while (from[where]!=-1) {
		adj[from[where]][where]-=cap;
		adj[where][from[where]]+=cap;
		where = from[where];
	}
	if (cap==Integer.MAX_VALUE) return 0;
	return cap;
}
} class Node {
	Vector<Node> adj = new Vector<Node>();
	Node parent;
	int ref;
	void maketree(Node p) {
		parent=p;
		if (p!=null) adj.remove(p);
		for (Node n : adj) {
			if (n==p) continue;
			n.maketree(this);
		}
	}
}