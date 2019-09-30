using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    List<int>[] G;
    List<int>[] revG;
    List<int>[] order;
    List<int>[] revorder;
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
        int M = re.i();
        G = new List<int>[N];
        order = new List<int>[N];
        revG = new List<int>[N];
        revorder = new List<int>[N];
        for(int j=0;j<N;j++){
            G[j] = new List<int>();
            order[j] = new List<int>();
            revG[j] = new List<int>();
            revorder[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = re.i()-1;
            int t = re.i()-1;
            G[f].Add(t);
            revG[t].Add(f);
            order[f].Add(j);
            revorder[t].Add(j);
        }
        bool[] Changed = new bool[M];
        for(int i=0;i<N;i++){
            int[] OK1 = new int[N];
            OK1[i] = N+5;
            for(int j=0;j<G[i].Count;j++){
                dfs(G[i][j],j+1,OK1);
            }
            int[] OK2 = new int[N];
            OK2[i] = N+5;
            for(int j=G[i].Count-1;j>=0;j--){
                dfs(G[i][j],j+1,OK2);
            }
            for(int j=0;j<G[i].Count;j++){
                if(OK1[G[i][j]] != j+1 || OK2[G[i][j]] != j+1){
                    Changed[order[i][j]] = !Changed[order[i][j]];
                }
            }
        }
        StrongConnectedGraph Scc = new StrongConnectedGraph(G);
        for(int i=0;i<N;i++){
            for(int j=0;j<revG[i].Count;j++){
                if(Scc.SameAffilication(i,revG[i][j])){
                    Changed[revorder[i][j]] = !Changed[revorder[i][j]];
                }
            }
        }
        for(int i=0;i<M;i++){
            if(Changed[i]){
                sb.Append("diff\n");
            }
            else{
                sb.Append("same\n");
            }
        }
    }
    void dfs(int v,int val,int[] OK){
        if(OK[v] != 0){
            return;
        }
        OK[v] = val;
        for(int i=0;i<G[v].Count;i++){
            dfs(G[v][i],val,OK);
        }
    }
    void dfs(int v,bool[] OK){
        if(OK[v]){
            return;
        }
        OK[v] = true;
        for(int i=0;i<G[v].Count;i++){
            dfs(G[v][i],OK);
        }
    }
}
class StrongConnectedGraph{
    List<int>[] originalGraph;
    List<int>[] reverseGraph;
    public List<int>[] G;
    int originalN;
    public int N;
    public int[] weight;
    bool[] b;
    int[] order;
    int count;
    public List<List<int>> division;
    int[] affilication;
    public StrongConnectedGraph(List<int>[] g){
        originalGraph = g;
        originalN = g.Length;
        Calc();
    }
    void Calc(){
        b = new bool[originalN];
        order = new int[originalN];
        reverseGraph = new List<int>[originalN];
        for(int i=0;i<originalN;i++){
            reverseGraph[i] = new List<int>();
        }
        for(int i=0;i<originalN;i++){
            for(int j=0;j<originalGraph[i].Count;j++){
                reverseGraph[originalGraph[i][j]].Add(i);
            }
        }
        count = 0;
        for(int i=0;i<originalN;i++){
            if(!b[i]){
                dfs1(i);
            }
        }
        count = 0;
        for(int i=0;i<originalN;i++){
            b[i] = false;
        }
        affilication = new int[originalN];
        division = new List<List<int>>();
        for(int i=originalN-1;i>=0;i--){
            if(!b[order[i]]){
                division.Add(new List<int>());
                dfs2(order[i]);
                count++;
            }
        }
    }
    void dfs1(int v){
        b[v] = true;
        for(int i=0;i<originalGraph[v].Count;i++){
            int t = originalGraph[v][i];
            if(!b[t]){
                dfs1(t);
            }
        }
        order[count] = v;
        count++;
    }
    void dfs2(int v){
        b[v] = true;
        division[count].Add(v);
        affilication[v] = count;
        for(int i=0;i<reverseGraph[v].Count;i++){
            int t = reverseGraph[v][i];
            if(!b[t]){
                dfs2(t);
            }
        }
    }
    public bool SameAffilication(int u,int v){
        return affilication[u] == affilication[v];
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