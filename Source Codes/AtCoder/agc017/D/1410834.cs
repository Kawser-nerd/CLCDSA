using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
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
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<N-1;i++){
            string[] str = Console.ReadLine().Split(' ');
            int x = int.Parse(str[0])-1;
            int y = int.Parse(str[1])-1;
            G[x].Add(y);
            G[y].Add(x);
        }
        int count = dfs(0,-1);
        if(count == 0){
            sb.Append("Bob\n");
        }
        else{
            sb.Append("Alice\n");
        }
    }
    int dfs(int v,int f){
        int x = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                x ^= dfs(t,v)+1;
            }
        }
        return x;
    }
}