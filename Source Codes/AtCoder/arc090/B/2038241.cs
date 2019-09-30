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
        var n = I;
        var m = I;
        var l = new int[m];
        var r = new int[m];
        var d = new long[m];
        var gr = new AdjacencyList<long>(n);

        Repeat(m, i =>
        {
            l[i] = I - 1;
            r[i] = I - 1;
            d[i] = L;
            gr.Add(l[i], r[i], d[i]);
            gr.Add(r[i], l[i], -d[i]);
        });

        var x = new long[n];
        foreach (var edge in gr.DepthFirstSearch())
            x[edge.Target] = x[edge.Source] + edge.Cost;

        Repeat(m, j => { if (x[r[j]] - x[l[j]] != d[j]) Answer(No); });
        Answer(Yes);
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

public struct Edge<T>
{
    public Edge(int source, int target, T cost)
    {
        this.Source = source;
        this.Target = target;
        this.Cost = cost;
    }

    public int Source { get; }
    public int Target { get; }
    public T Cost { get; }

    public override string ToString()
        => $"{this.Source} -> {this.Target} ({this.Cost})";
}

public class AdjacencyList<T>
{
    private readonly List<Edge<T>>[] _t;

    public AdjacencyList(int length)
    {
        _t = new List<Edge<T>>[length];
        for (var i = 0; i < length; i++) _t[i] = new List<Edge<T>>();
    }

    public int Length => _t.Length;

    public IList<Edge<T>> this[int source] => _t[source];

    public void Add(int source, int target, T cost)
        => _t[source].Add(new Edge<T>(source, target, cost));

    public IEnumerable<Edge<T>> Edges => _t.SelectMany(es => es);

    public IEnumerable<Edge<T>> DepthFirstSearch(int source)
    {
        var visited = new bool[this.Length];
        var stack = new Stack<Edge<T>>(this[source]);

        while (stack.Any())
        {
            var edge = stack.Pop();
            yield return edge;

            if (!visited[edge.Target])
            {
                foreach (var nextEdge in this[edge.Target])
                    stack.Push(nextEdge);
                visited[edge.Target] = true;
            }
        }
    }

    public IEnumerable<Edge<T>> DepthFirstSearch()
    {
        var unvisited = new bool[this.Length];
        foreach (var edge in this.Edges)
            unvisited[edge.Source] = unvisited[edge.Target] = true;

        var unvisitedCnt = unvisited.Count(x => x);
        if (unvisitedCnt == 0) yield break;

        var firstUnvisited = Enumerable.Range(0, this.Length).First(i => unvisited[i]);
        var stack = new Stack<Edge<T>>();

        while (unvisitedCnt > 0)
        {
            foreach (var edge in this[firstUnvisited])
                stack.Push(edge);
            unvisited[firstUnvisited] = false;
            unvisitedCnt--;

            while (stack.Any())
            {
                var edge = stack.Pop();
                yield return edge;

                if (unvisited[edge.Target])
                {
                    foreach (var nextEdge in this[edge.Target])
                        stack.Push(nextEdge);
                    unvisited[edge.Target] = false;
                    unvisitedCnt--;
                }
            }

            for (var i = firstUnvisited + 1; i < this.Length; i++)
                if (unvisited[i])
                {
                    firstUnvisited = i;
                    break;
                }
        }
    }
}

public static class Constants
{
    public const string Yes = nameof(Yes);
    public const string No = nameof(No);
    public const string YES = nameof(YES);
    public const string NO = nameof(NO);
    public const string Possible = nameof(Possible);
    public const string Impossible = nameof(Impossible);
}

[DebuggerStepThrough]
public static partial class Extensions
{
    public static void Answer(string str)
    {
        Console.WriteLine(str);
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