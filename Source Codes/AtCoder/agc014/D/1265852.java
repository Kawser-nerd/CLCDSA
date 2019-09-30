import java.util.*;

public class Main {
	static class Tree {
		public class Edge {
			int to, rev;

			public Edge(int to, int rev) {
				this.to = to;
				this.rev = rev;
			}
		}
		
		int V;
		ArrayList<ArrayList<Edge>> G;
		int root;
		int[] p;
		
		public Tree(int[] a, int[] b) {
			this.V = a.length+1;
			p = new int[V];
			
			G = new ArrayList<ArrayList<Edge>>();
			for(int i=0; i<V; i++) {
				G.add(new ArrayList<Edge>());
			}
			
			for(int i=0; i<V-1; i++) {
				G.get(a[i]).add(new Edge(b[i], G.get(b[i]).size()));
				G.get(b[i]).add(new Edge(a[i], G.get(a[i]).size()-1));
			}
			setRoot(0);
		}
		
		public void setRoot(int root) {
			this.root = root;
			setRoot(root, -1);
		}
		public void setRoot(int cur, int parent) {
			p[cur] = parent;
			for(int i=0; i<G.get(cur).size(); i++) {
				int next = G.get(cur).get(i).to;
				if(next!=parent) {
					setRoot(next, cur);
				}
			}
		}
		
		public boolean firstWin() {
			int len = 0;
			for(int i=0; i<G.get(root).size(); i++) {
				int next = G.get(root).get(i).to;
				if(next!=p[root]) {
					int cb = branchLength(next);
					if(cb<0)
						return true;
					else
						len += cb;
				}
			}
			return len!=1;
		}
		
		int branchLength(int cur) {
			int len = 0;
			for(int i=0; i<G.get(cur).size(); i++) {
				int next = G.get(cur).get(i).to;
				if(next!=p[cur]) {
					int cb = branchLength(next);
					if(cb<0)
						return cb;
					else
						len += cb;
				}
			}
			if(len>=2)
				return -1;
			else if(len==1)
				return 0;
			else
				return 1;
		}
	}
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N-1];
		int[] b = new int[N-1];
		for(int i=0; i<N-1; i++) {
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
		}
		
		Tree tree = new Tree(a,b);
		
		System.out.println(tree.firstWin() ? "First" : "Second");
		
		sc.close();
	}
}