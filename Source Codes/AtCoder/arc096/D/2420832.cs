using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
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
        long X = re.i();
        long D = re.i();
        long[] Cost = new long[N];
        int[] Val = new int[N];
        {
            List<int>[] G;
            G = new List<int>[N];
            for(int i=0;i<N;i++){
                G[i] = new List<int>();
            }
            long[] co = new long[N];
            co[0] = re.i();
            for(int i=1;i<N;i++){
                co[i] = re.i();
                G[re.i()-1].Add(i);
            }
            dfs(0,Cost,Val,co,G);
        }
        long[] DP = new long[125001];
        for(int i=1;i<=125000;i++){
            DP[i] = 100000000000;
        }
        {
            for(int j=1;j<=32;j*=2){
                int v = Val[0]*j;
                long c = Cost[0]*j;
                for(int k=125000;k>=v;k--){
                    DP[k] = Math.Min(DP[k],DP[k-v]+c);
                } 
            }
        }
        if(D >= 50){
            for(int i=1;i<N;i++){
                for(int j=1;j<=16;j*=2){
                    int v = Val[i]*j;
                    long c = Cost[i]*j;
                    for(int k=125000;k>=v;k--){
                        DP[k] = Math.Min(DP[k],DP[k-v]+c);
                    } 
                }
                {
                    int v = Val[i]*19;
                    long c = Cost[i]*19;
                    for(int k=125000;k>=v;k--){
                        DP[k] = Math.Min(DP[k],DP[k-v]+c);
                    }
                }
            }
        }
        else{
            int rest = (int)D;
            for(int j=1;j<=16;j*=2){
                if(rest == 0){
                    break;
                }
                int num;
                if(j <= rest){
                    num = j;
                }
                else{
                    num = rest;
                }
                rest -= num;
                for(int i=1;i<N;i++){
                    int v = Val[i]*num;
                    long c = Cost[i]*num;
                    for(int k=125000;k>=v;k--){
                        DP[k] = Math.Min(DP[k],DP[k-v]+c);
                    }
                }
            }
        }
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = i;
        }
        long count = 0;
        Array.Sort(A,(x,y)=>(Val[x]*Cost[y] > Val[y]*Cost[x] ? -1 : (Val[x]*Cost[y] == Val[y]*Cost[x] ? 0 : 1)));
        int p = 0;
        long greed = 0;
        long greedval = 0;
        long newD = Math.Max(D-50,0); 
        for(int i=125000;i>=0;i--){
            long rest = X - DP[i];
            long c = 0;
            if(rest < 0){
                continue;
            }
            while(greed + newD * Cost[A[p]] <= rest){
                if(A[p] == 0){
                    break;
                }
                greed += newD * Cost[A[p]];
                greedval += newD * Val[A[p]];
                p++;
            }
            c = greedval + i + (rest - greed) / Cost[A[p]] * Val[A[p]];
            count = Math.Max(count,c);
        }
        sb.Append(count+"\n");
    }
    void dfs(int v,long[] Cost,int[] Val,long[] co,List<int>[] G){
        long ans1 = co[v];
        int ans2 = 1;
        for(int i=0;i<G[v].Count;i++){
            dfs(G[v][i],Cost,Val,co,G);
            ans1 += Cost[G[v][i]];
            ans2 += Val[G[v][i]];
        }
        Cost[v] = ans1;
        Val[v] = ans2;
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