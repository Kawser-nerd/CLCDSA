using System;
using System.Text;
using System.Collections.Generic;
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
        long K = int.Parse(str[1]);
        long[] L = new long[N];
        long[] R = new long[N];
        int eN = 0;
        long sum = 0;
        {
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                long D = int.Parse(str[0]);
                bool b = int.Parse(str[1]) == 1;
                if(b && 2*D > K){
                    sb.Append("-1\n");
                    return;
                }
                if(b){
                    L[eN] = K - ((sum + 2*D) % K);
                    R[eN] = K - (sum % K);
                    eN++;
                }
                sum += 2*D;
            }
        }
        long[] DPL = new long[eN];
        long[] DPR = new long[eN];
        long[] Points = new long[2*eN];
        int[] A = new int[2*eN];
        for(int i=0;i<eN;i++){
            Points[2*i] = L[i];
            Points[2*i+1] = R[i];
            A[2*i] = 2*i;
            A[2*i+1] = 2*i+1;
        }
        Array.Sort(Points,A);
        int[] B = new int[2*eN];
        for(int i=0;i<2*eN;i++){
            B[A[i]] = i;
        }
        SegTree Seg = new SegTree(2*eN,this);
        for(int i=4*eN-2;i>=0;i--){
            Seg.X[i] = eN;
        }
        for(int i=eN-1;i>=0;i--){
            int lp = B[2*i];
            int rp = B[2*i+1];
            int gL = Seg.Get(lp);
            DPL[i] = gL == eN ? 0 : DPR[gL] + (K + Points[B[2*gL+1]] - Points[lp]) % K;
            int gR = Seg.Get(rp);
            DPR[i] = gR == eN ? 0 : DPR[gR] + (K + Points[B[2*gR+1]] - Points[rp]) % K;
            int bf = 0;
            int bl = 2*eN;
            long C = Points[B[2*i]];
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(bc == 2*eN || C < Points[bc]){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            int l = bf;
            bf = -1;
            bl = 2*eN-1;
            C = Points[B[2*i+1]];
            while(bf != bl){
                int bc = (bf+bl+1)/2;
                if(bc == -1 || C > Points[bc]){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            int r = bf;
            if(Points[lp] < Points[rp]){
                if(l <= r){
                    Seg.Add(i,l,r);
                }
            }
            else{
                if(l != 2*eN){
                    Seg.Add(i,l,2*eN-1);
                }
                if(r != -1){
                    Seg.Add(i,0,r);
                }
            }
        }
        for(int i=4*eN-2;i>=0;i--){
            Seg.X[i] = eN;
        }
        long min = DPR[0];
        for(int i=0;i<eN;i++){
            int lp = B[2*i];
            int rp = B[2*i+1];
            int gL = Seg.Get(lp);
            if(gL == eN){
                min = Math.Min(min,DPL[i]);
            }
            int gR = Seg.Get(rp);
            if(gR == eN){
                min = Math.Min(min,DPR[i]);
            }
            int bf = 0;
            int bl = 2*eN;
            long C = Points[B[2*i]];
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(bc == 2*eN || C < Points[bc]){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            int l = bf;
            bf = -1;
            bl = 2*eN-1;
            C = Points[B[2*i+1]];
            while(bf != bl){
                int bc = (bf+bl+1)/2;
                if(bc == -1 || C > Points[bc]){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            int r = bf;
            if(Points[lp] < Points[rp]){
                if(l <= r){
                    Seg.Add(0,l,r);
                }
            } 
            else{
                if(l != 2*eN){
                    Seg.Add(0,l,2*eN-1);
                }
                if(r != -1){
                    Seg.Add(0,0,r);
                }
            }
        }
        sb.Append((min+sum)+"\n");
    }
}
struct SegTree{
    Solve Sol;
    public int[] X;
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
    public int Get(int p){
        //????
        int min = X[ToLeaf(p)];
        //????
        for(int v=ToLeaf(p);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            int sl = (v-1)/2*2+1;
            int sr = (v-1)/2*2+2;
            min = Math.Min(min,X[spa]);
        }
        return min;
    }
    //v????b????????(b???,b?ToBit????)
    void More(int C,int b,int v,int depth){
        if((b & (1 << depth)) == 0){
            //??????b?????
            if(((b+1) % (1 << depth)) != 0){
                More(C,b,v*2+1,depth-1);
                Act(C,v*2+2);
            }
            else{
                Act(C,v*2+2);
            }
        }
        else{
            //??????b??
            More(C,b,v*2+2,depth-1);
        }
    }
    //v????b????????(b???,b?ToBit????)
    void Less(int C,int b,int v,int depth){
        if((b & (1 << depth)) == 0){
            //??????b?????
            Less(C,b,v*2+1,depth-1);
        }
        else{
            //??????b??
            if(b % (1 << depth) != 0){
                Act(C,v*2+1);
                Less(C,b,v*2+2,depth-1);
            }
            else{
                //??????b??
                Act(C,v*2+1);
            }
        }
    }
    void Section(int C,int bl,int br,int v,int dl,int dr){
        if(v >= segf){
            //?
            Act(C,v);
        }
        else{
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                //???
                Section(C,bl,br,v*2+1,dl-1,dr-1);
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                //???
                Section(C,bl,br,v*2+2,dl-1,dr-1);
            }
            else{
                //????????
                if(bl % (1 << dl) != 0){
                    More(C,bl-1,v*2+1,dl-1);
                }
                else{
                    //????????
                    Act(C,v*2+1);
                }
                if((br + 1) % (1 << dl) != 0){
                    Less(C,br+1,v*2+2,dr-1);
                }
                else{
                    //????????
                    Act(C,v*2+2);
                }
            }
        }
    }
    public void Add(int C,int l0,int r0){
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(C,bl,br,0,dl,dr);
    }
    void Act(int C,int v){
        X[v] = C;
    }
}