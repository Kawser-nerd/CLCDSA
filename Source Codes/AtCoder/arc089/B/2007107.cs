using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using static System.Convert;
using static System.Math;
using static Extensions;
using static MathExtensions;

public static class Program
{
    public static void Solve()
    {
        var n = I;
        var k = I;
        var l = 2 * k;
        var t = Repeat(l, () => new int[l]).ToArray();

        Repeat(n, () =>
        {
            var x = I;
            var y = I;
            var c = C;
            if (c == 'W') { x += k; c = 'B'; }
            x %= 2 * k;
            y %= 2 * k;
            t[y][x]++;
        });

        Repeat(l, i => Repeat(l - 1, j => { t[i][j + 1] += t[i][j]; }));
        Repeat(l, i => Repeat(l - 1, j => { t[j + 1][i] += t[j][i]; }));

        Func<int, int, int, int, int> Get = (h1, w1, h2, w2) =>
        {
            Assert(h1 <= h2);
            Assert(w1 <= w2);
            var a = w1 == 0 ? 0 : t[h2][w1 - 1];
            var b = h1 == 0 ? 0 : t[h1 - 1][w2];
            var c = w1 == 0 || h1 == 0 ? 0 : t[h1 - 1][w1 - 1];
            return t[h2][w2] - a - b + c;
        };

        var ans = 0;

        Repeat(k, y => Repeat(k, x =>
        {
            var sum = Get(y, x, y + k - 1, x + k - 1);

            // down-right
            if (0 < y)
                sum += Get(0, x + k, y - 1, l - 1);
            // down-left
            if (0 < x && 0 < y)
                sum += Get(0, 0, y - 1, x - 1);
            // up-right
            if (true)
                sum += Get(y + k, x + k, l - 1, l - 1);
            // up-left
            if (0 < x)
                sum += Get(y + k, 0, l - 1, x - 1);

            ans = Max(ans, n - sum);
            ans = Max(ans, sum);
        }));

        Assert(0 < ans && ans <= n);
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
    static decimal M => decimal.Parse(_ts.Next());
    #endregion

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

public static partial class Extensions
{
}

#region Library
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

[DebuggerStepThrough]
public static partial class Extensions
{
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
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

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static void ForEach<T>(this IEnumerable<T> source, Action<T> action)
    {
        foreach (var item in source) action(item);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static void ForEach<T, _>(this IEnumerable<T> source, Func<T, _> func)
    {
        foreach (var item in source) func(item);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static void ForEach<T>(this IEnumerable<T> source, Action<T, int> action)
    {
        var i = 0;
        foreach (var item in source) action(item, i++);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static void ForEach<T, _>(this IEnumerable<T> source, Func<T, int, _> func)
    {
        var i = 0;
        foreach (var item in source) func(item, i++);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public static void Repeat(int count, Action action)
    {
        for (var i = 0; i < count; i++) action();
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
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
#endregion