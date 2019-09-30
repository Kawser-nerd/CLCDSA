import java.util.*;

public class Main {
    
    static int res = 0;
    static ArrayList<Integer>[] g;    
    
    static boolean dfs(int u,int par,int[] h){
        boolean exist = (h[u] == 1);
        
        for(int v : g[u]){
            if(v == par)continue;
            boolean child = dfs(v,u,h);
            if(child) res+= 2;
            exist |= child;
        }        
        return exist;
    }
    
    public static void main(String[] args) {    	                 
        Scanner  sc = new Scanner(System.in);                            
        
        int N =sc.nextInt();
        int k = sc.nextInt() - 1;

        int h[] = new int[N];
                
        for(int i = 0;i < N;i++){
            h[i] = sc.nextInt();
        }
        
        g = new ArrayList[N];
        
        for(int i = 0;i <N;i++)
            g[i] = new ArrayList<Integer>();
        
        for(int i = 0;i < N-1;i++){
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        
        dfs(k,-1,h);
        
        System.out.println(res);
        
    }
    
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.