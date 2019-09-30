import java.util.*;

public class Main { 
     
        public static class UnionFind{
            
               int parent[];
               int rank[];
            
               public UnionFind(int n){
                   parent = new int[n];
                   rank   = new int[n];
                   for(int i = 0 ;i < n;i++){
                         parent[i] = i;
                           rank[i] = 1;
                   }                   
               }
            
               int find(int x){
                   if(parent[x] == x)
                        return x;
                   return parent[x] = find(parent[x]);
               }
                              
               boolean same(int x,int y){
                   return find(x) == find(y);
               }
               
               void union(int x,int y){
                    x = find(x);
                    y = find(y);
                    
                    if(x != y){
                            if(rank[x] > rank[y]){
                                parent[y] = x;
                            }else{
                                parent[x] = y; 
                                if(rank[x] == rank[y]){
                                      rank[y]++;
                                }
                            }                               
                    }
                   
                    return;
               }   
        }
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);                                     
            
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            int S = sc.nextInt() - 1;                                                            
            
            ArrayList<Integer> [] g = new ArrayList[N];
            for(int i = 0 ;i < N;i++)
                    g[i] = new ArrayList<Integer>();

            for(int i = 1;i <= M;i++){
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;                
                g[a].add(b);
                g[b].add(a);
            }            
            
            UnionFind uft = new UnionFind(N);            
            ArrayList<Integer> ans = new ArrayList<Integer>();
                    
            for(int u = N - 1; u>=0;u--){                                                
               for(int j:g[u])
                    if(j > u)
                       uft.union(u,j);
               
               if(uft.same(u,S)){
                        ans.add(u+1);
               }               
            }
            
            for(int i = ans.size() - 1;i >= 0;i--){
               System.out.println(ans.get(i));
            }            
            
        }                                                             
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.