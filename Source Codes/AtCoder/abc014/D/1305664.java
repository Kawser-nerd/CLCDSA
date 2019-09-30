import java.util.*;


public class Main {	   
        
        void solve(Scanner sc){
             int N = sc.nextInt();
      ArrayList<ArrayList<Integer>> adj = new ArrayList<>(N);
      for (int i = 0; i < N; i++) adj.add(new ArrayList<Integer>());
      for (int i = 0; i < N - 1; i++) {
        int x = sc.nextInt() - 1;
        int y = sc.nextInt() - 1;
        adj.get(x).add(y);
        adj.get(y).add(x);
      }

      LCA lca = new LCA(adj);
      int Q = sc.nextInt();
      for (; Q > 0; Q--) {
        int x = sc.nextInt() - 1;
        int y = sc.nextInt() - 1;
        System.out.println(lca.getLength(x, y) + 1);
      }
        }
        
        static class LCA {
    ArrayList<ArrayList<Integer>> G;
    int[][] parent;
    int[] depth;
    int root, logV;

    void dfs(int v, int p, int d) {
      parent[0][v] = p;
      depth[v] = d;
      for (int u : G.get(v)) if (u != p) dfs(u, v, d + 1);
    }

    LCA(final ArrayList<ArrayList<Integer>> adj) {
      int V = adj.size();
      root = 0;
      G = adj;
      depth = new int[V];

      logV = 1;
      for (int i = 1; i <= V; ) {
        i *= 2;
        logV++;
      }
      parent = new int[logV][V];

      dfs(root, -1, 0);

      for (int k = 0; k + 1 < logV; ++k)
        for (int v = 0; v < V; ++v)
          if (parent[k][v] < 0) {
            parent[k + 1][v] = -1;
          } else {
            parent[k + 1][v] = parent[k][parent[k][v]];
          }
    }

    int getLCA(int u, int v) {
      if (depth[u] > depth[v]) {
        int tu = u;
        u = v;
        v = tu;
      }
      for (int k = 0; k < logV; ++k) if (((depth[v] - depth[u]) >> k & 1) != 0) v = parent[k][v];
      if (u == v) return u;
      for (int k = logV - 1; k >= 0; --k)
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
    
	public static void main(String[] args){
	          Scanner sc = new Scanner(System.in);
                  new Main().solve(sc);
	}
}