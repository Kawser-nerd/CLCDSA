using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    bool b;
    bool[] us;
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
        if(N == 2){
            sb.Append("Second\n");
            return;
        }
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<N-1;i++){
            string[] str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0]) - 1;
            int b = int.Parse(str[1]) - 1;
            G[a].Add(b);
            G[b].Add(a);
        }
        us = new bool[N];
        if(G[0].Count == 1){
            if(dfs(G[0][0]) == 1){
                b = true;
            }
        }
        else{
            if(dfs(0) == 1){
                b = true;
            }
        }
        sb.Append((b ? "First" : "Second")+"\n");
    }
    int dfs(int v){
        us[v] = true;
        if(G[v].Count == 1){
            return 1;
        }
        int state = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!us[t]){
                int j = dfs(t);
                if(state == 0){
                    if(j == 1){
                        state = 1;
                    }
                }
                else{
                    if(j == 1){
                        b = true;
                    }
                }
            }
        }
        if(state == 1){
            return 0;
        }
        else{
            return 1;
        }
    }
}