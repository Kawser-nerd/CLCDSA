using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    List<int>[] G;
    int A,B;
    bool[] even;
    bool[] b;
    int ce,co;
    long ans;
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
        N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        if(M == N-1){
            for(int i=0;i<M;i++){
                str = Console.ReadLine().Split(' ');
                int x = int.Parse(str[0])-1;
                int y = int.Parse(str[1])-1;
                G[x].Add(y);
                G[y].Add(x);
            }
        }
        else{
            UnionFind U = new UnionFind(N);
            for(int i=0;i<M;i++){
                str = Console.ReadLine().Split(' ');
                int x = int.Parse(str[0])-1;
                int y = int.Parse(str[1])-1;
                if(!U.Same(x,y)){
                    G[x].Add(y);
                    G[y].Add(x);
                    U.Union(x,y);
                }
                else{
                    A = x;
                    B = y;
                }
            }
        }
        even = new bool[N];
        b = new bool[N];
        ce = 0;
        co = 0;
        checkodd(0,true);
        if(M == N-1){
            if(ce != co){
                sb.Append("-1\n");
            }
            else{
                ans = 0;
                b = new bool[N];
                dfs(0);
                sb.Append(ans+"\n");
            }
        }
        else{
            if(even[A] != even[B]){
                if(ce != co){
                    sb.Append("-1\n");
                }
                else{
                    long bf = -N;
                    long bl = N;
                    while(bl - bf >= 9){
                        long bc1 = (2*bf+bl)/3;
                        long bc2 = (bf+2*bl)/3;
                        long a1 = check(bc1);
                        long a2 = check(bc2); 
                        if(a1 >= a2){
                            bf = bc1;
                        }
                        if(a1 <= a2){
                            bl = bc2;
                        }
                    }
                    for(long i=bf;i<=bl;i++){
                        bf = check(bf) < check(i) ? bf : i;
                    }
                    sb.Append(check(bf)+"\n");
                }
            }
            else{
                if(N % 2 == 1){
                    sb.Append("-1\n");
                }
                else{
                    ans = 0;
                    b = new bool[N];
                    dfs2(A,(ce-co)/2);
                    sb.Append(ans+"\n");
                }
            }
        }
    }
    long check(long ex){
        b = new bool[N];
        ans = 0;
        dfs2(A,ex);
        return ans;
    }
    long dfs2(int v,long ex){
        b[v] = true;
        long count = 0;
        if(v == B){
            count -= ex;
        }
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!b[t]){
                count += dfs2(t,ex);
            }
        }
        if(even[v]){
            count++;
        }
        else{
            count--;
        }
        ans += Math.Max(count,-count);
        return count;
    }
    long dfs(int v){
        b[v] = true;
        long count = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!b[t]){
                count += dfs(t);
            }
        }
        if(even[v]){
            count++;
        }
        else{
            count--;
        }
        ans += Math.Max(count,-count);
        return count;
    }
    void checkodd(int v,bool e){
        even[v] = e;
        b[v] = true;
        if(e){
            ce++;
        }
        else{
            co++;
        }
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(!b[t]){
                checkodd(t,!e);
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