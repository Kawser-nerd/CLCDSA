using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    List<int>[] G;
    bool[] us;
    bool[] b;
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
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int x = int.Parse(str[0])-1;
            int y = int.Parse(str[1])-1;
            G[x].Add(y);
            G[y].Add(x);
        }
        us = new bool[N];
        long single = 0;
        long tw = 0;
        long no = 0;
        b = new bool[N];
        for(int i=0;i<N;i++){
            if(!us[i]){
                if(G[i].Count == 0){
                    single++;
                }
                else if(!dfs(i,true)){
                    no++;
                }
                else{
                    tw++;
                }
            }
        }
        long count = 0;
        count += 2*single*N - single*single;
        count += 2*no*tw;
        count += no*no;
        count += tw*tw*2;
        sb.Append(count+"\n");
    }
    bool dfs(int v,bool c){
        us[v] = true;
        b[v] = c;
        bool ans = true;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!us[t]){
                if(!dfs(t,!c)){
                    ans = false;
                }
            }
            else if(b[v] == b[t]){
                ans = false;
            }
        }
        return ans;
    }
}