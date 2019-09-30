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
        int M = int.Parse(str[1]);
        int S = int.Parse(str[2])-1;
        List<int>[] graph = new List<int>[N];
        for(int i=0;i<N;i++){
            graph[i] = new List<int>();
        }
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int u = int.Parse(str[0]);
            int v = int.Parse(str[1]);
            if(u > v){
                graph[v-1].Add(u-1);
            }
            else{
                graph[u-1].Add(v-1);
            }
        }
        UnionFind U = new UnionFind(N);
        bool[] b = new bool[N];
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<graph[i].Count;j++){
                U.Union(i,graph[i][j]);
            }
            b[i] = U.Same(S,i);
        }
        for(int i=0;i<N;i++){
            if(b[i]){
                sb.Append(i+1+"\n");
            }
        }
    }
}
class UnionFind{
    int[] par;
    public UnionFind(int n){
        par = new int[n];
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    public void Union(int x,int y){
        par[Get(x)] = Get(y); 
    }
    public bool Same(int x,int y){
        return Get(x) == Get(y);
    }
    int Get(int x){
        if(x != par[x]){
            par[x] = Get(par[x]);
        }
        return par[x];
    }
}