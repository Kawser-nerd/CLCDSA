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
        int C = int.Parse(str[1]);
        int M = int.Parse(str[2]);
        int[] A = new int[C];
        int[] P = new int[N];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            P[int.Parse(str[0])-1]++;
            A[int.Parse(str[1])-1]++;
        }
        int MaxC = 0;
        for(int i=0;i<C;i++){
            MaxC = Math.Max(MaxC,A[i]);
        }
        int X;
        {
            int bf = 0;
            int bl = M;
            while(bf != bl){
                int bc = (bf+bl)/2;
                bool b = true;
                {
                    int c = 0;
                    for(int i=0;i<N;i++){
                        c += P[i];
                        if(c > bc){
                            b = false;
                            break;
                        }
                        c -= bc;
                    }
                }
                if(b){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            X = bf;
        }
        X = Math.Max(X,MaxC);
        int Y = 0;
        for(int i=0;i<N;i++){
            Y += Math.Max(0,P[i] - X);
        }
        sb.Append("Case #"+q+": "+X+" "+Y+"\n");
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
