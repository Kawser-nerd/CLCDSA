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
        long count = 2;
        if(N - M > 1 || M - N > 1){
            count = 0;
        }
        else if(N == M){
            count = 2;
        }
        else{
            count = 1;
        }
        for(int i=1;i<=N;i++){
            count *= i;
            count %= Define.mod;
        }
        for(int i=1;i<=M;i++){
            count *= i;
            count %= Define.mod;
        }
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}