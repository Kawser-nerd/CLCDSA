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
        int[] L = new int[M];
        int[] R = new int[M];
        int[] X = new int[M];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            L[i] = int.Parse(str[0]);
            R[i] = int.Parse(str[1]);
            X[i] = int.Parse(str[2]);
        }
        int[] Jmin = new int[N+1];
        int[] Jmax = new int[N+1];
        int[] Kmin = new int[N+1];
        int[] Kmax = new int[N+1];
        for(int i=0;i<=N;i++){
            Jmin[i] = 0;
            Jmax[i] = 500;
            Kmin[i] = 0;
            Kmax[i] = 500;
        }
        for(int i=0;i<M;i++){
            if(X[i] == 1){
                Jmax[R[i]] = Math.Min(Jmax[R[i]],L[i]-1);
            }
            else if(X[i] == 2){
                Kmax[R[i]] = Math.Min(Kmax[R[i]],L[i]-1);
                Jmin[R[i]] = Math.Max(Jmin[R[i]],L[i]);
            }
            else{
                Kmin[R[i]] = Math.Max(Kmin[R[i]],L[i]);
            }
        }
        long[,,] DP = new long[N+1,N+1,N+1];
        DP[1,0,0] = 3;
        for(int i=1;i<N;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    if(i != 0 && j == i){
                        DP[i,j,k] = 0;
                    }
                    if(j != 0 && j == k){
                        DP[i,j,k] = 0;
                    }
                    if(Jmin[i] > j || Jmax[i] < j){
                        DP[i,j,k] = 0;
                    }
                    if(Kmin[i] > k || Kmax[i] < k){
                        DP[i,j,k] = 0;
                    }
                    DP[i,j,k] %= Define.mod;
                    DP[i+1,j,k] += DP[i,j,k];
                    DP[i+1,i,j] += DP[i,j,k];
                    DP[i+1,i,k] += DP[i,j,k];
                }
            }
            
        }
        long count = 0;
        for(int j=0;j<N;j++){
            for(int k=0;k<=j;k++){
                if(j != 0 && j == k){
                    continue;
                }
                if(Jmin[N] > j || Jmax[N] < j){
                    continue;
                }
                if(Kmin[N] > k || Kmax[N] < k){
                    continue;
                }
                count += DP[N,j,k];
            }
        }
        count %= Define.mod;
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}