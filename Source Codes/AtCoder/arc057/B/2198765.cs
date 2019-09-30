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
        int N = cin.nextint;
        int K = cin.nextint;
        var A = new int[N + 1];
        var B = new int[N + 1];
        for (int i = 0; i < N; i++)
        {
            A[i + 1] = cin.nextint;
            B[i + 1] = B[i] + A[i + 1];
        }

        var dp = new long[N + 1, N + 1];
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                dp[i, j] = int.MaxValue;
            }
        }
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0) dp[i, j] = 0;
                else if (j == 1) dp[i, j] = 1;
                else
                {
                    dp[i, j] = dp[i - 1, j];
                    var x = dp[i - 1, j - 1] * B[i] / B[i - 1] + 1;

                    if (x - dp[i - 1, j - 1] <= A[i])
                    {
                        dp[i, j] = Math.Min(dp[i, j], x);
                    }
                }

                dp[i, j] = Math.Max(dp[i, j], K - (B[N] - B[i]));
            }
        }
        for (int i = N; i >= 0; i--)
        {
            if (dp[N, i] <= K)
            {
                WriteLine(i);
                return;
            }
        }
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