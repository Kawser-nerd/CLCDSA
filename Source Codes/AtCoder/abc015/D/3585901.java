import java.util.*;

public class Main {
    static long mod = 1000000000+7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        int n = sc.nextInt();
        int K = sc.nextInt();
        int[] a = new int[n+1];
        int[] b = new int[n+1];
        for(int i=1;i<=n;i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        int sumB = 0;
        for(int w:b) sumB += w;
        int[][] dp = new int[K+1][sumB+1];
        for(int i=0;i<K+1;i++) Arrays.fill(dp[i],Integer.MAX_VALUE/2);
        dp[0][0] = 0;
        for(int kind=1;kind<=n;kind++){
            for(int k=K-1;k>=0;k--){
                for(int sum=sumB;sum>=b[kind];sum--){
                    if(dp[k][sum-b[kind]]+a[kind]<=W) dp[k+1][sum] = Math.min(dp[k+1][sum],dp[k][sum-b[kind]]+a[kind]);
                }
            }
        }
        int ans = -1;
        for(int k=0;k<=K;k++){
            for(int sum=0;sum<=sumB;sum++){
                if(dp[k][sum]<=W) ans = Math.max(sum,ans);
            }
        }
        System.out.println(ans);
    }
}