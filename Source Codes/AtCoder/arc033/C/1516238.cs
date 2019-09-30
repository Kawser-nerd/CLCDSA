using System;
using System.Collections.Generic;
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

#region Library

#region Integer

interface IInteger<T>
{
    T MinusOne { get; }
    T One { get; }
    T Zero { get; }

    T Add(T left, T right);
    int Compare(T left, T right);
    T Divide(T dividend, T divisor);
    T Multiply(T left, T right);
    T Negate(T value);
    T Remainder(T dividend, T divisor);
    T Subtract(T left, T right);
}

static class Integer<T>
{
    static IInteger<int> i = new IntOperations();
    static IInteger<long> l = new LongOperations();
    static IInteger<BigInteger> bi = new BigIntegerOperations();

    public static IInteger<T> Default
    {
        get
        {
            if (typeof(T) == typeof(int)) return (IInteger<T>)i;
            if (typeof(T) == typeof(long)) return (IInteger<T>)l;
            if (typeof(T) == typeof(BigInteger)) return (IInteger<T>)bi;
            throw new NotSupportedException();
        }
    }
}

class IntOperations : IInteger<int>
{
    public int MinusOne => -1;
    public int One => 1;
    public int Zero => 0;

    public int Add(int left, int right) => checked(left + right);
    public int Compare(int left, int right) => left.CompareTo(right);
    public int Divide(int dividend, int divisor) => dividend / divisor;
    public int Multiply(int left, int right) => checked(left * right);
    public int Negate(int value) => checked(-value);
    public int Remainder(int dividend, int divisor) => dividend % divisor;
    public int Subtract(int left, int right) => checked(left - right);
}

class LongOperations : IInteger<long>
{
    public long MinusOne => -1;
    public long One => 1;
    public long Zero => 0;

    public long Add(long left, long right) => checked(left + right);
    public int Compare(long left, long right) => left.CompareTo(right);
    public long Divide(long dividend, long divisor) => dividend / divisor;
    public long Multiply(long left, long right) => checked(left * right);
    public long Negate(long value) => checked(-value);
    public long Remainder(long dividend, long divisor) => dividend % divisor;
    public long Subtract(long left, long right) => checked(left - right);
}

class BigIntegerOperations : IInteger<BigInteger>
{
    public BigInteger MinusOne => BigInteger.MinusOne;
    public BigInteger One => BigInteger.One;
    public BigInteger Zero => BigInteger.Zero;

    public BigInteger Add(BigInteger left, BigInteger right)
        => BigInteger.Add(left, right);
    public int Compare(BigInteger left, BigInteger right)
        => BigInteger.Compare(left, right);
    public BigInteger Divide(BigInteger dividend, BigInteger divisor)
        => BigInteger.Divide(dividend, divisor);
    public BigInteger Multiply(BigInteger left, BigInteger right)
        => BigInteger.Multiply(left, right);
    public BigInteger Negate(BigInteger value)
        => BigInteger.Negate(value);
    public BigInteger Remainder(BigInteger dividend, BigInteger divisor)
        => BigInteger.Remainder(dividend, divisor);
    public BigInteger Subtract(BigInteger left, BigInteger right)
        => BigInteger.Subtract(left, right);
}

#endregion

#region Monoid

interface IMonoid<T>
{
    T Mempty { get; }
    T Mappend(T a, T b);
}

class Monoid<T> : IMonoid<T>
{
    public T Mempty { get; private set; }
    Func<T, T, T> mappend;
    public T Mappend(T a, T b) => mappend(a, b);

    public Monoid(T mempty, Func<T, T, T> mappend)
    {
        this.Mempty = mempty;
        this.mappend = mappend;
    }

    public static IMonoid<T> GetSumMonoid()
        => new IntegerSumMonoid<T>(Integer<T>.Default);

    public static IMonoid<T> GetSumMonoid(IInteger<T> integer)
        => new IntegerSumMonoid<T>(integer);

    public static IMonoid<T> GetMinMonoid(T upperBound)
        => new IntegerMinMonoid<T>(Integer<T>.Default, upperBound);

    public static IMonoid<T> GetMinMonoid(IInteger<T> integer, T upperBound)
        => new IntegerMinMonoid<T>(integer, upperBound);

    public static IMonoid<T> GetMaxMonoid(T lowerBound)
        => new IntegerMaxMonoid<T>(Integer<T>.Default, lowerBound);

    public static IMonoid<T> GetMaxMonoid(IInteger<T> integer, T lowerBound)
        => new IntegerMaxMonoid<T>(integer, lowerBound);
}

class IntegerSumMonoid<T> : IMonoid<T>
{
    protected readonly IInteger<T> integer;
    public T Mempty => integer.Zero;
    public T Mappend(T a, T b) => integer.Add(a, b);

    public IntegerSumMonoid(IInteger<T> integer)
    {
        this.integer = integer;
    }
}

class IntegerMinMonoid<T> : IMonoid<T>
{
    protected readonly IInteger<T> integer;
    public T Mempty { get; private set; }
    public T Mappend(T a, T b) => integer.Compare(a, b) < 0 ? a : b;

    public IntegerMinMonoid(IInteger<T> integer, T upperBound)
    {
        this.integer = integer;
        this.Mempty = upperBound;
    }
}

class IntegerMaxMonoid<T> : IMonoid<T>
{
    protected readonly IInteger<T> integer;
    public T Mempty { get; private set; }
    public T Mappend(T a, T b) => integer.Compare(a, b) > 0 ? a : b;

    public IntegerMaxMonoid(IInteger<T> integer, T lowerBound)
    {
        this.integer = integer;
        this.Mempty = lowerBound;
    }
}

#endregion

#region Group

interface IGroup<T> : IMonoid<T>
{
    T InvMappend(T a, T b);
}

class Group<T> : Monoid<T>, IGroup<T>
{
    Func<T, T, T> invMappend;
    public T InvMappend(T a, T b) => invMappend(a, b);

    public Group(T mempty, Func<T, T, T> mappend, Func<T, T, T> invMappend)
        : base(mempty, mappend)
    {
        this.invMappend = invMappend;
    }

    public static IGroup<T> GetSumGroup()
        => new IntegerSumGroup<T>(Integer<T>.Default);

    public static IGroup<T> GetSumGroup(IInteger<T> integer)
        => new IntegerSumGroup<T>(integer);
}

class IntegerSumGroup<T> : IntegerSumMonoid<T>, IGroup<T>
{
    public T InvMappend(T a, T b) => integer.Subtract(a, b);

    public IntegerSumGroup(IInteger<T> integer) : base(integer) { }
}

#endregion

class BinaryIndexedTree<T>
{
    T[] tree;

    public readonly int N;
    public readonly IMonoid<T> Monoid;
    readonly bool supportsGroup = false;

    // O(N)
    public BinaryIndexedTree(int n, IMonoid<T> monoid)
    {
        N = n;
        Monoid = monoid;
        tree = Enumerable.Repeat(monoid.Mempty, n + 1).ToArray();
    }

    // O(N)
    public BinaryIndexedTree(IEnumerable<T> collection, IMonoid<T> monoid)
    {
        N = collection.Count();
        Monoid = monoid;
        tree = new T[N + 1];
        for (var i = 0; i < N; i++) tree[i + 1] = collection.ElementAt(i);
        for (var i = 1; i < N; i++)
        {
            var j = i + (i & -i);
            if (j < N) tree[j] = monoid.Mappend(tree[j], tree[i]);
        }
    }

    // O(N)
    public BinaryIndexedTree(int n, IGroup<T> group)
        : this(n, (IMonoid<T>)group)
    {
        supportsGroup = true;
    }

    // O(N)
    public BinaryIndexedTree(IEnumerable<T> collection, IGroup<T> group)
        : this(collection, (IMonoid<T>)group)
    {
        supportsGroup = true;
    }

    public T this[int i]
    {
        // O(log N)
        get { return this[i, i]; }

        // O(log N)
        set
        {
            if (!supportsGroup) throw new InvalidOperationException();
            var group = (IGroup<T>)Monoid;
            Append(i, group.InvMappend(value, this[i]));
        }
    }

    public T this[int i, int j]
    {
        // O(log N)
        get
        {
            if (!supportsGroup) throw new InvalidOperationException();
            var group = (IGroup<T>)Monoid;
            var acc = group.Mempty;
            j++;
            for (; j > i; j -= j & -j) acc = group.Mappend(acc, tree[j]);
            for (; i > j; i -= i & -i) acc = group.InvMappend(acc, tree[i]);
            return acc;
        }
    }

    // O(log N)
    public T Concat(int i)
    {
        var acc = Monoid.Mempty;
        for (i++; i > 0; i -= i & -i) acc = Monoid.Mappend(acc, tree[i]);
        return acc;
    }

    // O(log N)
    public void Append(int i, T d)
    {
        for (i++; i <= N; i += i & -i) tree[i] = Monoid.Mappend(tree[i], d);
    }
}

static partial class Extentions
{
}

#endregion

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
        var kMax = 200000;
        var bit = new BinaryIndexedTree<int>(kMax + 1, Group<int>.GetSumGroup());

        var q = io.I;

        for (var i = 0; i < q; i++)
        {
            var t = io.C;
            var x = io.I;

            if (t == '2')
            {
                var ok = kMax;
                var ng = -1;

                while (Abs(ok - ng) > 1)
                {
                    var mid = (ok + ng) / 2;
                    if (bit.Concat(mid) >= x) ok = mid;
                    else ng = mid;
                }

                io.Write(ok);
                bit[ok] = 0;
            }
            else bit[x] = 1;
        }
    }
}