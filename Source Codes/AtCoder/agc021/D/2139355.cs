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

    int[,,] dp;
    string S;
    void solve()
    {
        S = ReadLine();
        int K = cin.nextint;
        dp = new int[S.Length, S.Length, K + 1];//?????1?????
        WriteLine(calc(0, S.Length - 1, K));

    }
    int calc(int l, int r, int k)
    {
        if (dp[l, r, k] > 0) return dp[l, r, k];

        int res = 0;
        if (l == r) return 1;
        else if (l + 1 == r)
        {
            if (S[l] == S[r] || k > 0) res = 2;
            else res = 1;
        }
        else
        {
            res = Math.Max(res, calc(l + 1, r, k));
            res = Math.Max(res, calc(l, r - 1, k));

            if (S[l] == S[r]) res = Math.Max(res, calc(l + 1, r - 1, k) + 2);
            if (k > 0) res = Math.Max(res, calc(l + 1, r - 1, k - 1) + 2);
        }

        return dp[l, r, k] = res;
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