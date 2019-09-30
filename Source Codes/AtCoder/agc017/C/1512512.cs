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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        int[] A = new int[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        int count = 0;
        int[] C = new int[N+1];
        int[] D = new int[2*N+1];
        for(int i=0;i<N;i++){
            if(D[A[i]-C[A[i]]+N] != 0 || A[i] <= C[A[i]] ){
                count++;
            }
            D[A[i]-C[A[i]]+N]++;
            C[A[i]]++;
        }
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int X = int.Parse(str[0])-1;
            int Y = int.Parse(str[1]);
            int old = A[X];
            C[old]--;
            D[old-C[old]+N]--;
            if(D[old-C[old]+N] != 0 || old <= C[old]){
                count--;
            }
            A[X] = Y;
            if(D[Y-C[Y]+N] != 0 || Y <= C[Y]){
                count++;
            }
            D[Y-C[Y]+N]++;
            C[Y]++;
            sb.Append(count + "\n");
        }
    }
}