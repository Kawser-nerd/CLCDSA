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
        int N = int.Parse(Console.ReadLine());
        int[] X = new int[N];
        int[] V = new int[N];
        for(int i=0;i<N;i++){
            string[] str = Console.ReadLine().Split(' ');
            X[i] = int.Parse(str[0]);
            V[i] = int.Parse(str[1]);
        }
        Array.Sort(X,V);
        int[] DPL = new int[N];
        DPL[0] = V[0];
        for(int i=1;i<N;i++){
            DPL[i] = Math.Max(DPL[i-1],V[i]);
        }
        int[] DPR = new int[N];
        DPR[N-1] = V[N-1];
        for(int i=N-2;i>=0;i--){
            DPR[i] = Math.Min(DPR[i+1],V[i]);
        }
        Compression C = new Compression(V);
        for(int i=0;i<N;i++){
            DPL[i] = N-1 - C.ToPoint(DPL[i]);
            DPR[i] = N-1 - C.ToPoint(DPR[i]);
        }
        long[] DP = new long[N+1];
        DP[0] = 1;
        long D = 1;
        int p = 0;
        for(int i=N-1;i>=0;i--){
            while(DPL[i] > p){
                D = (D + Define.mod - DP[p]) % Define.mod;
                p++;
            }
            DP[DPR[i]+1] = (DP[DPR[i]+1] + D) % Define.mod;
            D *= 2;
            D %= Define.mod;
        }
        sb.Append(DP[N]+"\n");
    }
}
class Compression{
    public int size;
    public long[] A;
    public Compression(int[] a){
        int[] b = new int[a.Length];
        for(int i=0;i<a.Length;i++){
            b[i] = a[i];
        }
        a = b;
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