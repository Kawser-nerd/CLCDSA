using System;
using System.Text;
using System.Collections.Generic;
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
        int K = int.Parse(str[1]);
        long[] U = new long[1 << N];
        {
            int[,] u = new int[N,N];
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                for(int j=0;j<N;j++){
                    u[i,j] = int.Parse(str[j]);
                }
            }
            for(int i=0;i<1 << N;i++){
                List<int> l = new List<int>();
                for(int j=0;j<N;j++){
                    if((i & (1 << j)) != 0){
                        l.Add(j);
                    }
                }
                if(l.Count == 0 || l.Count == 1){
                    U[i] = 0;
                }
                else{
                    long sum = U[i-(1 << l[0])];
                    for(int j=1;j<l.Count;j++){
                        sum += u[l[0],l[j]];
                    }
                    U[i] = sum;
                }
            }
        }
        long[] dp = new long[1 << N];
        for(int i=0;i<1 << N;i++){
            if(i == 0){
                dp[i] = 0;
            }
            else{
                long max = 0;
                for(int j=i;j>0;j=(j-1)&i){
                    long v = K+dp[i-j]-(U[i]-U[j]-U[i-j]);
                    max = max < v ? v : max;
                }
                dp[i] = max;
            }
        }
        sb.Append(dp[(1 << N) - 1]+"\n");
    }
}