using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    bool[] b;
    long[] wh;
    long[] bl;
    List<int>[] T;
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
        T = new List<int>[N];
        for(int i=0;i<N;i++){
            T[i] = new List<int>();
        }
        string[] str;
        for(int i=0;i<N-1;i++){
            str = Console.ReadLine().Split(' ');
            T[int.Parse(str[0])-1].Add(int.Parse(str[1])-1);
            T[int.Parse(str[1])-1].Add(int.Parse(str[0])-1);
        }
        b = new bool[N];
        wh = new long[N];
        bl = new long[N];
        dfs(0);
        sb.Append((bl[0]+wh[0])%Define.mod+"\n");
    }
    void dfs(int n){
       long o = 1;
       long w = 1;
       b[n] = true;
       for(int i=0;i<T[n].Count;i++){
           int j = T[n][i];
           if(!b[j]){
               dfs(j);
               o = o * wh[j] % Define.mod;
               w = w *(wh[j] + bl[j]) % Define.mod;
           }
       }
       bl[n] = o;
       wh[n] = w; 
    }
}
public static class Define{
    public const long mod = 1000000007;
}