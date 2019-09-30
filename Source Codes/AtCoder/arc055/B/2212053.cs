using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
//using pair = Pair<int, int>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        N = cin.nextint;
        K = cin.nextint;

        dp = new double[N + 1, K + 1, 2];
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    dp[i, j, k] = -1;
                }
            }
        }

        WriteLine(dfs(0, 0, 0).ToString("F7"));
    }
    int N, K;
    double[,,] dp;
    double dfs(int id, int ate, int ok)
    {
        if (dp[id, ate, ok] >= 0) return dp[id, ate, ok];
        if (id == N) return dp[id, ate, ok] = ok;

        dp[id, ate, ok] = dfs(id + 1, ate, ok) * id / (id + 1);

        var tmp = dfs(id + 1, ate, 0) / (id + 1);
        if (ate < K) tmp = Math.Max(tmp, dfs(id + 1, ate + 1, 1) / (id + 1));

        dp[id, ate, ok] += tmp;

        return dp[id, ate, ok];
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