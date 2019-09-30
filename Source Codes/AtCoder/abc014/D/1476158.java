import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * http://abc014.contest.atcoder.jp/tasks/abc014_4
 * LCA
 */
public class Main {
	
	static class LCA {
		final int N;
		int logN;
		final int ROOT;
		int[] depth;
		int[][] parent;
		
		Map<Integer,Set<Integer>> edge = new HashMap<>();
	
		LCA(final Map<Integer,Set<Integer>> edge, final int root){
			this.edge = edge;
			ROOT = root;
			N = this.edge.size();
			logN = 1;
			for (int i=1; i<=N; i*=2) logN++;
			depth = new int[N];
			parent = new int[logN][N];
			
			dfs(ROOT, -1, 0);
			
			for (int k = 0; k + 1 < logN; ++k){
				for (int v = 0; v < N; ++v){
					if (parent[k][v] < 0) {
						parent[k + 1][v] = -1;
					}else{
						parent[k + 1][v] = parent[k][parent[k][v]];
					}
				}
			}

			
		}
		
		void dfs(int current, int p, int d){
		    parent[0][current] = p;
		    depth[current] = d;
		    for (int c: edge.get(current)) if (c!=p) dfs(c, current, d + 1);
		}
		
		int getLCA(int u, int v) {
			if (depth[u] > depth[v]) {
				int tu = u;
				u = v;
				v = tu;
			}
			for (int k = 0; k < logN; ++k) if (((depth[v] - depth[u]) >> k & 1) != 0) v = parent[k][v];
			if (u == v) return u;
			for (int k = logN - 1; k >= 0; --k)
				if (parent[k][u] != parent[k][v]) {
					u = parent[k][u];
					v = parent[k][v];
				}
			return parent[0][u];
		}
		
		int getLength(int u, int v) {
			int lca = getLCA(u, v);
			return depth[u] + depth[v] - depth[lca] * 2;
		}
	
	}
	


	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Map<Integer,Set<Integer>> e = new HashMap<>();
		for(int i=0; i<N; i++) e.put(i, new HashSet<Integer>());
		for(int i=0; i<N-1; i++){
			int x = sc.nextInt()-1;
			int y = sc.nextInt()-1;
			e.get(x).add(y);
			e.get(y).add(x);
		}
		final int Q = sc.nextInt();
		int[] a = new int[Q];
		int[] b = new int[Q];
		for(int i=0; i<Q; i++){
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
		}
		sc.close();
		
		LCA lca = new LCA(e,0);
		
		for(int i=0; i<Q; i++){
			System.out.println(lca.getLength(a[i],b[i])+1);
		}

	}

}