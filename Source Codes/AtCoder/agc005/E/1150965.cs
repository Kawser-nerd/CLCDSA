using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    List<int>[] G;
    int[] depth;
    int[] parent;
    bool[] b;
    int ans;
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
        int N,X;
        {
            string[] str = Console.ReadLine().Split(' ');
            N = int.Parse(str[0]);
            X = int.Parse(str[1])-1;
            int Y = int.Parse(str[2])-1;
            G = new List<int>[N];
            for(int i=0;i<N;i++){
                G[i] = new List<int>();
            }
            for(int i=0;i<N-1;i++){
                str = Console.ReadLine().Split(' ');
                int a = int.Parse(str[0])-1;
                int b = int.Parse(str[1])-1;
                G[a].Add(b);
                G[b].Add(a);
            }
            List<int>[] T = new List<int>[N];
            for(int i=0;i<N;i++){
                T[i] = new List<int>();
            }
            for(int i=0;i<N-1;i++){
                str = Console.ReadLine().Split(' ');
                int a = int.Parse(str[0])-1;
                int b = int.Parse(str[1])-1;
                T[a].Add(b);
                T[b].Add(a);
            }
            Tree Tr = new Tree(T);
            depth = Tr.GetDepth(Y);
            parent = Tr.GetParent(Y);
        }
        b = new bool[N];
        ans = 0;
        dfs(X,0);
        if(ans != -1){
            ans *= 2;
        }
        sb.Append(ans+"\n");
    }
    void dfs(int v,int d){
        b[v] = true;
        if(depth[v] < d){
            return;
        }
        if(ans != -1 && ans < depth[v]){
            ans = depth[v];
        }
        if(depth[v] > d){
            if(check(v)){
                ans = -1;
                return;
            }
            for(int i=0;i<G[v].Count;i++){
                int t = G[v][i];
                if(!b[t]){
                    dfs(t,d+1);
                }
            }
        }
    }
    bool check(int v){
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(parent[v] == parent[t] || (parent[v] != -1 && parent[parent[v]] == t) || (parent[t] != -1 && parent[parent[t]] == v) || parent[t] == v || parent[v] == t){
                ;         
            }
            else{
                return true;
            }
        }
        return false;
    }
}
public class Tree{
    List<int>[] T;
    bool[] b;
    int N;
    int temp1;
    int temp2;
    int[] depth;
    int[] parent;
    public int center1;
    public int center2;
    public int diamater;
    public Tree(List<int>[] G){
        T = G;
        N = G.Length;
    } 
    void calcLongestPath(int v){
        b = new bool[N];
        temp1 = 0;
        temp2 = 0;
        dfs1(v,0);
    }
    public int LongestPathDistance(int v){
        calcLongestPath(v);
        return temp1;
    }
    public int LongestPath(int v){
        calcLongestPath(v);
        return temp2;
    }
    public void Diamater(){
        int x1 = LongestPath(0);
        int x2 = LongestPath(x1);
        diamater = temp1;
    }
    public void Center(){
        int x1 = LongestPath(0);
        int x2 = LongestPath(x1);
        diamater = temp1;
        if(diamater % 2 == 0){
            center1 = Search(x1,x2,diamater/2);
            center2 = -1;
        }
        else{
            center1 = Search(x1,x2,diamater/2);
            center2 = Search(x1,x2,diamater/2+1);
        }
    }
    public int Search(int s,int t,int l){
        b = new bool[N];
        dfs2(s,t,0,l);
        return temp1;
    }
    public int[] GetDepth(int p){
        b = new bool[N];
        depth = new int[N];
        dfs3(p,0);
        return depth;
    }
    public int[] GetParent(int p){
        b = new bool[N];
        parent = new int[N];
        dfs4(p,-1);
        return parent;
    }
    void dfs1(int v,int l){
        b[v] = true;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs1(t,l+1);
            }
        }
        if(l >= temp1){
            temp1 = l;
            temp2 = v;
        }
    }
    bool dfs2(int v,int o,int l,int d){
        b[v] = true;
        bool x = v == o;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                x |= dfs2(t,o,l+1,d);
            }
        }
        if(x && l == d){
            temp1 = v;
        }
        return x;
    }
    void dfs3(int v,int d){
        b[v] = true;
        depth[v] = d;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs3(t,d+1);
            }
        }
    }
    void dfs4(int v,int p){
        b[v] = true;
        parent[v] = p;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs4(t,v);
            }
        }
    }
}