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
		public int countPath() {
			int ans = 0;
			for(ArrayList<Edge> node : G) {
				ans += node.size()%2;
			}
			return ans/2;
		}
		
		public boolean check(int B) {
			if(G.get(root).size()%2==0)
				return dp(root, B)==0;
			else
				return dp(root, B)<=B;
		}
		
		int dp(int cur, int B) {
			ArrayList<Integer> dp = new ArrayList<>();
			for(int i=0; i<G.get(cur).size(); i++) {
				int next = G.get(cur).get(i).to;
				if(next!=p[cur]) {
					dp.add(dp(next, B)+1);
				}
			}
			Collections.sort(dp);
			if(dp.size()>0 && dp.get(dp.size()-1)>B)
				return B+1;

			if(dp.size()%2==0) {
				if(validatePairing(dp, B, -1)) {
					return 0;
				} else {
					dp.remove(dp.size()-1);
					return leaveShortestPath(dp, B);
				}
			} else {
				return leaveShortestPath(dp, B);
			}
		}
		
		int leaveShortestPath(ArrayList<Integer> v, int B) {
			int N = v.size();
			int min = -1;
			int max = N;
			while(min+1<max) {
				int skip = (min+max)/2;
				if(validatePairing(v, B, skip))
					max = skip;
				else
					min = skip;
			}
			if(max<N)
				return v.get(max);
			else
				return B+1;
		}
		
		boolean validatePairing(ArrayList<Integer> v, int B, int skip) {
			for(int i=0,j=v.size()-1; i<j; i++,j--) {
				if(i==skip)
					i++;
				if(j==skip)
					j--;
				if(v.get(i) + v.get(j) > B)
					return false;
			}
			
			return true;
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
		Tree tree = new Tree(a, b);
		
		int A = tree.countPath();
		int min = 0;
		int max = N-1;
		while(min+1 < max) {
			int mid = (min+max)/2;
			if(tree.check(mid))
				max = mid;
			else
				min = mid;
		}
		
		System.out.println(A + " " + max);
		sc.close();
	}
}