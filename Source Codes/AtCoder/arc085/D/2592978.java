import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main{

    static class DP{
        int l,r, cost, useCost;
        DP(int l,int r){this.l=l;this.r=r;}
    }
    static DP[] dp;
    static int[] sum;
    static class RMQ{
        int data1[];
        int data2[];
        int N;
        RMQ(int n){
            N=1;
            while(N<n)N*=2;
            data1 = new int[2*N];
            data2 = new int[2*N];
            Arrays.fill(data1, Integer.MAX_VALUE/10);
            Arrays.fill(data2, Integer.MAX_VALUE/10);
        }
        void set1(int i, int x){
            i+=N;
            data1[i]=Math.min(data1[i], x);
            for(i=i/2;i>0;i/=2)data1[i]=Math.min(data1[2*i], data1[2*i+1]);
        }
        void set2(int i, int x){
            i+=N;
            data2[i]=Math.min(data2[i], x);
            for(i=i/2;i>0;i/=2)data2[i]=Math.min(data2[2*i], data2[2*i+1]);
        }
        //[l, r)
        int getMin1(int l, int r){return getMin(l, r, 1, 0, N, data1);}
        int getMin2(int l, int r){return getMin(l, r, 1, 0, N, data2);}
        int getMin(int l, int r, int k, int a,int b, int[] data){
            if(b<=l || r<=a)return Integer.MAX_VALUE/10;
            if(l<=a && b<=r)return data[k];
            return Math.min(getMin(l, r, 2*k, a, (a+b)/2, data), getMin(l, r, 2*k+1, (a+b)/2, b, data));
        }
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        sum = new int[N+1];
        for(int i=0;i<N;++i)sum[i+1]=sum[i]+scan.nextInt();
        int Q = scan.nextInt();
        dp = new DP[Q+1];
        dp[0] = new DP(0, 0);
        // [l, r]?1-index
        for(int i=0;i<Q;++i)dp[i+1] = new DP(scan.nextInt(), scan.nextInt());
        Arrays.sort(dp, (a,b)->a.l==b.l ? b.r-a.r : a.l-b.l);
        RMQ rmq = new RMQ(N+2);
        dp[0].useCost =0;
        rmq.set1(dp[0].r, 0);
        rmq.set2(dp[0].r, 0);
        for(int i=1;i<=Q;++i){
            // li<rk<ri
            dp[i].useCost = Math.min(dp[i].r-sum[dp[i].r] + rmq.getMin1(dp[i].l, dp[i].r), 2*sum[dp[i].l-1] + dp[i].r -(dp[i].l-1) -sum[dp[i].r] + rmq.getMin2(0, dp[i].l));
            rmq.set1(dp[i].r, dp[i].useCost -dp[i].r + sum[dp[i].r]);
            rmq.set2(dp[i].r, dp[i].useCost - sum[dp[i].r]);
        }
        // for(int i=0;i<=Q;++i)System.out.println("("+dp[i].l+", "+dp[i].r+") : "+dp[i].useCost);
        // System.out.println();
        // for(int i=0;i<=N;++i)System.out.println(i+" "+rmq.getMin1(i, i+1) + " "+rmq.getMin2(i, i+1));
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<=Q;++i)ans=Math.min(ans, dp[i].useCost + sum[N]-sum[dp[i].r]);
        System.out.println(ans);
    }
}