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
        int A = int.Parse(str[1]);
        int B = int.Parse(str[2]);
        int C = int.Parse(str[3]);
        int D = int.Parse(str[4]);
        long[,] DP = new long[B-A+2,N+1];
        Fact F = new Fact(10000);
        DP[0,0] = 1;
        for(int i=0;i<=B-A;i++){
            int d = A+i;
            long division = 1;
            for(int j=0;j<=D;j++){
                if(j == 0 || j >= C){
                    for(int k=0;k+j*d<=N;k++){
                        DP[i+1,k+j*d] = (DP[i+1,k+j*d] + DP[i,k]*F.GetConv(k+j*d,k)%Define.mod*division%Define.mod*F.rf[j]%Define.mod) % Define.mod;
                    }
                }
                if(j*d > N){
                    break;
                }
                division = division * F.GetConv((j+1)*d,d) % Define.mod;
            }
        }
        sb.Append(DP[B-A+1,N]+"\n");
    }
}
class Fact{
    public long[] f;
    public long[] rf;
    public Fact(int N){
        f = new long[N+1];
        rf = new long[N+1];
        for(int i=0;i<N+1;i++){
            if(i == 0){
                f[i] = 1;
            }
            else{
                f[i] = (f[i-1]*i)%Define.mod;
            }
        }
        for(int i=N;i>=0;i--){
            if(i == N){
                rf[i] = pow(f[N],Define.mod-2);
            }
            else{
                rf[i] = rf[i+1]*(i+1)%Define.mod;
            }
        }
    }
    public long pow(long N,long K){
        if(K == 0){
            return 1;
        }
        else if(K % 2 == 0){
            long t = pow(N,K/2);
            return t*t%Define.mod;
        }
        else{
            return N*pow(N,K-1)%Define.mod;
        }
    }
    public long GetFact(int N){
        return f[N];
    }
    public long GetConv(int N,int R){
        return ((f[N]*rf[R])%Define.mod*rf[N-R])%Define.mod;
    }
}
public static class Define{
    public const long mod = 1000000007;
}