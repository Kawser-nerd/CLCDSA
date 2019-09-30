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
        N++;
        int K = int.Parse(str[1]);
        double[] P = new double[N];
        double U = double.Parse(Console.ReadLine());
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N-1;i++){
            P[i] = double.Parse(str[i]);
        }
        P[N-1] = 1;
        Array.Sort(P);
        double S = 0;
        bool b = true;
        for(int i=0;i<N-1;i++){
            if(S + (i+1)*(P[i+1]-P[i]) >= U){
                double SP = P[i+1] + (U - S - (i+1)*(P[i+1]-P[i]))/(i+1);
                for(int j=0;j<=i;j++){
                    P[j] = SP;
                }
                b = false;
                break;
            }
            else{
                S += (i+1)*(P[i+1]-P[i]);
            }
        }
        if(b){
            sb.Append("Case #"+q+": ");
            sb.Append(1+"\n");
            return ;
        }
        double QP = 1;
        for(int i=0;i<N;i++){
            QP *= P[i];
        }
        sb.Append("Case #"+q+": ");
        sb.Append(QP+"\n");
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
