import java.util.*;

public class Main{              
    
    static ArrayList<Edge> edges[];    
    static int d[];        
    static int max;
    static int maxt;
    
    public static void main(String[] args){
       
       Scanner sc = new Scanner(System.in);
       
       int N = sc.nextInt();
       edges = new ArrayList[N];       
       
       for(int i = 0;i < N;i++)
          edges[i] = new ArrayList<Edge>();
       
       for(int i = 0;i < N - 1;i++){
           int a = sc.nextInt() - 1;
           int b = sc.nextInt() - 1;
           
           edges[a].add(new Edge(b,1));
           edges[b].add(new Edge(a,1));           
       }       
       
       int s = 0;
       d = new int[N];
       Arrays.fill(d,-1);
       d[s] = 0;
       max = 0;
       maxt = -1;
       dfs(s);
       
       s = maxt;
       d = new int[N];
       Arrays.fill(d,-1);
       d[s] = 0;
       max = 0;
       maxt = -1;
       dfs(s);       
       
       System.out.printf("%d %d%n",s + 1,maxt + 1);       
                                   
  }    
    
  private static void dfs(int i){
      
      for(Edge e: edges[i]){
          if(d[e.v] == -1){
              d[e.v] = d[i] + e.w;
              if(d[e.v] > max){
                  max = d[e.v];
                  maxt = e.v;
              }                                          
              dfs(e.v);              
          }
      }                              
      
      return;
  }
    
  private static class Edge {
    int u; // from
    int v; // to
    int w; // cost
		
    Edge(int v, int w) {
          this.u = u;
          this.v = v;
	  this.w = w;
    }               
  }             
  
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.