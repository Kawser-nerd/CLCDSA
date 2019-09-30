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
        int K = int.Parse(str[1]);
        int L = int.Parse(str[2]);
        int[] P1 = new int[K];
        int[] Q1 = new int[K];
        int[] P2 = new int[L];
        int[] Q2 = new int[L];
        UnionFind U1 = new UnionFind(N);
        for(int i=0;i<K;i++){
            str = Console.ReadLine().Split(' ');
            int p = int.Parse(str[0])-1;
            int q = int.Parse(str[1])-1;
            P1[i] = p;
            Q1[i] = q;
            U1.Union(p,q);
        }
        UnionFind U2 = new UnionFind(N);
        for(int i=0;i<L;i++){
            str = Console.ReadLine().Split(' ');
            int p = int.Parse(str[0])-1;
            int q = int.Parse(str[1])-1;
            P2[i] = p;
            Q2[i] = q;
            U2.Union(p,q);
        }
        int[] a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = i;
        }
        int[] u1 = new int[N];
        int[] u2 = new int[N];
        for(int i=0;i<N;i++){
            u1[i] = U1.Get(i);
            u2[i] = U2.Get(i);
        }
        Array.Sort(a,(x,y)=>(u1[x] > u1[y]) ? 1 : (u1[x] == u1[y] ? (u2[x] - u2[y]) : -1));
        int[] b = new int[N];
        {
            int i = 0;
            int count = 1;
            while(i != N){
                while(i != N-1 && u1[a[i]] == u1[a[i+1]] && u2[a[i]] == u2[a[i+1]]){
                    count++;
                    i++;
                }
                for(int j=i-count+1;j<=i;j++){
                    b[a[j]] = count;
                }
                count = 1;
                i++;
            }
        }
        for(int i=0;i<N;i++){
            sb.Append(b[i]+" ");
        }
        sb.Append("\n");
    }
}
class UnionFind{
    public int[] par;
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
    public int Get(int x){
        if(x != par[x]){
            par[x] = Get(par[x]);
        }
        return par[x];
    }
}