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
        int Ac = int.Parse(str[0]);
        int Aj = int.Parse(str[1]);
        bool[] bC = new bool[1440];
        bool[] bJ = new bool[1440];
        for(int i=0;i<Ac;i++){
            str = Console.ReadLine().Split(' ');
            for(int j=int.Parse(str[0]);j<int.Parse(str[1]);j++){
                bC[j] = true;
            }
        }
        for(int i=0;i<Aj;i++){
            str = Console.ReadLine().Split(' ');
            for(int j=int.Parse(str[0]);j<int.Parse(str[1]);j++){
                bJ[j] = true;
            }
        }
        int count = 1444;
        for(int b=0;b<2;b++){
            int[,,] DP = new int[1440,721,2];
            for(int i=0;i<1440;i++){
                for(int j=0;j<=720;j++){
                    for(int k=0;k<2;k++){
                        DP[i,j,k] = 1444;
                    }
                }
            }
            if(b == 0){
                DP[0,1,0] = 0;
                DP[0,0,1] = 1;
            }  
            else{
                DP[0,1,0] = 1;
                DP[0,0,1] = 0;
            }
            for(int i=0;i<1439;i++){
                for(int j=0;j<=720;j++){
                    for(int k=0;k<2;k++){
                        if(k == 0 && bC[i]){
                            continue;
                        }
                        if(k == 1 && bJ[i]){
                            continue;
                        }
                        if(k == 0){
                            if(j != 720){
                                DP[i+1,j+1,0] = Math.Min(DP[i+1,j+1,0],DP[i,j,0]);
                            }
                            DP[i+1,j,1] = Math.Min(DP[i,j,0] + 1,DP[i+1,j,1]);
                        }
                        else{
                            if(j != 720){
                                DP[i+1,j+1,0] = Math.Min(DP[i,j,1] + 1,DP[i+1,j+1,0]);
                            }
                            DP[i+1,j,1] = Math.Min(DP[i,j,1],DP[i+1,j,1]);
                        }
                    }
                }
            }
            if(b == 0){
                if(!bC[1439] && DP[1439,720,0] != 1444){
                    count = Math.Min(count,DP[1439,720,0]);
                }
            }
            else{
                if(!bJ[1439] && DP[1439,720,1] != 1444){
                    count = Math.Min(count,DP[1439,720,1]);
                }
            }
        }
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
