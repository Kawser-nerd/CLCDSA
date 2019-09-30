using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
//using static System.Math;
//using pair = Pair<int, int>;

class Program
{
    static void Main()
    {
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        int M = cin.nextint;
        int S = cin.nextint - 1;
        var G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < M; i++)
        {
            int u = cin.nextint - 1;
            int v = cin.nextint - 1;
            G[Math.Min(u, v)].Add(Math.Max(u, v));
            //G[u].Add(v);
            //G[v].Add(u);
        }

        //???
        var ans = new bool[N];
        var UF = new DisjointSet(N);
        for (int i = N - 1; i >= 0; i--)
        {
            foreach (var item in G[i])
            {
                UF.Unite(i, item);
            }
            if (UF.Same(i, S))
            {
                ans[i] = true;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (ans[i]) WriteLine(i + 1);
        }
    }

}

class DisjointSet
{
    int[] par;
    byte[] rank;
    /// <summary>
    /// 0 ?? <paramref name="N"/>-1 ????????? <paramref name="N"/> ?????????????????
    /// </summary>
    /// <param name="N">???</param>
    /// <remarks>?????????? O(N) ????????</remarks>
    public DisjointSet(int N)
    {
        par = new int[N];
        rank = new byte[N];
        for (int i = 0; i < N; i++)
            par[i] = -1;
    }
    /// <summary>
    /// ???????????????????????
    /// </summary>
    /// <param name="id">??????? 0-indexed ????</param>
    /// <returns>????????????????</returns>
    /// <remarks>????? O(?(N)) ????????</remarks>
    public int this[int id]
    {
        get
        {
            if ((par[id] < 0)) return id;
            return par[id] = this[par[id]];
        }
    }
    /// <summary>
    /// ???? 2 ????????????? 1 ??????????????
    /// </summary>
    /// <param name="x">?????? 0-indexed ????</param>
    /// <param name="y">2 ?????? 0-indexed ????</param>
    /// <returns>?????????? true???????? false?</returns>
    /// <remarks>????? O(?(N)) ????????</remarks>
    public bool Unite(int x, int y)
    {
        x = this[x]; y = this[y];
        if (x == y) return false;
        if (rank[x] < rank[y]) { var tmp = x; x = y; y = tmp; }
        par[x] += par[y];
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
    /// <summary>
    /// ???????????????????????
    /// </summary>
    /// <param name="x">??????? 0-indexed ????</param>
    /// <returns>??????</returns>
    /// <remarks>????? O(?(N)) ????????</remarks>
    public int Size(int x) { return -par[this[x]]; }

    /// <summary>
    /// ???? 2 ?????????????????????????? O(?(N))?
    /// </summary>
    /// <param name="x">?????? 0-indexed ????</param>
    /// <param name="y">2 ?????? 0-indexed ????</param>
    /// <returns>????? true???????? false?</returns>
    /// <remarks>????? O(?(N)) ????????</remarks>
    public bool Same(int x, int y) { return this[x] == this[y]; }

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