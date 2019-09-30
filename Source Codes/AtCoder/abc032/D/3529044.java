import java.util.*;

public class Main {
    static int N;
    static long W;
    static long[] a;
    static long[] b;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        W = sc.nextLong();
        a = new long[N];
        b = new long[N];
        long maxA = 0;
        long maxB = 0;
        for(int i=0; i<N; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            maxA = Math.max(a[i], maxA);
            maxB = Math.max(b[i], maxB);
        }
        sc.close();
        long ans = 0;
        if(N<=30){
            ans = dfs(0,W);
        }else if(maxA<=1000){
            ans = solve1();
        }else{
            ans = solve2();
        }
        System.out.println(ans);
    }

    static Map<String,Long> dp = new HashMap<>();
    static long dfs(int n, long w) {
        if (dp.get(getKey(n,w))!=null) {
            return dp.get(getKey(n,w));
        }
        long res;
        if (n==N) {
            res=0;
        }else if(w<b[n]) {
            res = dfs(n+1, w);
        }else{
            res = Math.max( dfs(n+1, w), dfs(n+1, w-b[n])+a[n]);
        }
        dp.put(getKey(n,w), res);
        return res;
    }

    static String getKey(int n, long w){
        return String.format("%d.%d", n,w);
    }

    private static long solve1() {

        int max = N*1000;
        long[] dp = new long[max+1];
        dp[0] = 0;
        for(int i=1; i<=max; i++) dp[i] = Long.MAX_VALUE/2;
        for(int i=0; i<N; i++){
            for(int j=max; j>=a[i]; j--){
                dp[j] = Math.min(dp[j], dp[(int)(j-a[i])]+b[i]);
            }
        }
        for(int i=max; i>=0; i--){
            if(dp[i]<=W)
                return i;
        }
        return 0;
    }

    private static long solve2() throws Exception {
        int max = N*1000;
        long[] dp = new long[max+1];
        for(int i=0; i<N; i++){
            for(int j=max; j>=b[i]; j--){
                dp[j] = Math.max(dp[j], dp[(int)(j-b[i])]+a[i]);
            }
        }
        return dp[(int)W];
    }

}