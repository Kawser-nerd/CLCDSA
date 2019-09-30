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
        int N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] us = new int[N+1];
        for(int i=0;i<=N;i++){
            us[i] = -1;
        }
        int p = -1;
        int q = -1;
        for(int i=0;i<=N;i++){
            if(us[int.Parse(str[i])] != -1){
                p = us[int.Parse(str[i])];
                q = i;
                break;
            }
            us[int.Parse(str[i])] = i;
        }
        Fact F = new Fact(N+1);
        for(int i=1;i<=N+1;i++){
            long count = 0;
            if(i != 1){
                count += F.GetConv(N-1,i-2);
            }
            if(i != N+1){
                count += 2*F.GetConv(N-1,i-1);
                int X = N-q+p;
                if(X >= i-1){
                    count += Define.mod - F.GetConv(X,i-1);
                }
            }
            if(i != N && i != N+1){
                count += F.GetConv(N-1,i);
            }
            count %= Define.mod;
            sb.Append(count+"\n");
        }
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