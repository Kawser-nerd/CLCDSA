using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    List<long>[] C;
    List<int>[] G2;
    List<int>[] G3;
    long[] revE;
    long[] regE;
    int[] child2;
    int[] child3;
    long[] ways2;
    long[] ways3;
    bool[] us2;
    bool[] us3;
    long count;
    Fact F;
    public Solve(){}
    StringBuilder sb;
    ReadData re;
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
        long[] E = new long[2*N];
        for(int i=0;i<2*N;i++){
            E[i] = (re.l()-1) * N + re.i()-1;
        }
        Array.Sort(E);
        G = new List<int>[2*N];
        C = new List<long>[2*N];
        for(int i=0;i<2*N;i++){
            G[i] = new List<int>();
            C[i] = new List<long>();
        }
        for(int i=0;i<2*N;i++){
            int x = (int)(E[i] / N);
            int y = (int)(E[i] % N);
            G[x].Add(y+N);
            G[y+N].Add(x);
            C[x].Add(E[i]);
            C[y+N].Add(E[i]);
        }
        regE = new long[2*N];
        revE = new long[2*N];
        int[] O = new int[2*N];
        for(int i=0;i<2*N;i++){
            O[i] = G[i].Count - 1;
        }
        int[] stack = new int[2*N];
        int p = 0;
        for(int i=0;i<2*N;i++){
            if(O[i] == 0){
                stack[p] = i;
                p++;
            }
        }
        while(p != 0){
            int v = stack[p-1];
            p--;
            bool b = false;
            for(int i=0;i<G[v].Count;i++){
                int t = G[v][i];
                if(O[t] != 0){
                    O[t]--;
                    regE[v] = C[v][i];
                    revE[v] = C[v][i];
                    b = true;
                    if(O[t] == 0){
                        stack[p] = t;
                        p++;
                    }
                }
            }
            if(!b){
                sb.Append("0\n");
                return;
            }
        }
        bool[] us = new bool[2*N];
        bool[] us4 = new bool[2*N];
        for(int i=0;i<2*N;i++){
            if(O[i] != 0 && O[i] != 1){
                sb.Append("0\n");
                return;
            }
            else if(O[i] == 1 && !us[i]){
                int v = i;
                GetCycle(v,-1,O,us);
                GetCycle2(v,-1,O,us4);
            }
        }
        Compression Comp = new Compression(E);
        long[] E2 = new long[2*N];
        for(int i=0;i<2*N;i++){
            E2[i] = E[i];
        }
        G2 = new List<int>[2*N];
        G3 = new List<int>[2*N];
        for(int i=0;i<2*N;i++){
            G2[i] = new List<int>();
            G3[i] = new List<int>();
        }
        Array.Sort(E2,(x,y)=>(x % N == y % N ? (int)((x - y)/N) : (int)((x % N) - (y % N))));
        for(int i=0;i<N;i++){
            int x = i;
            int y = (int)(regE[i]%N);
            int bf = 0;
            int bl = 2*N-1;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(E[bc]/N >= x){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            int v = Comp.ToPoint(regE[i]);
            for(int j=bf;E[j]/N == x && E[j]%N < y;j++){
                G2[v].Add(j);
            }
            x = i;
            y = (int)(revE[i]%N);
            bf = 0;
            bl = 2*N-1;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(E[bc]/N >= x){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            v = Comp.ToPoint(revE[i]);
            for(int j=bf;E[j]/N == x && E[j]%N < y;j++){
                G3[v].Add(j);
            }
            y = i;
            x = (int)(regE[N+i]/N);
            bf = 0;
            bl = 2*N-1;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(E2[bc] % N >= y){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            v = Comp.ToPoint(regE[N+i]);
            for(int j=bf;E2[j]%N == y && E2[j]/N < x;j++){
                G2[v].Add(Comp.ToPoint(E2[j]));
            }
            y = i;
            x = (int)(revE[N+i]/N);
            bf = 0;
            bl = 2*N-1;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(E2[bc] % N >= y){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            v = Comp.ToPoint(revE[N+i]);
            for(int j=bf;E2[j]%N == y && E2[j]/N < x;j++){
                G3[v].Add(Comp.ToPoint(E2[j]));
            }
        }
        F = new Fact(2*N);
        us2 = new bool[2*N];
        us3 = new bool[2*N];
        child2 = new int[2*N];
        child3 = new int[2*N];
        count = 1;
        int D = 2*N;
        ways2 = new long[2*N];
        ways3 = new long[2*N];
        for(int i=0;i<2*N;i++){
            if(!us2[i]){
                GetChild2(i);
            }
            if(!us3[i]){
                GetChild3(i);
            }
        }
        for(int i=0;i<2*N;i++){
            us2[i] = false;
            us3[i] = false;
            us[i] = false;
        }
        for(int i=0;i<2*N;i++){
            if(!us2[i]){
                dfs2(i);
            }
            if(!us3[i]){
                dfs3(i);
            }
        }
        for(int i=0;i<2*N;i++){
            if(!us[i]){
                int pp = 1;
                stack[0] = i;
                us[i] = true;
                for(int j=0;j<pp;j++){
                    int v = stack[j];
                    for(int k=0;k<G[v].Count;k++){
                        int t = G[v][k];
                        if(!us[t]){
                            stack[pp] = t;
                            pp++;
                            us[t] = true;
                        }
                    }
                }
                count = count * F.GetConv(D,pp) % Define.mod;
                D -= pp;
                int d1 = pp;
                int d2 = pp;
                long count1 = 1;
                long count2 = 1;
                for(int j=0;j<pp;j++){
                    int v2 = Comp.ToPoint(regE[stack[j]]);
                    count1 = count1 * ways2[v2] % Define.mod * F.GetConv(d1,child2[v2]) % Define.mod;
                    d1 -= child2[v2];
                    int v3 = Comp.ToPoint(revE[stack[j]]);
                    count2 = count2 * ways3[v3] % Define.mod * F.GetConv(d2,child3[v3]) % Define.mod;
                    d2 -= child3[v3];
                }
                count = count * (count1+count2) % Define.mod;
            }
        }
        sb.Append(count+"\n");
    }
    
    void GetCycle(int v,int f,int[] O,bool[] us4){
        us4[v] = true;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(O[t] == 1 && t != f){
                regE[v] = C[v][i];
                if(!us4[t]){
                    GetCycle(t,v,O,us4);
                }
                break;
            }
        }
    }
    void GetCycle2(int v,int f,int[] O,bool[] us4){
        us4[v] = true;
        for(int i=G[v].Count-1;i>=0;i--){
            int t = G[v][i];
            if(O[t] == 1 && t != f){
                revE[v] = C[v][i];
                if(!us4[t]){
                    GetCycle2(t,v,O,us4);
                }
                break;
            }
        }
    }
    void GetChild3(int v){
        int c = 1;
        us3[v] = true;
        for(int i=0;i<G3[v].Count;i++){
            int t = G3[v][i];
            if(!us3[t]){
                GetChild3(t);
            }
            c += child3[t];
        }
        child3[v] = c;
    }
    void GetChild2(int v){
        int c = 1;
        us2[v] = true;
        for(int i=0;i<G2[v].Count;i++){
            int t = G2[v][i];
            if(!us2[t]){
                GetChild2(t);
            }
            c += child2[t];
        }
        child2[v] = c;
    }
    void dfs2(int v){
        long c = 1;
        int d = child2[v]-1;
        us2[v] = true;
        for(int i=0;i<G2[v].Count;i++){
            int t = G2[v][i];
            if(!us2[t]){
                dfs2(t);
            }
            c = c * F.GetConv(d,child2[t]) % Define.mod * ways2[t] % Define.mod;
            d -= child2[t];
            child2[t] = 0;
            ways2[t] = 1;
        }
        ways2[v] = c;
    }
    void dfs3(int v){
        long c = 1;
        int d = child3[v]-1;
        us3[v] = true;
        for(int i=0;i<G3[v].Count;i++){
            int t = G3[v][i];
            if(!us3[t]){
                dfs3(t);
            }
            c = c * F.GetConv(d,child3[t]) % Define.mod * ways3[t] % Define.mod;
            d -= child3[t];
            child3[t] = 0;
            ways3[t] = 1;
        }
        ways3[v] = c;
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
class Compression{
    public int size;
    public long[] A;
    public Compression(long[] a){
        long[] b = new long[a.Length];
        for(int i=0;i<a.Length;i++){
            b[i] = a[i];
        }
        a = b;
        Array.Sort(a);
        List<long> AL = new List<long>();
        AL.Add(a[0]);
        for(int i=1;i<a.Length;i++){
            if(a[i] != a[i-1]){
                AL.Add(a[i]);
            }
        }
        A = AL.ToArray();
        size = A.Length;
    }
    public int ToPoint(long X){
        int bf = 0;
        int bl = size-1;
        while(bf != bl){
            int bc = (bf+bl)/2;
            if(A[bc] >= X){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        return bf;
    }
    public long Value(int i){
        return A[i];
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