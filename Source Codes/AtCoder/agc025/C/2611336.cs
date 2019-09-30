using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Convert;
using static System.Math;
using static Constants;
using static Extensions;
using static MathExtensions;

public class Program
{
    public static void Solve()
    {
        var n = I;
        var ranges = new Tuple<int, long, long>[n];
        foreach (var i in Range(n))
            ranges[i] = Tuple.Create(i, L, L);

        var ls = new Tuple<int, long, long>[n];
        Array.Copy(ranges, ls, n);
        Array.Sort(ls, (x, y) => y.Item2.CompareTo(x.Item2));

        var rs = new Tuple<int, long, long>[n];
        Array.Copy(ranges, rs, n);
        Array.Sort(rs, (x, y) => x.Item3.CompareTo(y.Item3));

        Func<bool, long> SuperNoelFunc = flg =>
        {
            var cnt = 0L;
            var crt = 0L;
            var li = 0;
            var ri = 0;
            var set = new HashSet<int>();

            while (set.Count < n)
            {
                if (flg)
                {
                    while (!set.Add(ls[li].Item1))
                        li++;

                    if (crt < ls[li].Item2)
                    {
                        cnt += ls[li].Item2 - crt;
                        crt = ls[li].Item2;
                    }
                    if (ls[li].Item3 < crt)
                    {
                        cnt += crt - ls[li].Item3;
                        crt = ls[li].Item3;
                    }
                }
                else
                {
                    while (!set.Add(rs[ri].Item1))
                        ri++;

                    if (crt < rs[ri].Item2)
                    {
                        cnt += rs[ri].Item2 - crt;
                        crt = rs[ri].Item2;
                    }
                    if (rs[ri].Item3 < crt)
                    {
                        cnt += crt - rs[ri].Item3;
                        crt = rs[ri].Item3;
                    }
                }

                flg = !flg;
            }

            return Abs(crt) + cnt;
        };

        var ans = Max(SuperNoelFunc(true), SuperNoelFunc(false));
        Console.WriteLine(ans);
    }

    #region Scanners
    static TextScanner _ts;

    static char C => char.Parse(_ts.Next());
    static string S => _ts.Next();
    static int I => int.Parse(_ts.Next());
    static long L => long.Parse(_ts.Next());
    static BigInteger B => BigInteger.Parse(_ts.Next());
    static double D => double.Parse(_ts.Next());

    static char[] Cs(int count) => Repeat(count, () => C).ToArray();
    static string[] Ss(int count) => Repeat(count, () => S).ToArray();
    static int[] Is(int count) => Repeat(count, () => I).ToArray();
    static long[] Ls(int count) => Repeat(count, () => L).ToArray();
    static BigInteger[] Bs(int count) => Repeat(count, () => B).ToArray();
    static double[] Ds(int count) => Repeat(count, () => D).ToArray();
    #endregion

    [DebuggerStepThrough]
    public static void Main()
    {
        var sw = new StreamWriter(Console.OpenStandardOutput());
        sw.NewLine = "\n";
#if DEBUG
        sw.AutoFlush = true;
#else
        sw.AutoFlush = false;
#endif
        Console.SetOut(sw);
        _ts = new TextScanner(Console.In);
        Solve();
        Console.Out.Flush();
    }
}

[DebuggerStepThrough]
public class TextScanner
{
    private readonly TextReader _tr;

    public TextScanner(TextReader tr)
    {
        _tr = tr;
    }

    public string Next()
    {
        var sb = new StringBuilder();
        int i;
        do
        {
            i = _tr.Read();
            if (i == -1) throw new EndOfStreamException();
        }
        while (char.IsWhiteSpace((char)i));
        while (i != -1 && !char.IsWhiteSpace((char)i))
        {
            sb.Append((char)i);
            i = _tr.Read();
        }
        return sb.ToString();
    }
}

public static class Constants
{
    public const int AnswerToLifeTheUniverseAndEverything = 42;
    public const string Yes = "Yes";
    public const string No = "No";
    public const string YES = "YES";
    public const string NO = "NO";
    public const string Possible = "Possible";
    public const string Impossible = "Impossible";
    public const string POSSIBLE = "POSSIBLE";
    public const string IMPOSSIBLE = "IMPOSSIBLE";
}

[DebuggerStepThrough]
public static class Extensions
{
    public static void Answer(object value)
    {
        Console.WriteLine(value);
        Exit(0);
    }

    public static void Assert(bool condition)
    {
        if (!condition) throw new Exception("Assertion failed");
    }

    public static string AsString(this IEnumerable<char> source) => new string(source.ToArray());

    public static Dictionary<T, int> Bucket<T>(this IEnumerable<T> source) where T : IEquatable<T>
    {
        var dict = new Dictionary<T, int>();
        foreach (var item in source) if (dict.ContainsKey(item)) dict[item]++; else dict[item] = 1;
        return dict;
    }

    public static int[] Bucket<T>(this IEnumerable<T> source, int maxValue, Func<T, int> selector)
    {
        var arr = new int[maxValue + 1];
        foreach (var item in source) arr[selector(item)]++;
        return arr;
    }

    public static IComparer<T> CreateDescendingComparer<T>()
        where T : IComparable<T>
        => Comparer<T>.Create((x, y) => y.CompareTo(x));

    public static IEnumerable<int> CumSum(this IEnumerable<int> source)
    {
        var sum = 0;
        foreach (var item in source) yield return sum += item;
    }

    public static IEnumerable<long> CumSum(this IEnumerable<long> source)
    {
        var sum = 0L;
        foreach (var item in source) yield return sum += item;
    }

    public static void Exit(int exitCode)
    {
        Console.Out.Flush();
        Environment.Exit(exitCode);
    }

    public static void ForEach<T>(this IEnumerable<T> source, Action<T> action)
    {
        foreach (var item in source) action(item);
    }

    public static void ForEach<T, _>(this IEnumerable<T> source, Func<T, _> func)
    {
        foreach (var item in source) func(item);
    }

    public static void ForEach<T>(this IEnumerable<T> source, Action<T, int> action)
    {
        var i = 0;
        foreach (var item in source) action(item, i++);
    }

    public static void ForEach<T, _>(this IEnumerable<T> source, Func<T, int, _> func)
    {
        var i = 0;
        foreach (var item in source) func(item, i++);
    }

    // [l, r)
    public static bool IsIn<T>(this T value, T l, T r)
        where T : IComparable<T>
    {
        if (l.CompareTo(r) > 0) throw new ArgumentException();
        return l.CompareTo(value) <= 0 && value.CompareTo(r) < 0;
    }

    public static IEnumerable<int> Range(int start, int end, int step = 1)
    {
        for (var i = start; i < end; i += step) yield return i;
    }

    public static IEnumerable<int> Range(int end) => Range(0, end);

    public static void Repeat(int count, Action action)
    {
        for (var i = 0; i < count; i++) action();
    }

    public static void Repeat(int count, Action<int> action)
    {
        for (var i = 0; i < count; i++) action(i);
    }

    public static IEnumerable<T> Repeat<T>(int count, Func<T> func)
    {
        for (var i = 0; i < count; i++) yield return func();
    }

    public static IEnumerable<T> Repeat<T>(int count, Func<int, T> func)
    {
        for (var i = 0; i < count; i++) yield return func(i);
    }

    public static IEnumerable<int> RangeReverse(int start, int end, int step = 1)
    {
        for (var i = end - 1; i >= start; i -= step) yield return i;
    }

    public static IEnumerable<int> RangeReverse(int end) => RangeReverse(0, end);

    public static void Swap<T>(ref T x, ref T y)
    {
        var tmp = x; x = y; y = tmp;
    }
}

[DebuggerStepThrough]
public static class MathExtensions
{
    public static int DivCeil(int left, int right)
        => left / right + (left % right == 0 ? 0 : 1);

    public static long DivCeil(long left, long right)
        => left / right + (left % right == 0L ? 0L : 1L);

    public static int Gcd(int left, int right)
    {
        int r;
        while ((r = left % right) != 0) { left = right; right = r; }
        return right;
    }

    public static long Gcd(long left, long right)
    {
        long r;
        while ((r = left % right) != 0L) { left = right; right = r; }
        return right;
    }

    public static BigInteger Gcd(BigInteger left, BigInteger right)
        => BigInteger.GreatestCommonDivisor(left, right);

    public static int HighestOneBit(int x)
    {
        x |= x >> 01;
        x |= x >> 02;
        x |= x >> 04;
        x |= x >> 08;
        x |= x >> 16;
        return x - (x >> 1);
    }

    public static long HighestOneBit(long x)
    {
        x |= x >> 01;
        x |= x >> 02;
        x |= x >> 04;
        x |= x >> 08;
        x |= x >> 16;
        x |= x >> 32;
        return x - (x >> 1);
    }

    public static int Lcm(int left, int right) => left / Gcd(left, right) * right;

    public static long Lcm(long left, long right) => left / Gcd(left, right) * right;

    public static BigInteger Lcm(BigInteger left, BigInteger right)
        => left / Gcd(left, right) * right;

    public static int Pow(int value, int exponent)
    {
        var r = 1;
        while (exponent > 0)
        {
            if ((exponent & 1) == 1) r *= value;
            value *= value;
            exponent >>= 1;
        }
        return r;
    }

    public static long Pow(long value, int exponent)
    {
        var r = 1L;
        while (exponent > 0)
        {
            if ((exponent & 1) == 1) r *= value;
            value *= value;
            exponent >>= 1;
        }
        return r;
    }

    public static long Fact(int value)
    {
        var r = 1L;
        for (var i = 2; i <= value; i++) r *= i;
        return r;
    }
}