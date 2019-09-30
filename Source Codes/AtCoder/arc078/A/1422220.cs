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
        string[] str = Console.ReadLine().Split(' ');
        long[] A = new long[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        long sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
        }
        long count = 10000000000000000;
        long t = A[0];
        for(int i=1;i<N;i++){
            count = Math.Min(count,Math.Max(sum-2*t,2*t-sum));
            t += A[i];
        }
        sb.Append(count+"\n");
    }
}