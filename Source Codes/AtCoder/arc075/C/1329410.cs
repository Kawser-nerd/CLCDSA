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
        long K = int.Parse(str[1]);
        long[] A = new long[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(Console.ReadLine()) - K;
        }
        N++;
        long[] sum = new long[N];
        for(int i=1;i<N;i++){
            sum[i] = sum[i-1] + A[i-1];
        }
        long[] B = new long[N];
        int[] C = new int[N];
        for(int i=0;i<N;i++){
            B[i] = sum[i];
            C[i] = i;
        }
        Array.Sort(C,(x,y)=>(B[x] > B[y] ? 1 : (B[x] == B[y] ? (x > y ? 1 : (x == y ? 0 : -1)) : -1)));
        SegTree Seg = new SegTree(N,this);
        long count = 0;
        for(int i=N-1;i>=0;i--){
            
            count += Seg.Sum(C[i],N-1);
            Seg.Add(C[i]);
        }
        sb.Append(count+"\n");
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
    public void Add(int p){
        //????
        X[ToLeaf(p)]++;
        //????
        for(int v=ToLeaf(p);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            X[spa]++;
        }
    }
    //v????b????????(b???,b?ToBit????)
    int More(int b,int v,int depth){
        int count = 0;
        if((b & (1 << depth)) == 0){
            //??????b?????
            if(((b+1) % (1 << depth)) != 0){
                count += More(b,v*2+1,depth-1);
                count += Act(v*2+2);
            }
            else{
                count += Act(v*2+2);
            }
        }
        else{
            //??????b??
            count += More(b,v*2+2,depth-1);
        }
        return count;
    }
    //v????b????????(b???,b?ToBit????)
    int Less(int b,int v,int depth){
        int count = 0;
        if((b & (1 << depth)) == 0){
            //??????b?????
            count += Less(b,v*2+1,depth-1);
        }
        else{
            //??????b??
            if(b % (1 << depth) != 0){
                count += Act(v*2+1);
                count += Less(b,v*2+2,depth-1);
            }
            else{
                //??????b??
                count += Act(v*2+1);
            }
        }
        return count;
    }
    int Section(int bl,int br,int v,int dl,int dr){
        int count = 0;
        if(v >= segf){
            //?
            count += Act(v);
        }
        else{
            if((bl & (1 << dl)) == 0 && (br & (1 << dr)) == 0){
                //???
                count += Section(bl,br,v*2+1,dl-1,dr-1);
            }
            else if((bl & (1 << dl)) != 0 && (br & (1 << dr)) != 0){
                //???
                count += Section(bl,br,v*2+2,dl-1,dr-1);
            }
            else{
                //????????
                if(bl % (1 << dl) != 0){
                    count += More(bl-1,v*2+1,dl-1);
                }
                else{
                    //????????
                    count += Act(v*2+1);
                }
                if((br + 1) % (1 << dl) != 0){
                    count += Less(br+1,v*2+2,dr-1);
                }
                else{
                    //????????
                    count += Act(v*2+2);
                }
            }
        }
        return count;
    }
    public int Sum(int l0,int r0){
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        return Section(bl,br,0,dl,dr);
    }
    public int Act(int v){
        return X[v];
    }
}