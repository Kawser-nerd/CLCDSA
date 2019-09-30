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
        int[] p;
        {
            bool[] a = new bool[N+1];
            List<int> pp = new List<int>();
            int j = 2;
            for(int i=0;i<N+1;i++){
                a[i] = true;
            }
            while(j<=N){
                if(a[j]){
                    pp.Add(j);
                    for(int i=j;i*j<=N;i++){
                        a[i*j] = false;
                    }
                }
                j++;
            }
            p = pp.ToArray();
        }
        long count = 1;
        for(int i=0;i<p.Length;i++){
            int prime = p[i];
            long c = 0;
            int n = N;
            while(n > 0){
                c += n/prime;
                n /= prime;
            }
            count = count * (c+1) % Define.mod;
        }
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}