import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);                                      
     
     int N = sc.nextInt();
     int M = sc.nextInt();     
     
     UnionFind utf = new UnionFind(N);

     for(int i = 0;i < M;i++){
        int a = sc.nextInt() - 1;
        int b = sc.nextInt() - 1;
        utf.union(a,b);
     }
     
     System.out.println(utf.count(N) - 1);
                     
  }  
  
  public static class UnionFind{  
    int parent[];
    int rank[];
    
    public UnionFind(int n){
        parent = new int[n];
        rank   = new int[n];
        
        for(int i = 0;i < n;i++){
            parent[i] = i;
            rank[i]   = 0;
        }        
    }
    
    boolean same(int x,int y){
        return find(x) == find(y);
    }
    
    public int find(int x){
        if(parent[x] == x){
           return x;
        }else{
           return parent[x] = find(parent[x]);   
        }        
    }
      
    public void union(int x,int y){
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
    
    public int count(int n){
        int ret = 0;
        for(int i = 0;i < n;i++){
            if(i == find(i)){
                ret++;
            }
        }
        return ret;
    }
      
  }    
}