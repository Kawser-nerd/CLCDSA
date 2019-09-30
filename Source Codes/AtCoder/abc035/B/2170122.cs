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

public static class Program
{
    public static void Solve()
    {
        var s = S.OrderByDescending(c => c).AsString();
        var t = I;

        var units = new Dictionary<char, Point2D>
        {
            ['L'] = new Point2D(0, -1),
            ['R'] = new Point2D(0, 1),
            ['U'] = new Point2D(1, 0),
            ['D'] = new Point2D(-1, 0),
        };

        var crt = Point2D.Origin;

        foreach (var c in s)
        {
            if (c == '?')
            {
                var orderedUnits = units.Values
                    .OrderBy(p => Point2D.ManhattanDistance(crt + p, Point2D.Origin));
                crt += t == 1 ? orderedUnits.Last() : orderedUnits.First();
            }
            else crt += units[c];
        }

        var ans = Point2D.ManhattanDistance(crt, Point2D.Origin);
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

#pragma warning disable
public struct Point2D : IEquatable<Point2D>
{
    public Point2D(int y, int x)
    {
        this.Y = y;
        this.X = x;
    }

    public int Y { get; }

    public int X { get; }

    public static readonly Point2D Origin
        = new Point2D(0, 0);

    public static readonly IReadOnlyCollection<Point2D> NeumannNeighborhoodUnits
        = new[] { new Point2D(0, 1), new Point2D(1, 0), new Point2D(0, -1), new Point2D(-1, 0) };

    public static readonly IReadOnlyCollection<Point2D> MooreNeighborhoodUnits
        = new[] { new Point2D(-1, -1), new Point2D(-1, 0), new Point2D(-1, 1), new Point2D(0, -1), new Point2D(0, 1), new Point2D(1, -1), new Point2D(1, 0), new Point2D(1, 1) };

    public static IEnumerable<Point2D> InnerPoints(Point2D max)
        => InnerPoints(Origin, max);

    public static IEnumerable<Point2D> InnerPoints(Point2D min, Point2D max)
    {
        if (min.X > max.X || min.Y > max.Y) throw new ArgumentException();
        for (var i = min.Y; i < max.Y; i++)
            for (var j = min.X; j < max.X; j++)
                yield return new Point2D(i, j);
    }

    public static int ManhattanDistance(Point2D source, Point2D target)
        => System.Math.Abs(source.X - target.X) + System.Math.Abs(source.Y - target.Y);

    public static int ChebyshevDistance(Point2D source, Point2D target)
        => System.Math.Max(System.Math.Abs(source.X - target.X), System.Math.Abs(source.Y - target.Y));

    public static Point2D operator +(Point2D left, Point2D right)
        => new Point2D(left.Y + right.Y, left.X + right.X);

    public static Point2D operator -(Point2D left, Point2D right)
        => new Point2D(left.Y - right.Y, left.X - right.X);

    public static bool operator ==(Point2D left, Point2D right)
        => left.Equals(right);

    public static bool operator !=(Point2D left, Point2D right)
        => !left.Equals(right);

    public bool IsIn(Point2D max)
        => this.IsIn(Origin, max);

    public bool IsIn(Point2D min, Point2D max)
    {
        if (min.X > max.X || min.Y > max.Y) throw new ArgumentException();
        return min.Y <= this.Y && this.Y < max.Y && min.X <= this.X && this.X < max.X;
    }

    public bool Equals(Point2D other)
        => this.Y == other.Y && this.X == other.X;

    public override bool Equals(object obj)
        => obj is Point2D ? this.Equals((Point2D)obj) : false;

    public override int GetHashCode()
        => (this.X << 16) ^ this.Y;

    public override string ToString()
        => $"{this.X} {this.Y}";
}

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

public static partial class Extensions
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