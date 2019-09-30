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
        int A,B;
        {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            A = 0;
            B = 0;
            for(int i=0;i<s1.Length;i++){
                if(s1[i] == '1'){
                    if(s2[i] == '1'){
                        A++;
                    }
                    else{
                        B++;
                    }
                }
            }
        }
        Fact F = new Fact(A+B);
        long[,] DP = new long[A+1,B+1];
        for(int i=0;i<=A;i++){
            for(int j=0;j<=B;j++){
                if(i == 0){
                    DP[i,j] = F.f[j]*F.f[j]%Define.mod;
                }
                else{
                    DP[i,j] = (i*j*DP[i-1,j] + j*j*(j == 0 ? 0 : DP[i,j-1])) % Define.mod;
                }
            }
        }
        long count = 0;
        for(int i=0;i<=A;i++){
            count = (count + DP[i,B] * F.GetConv(A+B,A-i) % Define.mod * F.f[A-i] % Define.mod * F.f[A-i] % Define.mod * F.GetConv(A,i)) % Define.mod;
        }
        sb.Append(count+"\n");
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
    public const long mod = 998244353;
}