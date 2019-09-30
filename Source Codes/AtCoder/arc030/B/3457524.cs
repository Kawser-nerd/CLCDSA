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
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    List<int>[] G;
    long ans = 0;
    int[] H;

    bool dfs(int u, int before)
    {
        bool ret = false;
        if (H[u] == 1) ret = true;
        foreach (var v in G[u])
        {
            if (v == before) continue;
            ret |= dfs(v, u);
        }

        if (ret && before != -1)
        {
            ans += 2;
        }

        return ret;
    }
    void solve()
    {
        int N = cin.nextint;
        int X = cin.nextint - 1;
        H = cin.scanint;
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < N - 1; i++)
        {
            int a = cin.nextint - 1;
            int b = cin.nextint - 1;
            G[a].Add(b);
            G[b].Add(a);
        }

        dfs(X, -1);

        WriteLine(ans);
    }

}

class Scanner
{
    string[] s; int i;
    readonly char[] cs = new char[] { ' ' };
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
    public void join<T>(IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
}