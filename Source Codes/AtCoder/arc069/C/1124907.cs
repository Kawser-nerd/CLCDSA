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
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";


    void Solve()
    {
        int N = cin.Nextint;
        var A = cin.Scanlong;
        var C = Enumerable.Range(0, N).ToArray();
        var G = A.Select((x, y) => new { x, y }).OrderByDescending(z => z.x).ThenByDescending(z => z.y).ToArray();

        var ans = new long[N];
        int min = G[0].y;
        for (int i = 1; i < N; i++)
        {
            ans[min] += i * (G[i - 1].x - G[i].x);
            min = Math.Min(min, G[i].y);
        }
        ans[0] = A.Sum() - (ans.Sum() - ans[0]);

        foreach (var v in ans)
        {
            WriteLine(v);
        }

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