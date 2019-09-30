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
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }


    void solve()
    {
        int W = cin.nextint;
        int N = cin.nextint;
        int K = cin.nextint;
        var dp = new int[K + 1, W + 1];
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < W; j++)
            {
                dp[i, j] = -1;
            }
        }
        dp[0, 0] = 0;

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int A = cin.nextint;
            int B = cin.nextint;
            for (int j = W; j >= 0; j--)
            {
                for (int k = 0; k < K; k++)
                {
                    if(0 <= j - A) chmax(ref dp[k + 1, j], dp[k, j - A] + B);
                    chmax(ref ans, dp[k + 1, j]);
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