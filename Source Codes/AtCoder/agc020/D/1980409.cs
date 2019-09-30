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
        int Q = re.i();
        for(int i=0;i<Q;i++){
            Calc(re.i(),re.i(),re.i()-1,re.i()-1);
        }
    }
    void Calc(long A,long B,int C,int D){
        long W;
        {
            long bf = 1;
            long bl = Math.Max(A,B);
            long s = Math.Min(A,B);
            long b = Math.Max(A,B);
            while(bf != bl){
                long bc = (bf+bl)/2;
                if(s*bc+bc >= b){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            W = bf;
        }
        if(A*W < B){
            long m = B-A*W;
            for(int i=C;i<=D;i++){
                if(i % (W+1) == m){
                    sb.Append('A');
                }
                else{
                    sb.Append('B');
                }
            }
        }
        else{
            long bf = 0;
            long bl = (A+B)/(W+1);
            while(bf != bl){
                long bc = (bf+bl+1)/2;
                bool OK = true;
                long Ad = A-bc*W;
                long Bd = B-bc;
                OK &= Ad >= 0;
                OK &= Bd >= 0;
                OK &= Ad*W >= Bd; 
                if(OK){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            long border1 = (W+1)*bf;
            long AAB = bf;
            A -= AAB*W;
            B -= AAB;
            bf = 0;
            bl = (A+B)/(W+1);
            while(bf != bl){
                long bc = (bf+bl+1)/2;
                bool OK = true;
                long Ad = A-bc;
                long Bd = B-bc*W;
                OK &= Bd == 0 || Ad != 0; 
                OK &= Ad >= 0;
                OK &= Bd >= 0;
                if(OK){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            long ABB = bf;
            A -= ABB;
            B -= ABB*W;
            long border2 = border1+A;
            long border3 = border2+B;
            for(int i=C;i<=D;i++){
                if(i < border1){
                    if(i % (W+1) == W){
                        sb.Append('B');
                    }
                    else{
                        sb.Append('A');
                    }
                }
                else if(i < border2){
                    sb.Append('A');
                }
                else if(i < border3){
                    sb.Append('B');
                }
                else{
                    if((i-border3) % (W+1) == 0){
                        sb.Append('A');
                    }
                    else{
                        sb.Append('B');
                    }
                }
            }
        }
        sb.Append("\n");
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