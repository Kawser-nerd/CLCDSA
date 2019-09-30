using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    ReadData re;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new ReadData();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N = re.i();
        int[] B = re.ia();
        int Q = re.i();
        Data[] D = new Data[Q];
        for(int i=0;i<Q;i++){
            D[i] = new Data(re.i()-1,re.i()-1);
        }
        Array.Sort(D,(x,y)=>(x.l-y.l));
        SegTree Seg = new SegTree(N+1,this);
        for(int i=2*N;i>=0;i--){
            if(i >= Seg.segf){
                Seg.X[i] = Seg.ToPoint(i) == 0 ? 0 : 10000000;
            }
            else{
                int sl = i*2+1;
                int sr = i*2+2;
                Seg.X[i] = Math.Min(Seg.X[sl],Seg.X[sr]);
            }
        }
        int p = 0;
        {
            while(p < Q && D[p].l == 0){
                Seg.Change(D[p].r+1,0);
                p++;
            }
        }
        for(int i=0;i<N;i++){
            if(i != 0){
                Seg.Change(i,Seg.Min(i-1,i));
            }
            if(B[i] == 1){
                Seg.Add(i,i,1);
            }
            else{
                Seg.Add(i+1,N,1);
            }
            while(p < Q && D[p].l == i+1){
                Seg.Change(D[p].r+1,Seg.Min(i,D[p].r+1));
                p++;
            }
        }
        sb.Append(Seg.Min(N-1,N)+"\n");
    }
}
struct Data{
    public int l;
    public int r;
    public Data(int l0,int r0){
        l = l0;
        r = r0;
    }
}
struct SegTree{
    Solve Sol;
    int C;
    public int[] X;
    public int[] Y;
    bool mode;
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
        X = new int[2*N-1];
        Y = new int[2*N-1];
        mode = true;
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
        if(v < segf){
            Delay(v);
        }
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
        if(v < segf){
            Adjust(v);
        }
    }
    //v????b????????(b???,b?ToBit????)
    void Less(int b,int v,int depth){
        if(v < segf){
            Delay(v);
        }
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
        if(v < segf){
            Adjust(v);
        }
    }
    void Section(int bl,int br,int v,int dl,int dr){
        if(v >= segf){
            //?
            Act(v);
        }
        else{
            Delay(v);
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
            Adjust(v);
        }
    }
    void Delay(int v){
        X[v] += Y[v];
        Y[v*2+1] += Y[v];
        Y[v*2+2] += Y[v];
        Y[v] = 0;
    }
    void Adjust(int v){
        X[v] = Math.Min(X[v*2+1]+Y[v*2+1],X[v*2+2]+Y[v*2+2]);
    }
    void Act(int v){
        if(mode){
            Y[v] += C;
        }
        else{
            C = Math.Min(C,X[v]+Y[v]);
        }
    }
    public int Min(int l0,int r0){
        C = 1000000000;
        mode = false;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
        return C;
    }
    public void Add(int l0,int r0,int value){
        mode = true;
        C = value;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
    }
    public void Change(int v,int value){
        Add(v,v,value-Min(v,v));
    }
}
class ReadData{
    string[] str;
    int counter;
    public ReadData(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}