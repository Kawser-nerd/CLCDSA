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
        //SetIn(new StreamReader("deg.txt"));
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        var A = cin.scanint;

        var B = new int[N];
        ModInt ans = 1;
        for (int i = 0; i < N; i++)
        {
            if (i > 0 && A[i] == 0)
            {
                ans = 0;
            }
            B[A[i]]++;
        }
        //var ncr = new BinomialCoefficient(N);
        
        var Z = new ModInt[N + 1];
        Z[0] = 1;
        for (int i = 0; i < N; i++)
        {
            Z[i + 1] = Z[i] * 2;
        }

        for (int i = 1; i < N; i++)
        {
            //if (B[i] == 0) continue;

            ans *= ModInt.Pow(Z[B[i - 1]] - 1, B[i]) * ModInt.Pow(2, (long)B[i] * (B[i] - 1) / 2);

            //WriteLine(i + " " + B[i] + " " + ans);
        }
        WriteLine(ans);
    }

}
#region ModInt
/// <summary>
/// [0,<see cref="Mod"/>) ???????????
/// </summary>
public struct ModInt
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
#endregion

#region Binomial Coefficient
public class BinomialCoefficient
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
#endregion
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