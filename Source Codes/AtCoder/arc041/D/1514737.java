import java.util.*;

public class Main{              
    
    public static class Edge {
		int idx;
		int to;
		boolean isRed;
		public Edge(int idx, int to, char c) {
			this.idx = idx;
			this.to = to;
			isRed = c=='r';
		}
		
	}
	public static class Node {
		ArrayList<Edge> e = new ArrayList<Edge>();
		
	}
	static Node[] node;
	static int M;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		M = sc.nextInt();

		node = new Node[N];
		for(int i=0; i<N; i++)
			node[i] = new Node();
		for(int i=0; i<M; i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			char c = sc.next().charAt(0);
			node[a].e.add(new Edge(i, b, c));
			node[b].e.add(new Edge(i, a, c));
		}
		
		color = new int[N];
		used = new boolean[M];
		for(int i=0; i<N; i++) {
			if(check(i, true) || check(i, false)) {
				System.out.println("Yes");
				return;
			}
		}
		
		System.out.println("No");
	}
	static int[] color;
	static boolean[] used;
	public static boolean check(int idx, boolean red) {
		Arrays.fill(color, 0);
		Arrays.fill(used, false);
		if(dfs(idx, red))
			return true;
		for(int i=0; i<M; i++)
			if(!used[i])
				return false;
		return true;
	}
	
	public static boolean dfs(int idx, boolean isRed) {
		if(color[idx] != 0) {
			int add = isRed ? 1 : 2;
			return color[idx] != add;
		}
		color[idx] |= isRed ? 1 : 2;
		for(int i=0; i<node[idx].e.size(); i++) {
			if(!used[node[idx].e.get(i).idx]) {
				if(node[idx].e.get(i).isRed==isRed) {
					used[node[idx].e.get(i).idx] = true;
					if(dfs(node[idx].e.get(i).to, isRed^true))
						return true;
				}
			}
		}
		return false;
	}
    
}