using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    long[] x;
    long[] y;
    long[] r;
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
        double[] d = new double[(N+2)*(N+2)];
        int[] f = new int[(N+2)*(N+2)];
        int[] t = new int[(N+2)*(N+2)];
        for(int i=0;i<N+2;i++){
            for(int j=0;j<N+2;j++){
                d[i*(N+2)+j] = Distance(i,j);
                f[i*(N+2)+j] = i;
                t[i*(N+2)+j] = j;
            }
        }
        Dijkstra D = new Dijkstra(f,t,d,N+2,N);
        sb.Append(D.GetCost(N+1)+"\n");

    }
    double Distance(int i,int j){
        return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) > (r[i]+r[j])*(r[i]+r[j]) ? Math.Sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) - (r[i]+r[j]) : 0;
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(Console.ReadLine());
        x = new long[N+2];
        y = new long[N+2];
        r = new long[N+2];
        x[N] = Int64.Parse(str[0]);
        x[N+1] = Int64.Parse(str[2]);
        y[N] = Int64.Parse(str[1]);
        y[N+1] = Int64.Parse(str[3]);
        r[N] = 0;
        r[N+1] = 0;
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            x[i] = Int64.Parse(str[0]);
            y[i] = Int64.Parse(str[1]);
            r[i] = Int64.Parse(str[2]);
        }
    }    
}
struct Edge{
    public Vertex v;
    public double cost;
    public Edge(Vertex v0,double c){
        v = v0;
        cost = c;
    }
}
class Vertex{
    public bool finished;
    public List<Vertex> edges;
    public List<double> costs;
    public double cost;
    public void AddEdge(Vertex v,double c){
        edges.Add(v);
        costs.Add(c);
    }
    public Vertex(){
        edges = new List<Vertex>();
        costs = new List<double>();
        cost = -1;
        finished = false;
    }
}
class Dijkstra{
	int E;
	Vertex[] point;
    Vertex S;
    public double GetCost(int i){
        return point[i].cost;
    }
    public Dijkstra(int[] f,int[] t,double[] cost,int n,int s){
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