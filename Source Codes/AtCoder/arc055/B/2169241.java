import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        double[][] dp = new double[1001][1001];
        
        for(int r=n-1; r>0; r--){
            dp[r][0] = dp[r+1][0];
            for(int s=1; s<=k; s++){
                dp[r][s] = dp[r+1][s] + Math.max(1.0/n + dp[r+1][s-1], dp[r+1][s]) / r;
            }
        }
        
        System.out.println(Math.max(1.0/n + dp[1][k-1], dp[1][k]));
    }
}