using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    long[] X;
    long[] Y;
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
    long Distance(int i,int j){
        return Math.Max(Math.Max(X[i]-X[j],X[j]-X[i]),Math.Max(Y[i]-Y[j],Y[j]-Y[i]));
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int A = int.Parse(str[1])-1;
        X = new long[N];
        Y = new long[N];
        long D;
        {
            int B = int.Parse(str[2])-1;
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                X[i] = long.Parse(str[0]) + long.Parse(str[1]);
                Y[i] = long.Parse(str[0]) - long.Parse(str[1]);
            }
            D = Distance(A,B);
        }
        UnionFind U = new UnionFind(N);
        int[] Num = new int[N];
        {
            int[] a = new int[N];
            for(int i=0;i<N;i++){
                a[i] = i;
            }
            Array.Sort(a,(x,y)=>X[x] > X[y] ? 1 : (X[x] < X[y] ? -1 : (Y[x] > Y[y] ? 1 : (Y[x] < Y[y] ? -1 : 0))));
            int s = 0;
            int g = 0;
            while(g < N){
                while(g < N && X[a[s]] + D > X[a[g]]){
                    g++;
                }
                if(g == N){
                    break;
                }
                while(X[a[s]] + D < X[a[g]]){
                    s++;
                }
                if(X[a[s]] + D != X[a[g]]){
                    continue;
                }
                long sp = X[a[s]];
                long gp = X[a[g]];
                int gb = g;
                while(sp == X[a[s]]){
                    if(g < N && gp == X[a[g]] && Y[a[s]] + D >= Y[a[g]]){
                        if(Y[a[s]] <= Y[a[g]] + D){
                            U.Union(a[s],a[g]);
                        }
                        g++;
                    }
                    else if(gb != g && Y[a[s]] > Y[a[gb]] + D){
                        gb++;
                    }
                    else if(gb != g){
                        U.Union(a[s],a[gb]);
                        Num[a[s]] += g - gb;
                        s++;
                    }
                    else{
                        s++;
                    }
                }
            }
            Array.Sort(a,(x,y)=>Y[x] > Y[y] ? 1 : (Y[x] < Y[y] ? -1 : (X[x] > X[y] ? 1 : (X[x] < X[y] ? -1 : 0))));
            s = 0;
            g = 0;
            while(g < N){
                while(g < N && Y[a[s]] + D > Y[a[g]]){
                    g++;
                }
                if(g == N){
                    break;
                }
                while(Y[a[s]] + D < Y[a[g]]){
                    s++;
                }
                if(Y[a[s]] + D != Y[a[g]]){
                    continue;
                }
                long sp = Y[a[s]];
                long gp = Y[a[g]];
                int gb = g;
                while(sp == Y[a[s]]){
                    if(g < N && gp == Y[a[g]] && X[a[s]] + D > X[a[g]]){
                        if(X[a[s]] < X[a[g]] + D){
                            U.Union(a[s],a[g]);
                        }
                        g++;
                    }
                    else if(gb != g && X[a[s]] >= X[a[gb]] + D){
                        gb++;
                    }
                    else if(gb != g){
                        Num[a[s]] += g - gb;
                        U.Union(a[s],a[gb]);
                        s++;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        long count = 0;
        for(int i=0;i<N;i++){
            if(U.Same(A,i)){
                count += Num[i];
            }
        }
        sb.Append(count+"\n");
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