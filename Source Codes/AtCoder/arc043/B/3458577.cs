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
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int M = 100000;
        int R = 4;
        var BIT = Enumerable.Range(0, R).Select(i => new FenwickTree(M)).ToArray();
        int N = cin.nextint;
        var D = new int[N];
        for (int i = 0; i < N; i++)
        {
            D[i] = cin.nextint;
        }
        Array.Sort(D);
        Array.Reverse(D);

        for (int i = 0; i < N; i++)
        {
            BIT[3].Add(D[i], 1);
            for (int j = R - 2; j >= 0; j--)
            {
                BIT[j].Add(D[i], BIT[j + 1][D[i] * 2, M] % mod);
            }
        }

        WriteLine(BIT[0][M] % mod);
    }

}

#region Fenwick
public class FenwickTree
{
    readonly int n;
    readonly long[] bit;
    readonly int max = 1;
    public FenwickTree(int size)
    {
        n = size; bit = new long[n + 1];
        while ((max << 1) <= n) max <<= 1;
    }
    /// <summary>sum[a,b]</summary>
    public long this[int i, int j] { get { return i <= j ? this[j] - this[i - 1] : 0; } }
    /// <summary>sum[0,i]</summary>
    public long this[int i] { get { long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; } }
    public int LowerBound(long w)
    {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = max; k > 0; k >>= 1)
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        return x + 1;
    }
    /// <summary>add v to bit[i]</summary>
    public void Add(int i, long v)
    {
        if (i == 0) System.Diagnostics.Debug.Fail("BIT is 1 indexed");
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    public long[] Items
    {
        get
        {
            var ret = new long[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
    }
}
#endregion
#region RangeAddFenwick
public class RangeAddFenwickTree
{
    readonly int n;
    FenwickTree a, b;
    public RangeAddFenwickTree(int n)
    {
        this.n = n;
        a = new FenwickTree(n);
        b = new FenwickTree(n);
    }
    /// <summary>Add V to[i,j]</summary>
    public void Add(int i, int j, long v)
    {
        a.Add(i, -(i - 1) * v); a.Add(j + 1, j * v);
        b.Add(i, v); b.Add(j + 1, -v);
    }
    /// <summary>Sum [0,i]</summary>
    public long this[int i] { get { return a[i] + b[i] * i; } }
    /// <summary>Sum [i,j]</summary>
    public long this[int i, int j] { get { return i <= j ? this[j] - this[i - 1] : 0; } }
    public long[] Items
    {
        get
        {
            var ret = new long[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
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