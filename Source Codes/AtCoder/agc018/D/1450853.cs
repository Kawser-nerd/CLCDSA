using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    List<long>[] C;
    int[] child;
    long[] cost;
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
        C = new List<long>[N];
        child = new int[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
            C[i] = new List<long>();
        }
        for(int i=0;i<N-1;i++){
            string[] str = Console.ReadLine().Split(' ');
            G[int.Parse(str[0])-1].Add(int.Parse(str[1])-1);
            C[int.Parse(str[0])-1].Add(int.Parse(str[2]));
            G[int.Parse(str[1])-1].Add(int.Parse(str[0])-1);
            C[int.Parse(str[1])-1].Add(int.Parse(str[2]));
        }
        GetChild(0,-1);
        int Center = Central(0,N/2,-1);
        GetChild(Center,-1);
        long count = 0;
        cost = new long[N];
        Cost(Center,0,-1);
        for(int i=0;i<N;i++){
            count += 2*cost[i];
        }
        int Center2 = -1;
        if(N % 2 == 0){
            for(int i=0;i<N;i++){
                if(child[i] == N/2){
                    Center2 = i;
                }
            }
        }
        long min = 100000000;
        if(Center2 == -1){
            for(int i=0;i<G[Center].Count;i++){
                min = Math.Min(min,C[Center][i]);
            }
        }
        else{
            min = cost[Center2];
        }
        count -= min;
        sb.Append(count+"\n");
    }
    void Cost(int v,long c,int f){
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                Cost(t,c+C[v][i],v);
            }
        }
        cost[v] = c;
    }
    int Central(int v,int c,int f){
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f && child[t] > c){
                return Central(t,c,v);
            }
        }
        return v;
    }
    int GetChild(int v,int f){
        int count = 1;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                count += GetChild(t,v);
            }
        }
        child[v] = count;
        return count;
    }
}