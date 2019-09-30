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

    int N, W;
    long we = 0;
    long ans = 0;
    void Solve()
    {
        N = cin.Nextint;
        W = cin.Nextint;
        var w = new int[N];
        var v = new int[N];
        for (int i = 0; i < N; i++)
        {
            w[i] = cin.Nextint;
            v[i] = cin.Nextint;
        }
        int w1 = w[0];
        var A = new List<int>();
        var B = new List<int>();
        var C = new List<int>();
        var D = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if (w[i] == w1) A.Add(v[i]);
            else if (w[i] == w1 + 1) B.Add(v[i]);
            else if (w[i] == w1 + 2) C.Add(v[i]);
            else if (w[i] == w1 + 3) D.Add(v[i]);
        }
        A = A.OrderByDescending(i => i).ToList();
        B = B.OrderByDescending(i => i).ToList();
        C = C.OrderByDescending(i => i).ToList();
        D = D.OrderByDescending(i => i).ToList();

        var dp = new long[A.Count + 1, B.Count + 1, C.Count + 1, D.Count + 1, 2];
        for (int i = 0; i <= A.Count; i++)
        {
            if (i == 0) continue;
            if (dp[i - 1, 0, 0, 0, 1] + w1 <= W)
            {
                dp[i, 0, 0, 0, 0] = dp[i - 1, 0, 0, 0, 0] + A[i - 1];
                dp[i, 0, 0, 0, 1] = dp[i - 1, 0, 0, 0, 1] + w1;
            }
            else dp[i, 0, 0, 0, 1] = W + 1;
        }
        for (int i = 0; i <= A.Count; i++)
        {
            for (int j = 0; j <= B.Count; j++)
            {
                if (j == 0) continue;
                if (dp[i, j - 1, 0, 0, 1] + w1 + 1 <= W)
                {
                    dp[i, j, 0, 0, 0] = dp[i, j - 1, 0, 0, 0] + B[j - 1];
                    dp[i, j, 0, 0, 1] = dp[i, j - 1, 0, 0, 1] + w1 + 1;
                }
                else dp[i, j, 0, 0, 1] = W + 1;
            }
        }
        for (int i = 0; i <= A.Count; i++)
        {
            for (int j = 0; j <= B.Count; j++)
            {
                for (int k = 0; k <= C.Count; k++)
                {
                    if (k == 0) continue;
                    if (dp[i, j, k - 1, 0, 1] + w1 + 2 <= W)
                    {
                        dp[i, j, k, 0, 0] = dp[i, j, k - 1, 0, 0] + C[k - 1];
                        dp[i, j, k, 0, 1] = dp[i, j, k - 1, 0, 1] + w1 + 2;
                    }
                    else dp[i, j, k, 0, 1] = W + 1;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i <= A.Count; i++)
        {
            for (int j = 0; j <= B.Count; j++)
            {
                for (int k = 0; k <= C.Count; k++)
                {
                    for (int l = 0; l <= D.Count; l++)
                    {
                        if (l == 0)
                        {
                            ans = Math.Max(dp[i, j, k, l, 0], ans);
                            continue;
                        }
                        if (dp[i, j, k, l - 1, 1] + w1 + 3 <= W)
                        {
                            dp[i, j, k, l, 0] = dp[i, j, k, l - 1, 0] + D[l - 1];
                            dp[i, j, k, l, 1] = dp[i, j, k, l - 1, 1] + w1 + 3;
                        }
                        else dp[i, j, k, l, 1] = W + 1;
                        ans = Math.Max(dp[i, j, k, l, 0], ans);
                    }
                }
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