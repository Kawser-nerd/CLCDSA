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
        long D = int.Parse(str[1]);
        long[] P = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            P[i] = int.Parse(str[i]);
        }
        long[] DP = new long[N+1];
        DP[N] = 1;
        for(int i=N-1;i>=0;i--){
            if(P[i] >= 2*DP[i+1]){
                DP[i] = DP[i+1];
            }
            else{
                DP[i] = DP[i+1] + P[i];
            }
        }
        bool[] b = new bool[N];
        for(int i=0;i<N;i++){
            b[i] = D >= DP[i+1];
            D = Math.Min(D,Math.Max(D-P[i],P[i]-D));
        }
        int Q = int.Parse(Console.ReadLine());
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<Q;i++){
            if(b[int.Parse(str[i])-1]){
                sb.Append("YES\n");
            }
            else{
                sb.Append("NO\n");
            }
        }
    }
}