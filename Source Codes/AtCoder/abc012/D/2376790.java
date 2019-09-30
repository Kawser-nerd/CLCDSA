import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        final int INF = 1_000_000_000;
        
        int[][] d = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    d[i][j] = INF;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int t = sc.nextInt();
            d[a-1][b-1] = t;
            d[b-1][a-1] = t;
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(d[i][j] > d[i][k] + d[k][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        
        int ans = INF;
        for(int i=0; i<n; i++){
            int max = 0;
            for(int j=0; j<n; j++){
                max = Math.max(max, d[i][j]);
            }
            ans = Math.min(ans, max);
        }
        
        System.out.println(ans);
    }
}