using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N,M,K;
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
        Fact F = new Fact(N+M+K);
        long[] po = new long[M+K+1];
        po[0] = 1;
        for(int i=1;i<=M+K;i++){
            po[i] = po[i-1]*3%Define.mod;
        }
        long d = 1;
        long count = 0;
        for(int i=N;i<=N+M+K;i++){
            count = (count + (F.GetConv(i-1,N-1)*d)%Define.mod*po[N+M+K-i]%Define.mod) % Define.mod;
            d = d*2%Define.mod;
            if(i-N >= M){
                d = (d + Define.mod - F.GetConv(i-N,M))%Define.mod;
            }
            if(i-N >= K){
                d = (d + Define.mod - F.GetConv(i-N,K))%Define.mod;
            }
        }
        sb.Append(count+"\n");
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        K = int.Parse(str[2]);
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