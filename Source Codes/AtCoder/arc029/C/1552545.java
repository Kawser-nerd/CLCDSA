import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    ArrayList<Edge> list = new ArrayList<>();
            
    int N = sc.nextInt();
    int M = sc.nextInt();
    
    for(int i = 0;i < N;i++){
        int c = sc.nextInt();
        list.add(new Edge(i,N,c));
    }    
    
    for(int i = 0;i < M;i++){
        int a = sc.nextInt() - 1;
        int b = sc.nextInt() - 1;
        int r = sc.nextInt();
        list.add(new Edge(a,b,r));
    }
    
    Collections.sort(list);
    
    UnionFind uf = new UnionFind(N+1);
    
    long ans = 0;
    
    for(int i = 0;i < list.size();i++){
        Edge e = list.get(i);
        if(!uf.isConnected(e.from,e.to)){
            uf.union(e.from,e.to);
            ans += e.cost;
        }
    }
    
    System.out.println(ans);
    
  }
  
  static class UnionFind{
      private int[] parent;
      
      UnionFind(int size){
         parent = new int[size];
         Arrays.fill(parent,-1);
      }
      
      public boolean union(int x,int y){
          x = root(x);
          y = root(y);
          if(x != y){   
            if(parent[y] < parent[x]){
               int tmp = y;                          
               y = x;
               x = tmp;
            }
            parent[x] += parent[y];
            parent[y] = x;
            return true;          
          }          
          return false;
      }
      
      public boolean isConnected(int x,int y){
          return root(x) == root(y);
      }
      
      public int root(int x){
          return parent[x] < 0 ? x : (parent[x] = root(parent[x]));
      }
      
      public int size(int x){
          return -parent[root(x)];    
      }
      
  }
  
  static class Edge implements Comparable<Edge>{
      
      int from,to;
      int cost;
      
      Edge(int from,int to,int cost){
          this.from = from;
          this.to   = to;
          this.cost = cost;
      }
      
      public int compareTo(Edge edge){
       return cost - edge.cost;   
      }            
      
  }  
  
}