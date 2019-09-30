using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
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
        int[] A = new int[N];
        int[] B = new int[N];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i])-1;
        }
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            B[i] = int.Parse(str[i])-1;
        }
        int[] D = new int[2*N];
        List<Edge>[] G = new List<Edge>[2*N];
        for(int i=0;i<2*N;i++){
            G[i] = new List<Edge>();
        }
        int ra = -1;
        for(int i=0;i<N;i++){
            if(A[i] == -2){
                ra = i;
            }
            else{
                Edge E = new Edge(A[i],i);
                G[A[i]].Add(E);
                G[i].Add(E);
                D[i]++;
                D[A[i]]++;
            }
        }
        int rb = -1;
        for(int i=0;i<N;i++){
            if(B[i] == -2){
                rb = N+i;
            }
            else{
                Edge E = new Edge(B[i]+N,i+N);
                G[B[i]+N].Add(E);
                G[i+N].Add(E);
                D[i+N]++;
                D[B[i]+N]++;
            }
        }
        bool b = true;
        D[ra]++;
        D[rb]++;
        {
            Edge E = new Edge(rb,ra);
            G[ra].Add(E);
            G[rb].Add(E);
        }
        for(int i=0;i<N;i++){
            b &= D[i] % 2 == D[i+N] % 2;
            if(D[i] % 2 == 1){
                Edge E = new Edge(i+N,i);
                G[i].Add(E);
                G[i+N].Add(E);
            }
        }
        if(!b){
            sb.Append("IMPOSSIBLE\n");
            return;
        }
        else{
            sb.Append("POSSIBLE\n");
        }
        int[] pointer = new int[2*N];
        int[] ans = new int[N];
        for(int i=0;i<2*N;i++){
            int p = i;
            while(pointer[p] < G[p].Count){
                while(pointer[p] < G[p].Count && G[p][pointer[p]].b){
                    pointer[p]++;
                }
                if(pointer[p] != G[p].Count){
                    Edge E = G[p][pointer[p]];
                    E.b = true;
                    if(E.f == p){
                        if(E.f == E.t + N){
                            ans[E.t] = -1;
                        }
                        if(E.f + N == E.t){
                            ans[E.f] = 1;
                        }
                        p = E.t;
                    }
                    else{
                        if(E.f == E.t + N){
                            ans[E.t] = 1;
                        }
                        if(E.f + N == E.t){
                            ans[E.f] = -1;
                        }
                        p = E.f;
                    }
                }
            }
        }
        if(D[ra] % 2 == 0){
            ans[ra] = 0;
        }
        for(int i=0;i<N;i++){
            sb.Append(ans[i]);
            if(i == N-1){
                sb.Append("\n");
            }
            else{
                sb.Append(" ");
            }
        }
    }
}
class Edge{
    public int f;
    public int t;
    public bool b;
    public Edge(int f0,int t0){
        f = f0;
        t = t0;
        b = false;
    }
}