using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    bool[] us;
    List<int> P;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.WriteLine(sb.ToString());
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0])-1;
            int b = int.Parse(str[1])-1;
            G[a].Add(b);
            G[b].Add(a);
        }
        int count = 1;
        us = new bool[N];
        P = new List<int>();
        dfs(0);
        for(int i=P.Count-1;i>=0;i--){
            sb.Append((P[i]+1)+" ");
            count++;
        }
        sb.Append("1 ");
        P = new List<int>();
        dfs(0);
        for(int i=0;i<P.Count;i++){
            sb.Append((P[i]+1)+" ");
            count++;
        }
        Console.Write(count+"\n");
    }
    void dfs(int v){
        us[v] = true;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!us[t]){
                P.Add(t);
                dfs(t);
                break;
            }
        }
    }
}