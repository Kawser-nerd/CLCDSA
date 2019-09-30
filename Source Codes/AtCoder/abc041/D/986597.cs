using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    int M;
    int[] x;
    int[] y;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        bool[,] b = new bool[N,N];
        long[] dp = new long[1 << N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                b[i,j] = false;
            }
        }
        for(int i=0;i<M;i++){
            b[x[i],y[i]] = true;
        }
        for(int i=0;i<(1 << N);i++){
            if(i == 0){
                dp[i] = 1;
            }
            else{
                long sum = 0;
                for(int j=0;j<N;j++){
                    if((i & (1 << j)) != 0){
                        bool c = false;
                        for(int k=0;k<N;k++){
                            if((i & (1 << k)) != 0){
                                c |= b[j,k];
                            }
                        }
                        if(!c){
                            sum += dp[i-(1 << j)];
                        }
                    }
                }
                dp[i] = sum;
            }
        }
        sb.Append(dp[(1 << N)-1]+"\n");
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        x = new int[M];
        y = new int[M];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            x[i] = int.Parse(str[0])-1;
            y[i] = int.Parse(str[1])-1;
        }
    }    
}