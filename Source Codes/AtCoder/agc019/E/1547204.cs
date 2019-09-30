using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    long[] G;
    long[] E;
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
        Fact F = new Fact(A+B+1);
        G = new long[A+1];
        E = new long[A+1];
        E[0] = 1;
        for(int i=0;i<=A;i++){
            G[i] = F.rf[i+1];
        }
        long[] M = Pow(B);
        long count = 0;
        for(int i=0;i<=A;i++){
            count += M[i];
        }
        count %= Define.mod;
        count = count * F.f[A+B] % Define.mod * F.f[A] % Define.mod * F.f[B] % Define.mod;
        sb.Append(count+"\n");
    }
    long[] Pow(int b){
        if(b == 0){
            return E;
        }
        else if(b == 1){
            return G;
        }
        else{
            long[] D = new long[G.Length];
            Convolution C;
            if(b % 2 == 0){
                long[] Z = Pow(b/2);
                C = new Convolution(Z,Z,G.Length);
            }
            else{
                C = new Convolution(G,Pow(b-1),G.Length);
            }
            for(int i=0;i<G.Length;i++){
                D[i] = C.GetCoefficient(i) % Define.mod;
            }
            return D;
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
class Convolution{
    long[] product;
    long[] F;
    long[] G;
    int size;
    long[] W;
    long E;
    long HALF;
    public Convolution(long[] f,long[] g,int N){
        size = 1;
        while(size < N){
            size *= 2;
        }
        size *= 2;
        F = new long[size];
        G = new long[size];
        for(int i=0;i<N;i++){
            F[i+size-N] = f[N-1-i];
            G[i+size-N] = g[N-1-i];
        }
        Calc();
    }
    public long[] coefficient(){
        return product;
    }
    public long GetCoefficient(int i){
        return product[product.Length-1-i];
    }
    public long pow(long X,long Y){
        if(Y == 0){
            return 1;
        }
        else if(Y%2 == 1){
            return X*pow(X,Y-1)%Define.FFTmod;
        }
        else{
            long Z = pow(X,Y/2);
            return Z*Z%Define.FFTmod;
        }
    }
    void Calc(){
        W = new long[size];
        E = pow(Define.E,Define.B / size);
        HALF = pow(2,Define.FFTmod-2);
        W[0] = 1;
        for(int i=1;i<size;i++){
            W[i] = W[i-1]*E%Define.FFTmod;
        }
        long[] cf = FFT(F,size);
        long[] cg = FFT(G,size);
        long[] c = new long[size];
        for(int i=0;i<size;i++){
            c[i] = cf[i]*cg[i]%Define.FFTmod;
        }
        product = IFFT(c,size);
        for(int i=0;i<size;i++){
        }
    }
    long[] FFT(long[] f,int s){
        if(s == 1){
            return f;
        }
        int b = size/s;
        long[] o;
        long[] e;
        {
            long[] o0 = new long[s/2];
            long[] e0 = new long[s/2];
            for(int i=0;i<s;i++){
                if(i%2 == 0){
                    o0[i/2] = f[i];
                }
                else{
                    e0[i/2] = f[i];
                }
            }
            o = FFT(o0,s/2);
            e = FFT(e0,s/2);
        }
        long[] ans = new long[s];
        for(int i=0;i<s;i++){
            ans[i] = (o[i%(s/2)]*W[b*i]+e[i%(s/2)])%Define.FFTmod;
        }
        return ans;
    }
    long[] IFFT(long[] f,int s){
        if(s == 1){
            return f;
        }
        int b = size/s;
        long[] o;
        long[] e;
        {
            long[] o0 = new long[s/2];
            long[] e0 = new long[s/2];
            for(int i=0;i<s/2;i++){
                o0[i] = (f[i]-f[i+s/2]+Define.FFTmod)*W[(size - i*b)%size]%Define.FFTmod*HALF%Define.FFTmod;
                e0[i] = (f[i]+f[i+s/2])*HALF%Define.FFTmod;
            }
            o = IFFT(o0,s/2);
            e = IFFT(e0,s/2);
        }
        long[] ans = new long[s];
        for(int i=0;i<s;i++){
            if(i%2 == 0){
                ans[i] = o[i/2];
            }
            else{
                ans[i] = e[i/2];
            }
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 998244353;
    public const long FFTmod = 998244353;
    public const long E = 15311432;
    public const long B = 8388608;
}