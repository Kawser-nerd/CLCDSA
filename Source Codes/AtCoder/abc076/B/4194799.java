import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        
        int[] dp = new int[N+1];
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
        	dp[i] = Math.min(dp[i-1] * 2, dp[i-1]+K);
        }
        
        System.out.println(dp[N]);
    }
}