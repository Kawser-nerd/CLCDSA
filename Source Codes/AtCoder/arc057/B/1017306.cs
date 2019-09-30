using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        long K = long.Parse(str[1]);
        long[] a = new long[N];
        long[] sum = new long[N];
        int count = N;
        for(int i=0;i<N;i++){
            a[i] = int.Parse(Console.ReadLine());
            sum[i] = i == 0 ? a[i] : sum[i-1] + a[i];
        }
        if(sum[N-1] == K){
            count = 1;
        }
        else{
            long[,] dp = new long[N+1,N+1];
            dp[0,0] = 0;
            dp[1,0] = 0;
            dp[1,1] = 1;
            for(int i=2;i<N+1;i++){
                dp[i,0] = 0;
                for(int j=1;j<i;j++){
                    long r = dp[i-1,j-1]*a[i-1]/sum[i-2]+1;
                    dp[i,j] = dp[i-1,j] > dp[i-1,j-1] + r ? dp[i-1,j-1] + r : dp[i-1,j];
                }
                dp[i,i] = dp[i-1,i-1] + dp[i-1,i-1] * a[i-1] / sum[i-2] + 1;
            }
            for(int i=0;i<N+1;i++){
                if(dp[N,i] > K){
                    count = i-1;
                    break;
                }
            }
        }
        sb.Append(count+"\n");
    }
}