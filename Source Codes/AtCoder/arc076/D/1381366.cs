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
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        int[] L = new int[N];
        int[] R = new int[N];
        int[] C = new int[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            L[i] = int.Parse(str[0]);
            R[i] = int.Parse(str[1]);
            C[i] = i;
        }
        Array.Sort(C,(x,y)=>(R[y] - R[x]));
        int count = Math.Max(N-M,0);
        SegTree Seg = new SegTree(M+2,this);
        for(int i=2*M+2;i>=0;i--){
            if(i >= Seg.segf){
                Seg.Z[i] = -Seg.ToPoint(i); 
            }
            else{
                int sl = i*2+1;
                int sr = i*2+2;
                Seg.Z[i] = Math.Max(Seg.Z[sl],Seg.Z[sr]);
            }
        }
        int p = 0;
        for(int i=M;i>=0;i--){
            while(p < N && R[C[p]] >= i+1){
                Seg.Add(L[C[p]],M+1);
                p++;
            }
            int A = Seg.Max(0,i)-(M-i);
            count = Math.Max(count,A);
        }
        sb.Append(count+"\n");
    }
}
struct SegTree{
    Solve Sol;
    public int[] Y;
    public int[] Z;
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
        C = 0;
        Sol = So;
        Y = new int[2*N-1];
        Z = new int[2*N-1];
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
    void Act2(int v){
        C = Math.Max(Z[v],C);
    }
    void Act3(int v){
        if(v < segf){
            Z[v] = Math.Max(Z[v],Z[v*2+1]);
            Z[v] = Math.Max(Z[v],Z[v*2+2]);
        }
    }
    void Act4(int v){
        if(v < segf){
            Y[v*2+1] += Y[v];
            Y[v*2+2] += Y[v];
            Z[v*2+1] += Y[v];
            Z[v*2+2] += Y[v];
        }
        Y[v] = 0;
    }
    //v????b????????(b???,b?ToBit????)
    void More2(int b,int v,int depth){
        Act4(v);
        if((b & (1 << depth)) == 0){
            //??????b?????
            if(((b+1) % (1 << depth)) != 0){
                More2(b,v*2+1,depth-1);
                Act2(v*2+2);
            }
            else{
                Act2(v*2+2);
            }
        }
        else{
            //??????b??
            More2(b,v*2+2,depth-1);
        }
    }
    //v????b????????(b???,b?ToBit????)
    void Less2(int b,int v,int depth){
        Act4(v);
        if((b & (1 << depth)) == 0){
            //??????b?????
            Less2(b,v*2+1,depth-1);
        }
        else{
            //??????b??
            if(b % (1 << depth) != 0){
                Act2(v*2+1);
                Less2(b,v*2+2,depth-1);
            }
            else{
                //??????b??
                Act2(v*2+1);
            }
        }
    }
    void Section2(int bl,int br,int v,int dl,int dr){
        Act4(v);
        if(v >= segf){
            //?
            Act2(v);
        }
        else{
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                //???
                Section2(bl,br,v*2+1,dl-1,dr-1);
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                //???
                Section2(bl,br,v*2+2,dl-1,dr-1);
            }
            else{
                //????????
                if(bl % (1 << dl) != 0){
                    More2(bl-1,v*2+1,dl-1);
                }
                else{
                    //????????
                    Act2(v*2+1);
                }
                if((br + 1) % (1 << dl) != 0){
                    Less2(br+1,v*2+2,dr-1);
                }
                else{
                    //????????
                    Act2(v*2+2);
                }
            }
        }
    }
    public int Max(int l0,int r0){
        C = -2000000;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section2(bl,br,0,dl,dr);
        return C;
    }
    void Act(int v){
        Y[v]++;
        Z[v]++;
    }
    //v????b????????(b???,b?ToBit????)
    void More(int b,int v,int depth){
        Act4(v);
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
        Act3(v);
    }
    //v????b????????(b???,b?ToBit????)
    void Less(int b,int v,int depth){
        Act4(v);
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
        Act3(v);
    }
    void Section(int bl,int br,int v,int dl,int dr){
        Act4(v);
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
        Act3(v);
    }
    public void Add(int l0,int r0){
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
    }
}