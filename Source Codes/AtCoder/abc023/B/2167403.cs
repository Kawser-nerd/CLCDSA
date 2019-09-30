?using System;
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
        var s = S;
        if (s.Length % 2 != 1 || s[s.Length / 2] != 'b') Answer(-1);
        
        var deque = new Deque<char>(s);
        var ans = s.Length / 2;
        for (var i = ans; deque.Count > 1; i--)
        {
            var first = deque.DequeueFirst();
            var last = deque.DequeueLast();
            if (i % 3 == 1 && (first != 'a' || last != 'c')) Answer(-1);
            if (i % 3 == 2 && (first != 'c' || last != 'a')) Answer(-1);
            if (i % 3 == 0 && (first != 'b' || last != 'b')) Answer(-1);
        }

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

public partial class Deque<T> : IEnumerable<T>, IReadOnlyCollection<T>
{
    private const int _defaultCapacity = 4;
    private T[] _array;
    private int _first, _last;

    public Deque()
    {
        _array = Array.Empty<T>();
    }

    public Deque(int capacity)
    {
        _array = new T[capacity];
    }

    public Deque(IEnumerable<T> collection)
    {
        _array = collection.ToArray();
        _last = _array.Length - 1;
        this.Count = _array.Length;
    }

    public int Count { get; private set; }

    public int Capacity => _array.Length;

    public void Clear()
    {
        this.Count = 0;
        _first = _last = 0;
    }

    public void EnqueueFirst(T item)
    {
        EnsureCapacity(this.Count + 1);
        if (this.Count++ > 0) Decrement(ref _first);
        _array[_first] = item;
    }

    public void EnqueueLast(T item)
    {
        EnsureCapacity(this.Count + 1);
        if (this.Count++ > 0) Increment(ref _last);
        _array[_last] = item;
    }

    public T DequeueFirst()
    {
        if (this.Count == 0) throw new InvalidOperationException();
        var item = _array[_first];
        if (--this.Count > 0) Increment(ref _first);
        return item;
    }

    public T DequeueLast()
    {
        if (this.Count == 0) throw new InvalidOperationException();
        var item = _array[_last];
        if (--this.Count > 0) Decrement(ref _last);
        return item;
    }

    public T PeekFirst()
    {
        if (this.Count == 0) throw new InvalidOperationException();
        return _array[_first];
    }

    public T PeekLast()
    {
        if (this.Count == 0) throw new InvalidOperationException();
        return _array[_last];
    }

    public IEnumerator<T> GetEnumerator()
    {
        var i = _first;
        for (var j = 0; j < this.Count; j++)
        {
            yield return _array[i];
            Increment(ref i);
        }
    }

    IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

    private void EnsureCapacity(int capacity)
    {
        if (this.Capacity >= capacity) return;

        var newCapacity = System.Math.Max(this.Capacity == 0 ? _defaultCapacity : this.Capacity << 1, capacity);
        var newArray = new T[newCapacity];

        if (this.Count == 0)
        {
            _array = newArray;
            return;
        }

        if (_first < _last)
            Array.Copy(_array, _first, newArray, 0, this.Count);
        else
        {
            Array.Copy(_array, _first, newArray, 0, _array.Length - _first);
            Array.Copy(_array, 0, newArray, _array.Length - _first, _last + 1);
        }

        _first = 0;
        _last = this.Count - 1;
        _array = newArray;
    }

    private void Increment(ref int index)
    {
        if (++index == _array.Length) index = 0;
    }

    private void Decrement(ref int index)
    {
        if (--index == -1) index = _array.Length - 1;
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