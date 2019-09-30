import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] D = new int[n+1];
        for(int i=1;i<=n;i++) D[i]=sc.nextInt();
        Arrays.sort(D);
        long[] dp = new long[n+1], sum = new long[n+1];
        long[] dp0 = new long[n+1], sum0 = new long[n+1]; // for back up
        Arrays.fill(dp,1);
        dp[0]=0;
        for(int i=1;i<=n;i++) sum[i]=i;
        for(int pass=2;pass<=4;pass++){
            System.arraycopy(dp,0,dp0,0,n+1);
            System.arraycopy(sum,0,sum0,0,n+1);
            Arrays.fill(dp,0);
            Arrays.fill(sum,0);
            int left=0;
            for(int i=pass;i<=n;i++){
                int target = D[i]/2+1;
                // binary search doesn't necessarily give the left-most bound (when multiple happens)
                while(left<=n&&2*D[left]<=D[i]) left++;
                dp[i] = sum0[left-1];
                sum[i] = (sum[i-1]+dp[i])%mod;
            }
        }
        System.out.println(sum[n]);
    }
}