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
        long x1 = int.Parse(str[0]);
        long y1 = int.Parse(str[1]);
        long x2 = int.Parse(str[2]);
        long y2 = int.Parse(str[3]);
        int N = int.Parse(Console.ReadLine());
        double count;
        if(x1 == x2){
            bool b = false;
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                long X = int.Parse(str[0]);
                if(x1 == X){
                    long Y = int.Parse(str[1]);
                    if(Math.Min(y1,y2) < Y && Y < Math.Max(y1,y2)){
                        b = true;
                    }
                    break;
                }
            }
            count = (Math.Max(y1,y2) - Math.Min(y1,y2)) * 100 + (b ? (20*(Math.PI/2-1)) : 0);
        }
        else if(y1 == y2){
            bool b = false;
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                long Y = int.Parse(str[1]);
                if(y1 == Y){
                    long X = int.Parse(str[0]);
                    if(Math.Min(x1,x2) < X && X < Math.Max(x1,x2)){
                        b = true;
                    }
                    break;
                }
            }
            count = (Math.Max(x1,x2) - Math.Min(x1,x2)) * 100 + (b ? (20*(Math.PI/2-1)) : 0);
        }
        else{
            long[] xp = new long[N];
            long[] yp = new long[N];
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                long X = int.Parse(str[0]);
                if(x1 > x2){
                    X = 100000000-1-X;
                }
                long Y = int.Parse(str[1]);
                if(y1 > y2){
                    Y = 100000000-1-Y;
                }
                xp[i] = X;
                yp[i] = Y;
            }
            if(x1 > x2){
                x1 = 100000000-1-x1;
                x2 = 100000000-1-x2;
            }
            if(y1 > y2){
                y1 = 100000000-1-y1;
                y2 = 100000000-1-y2;
            }
            long[] DX;
            long[] DY;
            Compression YC;
            {
                List<long> LX = new List<long>();
                List<long> LY = new List<long>();
                for(int i=0;i<N;i++){
                    if(x1 <= xp[i] && xp[i] <= x2 && y1 <= yp[i] && yp[i] <= y2){
                        LX.Add(xp[i]);
                        LY.Add(yp[i]);
                    }
                }
                DX = LX.ToArray();
                DY = LY.ToArray();
                YC = new Compression(LY.ToArray());
            }
            Array.Sort(DX,DY);
            if(DY.Length != 0){
                bool b1 = (DY[0] == y1 && DY[DY.Length-1] == y2);
                bool b2 = (DX[0] == x1 && DX[DX.Length-1] == x2);
                for(int i=1;i<DY.Length;i++){
                    b2 &= DX[i] == DX[i-1]+1 && DY[i] > DY[i-1];
                    b1 &= DY[i] == DY[i-1]+1;
                }
                SegTree Seg = new SegTree(YC.size,this);
                for(int i=0;i<DY.Length;i++){
                    int YP = YC.ToPoint(DY[i]);
                    Seg.Add(YP,Seg.Max(0,YP)+1);
                }
                count = (y2-y1+x2-x1) * 100 - (20 - 5*Math.PI) * Seg.Max(0,YC.size-1) + ((b1 || b2) ? 5*Math.PI : 0);
            }
            else{
                count = (y2-y1+x2-x1) * 100;
            }
        }
        sb.Append(count+"\n");
    }
}
struct SegTree{
    Solve Sol;
    public int[] X;
    int C;
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
        X = new int[2*N-1];
        C = 0;
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
    public void Add(int p,int C0){
        //????
        X[ToLeaf(p)] = C0;
        //????
        for(int v=ToLeaf(p);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            X[spa] = Math.Max(X[spa],C0);
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
    void Act(int v){
        C = Math.Max(C,X[v]);
    }
    public int Max(int l0,int r0){
        C = 0;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
        return C;
    }
}
class Compression{
    public int size;
    public long[] A;
    public Compression(long[] a){
        if(a.Length == 0){
            size = 0;
            return;
        }
        Array.Sort(a);
        List<long> AL = new List<long>();
        AL.Add(a[0]);
        for(int i=1;i<a.Length;i++){
            if(a[i] != a[i-1]){
                AL.Add(a[i]);
            }
        }
        A = AL.ToArray();
        size = A.Length;
    }
    public int ToPoint(long X){
        int bf = 0;
        int bl = size-1;
        while(bf != bl){
            int bc = (bf+bl)/2;
            if(A[bc] >= X){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        return bf;
    }
    public long Value(int i){
        return A[i];
    }
}