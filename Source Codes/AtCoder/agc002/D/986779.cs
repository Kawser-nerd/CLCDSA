using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N,M;
    int[] a,b;
    int Q;
    int[] x,y,z;
    int[] ans;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        ans = new int[Q];
        List<List<int>> L = new List<List<int>>();
        List<List<int>> L1 = new List<List<int>>();
        List<int> pl = new List<int>();
        List<int> pl1 = new List<int>();
        {
            pl.Add(1);
            pl.Add(M+1);
            List<int> LL = new List<int>();
            for(int i=0;i<Q;i++){
                LL.Add(i);
            }
            L.Add(LL);
        }
        while(true){
            UnionFind U = new UnionFind(N);
            int i = 0;
            bool c = true;
            while(i < pl.Count-1){
                if(pl[i]+1 == pl[i+1]){
                    pl1.Add(pl[i]);
                    L1.Add(L[i]);
                    U.Union(a[pl[i]-1],b[pl[i]-1]);
                    i++;
                    continue;
                }
                c = false;
                int m = (pl[i]+pl[i+1])/2;
                pl1.Add(pl[i]);
                pl1.Add(m);
                List<int> LL1 = new List<int>();
                List<int> LL2 = new List<int>();
                for(int j=pl[i];j<m;j++){
                    U.Union(a[j-1],b[j-1]);
                }
                for(int j=0;j<L[i].Count;j++){
                    int t = L[i][j];
                    if((!U.Same(x[t],y[t]) && (U.Num(x[t])+U.Num(y[t]) >= z[t])) || (U.Num(x[t]) >= z[t])){
                        LL1.Add(t);
                    }
                    else{
                        LL2.Add(t);
                    }
                }
                for(int j=m;j<pl[i+1];j++){
                    U.Union(a[j-1],b[j-1]);
                }
                L1.Add(LL1);
                L1.Add(LL2);
                i++;
            }
            pl1.Add(M+1);
            if(!c){
                L = L1;
                L1 = new List<List<int>>();
                pl = pl1;
                pl1 = new List<int>();
            }
            else{
                for(int j=0;j<L1.Count;j++){
                    for(int k=0;k<L1[j].Count;k++){
                        ans[L1[j][k]] = pl1[j];
                    }
                }
                break;
            }
        }
        for(int i=0;i<Q;i++){
            sb.Append(ans[i]+"\n");
        }
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        a = new int[M];
        b = new int[M];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
        }
        Q = int.Parse(Console.ReadLine());
        x = new int[Q];
        y = new int[Q];
        z = new int[Q];
        for(int i=0;i<Q;i++){
            str = Console.ReadLine().Split(' ');
            x[i] = int.Parse(str[0])-1;
            y[i] = int.Parse(str[1])-1;
            z[i] = int.Parse(str[2]);
        }
    }    
}
class UnionFind{
    int[] par;
    int[] num;
    public UnionFind(int n){
        par = new int[n];
        num = new int[n];
        for(int i=0;i<n;i++){
            par[i] = i;
            num[i] = 1;
        }
    }
    public int Num(int x){
        return num[Get(x)];
    }
    public void Union(int x,int y){
        int i = Get(x);
        int j = Get(y);
        if(i != j){
            num[i] += num[j];
            par[j] = i;
        } 
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