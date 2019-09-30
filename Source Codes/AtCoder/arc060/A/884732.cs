using System;
using System.Collections.Generic;
class Solve{
    public int N;
    public int[] x;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long[] dp = new long[5000];//2499?0
        for(int i=0;i<N;i++){
            dp[i]=0;
        }
        dp[2499] = 1;
        for(int i=0;i<N;i++){
            long[] dp2 = new long[5000];
            for(int j=0;j<5000;j++){
                if(j-x[i] < 5000 && j-x[i] >= 0){
                    dp2[j] = dp[j]+dp[j-x[i]];
                }
                else{
                    dp2[j] = dp[j];
                }
            }
            dp = dp2;
        }
        Console.WriteLine(dp[2499]-1);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        int A = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        x = new int[N];
        for(int i=0;i < N;i++){
            x[i] = int.Parse(str[i])-A;
        }
    }    
}