using System;
using System.Collections.Generic;
class Solve{
    int N;
    int C;
    int[] a;
    int[] b;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long[,] pow = new long[401,C+1];
        long[,] powsum = new long[401,C+1];
        long[,] dp = new long[N+1,C+1];
        for(int i=0;i<401;i++){
            for(int j=0;j<C+1;j++){
                if(j == 0){
                    pow[i,j] = 1;
                }
                else{
                    pow[i,j] = (pow[i,j-1]*i)%Define.mod;
                }
            }
        }
        for(int i=0;i<401;i++){
            for(int j=0;j<C+1;j++){
                if(i == 0){
                    powsum[i,j] = pow[i,j]; 
                }
                else{
                    powsum[i,j] = (pow[i,j]+powsum[i-1,j])%Define.mod;
                }
            }
        }
        for(int i=0;i<N+1;i++){
            for(int j=0;j<C+1;j++){
                if(i == 0 && j == 0){
                    dp[i,j] = 1;
                }
                else if(j == 0){
                    dp[i,j] = (b[i-1]-a[i-1]+1)*dp[i-1,j]%Define.mod;
                }
                else if(i == 0){
                    dp[i,j] = 0;
                }
                else{
                    long count = dp[i-1,j]*(b[i-1]-a[i-1]+1)%Define.mod;
                    for(int k=1;k<j+1;k++){
                        count = (count+((powsum[b[i-1],k]-powsum[a[i-1]-1,k])%Define.mod*dp[i-1,j-k]%Define.mod))%Define.mod; 
                    }
                    dp[i,j] = count;
                }
            }
        }
        Console.WriteLine(dp[N,C] > 0 ? dp[N,C] : dp[N,C]+Define.mod);
        
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        C = int.Parse(str[1]);
        a = new int[N];
        b = new int[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            a[i] = int.Parse(str[i]);
        }
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            b[i] = int.Parse(str[i]);
        }
    }    
}
public static class Define{
    public const long mod = 1000000007;
    public static void DebugPrint(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
}