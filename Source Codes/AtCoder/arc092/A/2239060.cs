using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    ReadData re;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new ReadData();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N = re.i();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];
        int[] D = new int[N];
        for(int i=0;i<N;i++){
            A[i] = re.i();
            B[i] = re.i();
        }
        for(int i=0;i<N;i++){
            C[i] = re.i();
            D[i] = re.i();
        }
        List<int> f = new List<int>();
        List<int> t = new List<int>();
        List<long> capa = new List<long>();
        int S = 2*N;
        int G = 2*N+1;
        for(int i=0;i<N;i++){
            f.Add(S);
            t.Add(i);
            capa.Add(1);
        }
        for(int i=0;i<N;i++){
            f.Add(i+N);
            t.Add(G);
            capa.Add(1);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[i] < C[j] && B[i] < D[j]){
                    f.Add(i);
                    t.Add(j+N);
                    capa.Add(1);
                }
            }
        }
        MaxFlow F = new MaxFlow(f.ToArray(),t.ToArray(),capa.ToArray(),2*N+2,S,G);
        long count = F.flow;
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
class ReadData{
    string[] str;
    int counter;
    public ReadData(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}