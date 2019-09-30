import java.util.*;

public class Main{
    
    static int n,k;
    static double[][][] dp;

    public static void main(String[] args){
           
        Scanner sc = new Scanner(System.in);
      
        n = sc.nextInt();
        k = sc.nextInt();
        
        dp = new double[n + 1][k + 2][2];
        for (int i = 0; i < k + 1; i++) {
            dp[n][i][1] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < k + 1; j++) {
                for (int l = 0; l < 2; l++) {
                    double p = 1.0 / (i + 1);
                    double r = (1.0 - p) * dp[i + 1][j][l]
                            + p * Math.max(dp[i + 1][j + 1][1], dp[i + 1][j][0]);
                    dp[i][j][l] = r;
                }
            }
        }
        
        System.out.println(dp[0][0][0]);              
       
    }        
}