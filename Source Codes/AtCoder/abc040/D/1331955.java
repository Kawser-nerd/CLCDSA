import java.util.*;

public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        
      PriorityQueue<Edge> edges = new PriorityQueue<>();
      for (int i = 0; i < M; i++) {
        int a = sc.nextInt() - 1;
        int b = sc.nextInt() - 1;
        int y = sc.nextInt();
        edges.add(new Edge(a, b, y));
      }

      int Q = sc.nextInt();
      PriorityQueue<Edge> queries = new PriorityQueue<>();
      for (int i = 0; i < Q; i++) {
        int v = sc.nextInt() - 1;
        int y = sc.nextInt();
        queries.add(new Edge(i, v, y));
      }

      UnionFind unionFind = new UnionFind(N);
      
      int[] ans = new int[Q];
      
      while (!queries.isEmpty()) {
        Edge query = queries.poll();
        while (!edges.isEmpty() && edges.peek().year > query.year) {
          Edge edge = edges.poll();
          unionFind.unite(edge.to, edge.from);
        }

        ans[query.from] = unionFind.size(query.to);
      }
      for (int a : ans) System.out.println(a);                                
        
    }
    
     static class UnionFind {
    // par[i]????i???????????i == par[i]???????i??????????
    int[] par;
    // sizes[i]?????i?????????????i???????????????????
    int[] sizes;

    UnionFind(int n) {
      par = new int[n];
      sizes = new int[n];
      Arrays.fill(sizes, 1);
      // ?????????i?????i?????????????
      for (int i = 0; i < n; i++) par[i] = i;
    }

    // ???x??????????
    int find(int x) {
      if (x == par[x]) return x;
      return par[x] = find(par[x]);  // ????????????????????
    }

    // 2?????x, y???????????
    void unite(int x, int y) {
      // ???????????
      x = find(x);
      y = find(y);

      // ???????????????????
      if (x == y) return;

      // x???y??????????????
      if (sizes[x] < sizes[y]) {
        int tx = x;
        x = y;
        y = tx;
      }

      // x?y????????????
      par[y] = x;
      sizes[x] += sizes[y];
      // sizes[y] = 0;  // sizes[y]???????????0??????????
    }

    // 2?????x, y??????????true???
    boolean same(int x, int y) {
      return find(x) == find(y);
    }

    // ???x?????????????
    int size(int x) {
      return sizes[find(x)];
    }
  }

     
  static class Edge implements Comparable<Edge> {
    int from, to, year;
    
    Edge(int from, int to, int year) {
      this.from = from;
      this.to = to;
      this.year = year;
    }
    @Override
    public int compareTo(Edge o) {
      return o.year - this.year;
    }
    
  }   
    
}