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
        Data[] D = new Data[N];
        for(int i=0;i<N;i++){
            D[i] = new Data(re.i(),re.i());
        }
        Data[] L = new Data[N];
        Data[] R = new Data[N];
        for(int i=0;i<N;i++){
            L[i] = D[i];
            R[i] = D[i];
        }
        Array.Sort(L,(x,y)=>(x.L-y.L));
        Array.Sort(R,(x,y)=>(x.R-y.R));
        long count1 = 0;
        {
            int p = 0;
            int lp = N-1;
            int rp = 0;
            bool reverse = true;
            while(lp != -1 || rp != N){
                if(reverse){
                    while(rp != N && (R[rp].used || R[rp].R >= p)){
                        rp++;
                    }
                    if(rp != N){
                        count1 += p - R[rp].R;
                        p = R[rp].R;
                        R[rp].used = true;
                    }
                    reverse = !reverse;
                }
                else{
                    while(lp != -1 && (L[lp].used || L[lp].L <= p)){
                        lp--;
                    }
                    if(lp != -1){
                        count1 += L[lp].L - p;
                        p = L[lp].L;
                        L[lp].used = true;
                    }
                    reverse = !reverse;
                }
            }
            count1 += Math.Max(p,-p);
        }
        for(int i=0;i<N;i++){
            D[i].used = false;
        }
        long count2 = 0;
        {
            int p = 0;
            int lp = N-1;
            int rp = 0;
            bool reverse = false;
            while(lp != -1 || rp != N){
                if(reverse){
                    while(rp != N && (R[rp].used || R[rp].R >= p)){
                        rp++;
                    }
                    if(rp != N){
                        count2 += p - R[rp].R;
                        p = R[rp].R;
                        R[rp].used = true;
                    }
                    reverse = !reverse;
                }
                else{
                    while(lp != -1 && (L[lp].used || L[lp].L <= p)){
                        lp--;
                    }
                    if(lp != -1){
                        count2 += L[lp].L - p;
                        p = L[lp].L;
                        L[lp].used = true;
                    }
                    reverse = !reverse;
                }
            }
            count2 += Math.Max(p,-p);
        }
        long count = Math.Max(count1,count2);
        sb.Append(count+"\n");
    }
}
class Data{
    public int L;
    public int R;
    public bool used;
    public Data(int l,int r){
        L = l;
        R = r;
        used = false;
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