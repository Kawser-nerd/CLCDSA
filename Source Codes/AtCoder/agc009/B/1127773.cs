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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    //?????????
    void Solve()
    {
       
        int N = cin.Nextint;
        var G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 1; i < N; i++)
        {
            G[cin.Nextint - 1].Add(i);
        }
        //sw.Start();
        var B = new bool[N];
        var dp = new int[N];
        var S = new Stack<int>();
        S.Push(0);
        while (S.Any())
        {
            int u = S.Pop();
            if (B[u])
            {
                if (G[u].Count == 0)
                {
                    dp[u] = 0;
                    continue;
                }
                var L = new List<int>();
                foreach (var v in G[u])
                {
                    L.Add(dp[v]);
                }
                dp[u] = L.OrderBy(k => rnd.Next()).OrderByDescending(k => k).Select((v, i) => new { v, i }).Max(k => k.v + k.i) + 1;
            }
            else
            {
                B[u] = true;
                S.Push(u);
                foreach (var v in G[u])
                {
                    S.Push(v);
                }
            }
        }

        WriteLine(dp[0]);
        //WriteLine(sw.Elapsed);
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