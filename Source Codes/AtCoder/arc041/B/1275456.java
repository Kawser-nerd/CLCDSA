import java.util.*;

public class Main {

        
    public static void main(String[] args) {    	                 
            Scanner  sc = new Scanner(System.in);        
            
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            int a[][] = new int[N][M];
            
            for(int i = 0;i < N;i++){
                String s = sc.next();
                for(int j = 0;j < M;j++){
                    a[i][j] = Integer.valueOf(s.substring(j,j+1));   
                }                
            }
             
            int ret[][] = new int[N][M];
            
            for(int i = 1;i< N - 1;i++){
                for(int j = 1 ;j < M - 1;j++){
                    int min = 10;
                    min = Math.min(a[i][j-1],min);
                    min = Math.min(a[i][j+1],min);
                    min = Math.min(a[i+1][j],min);
                    min = Math.min(a[i-1][j],min);
                    a[i][j-1] -= min;
                    a[i][j+1] -= min;
                    a[i+1][j] -= min;
                    a[i-1][j] -= min;
                    ret[i][j] = min;
                }                
            }
            
            for(int i = 0;i < N;i++){
                for(int j = 0;j < M;j++){
                    System.out.print(ret[i][j]);
                }                
                System.out.println();
            }
            
            
    }    
}