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
		int[] path;
		int[] A;
		
		public Tree(int[] a, int[] b, int[] A) {
			this.V = a.length+1;
			p = new int[V];
			path = new int[V];
			this.A = A;
			
			G = new ArrayList<ArrayList<Edge>>();
			for(int i=0; i<V; i++) {
				G.add(new ArrayList<Edge>());
			}
			
			for(int i=0; i<V-1; i++) {
				G.get(a[i]).add(new Edge(b[i], G.get(b[i]).size()));
				G.get(b[i]).add(new Edge(a[i], G.get(a[i]).size()-1));
			}
			int root = 0;
			for(int i=0; i<V; i++)
				if(G.get(i).size()>1) {
					root=i;
					break;
				}
			setRoot(root);
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
		
		public boolean check(int cur) {
			if(G.get(cur).size()==1) {
				path[cur] = A[cur];
				return true;
			}

			long sum = 0;
			long max = -1;
			for(int i=0; i<G.get(cur).size(); i++) {
				int next = G.get(cur).get(i).to;
				if(next!=p[cur]) {
					if(!check(next))
						return false;
					sum += path[next];
					max = Math.max(max, path[next]);
				}
			}
			long maxPair = Math.min(sum/2, sum-max);
			if(sum<A[cur] || A[cur]<sum-maxPair)
				return false;
			
			path[cur] = A[cur] - (int)Math.max(0, sum-A[cur]);
			return true;
		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt();
		int[] a = new int[N-1];
		int[] b = new int[N-1];
		for(int i=0; i<N-1; i++) {
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
		}
		if(N==2) {
			System.out.println(A[0]==A[1] ? "YES" : "NO");
		} else {
			Tree tree = new Tree(a, b, A);
			System.out.println(tree.check(tree.root) && tree.path[tree.root]==0 ? "YES" : "NO");
		}
		sc.close();
	}
}