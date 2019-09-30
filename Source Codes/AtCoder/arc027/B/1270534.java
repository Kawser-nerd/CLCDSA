import java.util.*;

public class Main {
    public static void main(String[] args) {    	                 
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        String S1 = sc.next();
        String S2 = sc.next();
        
        char [] s1 = S1.toCharArray();
        char [] s2 = S2.toCharArray();                
           
        UnionFind uf = new UnionFind(10 + 'Z' - 'A' + 1);
        
        int count[] = new int['Z' - 'A' + 1];
        
        for(int i = 0;i < N;i++){
            if(s1[i] >= 'A' && s1[i] <= 'Z' && count[s1[i] - 'A'] == 0){
                count[s1[i] - 'A'] = 10 - (i == 0 ? 1: 0);
            }            
            if(s2[i] >= 'A' && s2[i] <= 'Z' && count[s2[i] - 'A'] == 0){
                count[s2[i] - 'A'] = 10 - (i == 0 ? 1: 0);
            }
            
            int i1,i2;
            if(s1[i] >= '0' && s1[i] <= '9'){
                 i1 = s1[i] - '0';
            }else{
                 i1 = s1[i] - 'A' + 10;
            }            
            if(s2[i] >= '0' && s2[i] <= '9'){
                 i2 = s2[i] - '0';
            }else{
                 i2 = s2[i] - 'A' + 10;
            }            
            
            uf.union(i1,i2);
        }
                
        for(int i = 0;i < 10;i++){            
            for(int j = 10;j <= 10 + 'Z' - 'A';j++){
                if(uf.same(i,j)){
                   count[j - 10] = 1;
                }                                   
            }            
        }
                            
        long ret = 1;
        for(int i = 10;i <= 'Z' - 'A' + 10;i++){
            if(count[i-10] != 0){
                   boolean flag = true;
                   for(int j = 10;j < i;j++){
                          if(uf.same(i,j)){
                              flag = false;
                          }                       
                   }                   
                   if(flag){
                        ret *= count[i-10];
                   }                   
            }
        }        
        
        System.out.println(ret);
        
    }                
       
    private static class UnionFind{
    
    int parent[];
    int   rank[];
    
    UnionFind(int n){
        parent    = new int[n];  
          rank    = new int[n];
      for(int i =0;i < n;i++){        
        parent[i] = i; 
          rank[i] = 0;
      }
    }
    
    int find(int x){
       if(parent[x] == x)
         return x;              
       else
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

        
}