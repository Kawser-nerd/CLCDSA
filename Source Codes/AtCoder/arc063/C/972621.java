import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

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
		int[] min;
		int[] max;
		int[] evenOdd;

		public Tree(int[] a, int[] b) {
			this.V = a.length+1;
			p = new int[V];
			min = new int[V];
			max = new int[V];
			evenOdd = new int[V];

			Arrays.fill(min, -10000000);
			Arrays.fill(max, 10000000);

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
		public boolean check() {
			if(!check(0))
				return false;
			setRecursive(0, min[0], min[0]);
			return true;
		}
		public void set(int i, int v) {
			min[i] = max[i] = v;
			evenOdd[i] = v%2==0 ? 2 : 1;
		}

		boolean check(int i) {
			boolean[] eo = new boolean[3];
			for(Edge e : G.get(i)) {
				if(e.to==p[i])
					continue;
				if(!check(e.to))
					return false;
				min[i] = Math.max(min[i], min[e.to]-1);
				max[i] = Math.min(max[i], max[e.to]+1);
				eo[evenOdd[e.to]] = true;
			}
			if(evenOdd[i]!=0)
				eo[3-evenOdd[i]] = true;
			if(eo[1] && eo[2])
				return false;
			evenOdd[i] = eo[1] ? 2 : (eo[2] ? 1 : 0);
			return min[i]<=max[i];
		}
		void setRecursive(int i, int x1, int x2) {
			if(min[i]<=x1 && x1<=max[i])
				min[i] = max[i] = x1;
			else
				min[i] = max[i] = x2;

			for(Edge e : G.get(i)) {
				if(e.to==p[i])
					continue;
				setRecursive(e.to, min[i]-1, min[i]+1);
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int N = sc.nextInt();

		int[] a = new int[N-1];
		int[] b = new int[N-1];
		for(int i=0; i<N-1; i++) {
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
		}

		Tree tree = new Tree(a, b);

		int K = sc.nextInt();
		for(int i=0; i<K; i++) {
			int V = sc.nextInt()-1;
			int P = sc.nextInt();
			tree.set(V, P);
		}

		if(tree.check()) {
			pw.println("Yes");
			for(int i=0; i<N; i++)
				pw.println(tree.min[i]);
		} else {
			pw.println("No");
		}

		sc.close();
		pw.close();
	}

}