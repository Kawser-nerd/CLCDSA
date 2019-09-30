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
        int N = int.Parse(Console.ReadLine());
        int[] a = new int[N];
        int[] b = new int[N];
        List<int>[] G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<N-1;i++){
            string[] str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
            G[a[i]].Add(b[i]);
            G[b[i]].Add(a[i]);
        }
        string s = Console.ReadLine();
        int o = 0;
        for(int i=0;i<N;i++){
            if(s[i] == '1'){
                o++;
            }
        }
        int[] depth;
        int[] depth2;
        int[] depth3;
        int[] depthR;
        int[] depthv;
        int[] child;
        {
            Tree T = new Tree(G,s);
            depth = T.GetDepth(0);
            T.GetDepthR(0);
            depth2 = T.depth2;
            depth3 = T.depth3;
            depthR = T.depthR;
            depthv = T.depthv;
            child = T.GetDecendant(0);
        }
        long count = 0;
        for(int i=0;i<N;i++){
            int min = N+1;
            int max = 0;
            if(s[i] == '1'){
                min = 0;
            }
            else{
                for(int j=0;j<G[i].Count;j++){
                    int t = G[i][j];
                    if(depth[t] > depth[i]){
                        if(child[t] > 0){
                            min = Math.Min(min,depth2[t]);
                        }
                    }
                    else if(depthv[t] == i){
                        if(o - child[i] > 0){
                            min = Math.Min(min,Math.Max(depth3[t],depthR[t]));
                        }
                    }
                    else{
                        if(o - child[i] > 0){
                            min = Math.Min(min,Math.Max(depth2[t],depthR[t]));
                        }
                    }
                }
            }
            max = (depthR[i] > depth3[i] ? Math.Min(depth2[i],depthR[i]) : depth3[i]) - 1;
            count += Math.Max(max - min + 1,0);
        }
        for(int i=0;i<N-1;i++){
            int p1,p2;
            if(depth[a[i]] > depth[b[i]]){
                p1 = b[i];
                p2 = a[i];
            }
            else{
                p1 = a[i];
                p2 = b[i];
            }
            int d1 = depthv[p1] == p2 ? Math.Max(depth3[p1],depthR[p1]) : Math.Max(depth2[p1],depthR[p1]);
            int d2 = depth2[p2];
            if(d1 == d2 || (d1 > d2  && child[p2] > 0) || (d2 > d1 && o > child[p2])){
                count++;
            }
        }
        sb.Append(count+"\n");
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
    int[] decendant;
    string s;
    public int[] depth2;
    public int[] depthv;
    public int[] depth3;
    public int[] depthR;
    public int center1;
    public int center2;
    public int diamater;
    public Tree(List<int>[] G,string s0){
        T = G;
        N = G.Length;
        s = s0;
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
    //???????
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
    public int[] GetDecendant(int p){
        b = new bool[N];
        decendant = new int[N];
        dfs5(p);
        return decendant;
    }
    //?????
    public int[] GetDepth2(int p){
        b = new bool[N];
        depth2 = new int[N];
        dfs6(p);
        return depth2;
    }
    //2????
    public void GetDepth3(int p){
        b = new bool[N];
        depth2 = new int[N];
        depthv = new int[N];
        depth3 = new int[N];
        dfs7(p);
    }
    public int[] GetDepthR(int p){
        GetDepth3(p);
        b = new bool[N];
        depthR = new int[N];
        dfs8(p,0);
        return depthR;
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
    int dfs5(int v){
        b[v] = true;
        int count = s[v] == '1' ? 1 : 0;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                count += dfs5(t);
            }
        }
        decendant[v] = count;
        return count;
    }
    int dfs6(int v){
        b[v] = true;
        int count = 1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                count = Math.Max(count,dfs6(t)+1);
            }
        }
        depth2[v] = count;
        return count;
    }
    int dfs7(int v){
        b[v] = true;
        int m = 1;
        int m2 = 1;
        int mv = -1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                int c = dfs7(t) + 1;
                if(c > m){
                    m2 = m;
                    m = c;
                    mv = t;
                }
                else if(c > m2){
                    m2 = c;
                }
            }
        }
        depth2[v] = m;
        depth3[v] = m2;
        depthv[v] = mv;
        return m;
    }
    void dfs8(int v,int d){
        b[v] = true;
        depthR[v] = d+1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                int td = depthv[v] == t ? Math.Max(depth3[v],d+1) : Math.Max(depth2[v],d+1); 
                dfs8(t,td);
            }
        }
    }
}