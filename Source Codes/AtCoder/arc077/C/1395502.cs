using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    int N;
    int M;
    int[] A;
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
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        SegTree Seg = new SegTree(M+2,this);
        for(int i=0;i<N-1;i++){
            if(A[i] < A[i+1]){
                Seg.Add(A[i]+1,A[i+1],A[i+1]+1,-1);
                Seg.Add(A[i+1]+1,M+1,A[i+1]-A[i],0);
                Seg.Add(0,A[i],A[i+1]-A[i],0);
            }
            else{
                Seg.Add(A[i+1]+1,A[i],A[i+1]-A[i]+M,0);
                Seg.Add(A[i]+1,M+1,A[i+1]+1+M,-1);
                Seg.Add(0,A[i+1],A[i+1]+1,-1);
            }
        }
        long count = 1000000000000;
        for(int i=1;i<=M;i++){
            count = Math.Min(Seg.Get(i),count);
        }
        sb.Append(count + "\n");
    }
}
struct SegTree{
    Solve Sol;
    public long[] X;
    public int[] Y;
    int V;
    int W;
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
        V = 0;
        W = 0;
        Sol = So;
        X = new long[2*N-1];
        Y = new int[2*N-1];
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
    public long Get(int p){
        long x = 0;
        long y = 0;
        //????
        x += X[ToLeaf(p)];
        y += Y[ToLeaf(p)];
        //????
        for(int v=ToLeaf(p);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            x += X[spa];
            y += Y[spa];
        }
        return p*y+x;
    }
    //v????b????????(b???,b?ToBit????)
    void More(int b,int v,int depth){
        if((b & (1 << depth)) == 0){
            //??????b?????
            if(((b+1) % (1 << depth)) != 0){
                More(b,v*2+1,depth-1);
                Act(v*2+2);
            }
            else{
                Act(v*2+2);
            }
        }
        else{
            //??????b??
            More(b,v*2+2,depth-1);
        }
    }
    //v????b????????(b???,b?ToBit????)
    void Less(int b,int v,int depth){
        if((b & (1 << depth)) == 0){
            //??????b?????
            Less(b,v*2+1,depth-1);
        }
        else{
            //??????b??
            if(b % (1 << depth) != 0){
                Act(v*2+1);
                Less(b,v*2+2,depth-1);
            }
            else{
                //??????b??
                Act(v*2+1);
            }
        }
    }
    void Section(int bl,int br,int v,int dl,int dr){
        if(v >= segf){
            //?
            Act(v);
        }
        else{
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                //???
                Section(bl,br,v*2+1,dl-1,dr-1);
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                //???
                Section(bl,br,v*2+2,dl-1,dr-1);
            }
            else{
                //????????
                if(bl % (1 << dl) != 0){
                    More(bl-1,v*2+1,dl-1);
                }
                else{
                    //????????
                    Act(v*2+1);
                }
                if((br + 1) % (1 << dl) != 0){
                    Less(br+1,v*2+2,dr-1);
                }
                else{
                    //????????
                    Act(v*2+2);
                }
            }
        }
    }
    public void Add(int l0,int r0,int V0,int W0){
        V = V0;
        W = W0;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
    }
    void Act(int v){
        X[v] += V;
        Y[v] += W; 
    }
}