using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    SegTree Seg1;
    SegTree Seg2;
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
        int N = int.Parse(Console.ReadLine());
        int[] p = new int[N];
        int[] rp = new int[N];
        int[] q = new int[N];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            p[i] = int.Parse(str[i]) - 1;
            rp[int.Parse(str[i]) - 1] = i;
        }
        SegTree Seg1 = new SegTree(N/2,this,true);
        for(int i=N-2;i>=0;i--){
            if(i >= Seg1.segf){
                Seg1.X[i] = p[Seg1.ToPoint(i)*2];
            }
            else{
                int sl = i*2+1;
                int sr = i*2+2;
                Seg1.X[i] = Math.Min(Seg1.X[sl],Seg1.X[sr]);
            }
        }
        SegTree Seg2 = new SegTree(N/2,this,false);
        for(int i=N-2;i>=0;i--){
            if(i >= Seg2.segf){
                Seg2.X[i] = p[Seg2.ToPoint(i)*2+1];
            }
            else{
                int sl = i*2+1;
                int sr = i*2+2;
                Seg2.X[i] = Math.Min(Seg2.X[sl],Seg2.X[sr]);
            }
        }
        Heap H = new Heap(N);
        {   
            int min1 = rp[Seg1.Min(0,N-1)];
            int min2 = rp[Seg2.Min(min1+1,N-1)];
            H.push(new Data(0,N-1,min1,min2,p[min1]));
            Seg1.Delete(min1);
            Seg2.Delete(min2);
        }
        int pointer = 0;
        while(pointer < N){
            Data D = H.pop();
            q[pointer] = p[D.fp]+1;
            q[pointer+1] = p[D.sp]+1;
            pointer += 2;
            if(D.fp != D.f){
                int min1;
                int min2;
                if(D.f % 2 == 0){
                    min1 = rp[Seg1.Min(D.f,D.fp-1)];
                    min2 = rp[Seg2.Min(min1+1,D.fp-1)];
                    Seg1.Delete(min1);
                    Seg2.Delete(min2);
                }
                else{
                    min1 = rp[Seg2.Min(D.f,D.fp-1)];
                    min2 = rp[Seg1.Min(min1+1,D.fp-1)];
                    Seg2.Delete(min1);
                    Seg1.Delete(min2);
                }
                H.push(new Data(D.f,D.fp-1,min1,min2,p[min1]));
            }
            if(D.sp != D.l){
                int min1;
                int min2;
                if((D.sp+1) % 2 == 0){
                    min1 = rp[Seg1.Min(D.sp+1,D.l)];
                    min2 = rp[Seg2.Min(min1+1,D.l)];
                    Seg1.Delete(min1);
                    Seg2.Delete(min2);
                }
                else{
                    min1 = rp[Seg2.Min(D.sp+1,D.l)];
                    min2 = rp[Seg1.Min(min1+1,D.l)];
                    Seg2.Delete(min1);
                    Seg1.Delete(min2);
                }
                H.push(new Data(D.sp+1,D.l,min1,min2,p[min1]));
            }
            if(D.fp+1 != D.sp){
                int min1;
                int min2;
                if((D.fp+1) % 2 == 0){
                    min1 = rp[Seg1.Min(D.fp+1,D.sp-1)];
                    min2 = rp[Seg2.Min(min1+1,D.sp-1)];
                    Seg1.Delete(min1);
                    Seg2.Delete(min2);
                }
                else{
                    min1 = rp[Seg2.Min(D.fp+1,D.sp-1)];
                    min2 = rp[Seg1.Min(min1+1,D.sp-1)];
                    Seg2.Delete(min1);
                    Seg1.Delete(min2);
                }
                H.push(new Data(D.fp+1,D.sp-1,min1,min2,p[min1]));
            }
        }
        for(int i=0;i<N;i++){
            sb.Append(q[i]);
            if(i == N-1){
                sb.Append("\n");
            }
            else{
                sb.Append(" ");
            }
        }
    }
}
struct Data{
    public int f;
    public int l;
    public int fp;
    public int sp;
    public int p;
    public Data(int f0,int s0,int fv0,int sv0,int p0){
        f = f0;
        l = s0;
        fp = fv0;
        sp = sv0;
        p = p0;
    }
}
class Heap{
    public int size;
    Data[] obj;

    public Heap(int maxsize){
        size = 0;
        obj = new Data[maxsize];
    }
    public bool Compare(Data a,Data b){
        return a.p <= b.p;
    }
    public void push(Data a){
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
    public Data pop(){
        Data t = obj[0];
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
struct SegTree{
    bool b;
    Solve Sol;
    int C;
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
    public SegTree(int N,Solve So,bool b0){
        b = b0;
        C = 0;
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
    public void Delete(int p){
        //????
        X[ToLeaf(p/2)] = 1000000000; 
        //????
        for(int v=ToLeaf(p/2);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            int sl = (v-1)/2*2+1;
            int sr = (v-1)/2*2+2;
            X[spa] = Math.Min(X[sl],X[sr]);
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
        C = Math.Min(C,X[v]);
    }
    public int Min(int l0,int r0){
        if(b){
            if(l0 % 2 == 1){
                l0++;
            }
            if(r0 % 2 == 1){
                r0--;
            }
        }
        else{
            if(l0 % 2 == 0){
                l0++;
            }
            if(r0 % 2 == 0){
                r0--;
            }
        }
        l0 /= 2;
        r0 /= 2;
        C = 1000000000;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
        return C;
    }
}