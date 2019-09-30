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
        long[,] cost = new long[N,N];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int A = int.Parse(str[0])-1;
            int B = int.Parse(str[1])-1;
            int C = int.Parse(str[2]);
            cost[A,B] = C;
            cost[B,A] = C;
        }
        long[] SC = new long[1 << N];
        for(int i=1;i<1 << N;i++){
            long count = 0;
            for(int j=0;j<N;j++){
                if(((1 << j) & i) != 0){
                    count += SC[i-(1 << j)];
                    for(int k=j+1;k<N;k++){
                        if(((1 << k) & i) != 0){
                            count += cost[j,k];
                        }
                    }
                    break;
                }
            }
            SC[i] = count;
        }
        long[,] DP = new long[1 << N,N];
        for(int i=1;i<N;i++){
            DP[0,i] = 10000000000;
        }
        for(int i=1;i<1 << N;i++){
            for(int j=0;j<N;j++){
                DP[i,j] = 10000000000;
                if(((1 << j) & i) != 0 || (i % 2 == 0 && j != 0)){
                    continue;
                }
                for(int k=0;k<N;k++){
                    if(((1 << k) & i) != 0 && cost[k,j] != 0){
                        DP[i,j] = Math.Min(DP[i-(1 << k),k]-SC[i-(1 << k)]+SC[i-(1 << k)+(1 << j)],DP[i,j]);
                    }
                }
                for(int k=i;k != 0;k = (k-1) & i){
                    DP[i,j] = Math.Min(DP[i-k,j]+SC[i]-SC[k]-SC[i-k],DP[i,j]);
                }
            }
        }
        sb.Append(DP[(1 << (N-1))-1,N-1]+"\n");
    }
}