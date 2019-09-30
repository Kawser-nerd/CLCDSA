using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using SB = System.Text.StringBuilder;
//using System.Threading.Tasks;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
using static System.Math;
using pair = Pair<int, int>;

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


    long calc(long[] X, int L)
    {
        int N = X.Length;
        var LX = new long[N];
        for (int i = 0; i < N; i++)
        {
            LX[i] = L - X[N - 1 - i];
        }
        var SX = new long[N + 1];
        var SLX = new long[N + 1];
        for (int i = 0; i < N; i++)
        {
            SX[i + 1] = SX[i] + X[i];
            SLX[i + 1] = SLX[i] + LX[i];
        }
        var ans = X[N - 1];

        //i???????i+1??????????????
        for (int i = 0; i < N - 1; i++)
        {
            int l = (N - i) / 2;
            int r = N - l;

            //Write($"{i} {l} {r}");
            var sum = 2 * (SX[r] - SX[i]);

            sum += 2 * SLX[l];

            int x = r - i - 1;
            if (l == x)
            {
                sum -= X[r - 1];
               // WriteLine(" " + "r");
            }
            else
            {
                sum -= LX[l - 1];
               // WriteLine(" " + "l");
            }

            chmax(ref ans, sum);
        }

        return ans;

    }
    void solve()
    {
        int L = cin.nextint;
        int N = cin.nextint;
        var X = new long[N];
        for (int i = 0; i < N; i++)
        {
            X[i] = cin.nextint;
        }

        var ans = calc(X, L);

        for (int i = 0; i < N; i++)
        {
            X[i] = L - X[i];
        }
        Array.Reverse(X);

        chmax(ref ans, calc(X, L));

        WriteLine(ans);
    }

}


static class Ex
{
    public static void join<T>(this IEnumerable<T> values, string sep = " ") => WriteLine(string.Join(sep, values));
    public static string concat<T>(this IEnumerable<T> values) => string.Concat(values);
    public static string reverse(this string s) { var t = s.ToCharArray(); Array.Reverse(t); return t.concat(); }

    public static int lower_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count;
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
        int low = 0, high = arr.Count;
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