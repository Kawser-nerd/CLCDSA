import java.util.*;

public class Main{    
    
        static int INF = Integer.MAX_VALUE/2;
            
	public static void main(String[] args) {
		
            Scanner sc = new Scanner(System.in);
            
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            int[][] g = new int[N][N];
            
            for(int i = 0;i < N;i++){
                for(int j = 0;j < N;j++){
                     g[i][j] = INF;   
                     g[i][i] = 0;
                }                
            }
            
            for(int i = 0;i < M;i++){
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                int c = sc.nextInt();
                g[a][b] = Math.min(g[a][b],c);
                g[b][a] = Math.min(g[b][a],c);
            }
            
            for(int k = 0;k < N;k++)
                for(int i = 0;i < N;i++)
                   for(int j = 0;j < N;j++)    
                       g[i][j] = Math.min(g[i][j],g[i][k] + g[k][j]);
                
            int K = sc.nextInt();
            
            for(int a = 0;a < K;a++){
                
                int x = sc.nextInt() - 1;
                int y = sc.nextInt() - 1;                
                int z = sc.nextInt();
                
                g[x][y] = Math.min(g[x][y],z);
                g[y][x] = Math.min(g[y][x],z);
                
                long s = 0;
                
                for(int i = 0;i < N;i++){
                    for(int j = 0 ;j < N;j++){
                        g[i][j] = Math.min(g[i][j],g[i][x] + g[x][y] + g[y][j]);   
                        g[i][j] = Math.min(g[i][j],g[i][y] + g[y][x] + g[x][j]);                           
                        if(i < j) s += g[i][j];
                    }                                        
                }   
                
                System.out.println(s);
                
            }
            
	}                
}