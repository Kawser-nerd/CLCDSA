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
        long V = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        long[] X = new long[N];
        for(int i=0;i<N;i++){
            X[i] = int.Parse(str[i]);
        }
        int[] DPL;
        int[] DPR;
        int K;
        {
            int k = 0;
            long V0 = V;
            while(V0 > 0){
                V0 /= 2;
                k++;
            }
            K = 1 << k;
            int[,] LT = new int[k,N];
            V0 = V;
            for(int i=0;i<k;i++){
                V0 /= 2;
                int p = N-1;
                for(int j=N-1;j>=0;j--){
                    if(j != N-1 && X[j+1] - X[j] > V0){
                        p = j;
                    }
                    LT[i,j] = p;
                }
            }
            DPL = new int[1 << k];
            DPL[0] = -1;
            for(int i=1;i<1<<k;i++){
                int max = 0;
                for(int j=0;j<k;j++){
                    if((i & (1 << j)) != 0){
                        max = Math.Max(max,DPL[i - (1 << j)] == N-1 ? N-1 : LT[j,DPL[i - (1 << j)]+1]);
                    }
                }
                DPL[i] = max;
            }
            int[,] RT = new int[k,N];
            V0 = V;
            for(int i=0;i<k;i++){
                V0 /= 2;
                int p = 0;
                for(int j=0;j<N;j++){
                    if(j != 0 && X[j] - X[j-1] > V0){
                        p = j;
                    }
                    RT[i,j] = p;
                }
            }
            DPR = new int[1 << k];
            DPR[0] = N;
            for(int i=1;i<1<<k;i++){
                int min = N-1;
                for(int j=0;j<k;j++){
                    if((i & (1 << j)) != 0){
                        min = Math.Min(min,DPR[i - (1 << j)] == 0 ? 0 : RT[j,DPR[i - (1 << j)]-1]);
                    }
                }
                DPR[i] = min;
            }
        }
        int[] L = new int[K];
        int[] R = new int[K];
        for(int i=0;i<K;i++){
            L[i] = DPL[i];
            R[i] = DPR[K-1-i];
        }
        int[] P = new int[N+1];
        Array.Sort(L,R);
        {
            int p = N+1;
            int rp = K-1;
            for(int i=N-1;i>=-1;i--){
                while(rp >= 0 && L[rp] >= i){
                    p = Math.Min(p,R[rp]);
                    rp--;
                }
                P[i+1] = p;
            }
        }
        {
            int i = 0;
            while(i < N){
                int j = i;
                while(i < N - 1 && X[i+1] - X[i] <= V){
                    i++;
                }
                if(P[j] <= i+1){
                    for(;j<=i;j++){
                        sb.Append("Possible\n");
                    }
                }
                else{
                    for(;j<=i;j++){
                        sb.Append("Impossible\n");
                    }
                }
                i++;
            }
        }
    }
}