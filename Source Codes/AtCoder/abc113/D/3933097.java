import java.util.Scanner;

public class Main {

    static int MOD = 1_000_000_007;
    static int H;
    static int W;
    static int K;
    static int[] fib = {1, 1, 2, 3, 5, 8, 13, 21, 34};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        K = sc.nextInt();
        sc.close();
        // dp[i][j]???????????????????? mod 1000000007
        long[][] dp = new long[H+1][W+1];
        dp[0][1] = 1L;
        if(W == 1){
            System.out.println(1);
        }else{
            for(int i = 1; i <= H; i++){
                for(int j = 1; j <= W; j++){
                    if(j == 1) dp[i][j] = (dp[i-1][2] * fib[W-2] + dp[i-1][1] * fib[W-1])% MOD;
                    else if(j == W) dp[i][j] = (dp[i-1][W-1] * fib[W-2] + dp[i-1][W] * fib[W-1])% MOD;
                    else dp[i][j] = (dp[i-1][j-1] * fib[j-2] * fib[W-j] + dp[i-1][j+1] * fib[j-1] * fib[W-(j+1)] + dp[i-1][j] * fib[j-1] * fib[W-j])% MOD;
                }
            }
            System.out.println(dp[H][K]);
        }
    }

}