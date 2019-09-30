import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static long mod = 1000000000+7;
    static long[] rest;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt(), W = sc.nextInt(), K = sc.nextInt();
        rest = legalDistribution();
        long ans = help(H,W,K);
        System.out.println(ans);
    }
    static long help(int H, int W, int K){
        if(W==1) return 1;
        long[][] dp = new long[H+2][W];
        dp[0][0] = 1;dp[1][0] = 1;
        for(int row=2;row<=H+1;row++){
            dp[row][0] = (dp[row-1][0]*getRest(W-2)%mod+dp[row-1][1]*getRest(W-3)%mod)%mod;
            for(int col=1;col<W-1;col++){
                dp[row][col] = dp[row-1][col]*getRest(col-1)%mod*getRest(W-col-2)%mod;
                dp[row][col] = (dp[row][col]+dp[row-1][col-1]*getRest(col-2)%mod*getRest(W-col-2)%mod)%mod;
                dp[row][col] = (dp[row][col]+dp[row-1][col+1]*getRest(col-1)%mod*getRest(W-col-3)%mod)%mod;
            }
            dp[row][W-1] = (dp[row-1][W-1]*getRest(W-2)%mod+dp[row-1][W-2]*getRest(W-3)%mod)%mod;
        }
        return dp[H+1][K-1];
    }
    static long getRest(int x){
        if(x<=0) return 1;
        return rest[x];
    }
    static long[] legalDistribution(){
        long[] ans = new long[9];
        ans[0]=1;
        ans[1]=2;
        for(int i=2;i<9;i++) ans[i] = (ans[i-1]+ans[i-2])%mod;
        return ans;
    }
}