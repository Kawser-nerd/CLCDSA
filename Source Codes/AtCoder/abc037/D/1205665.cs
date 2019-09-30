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

    int H, W;
    void Solve()
    {
        H = cin.Nextint;
        W = cin.Nextint;
        var E = new Pair[H * W];
        var A = new int[H, W];
        var dp = new long[H, W];//???????????
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                A[i, j] = cin.Nextint;
                E[W * i + j] = new Pair(A[i, j], W * i + j);
            }
        }
        E = E.OrderBy(i => i.Key).ToArray();

        //??dp
        for (int i = 0; i < H * W; i++)
        {
            int h = E[i].Value / W, w = E[i].Value % W;
            dp[h, w] = 1;
            for (int r = 0; r < 4; r++)
            {
                int x = h + dd[r];
                int y = w + dd[r + 1];
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (A[x, y] < A[h, w])
                {
                    dp[h, w] += dp[x, y];
                    dp[h, w] %= mod;
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                ans += dp[i, j];
                ans %= mod;
            }
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