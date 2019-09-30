using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    int N;
    int[] X;
    int[] Y;
    int[] P;
    int[] Q;
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
        N = int.Parse(Console.ReadLine());
        X = new int[N];
        Y = new int[N];
        for(int i=0;i<N;i++){
            string[] str = Console.ReadLine().Split(' ');
            X[i] = int.Parse(str[0]);
            Y[i] = int.Parse(str[1]);
        }
        P = new int[2*N];
        for(int i=0;i<2*N;i++){
            P[i] = i;
        }
        Array.Sort(P,(x,y)=>(x>=N ? Y[x-N] : X[x])-(y>=N ? Y[y-N] : X[y]));
        Q = new int[2*N];
        for(int i=0;i<2*N;i++){
            Q[P[i]] = i;
        }
        int bf = 0;
        int bl = 1000000000;
        while(bf != bl){
            int bc = (bf+bl+1)/2;
            if(check(bc)){
                bf = bc;
            }
            else{
                bl = bc-1;
            }
        }
        sb.Append(bf+"\n");
    }
    bool check(int D){
        SegTree Seg = new SegTree(2*N);
        for(int i=0;i<N;i++){
            Seg.Add(Seg.ToLeaf(Q[i]),Seg.ToLeaf(Q[i+N]),true,true);
        }
        for(int i=Seg.segf-1;i>=0;i--){
            int sl = i*2+1;
            int sr = i*2+2;
            Seg.Add(i,sl,true,false);
            Seg.Add(i,sr,true,false);
        }
        for(int i=0;i<2*N-1;i++){
            int Pi = P[i]>=N ? Y[P[i]-N] : X[P[i]];
            int bf = i;
            int bl = 2*N-1;
            while(bf != bl){
                int bc = (bf+bl+1)/2;
                if(Pi + D > (P[bc]>=N ? Y[P[bc]-N] : X[P[bc]])){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            if(bl != i){
                Seg.Add(i+1,bl,i);
            }
        }
        TwoSatSolver T = new TwoSatSolver(4*N-1,Seg.vs.ToArray(),Seg.us.ToArray(),Seg.vb.ToArray(),Seg.ub.ToArray());
        return T.Answer();
    }
}
struct SegTree{
    public List<int> vs;
    public List<int> us;
    public List<bool> vb;
    public List<bool> ub;
    //???????
    public int segf;
    //segf?bit
    public int segfb;
    //?????????
    public int depth;
    //?????????????
    public int borderP;
    //????????
    public int border;
    public SegTree(int N){
        vs = new List<int>();
        us = new List<int>();
        vb = new List<bool>();
        ub = new List<bool>();
        for(depth = 1;(1 << depth) <= N;depth++){
            ;
        }
        segf = N-1;
        borderP = (1 << depth) - 2;
        border = 2*N - borderP - 2;
        segfb = border/2;
    }
    public int ToBit(int p){
        if(p >= border){
            return segfb + p - border;
        }
        else{
            return p;
        }
    }
    public int ToLeaf(int p){
        if(p >= border){
            return segf + p - border;
        }
        else{
            return borderP + p + 1;
        }
    }
    public int ToPoint(int leaf){
        if(leaf > borderP){
            return leaf - borderP - 1;
        }
        else{
            return leaf - segf + border;
        }
    }
    public void Add(int v,int u,bool bv,bool bu){
        vs.Add(v);
        us.Add(u);
        vb.Add(bv);
        ub.Add(bu);
    }
    public void Add(int l0,int r0,int v){
        int Pl = ToLeaf(l0);
        int Pr = ToLeaf(r0);
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        int cp = 0;
        int lp = Pl;
        int rp = Pr;
        while(cp < segf){
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                cp = cp*2+1;
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                cp = cp*2+2;
            }
            else{
                lp = cp*2+1;
                rp = cp*2+2;
                dl--;
                dr--;
                break;
            }
            dl--;
            dr--;
        }
        //cp?????????
        //?????
        for(;lp!=Pl;dl--){
            if((bl & (1 << dl)) == 0){
                Add(ToLeaf(v),lp*2+2,false,false);
                lp = lp*2+1;
            }
            else{
                lp = lp*2+2;
            }
        }
        Add(ToLeaf(v),Pl,false,false);
        //?????
        for(;rp!=Pr;dr--){
            if((br & (1 << dr)) == 0){
                rp = rp*2+1;
            }
            else{
                Add(ToLeaf(v),rp*2+1,false,false);
                rp = rp*2+2;
            }
        }
        Add(ToLeaf(v),Pr,false,false);
    }
}
class TwoSatSolver{
    List<int>[] G;
    int N;
    bool OK;
    public TwoSatSolver(int n,int[] vs,int[] us,bool[] vb,bool[] ub){
        N = n;
        G = new List<int>[2*N];
        for(int i=0;i<2*N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<vs.Length;i++){
            G[vs[i]+(vb[i] ? N : 0)].Add(us[i]+(ub[i] ? 0 : N));
            G[us[i]+(ub[i] ? N : 0)].Add(vs[i]+(vb[i] ? 0 : N));
        }
        StrongConnectedGraph Scc = new StrongConnectedGraph(G);
        OK = true;
        for(int i=0;i<N;i++){
            OK &= !Scc.SameAffilication(i,i+N);
        }
    }
    public bool Answer(){
        return OK;
    }
}
class StrongConnectedGraph{
    List<int>[] originalGraph;
    List<int>[] reverseGraph;
    public List<int>[] G;
    int originalN;
    public int N;
    public int[] weight;
    bool[] b;
    int[] order;
    int count;
    List<List<int>> division;
    int[] affilication;
    public StrongConnectedGraph(List<int>[] g){
        originalGraph = g;
        originalN = g.Length;
        Calc();
    }
    void Calc(){
        b = new bool[originalN];
        order = new int[originalN];
        reverseGraph = new List<int>[originalN];
        for(int i=0;i<originalN;i++){
            reverseGraph[i] = new List<int>();
        }
        for(int i=0;i<originalN;i++){
            for(int j=0;j<originalGraph[i].Count;j++){
                reverseGraph[originalGraph[i][j]].Add(i);
            }
        }
        count = 0;
        for(int i=0;i<originalN;i++){
            if(!b[i]){
                dfs1(i);
            }
        }
        count = 0;
        for(int i=0;i<originalN;i++){
            b[i] = false;
        }
        affilication = new int[originalN];
        division = new List<List<int>>();
        for(int i=originalN-1;i>=0;i--){
            if(!b[order[i]]){
                division.Add(new List<int>());
                dfs2(order[i]);
                count++;
            }
        }
        N = count;
        int[] Last = new int[N];
        weight = new int[N];
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            weight[i] = division[i].Count;
            G[i] = new List<int>();
            for(int j=0;j<division[i].Count;j++){
                int v = division[i][j];
                for(int k=0;k<originalGraph[v].Count;k++){
                    int a = affilication[originalGraph[v][k]];
                    if(Last[a] != i+1 && a != i){
                        Last[a] = i+1;
                        G[i].Add(a);
                    }
                }
            }
        }
    }
    void dfs1(int v){
        b[v] = true;
        for(int i=0;i<originalGraph[v].Count;i++){
            int t = originalGraph[v][i];
            if(!b[t]){
                dfs1(t);
            }
        }
        order[count] = v;
        count++;
    }
    void dfs2(int v){
        b[v] = true;
        division[count].Add(v);
        affilication[v] = count;
        for(int i=0;i<reverseGraph[v].Count;i++){
            int t = reverseGraph[v][i];
            if(!b[t]){
                dfs2(t);
            }
        }
    }
    public bool SameAffilication(int u,int v){
        return affilication[u] == affilication[v];
    }
}