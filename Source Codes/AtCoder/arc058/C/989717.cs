using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N,X,Y,Z;
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
        long[,] dp = new long[N,1 << (X+Y+Z)];
        int l = 0;
        int g = 0;
        long count = 1;
        g += 1 << X+Y+Z-1;
        g += 1 << Y+Z-1;
        g += 1 << Z-1;
        for(int i=0;i<X+Y+Z;i++){
            l += 1 << i;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<1 << (X+Y+Z);j++){
                dp[i,j] = 0;
            }
        }
        for(int i=0;i<10;i++){
            dp[0,l & (1 << i)] ++;
        }
        for(int i=0;i<N-1;i++){
            for(int j=0;j<1 << (X+Y+Z);j++){
                for(int k = 1;k <= 10;k++){
                    int t = (j << k) + (1 << (k-1));
                    if((t & g) != g){
                        dp[i+1,t & l] = (dp[i+1,t & l] + dp[i,j]) % Define.mod; 
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            count = (count * 10) % Define.mod;
        }
        for(int i=0;i< 1 << (X+Y+Z);i++){
            count = (count - dp[N-1,i] + Define.mod) % Define.mod;
        }
        sb.Append(count+"\n");
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        X = int.Parse(str[1]);
        Y = int.Parse(str[2]);
        Z = int.Parse(str[3]);
    }    
}
public static class Define{
    public const long mod = 1000000007;
}