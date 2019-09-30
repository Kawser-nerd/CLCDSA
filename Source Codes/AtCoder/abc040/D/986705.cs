using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N,M;
    int[] a,b,y;
    int Q;
    int[] v,w;
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
        UnionFind U = new UnionFind(N);
        int[] st = new int[M];
        int[] pe = new int[Q];
        int[] ans = new int[Q];
        for(int i=0;i<M;i++){
            st[i] = i;
        }
        for(int i=0;i<Q;i++){
            pe[i] = i;
        }
        Array.Sort(st,(x1,x2) => y[x2]-y[x1]);
        Array.Sort(pe,(x1,x2) => w[x2]-w[x1]);
        {
            int s1 = 0;
            int s2 = 0;
            while(true){
                if(s2 == Q){
                    break;
                }
                else if(s1 != M && y[st[s1]] > w[pe[s2]]){
                    U.Union(a[st[s1]],b[st[s1]]);
                    s1++;
                }
                else{
                    ans[pe[s2]] = U.Num(v[pe[s2]]);
                    s2++;
                }
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
        y = new int[M];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
            y[i] = int.Parse(str[2]);
        }
        Q = int.Parse(Console.ReadLine());
        v = new int[Q];
        w = new int[Q];
        for(int i=0;i<Q;i++){
            str = Console.ReadLine().Split(' ');
            v[i] = int.Parse(str[0])-1;
            w[i] = int.Parse(str[1]);
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