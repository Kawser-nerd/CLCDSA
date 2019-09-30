using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using SB = System.Text.StringBuilder;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
using static System.Math;
using pair = Pair<long, long>;

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
    readonly int dom = 998244353;
    bool chmax<T>(ref T a, T b) where T : IComparable<T> { if (a.CompareTo(b) < 0) { a = b; return true; } return false; }
    bool chmin<T>(ref T a, T b) where T : IComparable<T> { if (b.CompareTo(a) < 0) { a = b; return true; } return false; }

    void solve()
    {
        var A = ReadLine();
        int N = A.Length;
        var dp = new int[N + 1, 2, 2, 2, 2]; //pos less have7 have5 have3
        dp[0, 0, 0, 0, 0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        for (int m = 0; m < 2; m++)
                        {
                            int x = j == 1 ? 7 : A[i] - '0';
                            for (int d = 3; d <= x; d += 2)
                            {
                                int less = j | (d < x ? 1 : 0);
                                if (d == 7)
                                {
                                    dp[i + 1, less, 1, l, m] += dp[i, j, k, l, m];
                                }
                                else if (d == 5)
                                {
                                    dp[i + 1, less, k, 1, m] += dp[i, j, k, l, m];
                                }
                                else if (d == 3)
                                {
                                    dp[i + 1, less, k, l, 1] += dp[i, j, k, l, m];
                                }
                            }
                        }
                    }
                }
            }
            dp[i + 1, 1, 0, 0, 0]++;
        }

        WriteLine(dp[N, 0, 1, 1, 1] + dp[N, 1, 1, 1, 1]);
    }

}


class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f;
    public U s;
    public Pair(T f, U s)
    {
        this.f = f;
        this.s = s;
    }
    public int CompareTo(Pair<T, U> a)
    {
        return f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    }
    public override string ToString()
    {
        return $"{f} {s}";
    }
}

static class Ex
{
    public static void join<T>(this IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
    public static string join<T>(this IEnumerable<T> values, string sep) { return string.Join(sep, values); }
    public static string concat<T>(this IEnumerable<T> values) { return string.Concat(values); }
    public static string reverse(this string s) { return s.Reverse().concat(); }

    public static int lower_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) < 0) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    public static int upper_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) <= 0) low = mid + 1;
            else high = mid;
        }
        return low;
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
}