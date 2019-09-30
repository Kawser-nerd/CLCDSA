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
        int N = int.Parse(Console.ReadLine());
        long n = N;
        long[] DP = new long[N];
        long sum = N;
        DP[N-1] = N;
        for(int i=N-2;i>=0;i--){
            long count = 0;
            if(i == N-2){
                count += DP[i+1] + n*(n-1);
                count %= Define.mod;
            }
            else{
                count += (n-1)*(n-1);
                count += sum + Define.mod - DP[i+2] + i + 2;
                count %= Define.mod;
            }
            DP[i] = count;
            sum = (sum + count) % Define.mod;
        }
        sb.Append(DP[0]+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}