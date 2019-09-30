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
        string s = Console.ReadLine();
        int N = int.Parse(str[0]);
        int[] R = new int[N];
        {
            int M = int.Parse(str[1]);
            int l = 0;
            int r = 0;
            for(int i=0;i<M;i++){
                str = Console.ReadLine().Split(' ');
                int a = int.Parse(str[0])-1;
                int b = int.Parse(str[1])-1;
                if(l != a){
                    for(int j=l;j<a;j++){
                        R[j] = Math.Max(r,j);
                    }
                    l = a;
                }
                r = Math.Max(r,b);
            }
            for(int j=l;j<N;j++){
                R[j] = Math.Max(r,j);
            }
        }
        int[] one = new int[N];
        one[0] = s[0] == '1' ? 1 : 0;
        for(int i=1;i<N;i++){
            one[i] = one[i-1] + (s[i] == '1' ? 1 : 0);
        }
        int C = one[N-1];
        long[,] dp = new long[N,C+1];
        dp[N-1,C] = 1;
        for(int i=C-1;i>=0;i--){
            dp[N-1,i] = 0;
        }
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<C;j++){
                dp[i,j] = (one[R[i]] >= j && (R[i] + 1 - one[R[i]] >= i + 1 - j) && i+1 >= j) ? (dp[i+1,j] + dp[i+1,j+1]) % Define.mod : 0; 
            }
            dp[i,C] = (one[R[i]] >= C && (R[i] + 1 - one[R[i]] >= i + 1 - C) && i+1 >= C) ? dp[i+1,C] : 0;
        }
        sb.Append((C != 0 ? (dp[0,0] + dp[0,1])%Define.mod : dp[0,0])+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}