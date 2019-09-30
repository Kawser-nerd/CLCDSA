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
        int Q = int.Parse(Console.ReadLine());
        for(int q=0;q<Q;q++){
            Calc(q+1);
        }
        Console.Write(sb.ToString());
    }
    void Calc(int q){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int K = int.Parse(str[1]);
        long[] R = new long[N];
        long[] H = new long[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            R[i] = int.Parse(str[0]);
            H[i] = int.Parse(str[1]);
        }
        long[] S = new long[N];
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            S[i] = 2*R[i]*H[i];
            A[i] = i;
        }
        Array.Sort(S,A);
        long max = 0;
        for(int i=0;i<N;i++){
            long s = R[i]*R[i]+2*R[i]*H[i];
            int k=0;
            for(int j=N-1;k<K-1;j--){
                if(A[j] != i){
                    k++;
                    s += S[j];
                }
            }
            max = Math.Max(max,s);
        }
        double count = max * Math.PI;
        sb.Append("Case #"+q+": ");
        sb.Append(count+"\n");
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
