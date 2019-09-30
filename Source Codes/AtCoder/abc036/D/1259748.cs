using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    int N;
    List<int>[] G;
    long[] B, W;
    bool[] K;
    void Solve()
    {
        N = cin.Nextint;
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < N - 1; i++)
        {
            var a = cin.Nextint - 1;
            var b = cin.Nextint - 1;
            G[a].Add(b);
            G[b].Add(a);
        }
        B = Enumerable.Repeat(long.MaxValue, N).ToArray();
        W = Enumerable.Repeat(long.MaxValue, N).ToArray();
        K = new bool[N];
        Dfs(0);
        WriteLine(B[0]);
        //WriteLine(string.Join(" ", B));
        //WriteLine(string.Join(" ", W));

    }
    void Dfs(int u)
    {
        K[u] = true;
        int cnt = 0;
        foreach (var v in G[u])
        {
            if (K[v]) continue;
            cnt++;
            Dfs(v);
        }
        if (cnt == 0)
        {
            W[u] = 1;
            B[u] = 2;
            return;
        }

        W[u] = B[u] = 1;
        foreach (var v in G[u])
        {
            if (W[v] == long.MaxValue) continue;
            B[u] = (B[u] * W[v]) % mod;
            W[u] = (W[u] * B[v]) % mod;
        }
        B[u] = (B[u] + W[u]) % mod;
        
  

    }

}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}