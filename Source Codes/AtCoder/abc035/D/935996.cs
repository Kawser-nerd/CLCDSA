using System;
using System.Collections.Generic;
using System.Linq;
 
 
//max heap
public class Heap<T>{
    private List<T> array;
    private IComparer<T> cmp;
    private int size;
    
    
    
    
    public Heap(int capacity, IComparer<T> cmp){
        this.array = new List<T>(capacity);
        this.size = 0;
        this.cmp = cmp;
    }
    
    //Caution:subeffetable!!
    public Heap(List<T> array, IComparer<T> cmp){
        this.array = array;
        this.cmp = cmp;
        this.size = array.Count;
        BuildHeap();
    }
    
    public void Clear(){
        array.Clear();
        this.size = 0;
    }
    
    public bool Empty(){
        return size==0;
    }
    
    protected int Parent(int i){
        return (i-1)/2;
    }
    
    protected int Left(int i){
        return 2*i+1;
    }
    
    protected int Right(int i){
        return 2*i+2;
    }
    
    public T Front(){
        if(size!=0){
            return array[0];
        } else {
            return default(T);
        }
    }
    
    public void Heapify(int i){
        int l = Left(i);
        int r = Right(i);
        int largest = i;
        if(l<size && cmp.Compare(array[l], array[i]) > 0) largest = l;
        if(r<size && cmp.Compare(array[r], array[largest])>0) largest = r;
        if(largest != i){
            T tmp = array[i];
            array[i] = array[largest];
            array[largest] = tmp;
            Heapify(largest);
        } 
    }
    
    public void BuildHeap(){
        for(int i= (size-2)/2; i>-1;--i){
            Heapify(i);
        }
    }
    
    public T Pop(){
        if(size < 1) return default(T);
        T max = array[0];
        array[0] = array[size-1];
        size--;
        Heapify(0);
        return max;
    }
    
    
    public void Insert(T key){
        size = size + 1;
        if( array.Count < size){
            array.Add(key);
        }  else {
            array[size-1] = key;
        }
        int i = size-1;
        while(i>0 && cmp.Compare(array[Parent(i)],array[i])<0){
            T tmp = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = tmp;
            i = Parent(i);
        }
    }
    
    public void Print(){
        for(int i=0;i<size;i++){
            Console.Write(array[i]);
        }
        Console.WriteLine();
    }
}
class Cmp : Comparer<Z2> {
    public override int Compare(Z2 x, Z2 y){
        if(x.x<y.x) return 1;
        if(x.x>y.x) return -1;
        return 0;
    }
}
 
public struct Z2 {
    public int x, y;
    public Z2(int x, int y){
        this.x = x;
        this.y = y;
    }
}
public struct Edge {
    public int to, cost;
    public Edge(int to, int cost){
        this.to = to;
        this.cost = cost;
    }
}
 
public class FDijkstra {
    Heap<Z2> hp;
    List<Edge>[] G;
    int[] d;
    const int INF = int.MaxValue;
    
    public FDijkstra(int maxV){
        d = new int[maxV];
        hp = new Heap<Z2>(maxV, new Cmp());
        G = new List<Edge>[maxV];
        for(int i=0;i<maxV;i++) G[i] = new List<Edge>();
       
    }
    
    public void MakeEdge(int x, int y, int cost){
        G[x].Add(new Edge(y, cost));
        //G[y].Add(new Edge(x, cost));
    }
    
    public void Dijkstra(int s){
        hp.Clear();
        for(int i=0;i<d.Length;i++) d[i] = INF;
        d[s] = 0;
        hp.Insert(new Z2(0,s));
        while(!hp.Empty()){
            Z2 p = hp.Pop();
            int v = p.y;
            if(d[v]<p.x) continue;
            foreach(var e in G[v]){
                if(d[e.to]>d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    hp.Insert(new Z2(d[e.to],e.to));
                }
            }
        }
    }
    
    public int GetDistance(int t){
        return d[t];
    }
}
 
 
public class Program {
    static void Main(string[] args){
        int[] ns = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int N = ns[0], M = ns[1], T = ns [2]; 
        FDijkstra fd1 = new FDijkstra(N);
        FDijkstra fd2 = new FDijkstra(N);
        ns = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = ns[i];
        }
        for(int i=0;i<M;i++){
            ns = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            fd1.MakeEdge(ns[0]-1,ns[1]-1,ns[2]);
            fd2.MakeEdge(ns[1]-1,ns[0]-1,ns[2]);
        }
        long ans = 0;
        fd1.Dijkstra(0);
        fd2.Dijkstra(0);
        for(int i=0;i<N;i++){
            if(fd1.GetDistance(i)==int.MaxValue || fd2.GetDistance(i)==int.MaxValue) continue;
            long t = fd1.GetDistance(i)+fd2.GetDistance(i);
            if(t<T){
                long a = A[i];
                long d = T-t;
                ans = Math.Max(ans,a*d);
            }
        }
        Console.WriteLine(ans);
    }
}