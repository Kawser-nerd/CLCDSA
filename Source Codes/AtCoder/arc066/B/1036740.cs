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
        long N = long.Parse(Console.ReadLine());
        long M = N;
        long count = 0;
        long[,] dp = new long[63,3];
        dp[0,0] = 1;
        int i;
        for(i=1;i<63;i++){
            if(M <= 3){
                break;
            }
            M /= 2;
            if((N & ((long)(1) << (i - 1))) != 0){
                dp[i,0] = (2*dp[i-1,0] + dp[i-1,1]) % Define.mod;
                dp[i,1] = (dp[i-1,0] + 2*dp[i-1,1] + 2*dp[i-1,2]) % Define.mod;
                dp[i,2] = dp[i-1,2]; 
            }
            else{
                dp[i,0] = dp[i-1,0];
                dp[i,1] = (2*dp[i-1,0] + 2*dp[i-1,1] + dp[i-1,2]) % Define.mod;
                dp[i,2] = (dp[i-1,1] + 2*dp[i-1,2]) % Define.mod;
            }
        }
        if(M == 1){
            count = 2;
        }
        else if(M == 2){
            count = (4*dp[i-1,0] + 2*dp[i-1,1] + dp[i-1,2]) % Define.mod;
        }
        else{
            count = (5*dp[i-1,0] + 4*dp[i-1,1] + 2*dp[i-1,2]) % Define.mod;
        }
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}