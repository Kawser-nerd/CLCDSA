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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    readonly int dom = 998244353;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    const double eps = 1e-12;
    long dist(pair a, pair b)
    {
        var x = a.f - b.f;
        var y = a.s - b.s;
        return x * x + y * y;
    }
    void solve()
    {
        int N = cin.nextint;

        var P = new pair[N];
        for (int i = 0; i < N; i++)
        {
            P[i] = new pair(cin.nextlong, cin.nextlong);
        }

        var sum = (long)N * (N - 1) * (N - 2) / 6;
        var choku = 0L;
        var don = 0L;
        for (int i = 0; i < N; i++)
        {
            var L = new List<double>();
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;
                var angle = Atan2(P[j].s - P[i].s, P[j].f - P[i].f);
                L.Add(angle);
                L.Add(angle + 2 * PI);
            }
            L.Sort();

            for (int j = 0; j < N - 1; j++)
            {
                choku += upper_bound(L, L[j] + PI / 2 + eps) - lower_bound(L, L[j] + PI / 2 - eps);
                don += lower_bound(L, L[j] + PI - eps) - upper_bound(L, L[j] + PI / 2 + eps);
            }

        }
        WriteLine($"{sum - choku - don} {choku} {don}");
    }

    int upper_bound<T>(IList<T> arr, T val) where T : IComparable<T>
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

    int lower_bound<T>(IList<T> arr, T val) where T : IComparable<T>
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
        return f + " " + s;
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
    public void join<T>(IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
}