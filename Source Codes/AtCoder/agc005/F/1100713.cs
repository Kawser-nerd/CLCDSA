using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    long[] A;
    int N;
    List<int>[] e;
    bool[] b;
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
        N = int.Parse(Console.ReadLine());
        string[] str;
        A = new long[N+1];
        e = new List<int>[N];
        b = new bool[N];
        for(int i=0;i<N;i++){
            e[i] = new List<int>();
        }
        for(int i=0;i<N-1;i++){
            str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0])-1;
            int c = int.Parse(str[1])-1;
            e[a].Add(c);
            e[c].Add(a);
        }
        dfs(0);
        A[0]--;
        A[N]--;
        long[] C = new long[N+1];
        long[] D = new long[N+1];
        Fact F = new Fact(N);
        for(int i=0;i<N+1;i++){
            C[i] = A[i]*F.f[i]%Define.mod;
            D[i] = F.rf[N-i];
        }
        Convolution Co = new Convolution(C,D,N+1);
        long[] ans = Co.coefficient();
        for(int i=1;i<N+1;i++){
            long fa = (Define.mod - ans[ans.Length-1-N-i]*F.rf[i]%Define.mod + N*F.GetConv(N,i))%Define.mod;
            sb.Append(fa+"\n");
        }
    }
    int dfs(int v){
        b[v] = true;
        List<int> ed = e[v];
        int count = 1;
        for(int i=0;i<ed.Count;i++){
            if(!b[ed[i]]){
                count += dfs(ed[i]);
            }
        }
        A[count]++;
        A[N-count]++;
        return count;
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
    public long pow(long X,long Y){
        if(Y == 0){
            return 1;
        }
        else if(Y%2 == 1){
            return X*pow(X,Y-1)%Define.mod;
        }
        else{
            long Z = pow(X,Y/2);
            return Z*Z%Define.mod;
        }
    }
    void Calc(){
        W = new long[size];
        E = pow(Define.E,Define.B / size);
        HALF = pow(2,Define.mod-2);
        W[0] = 1;
        for(int i=1;i<size;i++){
            W[i] = W[i-1]*E%Define.mod;
        }
        long[] cf = FFT(F,size);
        long[] cg = FFT(G,size);
        long[] c = new long[size];
        for(int i=0;i<size;i++){
            c[i] = cf[i]*cg[i]%Define.mod;
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
            ans[i] = (o[i%(s/2)]*W[b*i]+e[i%(s/2)])%Define.mod;
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
                o0[i] = (f[i]-f[i+s/2]+Define.mod)*W[(size - i*b)%size]%Define.mod*HALF%Define.mod;
                e0[i] = (f[i]+f[i+s/2])*HALF%Define.mod;
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
    public const long mod = 924844033;
    public const long E = 44009197;
    public const long B = 2097152;
}