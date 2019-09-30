using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    long[] pow;
    List<long>[] DP0;
    List<long>[] DP1;
    List<long>[] DP2;
    int[] depthCount;
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
        int N = re.i()+1;
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=1;i<N;i++){
            G[re.i()].Add(i);
        }
        DP0 = new List<long>[N];
        DP1 = new List<long>[N];
        DP2 = new List<long>[N];
        pow = new long[N+1];
        pow[0] = 1;
        for(int i=1;i<=N;i++){
            pow[i] = pow[i-1]*2%Define.mod;
        }
        depthCount = new int[N];
        dfs(0,0);
        long count = 0;
        for(int i=0;i<DP1[0].Count;i++){
            count += (DP1[0][i] * pow[N - depthCount[DP1[0].Count-1-i]]) % Define.mod;
        }
        count %= Define.mod;
        sb.Append(count+"\n");
    }
    int dfs(int v,int depth){
        depthCount[depth]++;
        int max = 0;
        int maxL = -1;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            int gt = dfs(t,depth+1);
            if(max == 0){
                maxL = i;
                max = gt;
            }
            else{
                if(max < gt){
                    max = gt;
                    maxL = i;
                }
            }
        }
        if(max == 0){
            DP0[v] = new List<long>();
            DP1[v] = new List<long>();
            DP2[v] = new List<long>();
            DP0[v].Add(1);
            DP1[v].Add(1);
            DP2[v].Add(0);
            return 1;
        }
        int secdepth = 0;
        DP0[v] = DP0[G[v][maxL]];
        DP1[v] = DP1[G[v][maxL]];
        DP2[v] = DP2[G[v][maxL]];
        for(int i=0;i<G[v].Count;i++){
            if(i != maxL){
                int t = G[v][i];
                for(int j=0;j<DP0[t].Count;j++){
                    long Z = DP0[v][DP0[v].Count-1-j] * DP0[t][DP0[t].Count-1-j] % Define.mod;
                    long O = DP0[v][DP0[v].Count-1-j] * DP1[t][DP0[t].Count-1-j] % Define.mod + DP1[v][DP0[v].Count-1-j] * DP0[t][DP0[t].Count-1-j] % Define.mod;
                    long T = DP2[v][DP0[v].Count-1-j] * DP0[t][DP0[t].Count-1-j] % Define.mod + DP2[v][DP0[v].Count-1-j] * DP1[t][DP0[t].Count-1-j] % Define.mod + DP2[v][DP0[v].Count-1-j] * DP2[t][DP0[t].Count-1-j] % Define.mod + DP1[v][DP0[v].Count-1-j] * DP1[t][DP0[t].Count-1-j] % Define.mod;
                    DP0[v][DP0[v].Count-1-j] = Z;
                    DP1[v][DP0[v].Count-1-j] = O % Define.mod;
                    DP2[v][DP0[v].Count-1-j] = T % Define.mod;
                }
                secdepth = Math.Max(secdepth,DP0[t].Count);
            }
        }
        for(int j=0;j<secdepth;j++){
            DP0[v][DP0[v].Count-1-j] = (DP0[v][DP0[v].Count-1-j] + DP2[v][DP0[v].Count-1-j]) % Define.mod;
            DP2[v][DP0[v].Count-1-j] = 0;
        }
        DP0[v].Add(1);
        DP1[v].Add(1);
        DP2[v].Add(0);
        return DP0[v].Count;
    }
}
class Data{
    public long D;
    public Data(long d){
        D = d;
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