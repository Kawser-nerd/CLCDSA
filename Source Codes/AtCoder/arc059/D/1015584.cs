using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N,S;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        long[,] dp = new long[N+1,N+1];
        for(int i=0;i<N;i++){
            dp[0,i] = i == 0 ? 1 : 0;
        }
        for(int i=1;i<N+1;i++){
            dp[i,0] = (dp[i-1,0]+dp[i-1,1]*2%Define.mod)%Define.mod;
            for(int j=1;j<N;j++){
                dp[i,j] = (dp[i-1,j-1]+dp[i-1,j+1]*2%Define.mod)%Define.mod;
            }
            dp[i,N] = dp[i-1,N-1];
        }
        sb.Append(dp[N,S]+"\n");
    }
    void Read(){
        N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        S = s.Length;
    }    
}
public static class Define{
    public const long mod = 1000000007;
}