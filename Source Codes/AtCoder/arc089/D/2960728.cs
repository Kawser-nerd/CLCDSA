using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    int[] L;
    Fact F;
    StringBuilder sb;
    ReadData re;
    long count;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new ReadData();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N = re.i();
        int K = re.i();
        string S = re.s();
        count = 1;
        L = new int[70];
        F = new Fact(1000);
        for(int i=1;i<=70;i++){
            L[0] = i; 
            if(i == 1){
                dfs(N,1,N-i,S,1);
            }
            else{
                dfs(N,1,N-i,S,i*2-3);
            }
        }
        count %= Define.mod;
        sb.Append(count+"\n");
    }
    void dfs(int N,int l,int n,string S,int a){
        if(N < a){
            return;
        }
        if(Possible(l,S)){
            count += Querry(l,N);
        }
        for(int i=L[l-1];i<=n;i++){
            L[l] = i;
            if(i == 1){
                dfs(N,l+1,n-i,S,a+1);
            }
            else{
                dfs(N,l+1,n-i,S,a+i*2-3);
            }
        }
    }
    long Querry(int l,int N){
        if(l == 0){
            return 1;
        }
        int a = 0;
        int b = 0;
        for(int i=0;i<l;i++){
            if(L[i] == 1){
                a += 1;
            }
            else{
                a += L[i]*2-3;
                b += 2;
            }
        }
        a += l-1;
        b += 2;
        if(N < a){
            return 0;
        }
        long ans = F.GetConv(N+b-1,a+b-1);
        ans *= F.f[l];
        ans %= Define.mod;
        int c = 1;
        for(int i=1;i<l;i++){
            if(L[i] == L[i-1]){
                c++;
            }
            else{
                ans *= F.rf[c];
                ans %= Define.mod;
                c = 1;
            }
        }
        ans *= F.rf[c];
        ans %= Define.mod;
        return ans;
    }
    bool Possible(int l,string S){
        int[] A = new int[l];
        int Zero = l-1;
        int One = l-1;
        int Two = l-1;
        for(int i=0;i<S.Length;i++){
            if(S[i] == 'r'){
                if(Zero != -1){
                    A[Zero]++;
                    Zero--;
                }
                else{
                    if(Two != -1 && L[Two] > 2 && A[Two] >= 2){
                        A[Two]++;
                        if(A[Two] == L[Two]){
                            Two--;
                        }
                    }
                }
            }
            else{
                if(One != -1 && L[One] != 1 && A[One] == 1){
                    A[One]++;
                    One--;
                }
                else{
                    if(Two != -1 && L[Two] > 2 && A[Two] >= 2){
                        A[Two]++;
                        if(A[Two] == L[Two]){
                            Two--;
                        }
                    }
                }
            }
        }
        return Zero == -1 && (One == -1 || L[One] == 1) && (Two == -1 || L[Two] <= 2);
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
    public long GetPerm(int N,int R){
        return f[N] * rf[N-R] % Define.mod;
    }
    public long GetConv(int N,int R){
        return ((f[N]*rf[R])%Define.mod*rf[N-R])%Define.mod;
    }
    public long GetRev(int N){
        if(N == 0){
            return 1;
        }
        else{
            return rf[N] * f[N-1] % Define.mod;
        }
    }
}
class ReadData{
    string[] str;
    int counter;
    public ReadData(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}