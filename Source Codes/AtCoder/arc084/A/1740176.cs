using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Console;
using static System.Convert;
using static System.Math;
using static Extentions;

class IO
{
    int idx;
    string[] input = In.ReadToEnd().Split(new[] { " ", "\n", "\r" },
        StringSplitOptions.RemoveEmptyEntries);

    T Get<T>(Func<string, T> parser) => parser(input[idx++]);

    public string S => Get(s => s);
    public char C => Get(char.Parse);
    public int I => Get(int.Parse);
    public long L => Get(long.Parse);
    public double F => Get(double.Parse);
    public decimal D => Get(decimal.Parse);
    public BigInteger B => Get(BigInteger.Parse);

    T[] Gets<T>(int n, Func<string, T> parser)
        => input.Skip((idx += n) - n).Take(n).Select(parser).ToArray();

    public string[] Ss(int n) => Gets(n, s => s);
    public char[] Cs(int n) => Gets(n, char.Parse);
    public int[] Is(int n) => Gets(n, int.Parse);
    public long[] Ls(int n) => Gets(n, long.Parse);
    public double[] Fs(int n) => Gets(n, double.Parse);
    public decimal[] Ds(int n) => Gets(n, decimal.Parse);
    public BigInteger[] Bs(int n) => Gets(n, BigInteger.Parse);

    public void Write<T>(params T[] xs) => WriteLine(string.Join(" ", xs));
    public void Write(params object[] xs) => WriteLine(string.Join(" ", xs));
}

public class Monoid<T>
{
    public Monoid(T unit, Func<T, T, T> append)
    {
        this.Unit = unit;
        this.Append = append;
    }

    public T Unit { get; }

    public Func<T, T, T> Append { get; }
}

public static class Monoid
{
    public static Monoid<T> Create<T>(T unit, Func<T, T, T> append) => new Monoid<T>(unit, append);

    public static Monoid<int> Sum_Int32 => new Monoid<int>(0, (x, y) => x + y);

    public static Monoid<int> Min_Int32 => new Monoid<int>(int.MaxValue, Min);

    public static Monoid<int> Max_Int32 => new Monoid<int>(int.MinValue, Max);
}

public class Group<T> : Monoid<T>
{
    public Group(T unit, Func<T, T, T> append, Func<T, T> invert) : base(unit, append)
    {
        this.Invert = invert;
    }

    public Func<T, T> Invert { get; }
}

public static class Group
{
    public static Group<T> Create<T>(T unit, Func<T, T, T> append, Func<T, T> invert)
        => new Group<T>(unit, append, invert);

    public static Group<int> Sum_Int32 => new Group<int>(0, (x, y) => x + y, x => -x);
}

public class FenwickTree<T> : IEnumerable<T>, IReadOnlyList<T>
{
    private readonly T[] _tree;
    private readonly Monoid<T> _monoid;
    private readonly Group<T> _group;

    public FenwickTree(int length, Monoid<T> monoid)
    {
        _tree = Enumerable.Repeat(monoid.Unit, length + 1).ToArray();
        _monoid = monoid;
    }

    public FenwickTree(int length, Group<T> group) : this(length, (Monoid<T>)group)
    {
        _group = group;
    }

    public FenwickTree(IEnumerable<T> collection, Monoid<T> monoid)
    {
        var count = collection.Count();
        _monoid = monoid;
        _tree = new T[count + 1];
        collection.ForEach((x, i) => { _tree[i + 1] = x; });
        for (var i = 1; i < count; i++)
        {
            var j = i + (i & -i);
            if (j < count) _tree[j] = monoid.Append(_tree[j], _tree[i]);
        }
    }

    public FenwickTree(IEnumerable<T> collection, Group<T> group) : this(collection, (Monoid<T>)group)
    {
        _group = group;
    }

    public int Length => _tree.Length - 1;

    int IReadOnlyCollection<T>.Count => this.Length;

    public T this[int i]
    {
        get { return this[i, i]; }
        set { this.AppendAt(i, _group.Append(value, _group.Invert(this[i]))); }
    }

    public T this[int i, int j]
    {
        get
        {
            var r = _group.Unit;
            j++;
            for (; j > i; j -= j & -j) r = _group.Append(r, _tree[j]);
            for (; i > j; i -= i & -i) r = _group.Append(r, _group.Invert(_tree[i]));
            return r;
        }
    }

    public IEnumerator<T> GetEnumerator()
    {
        for (var i = 0; i < this.Length; i++) yield return ConcatTo(i);
    }

    IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

    public T ConcatTo(int i)
    {
        var r = _monoid.Unit;
        for (i++; i > 0; i -= i & -i) r = _monoid.Append(r, _tree[i]);
        return r;
    }

    public void AppendAt(int i, T value)
    {
        for (i++; i <= this.Length; i += i & -i) _tree[i] = _monoid.Append(_tree[i], value);
    }
}

static class Extentions
{
    [DebuggerStepThrough]
    public static void Assert(bool condition)
    {
        if (!condition) throw new Exception("Assertion failed");
    }

    public static string AsString(this IEnumerable<char> source) => new string(source.ToArray());

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

    public static IEnumerable<T> Repeat<T>(Func<T> func)
    {
        for (var i = 0; ; i++) yield return func();
    }

    public static IEnumerable<T> Repeat<T>(int count, Func<T> func)
    {
        for (var i = 0; i < count; i++) yield return func();
    }

    public static IEnumerable<T> Repeat<T>(Func<int, T> func)
    {
        for (var i = 0; ; i++) yield return func(i);
    }

    public static IEnumerable<T> Repeat<T>(int count, Func<int, T> func)
    {
        for (var i = 0; i < count; i++) yield return func(i);
    }

    public static void Swap<T>(ref T x, ref T y)
    {
        var tmp = x; x = y; y = tmp;
    }

    public static int UpperBound<T>(this IReadOnlyList<T> source, T value) where T : IComparable<T>
    {
        var ok = source.Count - 1;
        var ng = -1;

        while (Abs(ok - ng) > 1)
        {
            var mid = (ok + ng) / 2;
            if (source[mid].CompareTo(value) > 0) ok = mid;
            else ng = mid;
        }

        return source[ok].CompareTo(value) <= 0 ? ok + 1 : ok;
    }
}

static class Program
{
    public static void Main()
    {
        var sw = new StreamWriter(OpenStandardOutput()) { NewLine = "\n" };
#if DEBUG
        sw.AutoFlush = true;
#else
        sw.AutoFlush = false;
#endif
        SetOut(sw);
        Solve(new IO());
        Out.Flush();
    }

    static void Solve(IO io)
    {
        var n = io.I;
        var a = io.Is(n);
        var b = io.Is(n);
        var c = io.Is(n);
        Array.Sort(a);
        Array.Sort(b);
        Array.Sort(c);

        var ai = new int[n];
        var bn = new int[n];
        Repeat(n, i => { ai[i] = b.UpperBound(a[i]); });
        Repeat(n, i => { bn[i] = n - c.UpperBound(b[i]); });

        var bnft = new FenwickTree<long>(n, Group.Create(0L, (x, y) => x + y, x => -x));
        bn.Reverse().ForEach((x, i) => { bnft[i] = x; });

        var ans = 0L;
        for (var i = 0; i < n; i++) if (ai[i] < n) ans += bnft.ConcatTo(n - ai[i] - 1);

        io.Write(ans);
    }
}