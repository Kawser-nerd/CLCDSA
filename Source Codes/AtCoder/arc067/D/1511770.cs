using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    int N;
    long[,] Map;
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
        int M = int.Parse(str[1]);
        long[] A = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N-1;i++){
            A[i+1] = A[i] + int.Parse(str[i]);
        }
        long[,] B = new long[N,M];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            for(int j=0;j<M;j++){
                B[i,j] = int.Parse(str[j]);
            }
        }
        Map = new long[N,N];
        RangeMinimumQuerry RMQ = new RangeMinimumQuerry(N,this);
        for(int j=0;j<M;j++){
            for(int i=2*N-2;i>=0;i--){
                if(i >= RMQ.segf){
                    RMQ.X[i] = B[RMQ.ToPoint(i),j];
                    RMQ.Y[i] = RMQ.ToPoint(i);
                }
                else{
                    int sl = i*2+1;
                    int sr = i*2+2;
                    if(RMQ.X[sl] > RMQ.X[sr]){
                        RMQ.X[i] = RMQ.X[sl];
                        RMQ.Y[i] = RMQ.Y[sl];
                    }
                    else{
                        RMQ.X[i] = RMQ.X[sr];
                        RMQ.Y[i] = RMQ.Y[sr];
                    }
                }
            }
            F(RMQ,0,N-1);
        }
        long max = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Map[i,j] += (i == 0 ? 0 : Map[i-1,j]) + (j == 0 ? 0 : Map[i,j-1]) - ((i == 0 || j == 0) ? 0 : Map[i-1,j-1]);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                max = Math.Max(max,Map[i,j]+A[i]-A[j]);
            }
        }
        sb.Append(max+"\n");
    }
    void F(RangeMinimumQuerry RMQ,int l,int r){
        RMQ.Querry(l,r);
        int s = RMQ.C;
        Add(l,s,s,r,RMQ.D);
        if(s != l){
            F(RMQ,l,s-1);
        }
        if(s != r){
            F(RMQ,s+1,r);
        }
    }
    void Add(int x1,int x2,int y1,int y2,long C){
        Map[x1,y1] += C;
        if(x2 != N-1){
            Map[x2+1,y1] -= C;
        }
        if(y2 != N-1){
            Map[x1,y2+1] -= C;
        }
        if(x2 != N-1 && y2 != N-1){
            Map[x2+1,y2+1] += C;
        }
    }
}
class RangeMinimumQuerry{
    Solve Sol;
    public long[] X;
    public int[] Y;
    public int C;
    public long D;
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
    public RangeMinimumQuerry(int N,Solve So){
        Sol = So;
        C = 0;
        D = 0;
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
    public void Querry(int l0,int r0){
        D = 0;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
    }
    void Act(int v){
        if(D < X[v]){
            D = X[v];
            C = Y[v];
        }
    }
}