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
        long T = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        long sum = 0;
        long[] t = new long[N];
        for(int i=0;i<N;i++){
            t[i] = int.Parse(str[i]);
        }
        for(int i=0;i<N-1;i++){
            sum += Math.Min(T,t[i+1]-t[i]);
        }
        sum += T;
        sb.Append(sum+"\n");
    }
}