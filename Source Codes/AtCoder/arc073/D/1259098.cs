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
        int N = int.Parse(str[0])+1;
        int Q = int.Parse(str[1]);
        int A = int.Parse(str[2]);
        int B = int.Parse(str[3]);
        str = Console.ReadLine().Split(' ');
        SegTree SegM = new SegTree(N,this);
        SegTree SegP = new SegTree(N,this);
        {
            int q0 = int.Parse(str[0]);
            for(int i=2*N-2;i>=0;i--){
                if(i >= SegM.segf){
                    if(SegM.ToPoint(i) == A){
                        SegM.X[i] = Math.Max(q0 - B,B - q0) - SegM.ToPoint(i);
                    }
                    else if(SegM.ToPoint(i) == B){
                        SegM.X[i] = Math.Max(q0 - A,A - q0) - SegM.ToPoint(i);
                    }
                    else{
                        SegM.X[i] = Define.INF;
                    }
                }
                else{
                    int sl = i*2+1;
                    int sr = i*2+2;
                    SegM.X[i] = Math.Min(SegM.X[sl],SegM.X[sr]);
                }
            }
            for(int i=2*N-2;i>=0;i--){
                if(i >= SegP.segf){
                    if(SegP.ToPoint(i) == A){
                        SegP.X[i] = Math.Max(q0 - B,B - q0) + SegP.ToPoint(i);
                    }
                    else if(SegM.ToPoint(i) == B){
                        SegP.X[i] = Math.Max(q0 - A,A - q0) + SegP.ToPoint(i);
                    }
                    else{
                        SegP.X[i] = Define.INF;
                    } 
                }
                else{
                    int sl = i*2+1;
                    int sr = i*2+2;
                    SegP.X[i] = Math.Min(SegP.X[sl],SegP.X[sr]);
                }
            }
        }
        for(int i=1;i<Q;i++){
            int qb = int.Parse(str[i-1]);
            int q = int.Parse(str[i]);
            long V = Math.Min(SegP.GetMin(q,N-1) - q,SegM.GetMin(0,q) + q);
            SegP.AllAdd(Math.Max(qb-q,q-qb));
            SegP.Insert(qb,V+qb);
            SegM.AllAdd(Math.Max(qb-q,q-qb));
            SegM.Insert(qb,V-qb);
        }
        long count = Define.INF;
        for(int i=0;i<N;i++){
            count = Math.Min(count,SegP.X[SegP.ToLeaf(i)] - i);
        }
        count += SegP.L;
        sb.Append(count+"\n");
    }
}

struct SegTree{
    Solve Sol;
    public long[] X;
    public long L;
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
    public SegTree(int N,Solve So){
        Sol = So;
        X = new long[2*N-1];
        L = 0;
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
    //??????
    public int ToLeaf(int p){
        if(p >= border){
            return segf + p - border;
        }
        else{
            return borderP + p + 1;
        }
    }
    //??????
    public int ToPoint(int leaf){
        if(leaf > borderP){
            return leaf - borderP - 1;
        }
        else{
            return leaf - segf + border;
        }
    }
    public void Insert(int p,long C){
        int P = ToLeaf(p);
        int b = ToBit(p);
        int d = p >= border ? depth - 2 : depth - 1;
        int v = 0;
        C -= L;
        for(;v!=P;d--){
            X[v] = Math.Min(X[v],C);
            if((b & (1 << d)) == 0){
                v = v*2+1;
            }
            else{
                v = v*2+2;
            }
        }
        X[v] = Math.Min(X[v],C);
    }
    long Act(int v){
        return X[v];
    }
    //v????b????????(b???,b?ToBit????)
    long More(int b,int v,int depth){
        long min = Define.INF;
        if((b & (1 << depth)) == 0){
            //??????b?????
            if(((b+1) % (1 << depth)) != 0){
                min = Math.Min(More(b,v*2+1,depth-1),min);
                min = Math.Min(Act(v*2+2),min);
            }
            else{
                min = Math.Min(Act(v*2+2),min);
            }
        }
        else{
            //??????b??
            min = Math.Min(More(b,v*2+2,depth-1),min);
        }
        return min;
    }
    //v????b????????(b???,b?ToBit????)
    long Less(int b,int v,int depth){
        long min = Define.INF;
        if((b & (1 << depth)) == 0){
            //??????b?????
            min = Math.Min(Less(b,v*2+1,depth-1),min);
        }
        else{
            //??????b??
            if(b % (1 << depth) != 0){
                min = Math.Min(Act(v*2+1),min);
                min = Math.Min(Less(b,v*2+2,depth-1),min);
            }
            else{
                //??????b??
                min = Math.Min(Act(v*2+1),min);
            }
        }
        return min;
    }
    long Section(int bl,int br,int v,int dl,int dr){
        long min = Define.INF;
        if(v >= segf){
            //?
            min = Math.Min(Act(v),min);
        }
        else{
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                //???
                min = Math.Min(Section(bl,br,v*2+1,dl-1,dr-1),min);
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                //???
                min = Math.Min(Section(bl,br,v*2+2,dl-1,dr-1),min);
            }
            else{
                //????????
                if(bl % (1 << dl) != 0){
                    min = Math.Min(More(bl-1,v*2+1,dl-1),min);
                }
                else{
                    //????????
                    min = Math.Min(Act(v*2+1),min);
                }
                if((br + 1) % (1 << dl) != 0){
                    min = Math.Min(Less(br+1,v*2+2,dr-1),min);
                }
                else{
                    //????????
                    min = Math.Min(Act(v*2+2),min);
                }
            }
        }
        return min;
    }
    public long GetMin(int l0,int r0){
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        return L + Section(bl,br,0,dl,dr);
    }
    public void AllAdd(long p){
        L += p;
    }
}
public static class Define{
    public const long INF = 10000000000000;
}