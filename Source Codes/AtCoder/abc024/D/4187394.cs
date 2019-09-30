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
        ModInt A = cin.nextint;
        ModInt B = cin.nextint;
        ModInt C = cin.nextint;

        var X = (A * C - B * C) * ModInt.Inverse(B * C - A * B - A * C);
        var Y = (A * B - B * C) * ModInt.Inverse(B * C - A * B - A * C);

        WriteLine(X + " " + Y);
    }

}

/// <summary>
/// [0,<see cref="Mod"/>) ??????????? Original Author: camypaper
/// </summary>
struct ModInt
{
    /// <summary>
    /// ???????
    /// </summary>
    public const long Mod = (int)1e9 + 7;

    /// <summary>
    /// ??????
    /// </summary>
    public long num;
    /// <summary>
    /// ?? <paramref name="n"/> ???????????????????
    /// </summary>
    /// <param name="n">??????????</param>
    /// <remarks>????????????????????????????????????<paramref name="n"/> ? [0,<see cref="Mod"/>) ??????? <paramref name="n"/> ??????????????????? O(1) ????????</remarks>
    public ModInt(long n) { num = n; }
    /// <summary>
    /// ??????????????????????
    /// </summary>
    /// <returns>[0,<see cref="Mod"/>) ???????? 10 ????????</returns>
    public override string ToString() { return num.ToString(); }
    public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
    public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
    public static ModInt operator *(ModInt l, ModInt r) { return new ModInt(l.num * r.num % Mod); }
    public static implicit operator ModInt(long n) { n %= Mod; if (n < 0) n += Mod; return new ModInt(n); }

    /// <summary>
    /// ????? 2 ?????????????????
    /// </summary>
    /// <param name="v">?????</param>
    /// <param name="k">????</param>
    /// <returns>?????????? O(N log N) ????????</returns>
    public static ModInt Pow(ModInt v, long k) { return Pow(v.num, k); }

    /// <summary>
    /// ????? 2 ?????????????????
    /// </summary>
    /// <param name="v">?????</param>
    /// <param name="k">????</param>
    /// <returns>?????????? O(N log N) ????????</returns>
    public static ModInt Pow(long v, long k)
    {
        long ret = 1;
        for (k %= Mod - 1; k > 0; k >>= 1, v = v * v % Mod)
            if ((k & 1) == 1) ret = ret * v % Mod;
        return new ModInt(ret);
    }
    /// <summary>
    /// ????????????????
    /// </summary>
    /// <param name="v">???????????</param>
    /// <returns>?????????</returns>
    /// <remarks>??????????????????????????????? O(log N) ???????</remarks>
    public static ModInt Inverse(ModInt v) { return Pow(v, Mod - 2); }
}

class BinomialCoefficient
{
    public ModInt[] fact, ifact;
    public BinomialCoefficient(int n)
    {
        fact = new ModInt[n + 1];
        ifact = new ModInt[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;
        ifact[n] = ModInt.Inverse(fact[n]);
        for (int i = n - 1; i >= 0; i--)
            ifact[i] = ifact[i + 1] * (i + 1);
        ifact[0] = ifact[1];
    }
    public ModInt this[int n, int r]
    {
        get
        {
            if (n < 0 || n >= fact.Length || r < 0 || r > n) return 0;
            return fact[n] * ifact[n - r] * ifact[r];
        }
    }
    public ModInt RepeatedCombination(int n, int k)
    {
        if (k == 0) return 1;
        return this[n + k - 1, k];
    }
}

static class Ex
{
    public static void join<T>(this IEnumerable<T> values, string sep = " ") => WriteLine(string.Join(sep, values));
    public static string concat<T>(this IEnumerable<T> values) => string.Concat(values);
    public static string reverse(this string s) => s.Reverse().concat();
    public static void ForEach<T>(this T[] array, Action<T> action) => Array.ForEach(array, action);

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