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
        int p = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        int[] A = new int[p];
        int sum = 0;
        for(int i=0;i<N;i++){
            A[int.Parse(str[i])%p]++;
        }
        for(int i=0;i<p;i++){
            sum += i*A[i];
        }
        int count = N;
        if(p == 2){
            count -= A[0];
            count -= A[1]/2;
        }
        else if(p == 3){
            count -= A[0];
            if(A[1] >= A[2]){
                count -= A[2];
                int m = A[1] - A[2];
                count -= m/3;
            }
            else{
                count -= A[1];
                int m = A[2] - A[1];
                count -= m/3;
            }
        }
        else{
            count -= A[0];
            count -= A[2]/2;
            if(A[1] >= A[3]){
                count -= A[3];
                int m = A[1] - A[3];
                if(A[2] % 2 == 0){
                    count -= m/4;
                }
                else{
                    count -= (m+2)/4;
                }
            }
            else{
                count -= A[1];
                int m = A[3] - A[1];
                if(A[2] % 2 == 0){
                    count -= m/4;
                }
                else{
                    count -= (m+2)/4;
                }
            }
        }
        if(sum % p != 0){
            count--;
        }
        count = N-count;
        sb.Append("Case #"+q+": "+count+"\n");
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
