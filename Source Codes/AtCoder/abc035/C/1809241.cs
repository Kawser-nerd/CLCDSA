using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Math;
using static Extensions;
using static MathExtensions;

public static class Program
{
    public static void Solve()
    {
        var n = I;
        var q = I;
        var imos = new Imos<int>(n, Group.Sum_Int32);

        Repeat(q, () =>
        {
            var l = I - 1;
            var r = I - 1;
            imos.Append(l, r, 1);
        });

        imos.Integrate();
        var ans = imos.Select(x => (x & 1) == 0 ? '0' : '1').AsString();

        Console.WriteLine(ans);
    }

    #region Scanners
    static Scanner _scanner;
    static char C => _scanner.NextChar();
    static string S => _scanner.NextString();
    static int I => _scanner.NextInt();
    static long L => _scanner.NextLong();
    static BigInteger B => _scanner.NextBigInteger();
    static double D => _scanner.NextDouble();
    static decimal M => _scanner.NextDecimal();
    #endregion

    public static void Main()
    {
        var sw = new StreamWriter(Console.OpenStandardOutput());
        sw.NewLine = "\n";
#if DEBUG
        sw.AutoFlush = true;
        //Console.SetError(sw);
#else
        sw.AutoFlush = false;
#endif
        Console.SetOut(sw);
        _scanner = new Scanner(Console.OpenStandardInput());
        Solve();
        Console.Out.Flush();
    }
}

public static partial class Extensions
{
}

#region Library
public class Scanner
{
    private readonly Stream _stream;
    private const int _bufferSize = 1024;
    private readonly byte[] _buf = new byte[_bufferSize];
    private int _len, _ptr;

    public Scanner(Stream stream)
    {
        _stream = stream;
    }

    public byte ReadByte()
    {
        if (_ptr >= _len)
        {
            _len = _stream.Read(_buf, 0, _bufferSize);
            _ptr = 0;
        }
        return _buf[_ptr++];
    }

    public char ReadChar() => (char)ReadByte();

    public string ReadLine()
    {
        var r = new StringBuilder();
        if (_ptr == 0) r.Append(ReadChar());
        for (; _ptr < _len; _ptr++) r.Append((char)_buf[_ptr]);
        return r.ToString();
    }

    public char NextChar() => char.Parse(NextString());

    public string NextString()
    {
        var r = new StringBuilder();
        var b = ReadChar();
        while (b != ' ' && b != '\n')
        {
            r.Append(b);
            b = ReadChar();
        }
        return r.ToString();
    }

    public int NextInt() => (int)NextLong();

    public long NextLong()
    {
        var r = 0L;
        var b = ReadByte();
        var n = b == '-';
        if (n) b = ReadByte();
        while (b != ' ' && b != '\n')
        {
            r = r * 10 + b - '0';
            b = ReadByte();
        }
        return n ? -r : r;
    }

    public BigInteger NextBigInteger()
    {
        var r = new BigInteger();
        var b = ReadByte();
        var n = b == '-';
        if (n) b = ReadByte();
        while (b != ' ' && b != '\n')
        {
            r = r * 10 + b - '0';
            b = ReadByte();
        }
        return n ? -r : r;
    }

    public double NextDouble()
    {
        var i = 0L;
        var b = ReadByte();
        var n = b == '-';
        if (n) b = ReadByte();
        while (b != '.' && b != ' ' && b != '\n')
        {
            i = i * 10 + b - '0';
            b = ReadByte();
        }
        if (b != '.') return n ? -i : i;
        b = ReadByte();
        var f = 0L;
        var p = 0;
        while (b != ' ' && b != '\n')
        {
            f = f * 10 + b - '0';
            b = ReadByte();
            p++;
        }
        var r = i + (double)f / MathExtensions.Pow(10, p);
        return n ? -r : r;
    }

    public decimal NextDecimal() => decimal.Parse(NextString());

    public T Next<T>(Converter<string, T> parser) => parser(NextString());
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

    public static readonly Monoid<int> Min_Int32 = new Monoid<int>(int.MaxValue, Min);
    public static readonly Monoid<int> Max_Int32 = new Monoid<int>(int.MinValue, Max);

    public static readonly Monoid<long> Min_Int64 = new Monoid<long>(long.MaxValue, Min);
    public static readonly Monoid<long> Max_Int64 = new Monoid<long>(long.MinValue, Max);
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

    public static readonly Group<int> Sum_Int32 = new Group<int>(0, (x, y) => x + y, x => -x);
    public static readonly Group<long> Sum_Int64 = new Group<long>(0L, (x, y) => x + y, x => -x);
}

public class Imos<T> : IReadOnlyList<T>
{
    private readonly T[] _array;

    public Imos(int length, Monoid<T> monoid)
    {
        _array = Enumerable.Repeat(monoid.Unit, length).ToArray();
        this.Monoid = monoid;
    }

    public Imos(int length, Group<T> group) : this(length, (Monoid<T>)group)
    {
        this.Group = group;
    }

    public Monoid<T> Monoid { get; }

    public Group<T> Group { get; }

    public int Degree { get; private set; } = -1;

    public int Length => _array.Length;

    int IReadOnlyCollection<T>.Count => this.Length;

    public T this[int i]
    {
        get
        {
            if (this.Degree > 0) return _array[i];
            throw new InvalidOperationException();
        }
    }

    public IEnumerator<T> GetEnumerator()
    {
        if (this.Degree < 0) throw new InvalidOperationException();
        foreach (var value in _array) yield return value;
    }

    IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

    public void Append(int l, int r, T value)
    {
        _array[l] = this.Group.Append(_array[l], value);
        if (r == _array.Length - 1) return;
        _array[r + 1] = this.Group.Append(_array[r + 1], this.Group.Invert(value));
    }

    public void Append(int l, T value)
    {
        _array[l] = this.Monoid.Append(_array[l], value);
    }

    public void Integrate()
    {
        for (var i = 1; i < _array.Length; i++)
            _array[i] = this.Monoid.Append(_array[i - 1], _array[i]);
        this.Degree++;
    }

    public void Differentiate()
    {
        if (this.Degree < 0) throw new InvalidOperationException();
        for (var i = _array.Length - 1; i > 0; i--)
            _array[i] = this.Group.Append(_array[i], this.Group.Invert(_array[i - 1]));
        this.Degree--;
    }
}

[DebuggerStepThrough]
public static partial class Extensions
{
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

    public static T Iterate<T>(int count, T seed, Func<T, T> func)
    {
        var r = seed;
        Repeat(count, () => { r = func(r); });
        return r;
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
}

[DebuggerStepThrough]
public static class MathExtensions
{
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