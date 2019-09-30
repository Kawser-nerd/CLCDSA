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
        int K = int.Parse(str[1]);
        double[,,] dp = new double[N+1,K+1,2];
        for(int i=N;i>=0;i--){
            for(int j=K;j>=0;j--){
                if(i==N){
                    dp[i,j,1] = 1;
                    dp[i,j,0] = 0;
                }
                else if(j==K){
                    dp[i,j,1] = i/(double)(N);
                    dp[i,j,0] = 0;
                }
                else{
                    dp[i,j,1] = dp[i+1,j,1]*i/(i+1)+(dp[i+1,j,0] > dp[i+1,j+1,1] ? dp[i+1,j,0] : dp[i+1,j+1,1])/(i+1);
                    dp[i,j,0] = dp[i+1,j,0]*i/(i+1)+(dp[i+1,j,0] > dp[i+1,j+1,1] ? dp[i+1,j,0] : dp[i+1,j+1,1])/(i+1);
                }
            }
        }
        sb.Append(dp[0,0,1]+"\n");
    }
}