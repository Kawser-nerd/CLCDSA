using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    ReadData re;
    StringBuilder sb;
    List<int>[] G;
    string S;
    int N;
    int[] child;
    int[] depth;
    int[] depth2;
    int[] depthR;
    int fav;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        re = new ReadData();
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        N = re.i();
        {
            int[] fv = new int[2*N-2];
            int[] tv = new int[2*N-2];
            int cv = 0;
            int dv = N;
            for(int i=0;i<N-1;i++){
                int ai = re.i()-1;
                int bi = re.i()-1;
                fv[cv] = ai;
                tv[cv] = dv;
                cv++;
                fv[cv] = dv;
                tv[cv] = bi;
                cv++;
                dv++;
            }
            N = 2*N-1;
            G = re.g(N,fv,tv);
        }
        S = re.s();
        child = new int[N];
        depth = new int[N];
        depth2 = new int[N];
        depthR = new int[N];
        GetDepth(0,-1);
        GetDepthR(0,-1,0);
        GetChild(0,-1);
        fav = child[0];
        long count = dfs(0,-1);
        sb.Append(count+"\n");
    }
    long dfs(int v,int f){
        int min = child[v] == fav ? 1000000000 : depthR[v];
        int max = Math.Min(Math.Max(depth2[v],depthR[v]),depth[v]);
        long count = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                count += dfs(t,v);
                if(child[t] > 0){
                    min = Math.Min(min,depth[t]+1);
                }
            }
        }
        if(v < (N+1)/2 && S[v] == '1'){
            min = 0;
        }
        if(max >= min){
            count += (max-min)/2+1;
        }
        return count;
    }
    void GetDepth(int v,int f){
        int max1 = 0;
        int max2 = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                GetDepth(t,v);
                int val = depth[t]+1;
                if(val > max1){
                    max2 = max1;
                    max1 = val;
                }
                else if(val > max2){
                    max2 = val;
                }
            }
        }
        depth[v] = max1;
        depth2[v] = max2;
    }
    void GetDepthR(int v,int f,int d){
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                int val = depth[v] == depth[t]+1 ? depth2[v]+1 : depth[v]+1;
                val = Math.Max(val,d+1); 
                GetDepthR(t,v,val);
            }
        }
        depthR[v] = d;
    }
    void GetChild(int v,int f){
        int c = 0;
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                GetChild(t,v);
                c += child[t];
            }
        }
        if(v < (N+1)/2 && S[v] == '1'){
            c++;
        }
        child[v] = c;
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