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
        int H = re.i();
        int W = re.i();
        long[,] MaxH = new long[H+1,H+1];
        long[] sumH = new long[H+1];
        for(int i=1;i<=H;i++){
            sumH[i] = sumH[i-1] + re.i();
        }
        for(int i=0;i<=H;i++){
            for(int j=1;j<=H;j++){
                MaxH[i,j] = -10000000000000;
            }
        }
        MaxH[0,0] = 0;
        for(int i=1;i<=H;i++){
            for(int j=1;j<=i;j++){
                MaxH[i,j] = Math.Max(MaxH[i-1,j],sumH[i]-sumH[i-j]);
            }
        }
        long[,] MaxW = new long[W+1,W+1];
        long[] sumW = new long[W+1];
        for(int i=1;i<=W;i++){
            sumW[i] = sumW[i-1] + re.i();
        }
        for(int i=0;i<=W;i++){
            for(int j=1;j<=W;j++){
                MaxW[i,j] = -10000000000000;
            }
        }
        for(int i=1;i<=W;i++){
            for(int j=1;j<=i;j++){
                MaxW[i,j] = Math.Max(MaxW[i-1,j],sumW[i]-sumW[i-j]);
            }
        }
        int Q = re.i();
        for(int query=0;query<Q;query++){
            int h = re.i();
            int w = re.i();
            ConvexHullTrick Hull = new ConvexHullTrick(w);
            for(int w0=1;w0<=w;w0++){
                Hull.Add(w0,MaxW[w,w0]);
            }
            long max = -200000;
            for(int h0=1;h0<=h;h0++){
                max = Math.Max(max,Hull.Query(h0,MaxH[h,h0]));
            }
            sb.Append(max+"\n");
        }
    }
}
class ConvexHullTrick{
    long[] A;
    long[] B;
    int p;
    public ConvexHullTrick(int N){
        A = new long[N];
        B = new long[N];
        p = 0;
    }
    //a?????????????
    public void Add(long a,long b){
        while(p >= 2 && !Need(A[p-2],B[p-2],A[p-1],B[p-1],a,b)){
            p--;
        }
        A[p] = a;
        B[p] = b;
        p++;
    }
    //1??Add??????????
    public long Query(long h,long hwei){
        return Calc(h,hwei,findMax(h,hwei));
    }
    int findMax(long h,long hwei){
        int bf = 0;
        int bl = p-1;
        while(bf != bl){
            int bc = (bf+bl)/2;
            if(bc == p-1 || Calc(h,hwei,bc) >= Calc(h,hwei,bc+1)){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        return bf;
    }
    long Calc(long h,long hwei,int i){
        return A[i]*hwei + h*B[i];
    }
    //(a1,b1),(a2,b2),(a3,b3)?????(a2,b2)????
    bool Need(long a1,long b1,long a2,long b2,long a3,long b3){
        return (a2-a1)*(b2-b3) > (a3-a2)*(b1-b2);
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