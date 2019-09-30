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
        var A = cin.Scanint.Select((a, i) => new { a, i }).ToArray(); ;

        int ans = int.MinValue;
        for (int i = 0; i < N; i++)//????????????
        {
            int max = int.MinValue;
            int cho = int.MinValue;
            for (int j = 0; j < N; j++)//????????????
            {
                if (i == j) continue;
                int l = Math.Min(i, j);
                int r = Math.Max(i, j);
                var G = A.Where(z => l <= z.i && z.i <= r).Select((p, q) => new { p, q });
                int aok = G.Where(z => z.q % 2 == 1).Sum(z => z.p.a);
                if (max < aok)
                {
                    max = aok;
                    cho = G.Where(z => z.q % 2 == 0).Sum(z => z.p.a);
                }
            }
            ans = Math.Max(cho, ans);
        }

        WriteLine(ans);
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