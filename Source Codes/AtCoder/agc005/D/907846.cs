using System;
using System.Collections.Generic;
class Solve{
    int N;
    int K;
    const long mod = 924844033;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long count = 0;
        int length = (2*N-2*K)/(2*K);
        int larger = 2*N-2*K - (2*K)*length;
        int smaller = 2*K-larger;
        long[,] dp = new long[2*N,N+1];
        long[] fact = new long[N+1];
        for(int i=1;i<N+1;i++){
            dp[0,i] = 0;
            dp[1,i] = 0;
        }
        dp[1,1] = 1;
        for(int i=0;i<2*N;i++){
            dp[i,0] = 1;
        }
        for(int i=2;i<2*N;i++){
            if((i <= (length+2)*larger && i%(length+2) == 0) || ((i > (length+2)*larger) && ((i - (length+2)*larger)%(length+1) == 0))){
                for(int j=0;j<N+1;j++){
                    dp[i,j] = dp[i-1,j];
                }
            }
            else{
                for(int j=1;j<N+1;j++){
                    dp[i,j] = (dp[i-1,j]+dp[i-2,j-1])%mod;
                }
            }
        }
        {
            fact[0] = 1;
            for(int i=1;i<N+1;i++){
                fact[i] = i*fact[i-1]%mod;
            }    
        }
        for(int i=1;i<N+1;i++){
            if(i%2==0){
                count = (count - (fact[N-i]*dp[2*N-1,i])%mod + mod)%mod;
            }
            else{
                count = (count + (fact[N-i]*dp[2*N-1,i])%mod)%mod;
            }
        }
        Console.WriteLine((fact[N]-count+mod)%mod);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        K = int.Parse(str[1]);
    }    
}