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
        List<int>[] G = re.g(N,N-1);
        Tree T = new Tree(G);
        T.Center();
        int center1 = T.center1;
        int center2 = T.center2;
        sb.Append((T.diamater+2)/2);
        sb.Append(" ");
        if(center2 != -1){
            sb.Append(ans(G,center1,center2,N)+"\n");    
        }
        else{
            long min = ans(G,center1,N);
            for(int i=0;i<G[center1].Count;i++){
                min = Math.Min(min,ans(G,center1,G[center1][i],N));
            }
            sb.Append(min+"\n");
        }
    }
    long ans(List<int>[] G,int center1,int center2,int N){
        int[] dist1 = new int[N];
        int[] dist2 = new int[N];
        dfs(center1,dist1,-1,G,0);
        dfs(center2,dist2,-1,G,0);
        int[] dist = new int[N];
        for(int i=0;i<N;i++){
            dist[i] = Math.Min(dist1[i],dist2[i]);
        }
        int[] max = new int[N];
        for(int i=0;i<N;i++){
            max[dist[i]] = Math.Max(max[dist[i]],G[i].Count-1);
        }
        long answer = 1;
        for(int i=0;i<N;i++){
            if(max[i] != 0){
                answer *= max[i];
            }
        }
        return answer*2;
    }
    long ans(List<int>[] G,int center,int N){
        int[] dist = new int[N];
        dfs(center,dist,-1,G,0);
        int[] max = new int[N];
        for(int i=0;i<N;i++){
            max[dist[i]] = Math.Max(max[dist[i]],G[i].Count-1);
        }
        long answer = 1;
        max[0]++;
        for(int i=0;i<N;i++){
            if(max[i] != 0){
                answer *= max[i];
            }
        }
        return answer;
    }
    void dfs(int v,int[] dist,int f,List<int>[] G,int d){
        for(int i=0;i<G[v].Count;i++){
            int t = G[v][i];
            if(t != f){
                dfs(t,dist,v,G,d+1);
            }
        }
        dist[v] = d;
    }
}
public class Tree{
    List<int>[] T;
    bool[] b;
    int N;
    int temp1;
    int temp2;
    int[] depth;
    int[] parent;
    int[] decendant;
    public int[] depth2;
    public int[] depthv;
    public int[] depth3;
    public int[] depthR;
    public int center1;
    public int center2;
    public int diamater;
    public Tree(List<int>[] G){
        T = G;
        N = G.Length;
    } 
    void calcLongestPath(int v){
        b = new bool[N];
        temp1 = 0;
        temp2 = 0;
        dfs1(v,0);
    }
    public int LongestPathDistance(int v){
        calcLongestPath(v);
        return temp1;
    }
    public int LongestPath(int v){
        calcLongestPath(v);
        return temp2;
    }
    public void Diamater(){
        int x1 = LongestPath(0);
        int x2 = LongestPath(x1);
        diamater = temp1;
    }
    public void Center(){
        int x1 = LongestPath(0);
        int x2 = LongestPath(x1);
        diamater = temp1;
        if(diamater % 2 == 0){
            center1 = Search(x1,x2,diamater/2);
            center2 = -1;
        }
        else{
            center1 = Search(x1,x2,diamater/2);
            center2 = Search(x1,x2,diamater/2+1);
        }
    }
    public int Search(int s,int t,int l){
        b = new bool[N];
        dfs2(s,t,0,l);
        return temp1;
    }
    //???????
    public int[] GetDepth(int p){
        b = new bool[N];
        depth = new int[N];
        dfs3(p,0);
        return depth;
    }
    public int[] GetParent(int p){
        b = new bool[N];
        parent = new int[N];
        dfs4(p,-1);
        return parent;
    }
    public int[] GetDecendant(int p){
        b = new bool[N];
        decendant = new int[N];
        dfs5(p);
        return decendant;
    }
    //?????
    public int[] GetDepth2(int p){
        b = new bool[N];
        depth2 = new int[N];
        dfs6(p);
        return depth2;
    }
    //2????
    public void GetDepth3(int p){
        b = new bool[N];
        depth2 = new int[N];
        depthv = new int[N];
        depth3 = new int[N];
        dfs7(p);
    }
    //??????????
    public int[] GetDepthR(int p){
        GetDepth3(p);
        b = new bool[N];
        depthR = new int[N];
        dfs8(p,0);
        return depthR;
    }
    void dfs1(int v,int l){
        b[v] = true;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs1(t,l+1);
            }
        }
        if(l >= temp1){
            temp1 = l;
            temp2 = v;
        }
    }
    bool dfs2(int v,int o,int l,int d){
        b[v] = true;
        bool x = v == o;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                x |= dfs2(t,o,l+1,d);
            }
        }
        if(x && l == d){
            temp1 = v;
        }
        return x;
    }
    void dfs3(int v,int d){
        b[v] = true;
        depth[v] = d;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs3(t,d+1);
            }
        }
    }
    void dfs4(int v,int p){
        b[v] = true;
        parent[v] = p;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                dfs4(t,v);
            }
        }
    }
    int dfs5(int v){
        b[v] = true;
        int count = 1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                count += dfs5(t);
            }
        }
        decendant[v] = count;
        return count;
    }
    int dfs6(int v){
        b[v] = true;
        int count = 1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                count = Math.Max(count,dfs6(t)+1);
            }
        }
        depth2[v] = count;
        return count;
    }
    int dfs7(int v){
        b[v] = true;
        int m = 1;
        int m2 = 1;
        int mv = -1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                int c = dfs7(t) + 1;
                if(c > m){
                    m2 = m;
                    m = c;
                    mv = t;
                }
                else if(c > m2){
                    m2 = c;
                }
            }
        }
        depth2[v] = m;
        depth3[v] = m2;
        depthv[v] = mv;
        return m;
    }
    void dfs8(int v,int d){
        b[v] = true;
        depthR[v] = d+1;
        for(int i=0;i<T[v].Count;i++){
            int t = T[v][i];
            if(!b[t]){
                int td = depthv[v] == t ? Math.Max(depth3[v],d+1) : Math.Max(depth2[v],d+1); 
                dfs8(t,td);
            }
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