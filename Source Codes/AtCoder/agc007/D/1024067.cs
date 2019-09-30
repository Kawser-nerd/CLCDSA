using System;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        long E = long.Parse(str[1]);
        long T = long.Parse(str[2]);
        long[] x = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            x[i] = long.Parse(str[i]);
        }
        long[] dp = new long[N];
        long m = -2 * x[0];
        int p = -1;
        for(int i=0;i<N;i++){
            while(2 * x[p+1] + T < 2 * x[i]){
                p++;
                if(p != 0){
                    m = m > dp[p-1] - 2 * x[p] ? dp[p-1] - 2 * x[p] : m;
                }
            }
            if(p == -1){
                dp[i] = T;
            }
            else{
                dp[i] = T + dp[p] < 2 * x[i] + m ? T + dp[p] : 2 * x[i] + m;
            }
        }
        Console.WriteLine(E+dp[N-1]);
    }    
}