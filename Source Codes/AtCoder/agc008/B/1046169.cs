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
        long[] A = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        long[] s1 = new long[N];
        long[] s2 = new long[N];
        long sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i] >= 0 ? A[i] : 0;
            s1[i] = (i == 0 ? 0 : s1[i-1]) + (A[i] > 0 ? -A[i] : 0);
            s2[i] = (i == 0 ? 0 : s2[i-1]) + (A[i] < 0 ? A[i] : 0);
        }
        long max = 0;
        for(int i=0;i+K-1<N;i++){
            max = Math.Max(max,sum+s1[i+K-1]-(i != 0 ? s1[i-1] : 0));
        }
        for(int i=0;i+K-1<N;i++){
            max = Math.Max(max,sum+s2[i+K-1]-(i != 0 ? s2[i-1] : 0));
        }
        sb.Append(max+"\n");
    }
}