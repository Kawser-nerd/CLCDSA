using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
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
        int M = int.Parse(str[1]);
        long[,,] DP = new long[M+1,N+1,2];
        for(int i=0;i<N+1;i++){
            if(i == 0){
                DP[0,i,1] = 1;
            }
            else{
                DP[0,i,0] = 1;
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N+1;j++){
                DP[i,j,0] %= Define.mod;
                DP[i,j,1] %= Define.mod;
                if(j != N){
                    DP[i+1,j+1,0] += DP[i,j,0];
                    DP[i+1,j+1,1] += DP[i,j,1];
                }
                if(j == 1){
                    DP[i+1,j-1,1] += DP[i,j,0];
                    DP[i+1,j-1,1] += DP[i,j,1];
                }
                else if(j != 0){
                    DP[i+1,j-1,0] += DP[i,j,0];
                    DP[i+1,j-1,1] += DP[i,j,1];
                }
                if(j != N){
                    DP[i+1,j,0] += DP[i,j,0];
                    DP[i+1,j,1] += DP[i,j,1];
                }
                if(j == 1){
                    DP[i+1,j,1] += DP[i,j,0];
                    DP[i+1,j,1] += DP[i,j,1];
                }
                else if(j != 0){
                    DP[i+1,j,0] += DP[i,j,0];
                    DP[i+1,j,1] += DP[i,j,1];
                }
            }
        }
        long count = 0;
        for(int i=0;i<N+1;i++){
            count += DP[M,i,1];
        }
        count %= Define.mod;
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}