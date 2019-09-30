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
        int N = cin.nextint;
        int M = cin.nextint;
        var A = new List<pair>[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = new List<pair>();
        }
        for (int i = 0; i < M; i++)
        {
            int p = cin.nextint - 1;
            int y = cin.nextint;
            A[p].Add(new pair(y, i));
        }
        for (int i = 0; i < N; i++)
        {
            A[i].Sort();
        }

        var ANS = new string[M];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < A[i].Count; j++)
            {
                ANS[A[i][j].s] = $"{(i + 1).ToString("D6")}{(j + 1).ToString("D6")}";
            }
        }
        foreach (var item in ANS)
        {
            WriteLine(item);
        }

    }

}


static class Ex
{
    public static void join<T>(this IEnumerable<T> values, string sep = " ") => WriteLine(string.Join(sep, values));
    public static string concat<T>(this IEnumerable<T> values) => string.Concat(values);
    public static string reverse(this string s) => s.Reverse().concat();
    public static void ForEach<T>(this T[] array, Action<T> action) { Array.ForEach(array, action); }

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

class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f; public U s;
    public Pair(T f, U s) { this.f = f; this.s = s; }
    public int CompareTo(Pair<T, U> a) => f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    public override string ToString() => $"{f} {s}";
}

class Scanner
{
    string[] s; int i;
    readonly char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan => ReadLine().Split();
    public int[] scanint => Array.ConvertAll(scan, int.Parse);
    public long[] scanlong => Array.ConvertAll(scan, long.Parse);
    public double[] scandouble => Array.ConvertAll(scan, double.Parse);
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
    public int nextint => int.Parse(next);
    public long nextlong => long.Parse(next);
    public double nextdouble => double.Parse(next);
}