import java.util.*;
class Main
{
    static int mod = 1000000007;
    static int h, w, k;
    static int[] p;
    static long[][] dp;
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        h = sc.nextInt();
        w = sc.nextInt();
        k = sc.nextInt();
        p = new int[w + 2];
        p[0] = 1; p[1] = 1;
        for(int i = 2; i < w + 2; i++){
            p[i] = p[i-1] + p[i-2];
        }
        dp = new long[h+1][w+1];
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                dp[i][j] = calc(i, j);
            }
        }
        System.out.println(dp[h][k]);
    }
    public static long calc(int height, int width){
        if(height == 1 && width == 1) return p[w - 1];
        else if(height == 1 && width == 2) return p[w-2];
        else if(height + 1< width) return 0;
        else{
            long res = 0;
            res += dp[height - 1][width] * p[width - 1] * p[w - width];
            res %= mod;
            if(width > 1){
                res += dp[height - 1][width - 1] * p[width - 2] * p[w - width];
                res %= mod;
            }
            if(width < w){
                res += dp[height - 1][width + 1] * p[width - 1] * p[w - 1 - width];
                res %= mod;
            }
            return res;
        }
    }
}