using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;
//using static System.Math;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    readonly string ALFA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N;
    List<int>[] G;
    int[] X;
    bool ans = true;
    void solve()
    {
        N = cin.nextint;
        if (N == 1)
        {
            WriteLine("POSSIBLE");
            return;
        }
        var P = cin.scanint.Select(i => i - 1).ToArray();
        X = cin.scanint;
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < N - 1; i++)
        {
            G[P[i]].Add(i + 1);
        }
        calc(0);
        WriteLine(ans ? "POSSIBLE" : "IMPOSSIBLE");
    }

    const int inf = int.MaxValue / 3;
    int calc(int v)
    {
        if (G[v].Count == 0) return 0;

        var dp = new int[2][];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = Enumerable.Repeat(inf, X[v] + 1).ToArray();
        }
        dp[0][0] = 0;

        int j = 0;
        foreach (var u in G[v])
        {
            int p = calc(u);
            //WriteLine(p);
            int now = j % 2;
            int upd = (j + 1) % 2;
            dp[upd] = Enumerable.Repeat(inf, X[v] + 1).ToArray();
            for (int i = X[v]; i >= 0; i--)
            {
                if (i + p <= X[v])
                {
                    dp[upd][i + p] = Math.Min(dp[upd][i + p], dp[now][i] + X[u]);
                }
                if (i + X[u] <= X[v])
                {
                    dp[upd][i + X[u]] = Math.Min(dp[upd][i + X[u]], dp[now][i] + p);
                }
            }

            j++;
        }

        //WriteLine(string.Join(" ", dp[j % 2]));
        int ret = dp[j % 2].Min();
        if (ret == inf) ans = false;
        return ret;
    }

}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan { get { return ReadLine().Split(); } }
    public int[] scanint { get { return Array.ConvertAll(scan, int.Parse); } }
    public long[] scanlong { get { return Array.ConvertAll(scan, long.Parse); } }
    public double[] scandouble { get { return Array.ConvertAll(scan, double.Parse); } }
    public string next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return next;
        }
    }
    public int nextint { get { return int.Parse(next); } }
    public long nextlong { get { return long.Parse(next); } }
    public double nextdouble { get { return double.Parse(next); } }
}