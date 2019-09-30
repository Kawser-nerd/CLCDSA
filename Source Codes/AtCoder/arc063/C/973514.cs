using System;
using System.Collections.Generic;
class Solve{
    int N;
    int K;
    Vertex[] tree;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        if(dfs(tree[0])){
            Console.WriteLine("Yes");
            dfs2(tree[0],tree[0].min-1);
            for(int i=0;i<N;i++){
                Console.WriteLine(tree[i].j);
            }
        }
        else{
            Console.WriteLine("No");
        }
    }
    bool dfs(Vertex v){
        v.c = true;
        int min = -10000000;
        int max = 10000001;
        int oe = -1;
        for(int i=0;i<v.edges.Count;i++){
            Vertex vv = v.edges[i].v;
            if(!vv.c){
                if(!dfs(vv)){
                    return false;
                }
                if(oe == -1 && vv.oe == 0){
                    oe = 1;
                }
                else if(oe == -1 && vv.oe == 1){
                    oe = 0;
                }
                else if(oe != -1 && oe == vv.oe){
                    return false;
                }
                if(vv.min != -10000000 && vv.min-1 > min){
                    min = vv.min-1;
                }
                if(vv.max != 10000001 && vv.max+1 < max){
                    max = vv.max+1;
                }
            }
        }
        if(v.c2){
            if(min > v.j){
                return false;
            }
            if(max < v.j){
                return false;
            }
            if(oe != -1 && oe != v.j%2){
                return false;
            }
            v.min = v.j;
            v.max = v.j;
            v.oe = v.j%2;
        }
        else{
            if(max < min){
                return false;
            }
            v.min = min;
            v.max = max;
            v.oe = oe;
        }
        return true;
    }
    void dfs2(Vertex v,int a){
        v.c = false;
        if(v.min > a-1){
            v.j = a+1;
        }
        else{
            v.j = a-1;
        }
        for(int i=0;i<v.edges.Count;i++){
            Vertex vv = v.edges[i].v;
            if(vv.c){
                dfs2(vv,v.j);
            }
        }
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        tree = new Vertex[N];
        for(int i=0;i<N;i++){
            tree[i] = new Vertex();
        }
        string[] str;
        for(int i=0;i<N-1;i++){
            str = Console.ReadLine().Split(' ');
            tree[int.Parse(str[0])-1].addedge(new Edge(tree[int.Parse(str[1])-1]));
            tree[int.Parse(str[1])-1].addedge(new Edge(tree[int.Parse(str[0])-1]));
        }
        K = int.Parse(Console.ReadLine());
        for(int i=0;i<K;i++){
            str = Console.ReadLine().Split(' ');
            tree[int.Parse(str[0])-1].j = int.Parse(str[1]);
            tree[int.Parse(str[0])-1].c2 = true;
        }
    }    
}
class Vertex{
    public List<Edge> edges;
    public bool c;
    public bool c2;
    public int j;
    public int min;
    public int max;
    public int oe;
    public void addedge(Edge e){
        edges.Add(e);
    }
    public Vertex(){
        edges = new List<Edge>();
        c = false;
    }
}
class Edge{
    public Vertex v;
    public Edge(Vertex v0){
        v = v0;
    }
}