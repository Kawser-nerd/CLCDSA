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
        string S = re.s();
        int N = S.Length;
        int[] C = new int[26];
        for(int i=0;i<N;i++){
            C[S[i]-'a']++;
        }
        int odd = 0;
        for(int i=0;i<26;i++){
            if(C[i] % 2 == 1){
                odd++;
            }
        }
        if(odd > 1 || (odd == 1 && N % 2 == 0)){
            sb.Append(-1+"\n");
            return;
        }
        List<int>[] G = new List<int>[26];
        for(int i=0;i<26;i++){
            G[i] = new List<int>();
        }
        int[] order = new int[N];
        for(int i=0;i<N;i++){
            order[i] = G[S[i]-'a'].Count;
            G[S[i]-'a'].Add(i);
        }
        SegTree Seg = new SegTree(N,this);
        for(int i=2*N-2;i>=0;i--){
            if(i >= Seg.segf){
                Seg.X[i] = 1;
            }
            else{
                int sl = i*2+1;
                int sr = i*2+2;
                Seg.X[i] = Seg.X[sl] + Seg.X[sr];
            }
        }
        long count = 0;
        bool center = false;
        for(int i=0;i<N;i++){
            if(order[i]*2+1 < C[S[i]-'a']){
                int pair = G[S[i]-'a'][C[S[i]-'a']-1-order[i]];
                if(pair != N-1){
                    count += Seg.Sum(pair+1,N-1);
                }
                Seg.Delete(pair);
                if(center){
                    count++;
                }
            }
            else if(order[i]*2+1 == C[S[i]-'a']){
                center = true;
            }
        }
        sb.Append(count+"\n");
    }

}

struct SegTree{
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
    public SegTree(int N,Solve So){
        Sol = So;
        C = 0;
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
        X[ToLeaf(p)]--;
        //????
        for(int v=ToLeaf(p);v!=0;v=(v-1)/2){
            int spa = (v-1)/2;
            X[spa]--;
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
        C += X[v];
    }
    public int Sum(int l0,int r0){
        C = 0;
        int bl = ToBit(l0);
        int br = ToBit(r0);
        int dl = l0 >= border ? depth - 2 : depth - 1;
        int dr = r0 >= border ? depth - 2 : depth - 1;
        Section(bl,br,0,dl,dr);
        return C;
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