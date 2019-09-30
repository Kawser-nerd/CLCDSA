import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[] f = new int[n+2];
        for(int i=2;i<=n+1;i++) f[i]=sc.nextInt();
        long[] dp = new long[n+2], sum = new long[n+2];
        sum[1]=dp[1]=dp[2]=1;
        sum[2]=2;
        int start = 2;
        HashSet<Integer> vis = new HashSet<>();
        vis.add(f[2]);
        for(int end=3;end<=n+1;end++){
            if(vis.add(f[end])){
                dp[end] = (sum[end-1]-sum[start-2]+mod)%mod;
            } else{
                while(start<end&&f[start]!=f[end]) vis.remove(f[start++]);
                if(start+1==end) dp[end]=dp[start++];
                else{
                    dp[end] = (sum[end-1]-sum[start-1]+mod)%mod;
                    start++;
                }
            }
            sum[end] = (sum[end-1]+dp[end])%mod;
        }
        System.out.println(dp[n+1]);
    }
}