using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    bool[,] Map;
    List<int>[] G;
    List<int>[] O;
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
        G = new List<int>[N];
        O = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
            O[i] = new List<int>();
        }
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int x = int.Parse(str[0]) - 1;
            int y = int.Parse(str[1]) - 1;
            G[x].Add(y);
            G[y].Add(x);
            O[x].Add(i);
            O[y].Add(i);
        }
        bool[] OK = new bool[N];
        Map = new bool[N,N];
        int count = 0;
        for(int i=0;i<N;i++){
            OK[i] = dfs(i,i,M);
        }
        for(int i=0;i<N;i++){
            if(!OK[i]){
                continue;
            }
            for(int j=i+1;j<N;j++){
                if(OK[j]){
                    bool b = true;
                    for(int k=0;k<N;k++){
                        b &= !Map[i,k] || !Map[j,k];
                    }
                    if(b){
                        count++;
                    }
                }
            }
        }
        sb.Append(count+"\n");
    }
    bool dfs(int p,int v,int c){
        Map[p,v] = true;
        bool b = true;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(O[v][i] < c){
                if(!Map[p,t]){
                    b &= dfs(p,t,O[v][i]);
                }
                else{
                    return false;
                }
            }
        }
        return b;
    }
}