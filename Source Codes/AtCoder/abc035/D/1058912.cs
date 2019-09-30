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
        int M = int.Parse(str[1]);
        int T = int.Parse(str[2]);
        long[] A = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
            c[i] = int.Parse(str[2]);
        }
        long max = T*A[0];
        Dijkstra D1 = new Dijkstra(a,b,c,N,0);
        Dijkstra D2 = new Dijkstra(b,a,c,N,0);
        for(int i=1;i<N;i++){
            if(D1.GetCost(i) != -1 && D2.GetCost(i) != -1 && D1.GetCost(i)+D2.GetCost(i) <= T){
                max = Math.Max(max,(T-D1.GetCost(i)-D2.GetCost(i))*A[i]);
            }
        }
        sb.Append(max+"\n");
    }
}
struct Edge{
    public Vertex v;
    public long cost;
    public Edge(Vertex v0,long c){
        v = v0;
        cost = c;
    }
}
class Vertex{
    public bool finished;
    public List<Vertex> edges;
    public List<long> costs;
    public long cost;
    public void AddEdge(Vertex v,long c){
        edges.Add(v);
        costs.Add(c);
    }
    public Vertex(){
        edges = new List<Vertex>();
        costs = new List<long>();
        cost = -1;
        finished = false;
    }
}
class Dijkstra{
	int E;
	Vertex[] point;
    Vertex S;
    public long GetCost(int i){
        return point[i].cost;
    }
    public Dijkstra(int[] f,int[] t,long[] cost,int n,int s){
        point = new Vertex[n];
        for(int i=0;i<n;i++){
            point[i] = new Vertex();
        }
        E = f.Length;
        for(int i=0;i<E;i++){
            point[f[i]].AddEdge(point[t[i]],cost[i]);
        }
        S = point[s];
        calc();
    }
    void calc(){
        Heap H = new Heap(2*E);
        S.cost = 0;
        H.push(new Edge(S,0));
        while(!H.Empty()){
            Vertex v = H.pop().v;
            if(v.finished){
                continue;
            }
            v.finished = true;
            for(int i=0;i<v.edges.Count;i++){
                Vertex vi = v.edges[i];
                if(vi.cost == -1 || vi.cost > v.costs[i]+v.cost){
                    vi.cost = v.costs[i]+v.cost;
                    H.push(new Edge(vi,vi.cost));
                }
            }
        }
    }
}
class Heap{
    public int size;
    Edge[] obj;
    public Heap(int maxsize){
        size = 0;
        obj = new Edge[maxsize];
    }
    public void push(Edge a){
        int i = size;
        size++;
        while(i > 0){
            int p = (i - 1)/2;
            if(obj[p].cost <= a.cost){
                obj[i] = a;
                break;
            }
            obj[i] = obj[p];
            i = p;
        }
        if(i == 0){
            obj[0] = a;
        }
    }
    public bool Empty(){
        return size == 0;
    }
    public Edge pop(){
        Edge t = obj[0];
        int i = 0;
        size--;
        while(2*i+1 < size){
            int p = 2*i+1;
            if(p+1 < size && obj[p+1].cost < obj[p].cost){
                p++;
            }
            if(obj[p].cost < obj[size].cost){
                obj[i] = obj[p];
                i = p;
            }
            else{
                obj[i] = obj[size];
                break;
            }
        }
        if(2*i+1 >= size){
            obj[i] = obj[size];
        }
        return t;
    }
}