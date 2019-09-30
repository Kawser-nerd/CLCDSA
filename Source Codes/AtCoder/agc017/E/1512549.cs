using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    bool[] us;
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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int H = int.Parse(str[1]);
        G = new List<int>[N+2*H];
        for(int i=0;i<G.Length;i++){
            G[i] = new List<int>();
        }
        int[] I = new int[2*H];
        int[] O = new int[2*H];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            int c = int.Parse(str[2]);
            int d = int.Parse(str[3]);
            if(c == 0){
                G[a-1].Add(i+2*H);
                O[a-1]++;
            }
            else{
                G[c-1+H].Add(i+2*H);
                O[c-1+H]++;
            }
            if(d == 0){
                G[i+2*H].Add(b-1+H);
                I[b-1+H]++;
            }
            else{
                G[i+2*H].Add(d-1);
                I[d-1]++;
            }
        }
        bool ans = true;
        for(int i=0;i<H;i++){
            ans &= O[i] >= I[i];
        }
        for(int i=H;i<2*H;i++){
            ans &= O[i] <= I[i];
        }
        us = new bool[N+2*H];
        for(int i=0;i<H;i++){
            if(O[i] > I[i]){
                dfs(i);
            }
        }
        for(int i=2*H;i<2*H+N;i++){
            ans &= us[i];
        }
        if(ans){
            sb.Append("YES\n");
        }
        else{
            sb.Append("NO\n");
        }
    }
    void dfs(int v){
        if(us[v]){
            return;
        }
        us[v] = true;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!us[t]){
                dfs(t);
            }
        }
    }
}