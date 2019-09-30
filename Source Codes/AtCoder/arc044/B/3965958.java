import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        long ans = help(a);
        System.out.println(ans);
    }
    static long help(int[] a){
        if(a[0]!=0) return 0;
        int maxDist = 0;
        for(int w:a) maxDist = Math.max(maxDist,w);
        int[] rec = new int[maxDist+1];
        for(int w:a) rec[w]++;
        if(rec[0]!=1) return 0;
        for(int i=1;i<=maxDist;i++){
            if(rec[i]<1) return 0;
        }
        long[] dp = new long[maxDist+1];
        dp[0]=1;
        for(int i=1;i<=maxDist;i++){
            long base = power(2,rec[i-1])-1;
            dp[i] = power(base,rec[i])*dp[i-1]%mod;
            // in the same depth there can be arbitrary number of connection
            long sameLayer = ((long) rec[i])*((long) rec[i]-1)/2;
            dp[i] = dp[i]*power(2,sameLayer)%mod;
        }
        return dp[maxDist];
    }
    static long power(long base, long p){
        long ans = 1;
        while(p>0){
            if(p%2==1) ans = ans*base%mod;
            base = base*base%mod;
            p /= 2;
        }
        return ans;
    }
}