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
        string[] str = Console.ReadLine().Split(' ');
        int[] X = new int[N];
        for(int i=0;i<N;i++){
            X[i] = int.Parse(str[i]);
        }
        List<int> Diff = new List<int>();
        Diff.Add(X[0]);
        Diff.Add(X[N-1]+1);
        for(int i=1;i<N;i++){
            if(X[i] != X[i-1] + 1){
                Diff.Add(X[i]);
            }
        }
        for(int i=0;i<N-1;i++){
            if(X[i] + 1 != X[i+1]){
                Diff.Add(X[i]+1);
            }
        }
        int[] diff = Diff.ToArray();
        int o = 0;
        int e = 0;
        for(int i=0;i<diff.Length;i++){
            if(diff[i] % 2 == 0){
                e++;
            }
            else{
                o++;
            }
        }
        int[] Odd = new int[o];
        int[] Even = new int[e];
        o = 0;
        e = 0;
        for(int i=0;i<diff.Length;i++){
            if(diff[i] % 2 == 0){
                Even[e] = diff[i];
                e++;
            }
            else{
                Odd[o] = diff[i];
                o++;
            }
        }
        List<int> f = new List<int>();
        List<int> t = new List<int>();
        List<long> capa = new List<long>();
        int S = 0;
        int Ef = 1;
        int Of = e+1;
        int T = o+e+1;
        for(int i=0;i<e;i++){
            f.Add(S);
            t.Add(Ef+i);
            capa.Add(1);
        }
        for(int i=0;i<o;i++){
            f.Add(Of+i);
            t.Add(T);
            capa.Add(1);
        }
        Generateprimenumber G = new Generateprimenumber(10000);
        for(int i=0;i<e;i++){
            for(int j=0;j<o;j++){
                if(G.Prime(Math.Max(Even[i]-Odd[j],Odd[j]-Even[i]))){
                    f.Add(Ef+i);
                    t.Add(Of+j);
                    capa.Add(1);
                }
            }
        }
        MaxFlow Flow = new MaxFlow(f.ToArray(),t.ToArray(),capa.ToArray(),o+e+2,0,o+e+1);
        int flow = (int)Flow.flow;
        int count = diff.Length - flow;
        if(e % 2 != flow % 2){
            count++;
        }
        sb.Append(count+"\n");
    }
}
class Edge{
    public Vertex to;
    public long capacity;
    public Edge rev;
    public Edge(Vertex v,long c){
        to = v;
        capacity = c;
    }
}
class Vertex{
    public bool finished;
    public List<Edge> edges;
    public void AddEdge(Edge e){
        edges.Add(e);
    }
    public Vertex(){
        edges = new List<Edge>();
        finished = false;
    }
}
class MaxFlow{
    Vertex[] point;
    Vertex S;
    Vertex G;
    public long flow;
    int E;
    const long INF = 1000000000000000;
    public MaxFlow(int[] f,int[] t,long[] capacity,int n,int s,int g){
        point = new Vertex[n];
        for(int i=0;i<n;i++){
            point[i] = new Vertex();
        }
        E = f.Length;
        for(int i=0;i<E;i++){
            point[f[i]].AddEdge(new Edge(point[t[i]],capacity[i]));
            point[t[i]].AddEdge(new Edge(point[f[i]],0));
            point[f[i]].edges[point[f[i]].edges.Count-1].rev = point[t[i]].edges[point[t[i]].edges.Count-1];
            point[t[i]].edges[point[t[i]].edges.Count-1].rev = point[f[i]].edges[point[f[i]].edges.Count-1];
        }
        S = point[s];
        G = point[g];
        flow = 0;
        while(true){
            long fl = dfs(S,INF);
            flow += fl;
            if(fl == 0){
                break;
            }
            for(int i=0;i<n;i++){
                point[i].finished = false;
            }
        }
    }
    long dfs(Vertex v,long f){
        v.finished = true;
        if(v == G){
            return f;
        }
        for(int i=0;i<v.edges.Count;i++){
            Edge e = v.edges[i];
            if(!e.to.finished && e.capacity > 0){
                long d = dfs(e.to,Math.Min(f,e.capacity));
                if(d > 0){
                    e.capacity -= d;
                    e.rev.capacity += d;
                    return d;
                }
            }
        }
        return 0;
    }
}
class Generateprimenumber{
    public int[] p;
    public int length;
    public Generateprimenumber(int n){
        bool[] a = new bool[n+1];
        List<int> pp = new List<int>();
        int j = 2;
        for(int i=0;i<n+1;i++){
            a[i] = true;
        }
        while(j<=n){
            if(a[j]){
                pp.Add(j);
                for(int i=j;(long)i*(long)j<=n;i++){
                    a[i*j] = false;
                }
            }
            j++;
        }
        length = pp.Count;
        p = pp.ToArray();
    }
    public bool Prime(int x){
        for(int i=0;i<length;i++){
            if(p[i] == x){
                return true;
            }
            else if(x % p[i] == 0){
                return false;
            }
            else if(p[i]*p[i] > x){
                break;
            }
        }
        return x != 1;
    }
}