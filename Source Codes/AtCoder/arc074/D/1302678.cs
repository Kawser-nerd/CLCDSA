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
        string[] str = Console.ReadLine().Split(' ');
        int H = int.Parse(str[0]);
        int W = int.Parse(str[1]);
        int S = -1;
        int G = -1;
        int si = -1;
        int sj = -1;
        int gi = -1;
        int gj = -1;
        List<int> f = new List<int>();
        List<int> t = new List<int>();
        List<long> c = new List<long>();
        int count = H+W;
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                if(s[j] != '.'){
                    f.Add(count);
                    t.Add(i);
                    f.Add(count);
                    t.Add(H+j);
                    if(s[j] == 'S'){
                        S = count;
                        c.Add(1000000000);
                        c.Add(1000000000);
                        si = i;
                        sj = j;
                    }
                    else if(s[j] == 'T'){
                        G = count;
                        c.Add(1000000000);
                        c.Add(1000000000);
                        gi = i;
                        gj = j;
                    }
                    else{
                        c.Add(1);
                        c.Add(1);
                    }
                    count++;
                } 
            }
        }
        if(si == gi || sj == gj){
            sb.Append("-1\n");
            return;
        }
        MaxFlow F = new MaxFlow(f.ToArray(),t.ToArray(),c.ToArray(),count,S,G);
        sb.Append(F.flow+"\n");
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
            point[t[i]].AddEdge(new Edge(point[f[i]],capacity[i]));
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