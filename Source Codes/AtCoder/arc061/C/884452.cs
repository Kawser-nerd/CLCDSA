using System;
using System.Collections.Generic;
class Solve{
    public int N;
    public int M;
    public Pair[] d;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] x1 = new int[N];
        int t;
        Vertex[] x2 = new Vertex[N];
        Vertex[] station = new Vertex[N];
        List<Vertex> x = new List<Vertex>();
        Heap h;
        for(int i = 0;i < N;i++){
            x1[i] = -1;
            station[i] = new Vertex(-1,i,-1);
            x.Add(station[i]);
        }
        station[0].i = 0;
        Array.Sort(d,(a,b) => a.Compare(b));
        t = 0;
        while(t < M){
            int c = d[t].c;
            while(t < M && c == d[t].c){
                int p = d[t].p;
                int q = d[t].q;
                if(x1[p] != c){
                    x1[p] = c;
                    x2[p] = new Vertex(-1,p,c);
                    x.Add(x2[p]);
                    x2[p].addedge0(station[p]);
                    station[p].addedge1(x2[p]);
                }
                if(x1[q] != c){
                    x1[q] = c;
                    x2[q] = new Vertex(-1,q,c);
                    x.Add(x2[q]);
                    x2[q].addedge0(station[q]);
                    station[q].addedge1(x2[q]);
                }
                x2[p].addedge0(x2[q]);
                x2[q].addedge0(x2[p]);
                t++;
            }
        }
        h = new Heap(x.Count);
        h.push(station[0]);
        while(h.size > 0){
            Vertex v = h.pop();
            for(int i=0;i < v.edge0.Count;i++){
                if(v.i < v.edge0[i].i || v.edge0[i].i == -1){
                    v.edge0[i].i = v.i;
                    h.push(v.edge0[i]);
                }
            }
            for(int i=0;i < v.edge1.Count;i++){
                if(v.i + 1 < v.edge1[i].i || v.edge1[i].i == -1){
                    v.edge1[i].i = v.i + 1;
                    h.push(v.edge1[i]);
                }
            }
        }
        Console.WriteLine(x[N-1].i);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        d = new Pair[M];
        for(int i = 0;i < M;i++){
            str = Console.ReadLine().Split(' ');
            d[i] = new Pair(int.Parse(str[0])-1,int.Parse(str[1])-1,int.Parse(str[2]));
        }
    }    
}
class Pair{
    public int p;
    public int q;
    public int c;
    public Pair(int i0,int j0,int k0){
        p = i0;
        q = j0;
        c = k0;
    }
    public int Compare(Pair pa){
        if(c > pa.c){
            return 1;
        }
        else if(c == pa.c){
            return 0;
        }       
        else{
            return -1;
        }
    }
}
class Vertex{
    public int i;
    public int k;
    public int c;
    public List<Vertex> edge0;
    public List<Vertex> edge1;
    public void addedge0(Vertex v){
        edge0.Add(v);
    }
    public void addedge1(Vertex v){
        edge1.Add(v);
    }
    public Vertex(int j,int b,int s){
        i = j;
        k = b;
        c = s;
        edge0 = new List<Vertex>();
        edge1 = new List<Vertex>();
    }
}
class Heap{
    public int size;
    Vertex[] obj;

    public Heap(int maxsize){
        size = 0;
        obj = new Vertex[maxsize];
    }

    public bool Compare(Vertex a,Vertex b){
        return a.i < b.i;
    }
    public void push(Vertex a){
        int i = size;
        size++;
        while(i > 0){
            int p = (i - 1)/2;
            if(Compare(obj[p],a)){
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
    public Vertex pop(){
        Vertex t = obj[0];
        int i = 0;
        size--;
        while(2*i+1 < size){
            int p = 2*i+1;
            if(p+1 < size && Compare(obj[p+1],obj[p])){
                p++;
            }
            if(Compare(obj[p],obj[size])){
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