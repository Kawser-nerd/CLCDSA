using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class TemplateExtension
{
    public static X[] MakeArray<X>(this int count, Func<int, X> func)
    {
        var xs = new X[count];
        for (var i = 0; i < count; i++)
        {
            xs[i] = func(i);
        }
        return xs;
    }

    public static int[] Range(this int count, int start = 0)
    {
        return count.MakeArray(i => i + start);
    }

    public static string Intercalate<X>(this IEnumerable<X> @this, string separator)
    {
        return string.Join(separator, @this);
    }

    public sealed class ValueIndexPair<T>
        : Tuple<T, int>
    {
        public T Value { get { return Item1; } }
        public int Index { get { return Item2; } }

        public ValueIndexPair(T value, int index)
            : base(value, index)
        {
        }
    }

    public static IEnumerable<ValueIndexPair<X>> Indexed<X>(this IEnumerable<X> @this)
    {
        var i = 0;
        foreach (var x in @this)
        {
            yield return new ValueIndexPair<X>(x, i);
            i++;
        }
    }
}

public sealed class Scanner
{
    readonly TextReader reader;
    readonly StringBuilder sb = new StringBuilder();

    /// <summary>
    /// Reads next word separated by spaces.
    /// </summary>
    public string Word()
    {
        sb.Clear();

        while (true)
        {
            var r = reader.Read();

            if (r == '\r')
            {
                if (reader.Peek() == '\n') reader.Read();
                break;
            }
            else if (r == -1 || r == ' ' || r == '\n')
            {
                break;
            }
            else
            {
                sb.Append((char)r);
            }
        }

        return sb.ToString();
    }

    /// <summary>
    /// Reads next word as <see cref="int"/>.
    /// </summary>
    public int N()
    {
        return int.Parse(Word());
    }

    /// <summary>
    /// Reads next word as <see cref="long"/>.
    /// </summary>
    public long L()
    {
        return long.Parse(Word());
    }

    /// <summary>
    /// Reads next word as <see cref="double"/>.
    /// </summary>
    public double F()
    {
        return double.Parse(Word());
    }

    public int[] Ns(int count)
    {
        return count.MakeArray(_ => N());
    }

    public long[] Ls(int count)
    {
        return count.MakeArray(_ => L());
    }

    public double[] Fs(int count)
    {
        return count.MakeArray(_ => F());
    }

    /// <summary>
    /// Reads next line and splits it by spaces.
    /// </summary>
    public X[] Words<X>(Func<string, X> func)
    {
        return reader.ReadLine().Split(' ').Select(func).ToArray();
    }

    public Scanner(TextReader reader)
    {
        this.reader = reader;
    }
}

public partial class Program
{
    readonly TextReader input;
    readonly TextWriter output;
    readonly Scanner scanner;

    void WriteLine(int value)
    {
        output.WriteLine(value);
    }

    void WriteLine(long value)
    {
        output.WriteLine(value);
    }

    void WriteLine(double value)
    {
        output.WriteLine(value);
    }

    void WriteLine(char value)
    {
        output.WriteLine(value);
    }

    void WriteLine(string value)
    {
        output.WriteLine(value);
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
        scanner = new Scanner(input);
    }

    public static void Main(string[] args)
    {
#if DEBUG
        using (var writer = new VainZero.IO.DebugTextWriter(Console.Out))
#else
        var writer = Console.Out;
#endif
        {
            new Program(Console.In, writer).EntryPoint();
        }
    }
}

/// <summary>
/// Provides binary search implementations.
/// </summary>
public static class BinarySearch
{
    /// <summary>
    /// Performs Meguru-style binary search.
    /// <seealso cref="https://twitter.com/meguru_comp/status/697008509376835584"/>
    /// </summary>
    public static int Meguru(int ok, int ng, Func<int, bool> isOk)
    {
        while (Math.Abs(ok - ng) > 1)
        {
            var mid = (ok + ng) / 2;
            if (isOk(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return ok;
    }

    /// <summary>
    /// Performs Meguru-style binary search.
    /// </summary>
    public static long Meguru(long ok, long ng, Func<long, bool> isOk)
    {
        while (Math.Abs(ok - ng) > 1)
        {
            var mid = (ok + ng) / 2;
            if (isOk(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return ok;
    }

    /// <summary>
    /// Performs binary search
    /// to find the lower bound index of the specified value in the range.
    /// </summary>
    public static int LowerBound<X>(this IReadOnlyList<X> @this, X value, int lb, int ub, IComparer<X> comparer)
    {
        if (lb > ub) throw new ArgumentOutOfRangeException(nameof(ub));

        while (lb != ub)
        {
            var m = lb + (ub - lb) / 2;
            if (comparer.Compare(@this[m], value) < 0)
            {
                lb = m + 1;
            }
            else
            {
                ub = m;
            }
        }

        return lb;
    }

    /// <summary>
    /// Performs binary search
    /// to find the lower bound index of the specified value.
    /// </summary>
    public static int LowerBound<X>(this IReadOnlyList<X> @this, X value, IComparer<X> comparer)
    {
        return LowerBound(@this, value, 0, @this.Count, comparer);
    }

    /// <summary>
    /// Performs binary search
    /// to find the lower bound index of the specified value in the range.
    /// </summary>
    public static int LowerBound<X>(this IReadOnlyList<X> @this, X value, int lb, int ub)
    {
        return LowerBound(@this, value, lb, ub, Comparer<X>.Default);
    }

    /// <summary>
    /// Performs binary search
    /// to find the lower bound index of the specified value.
    /// </summary>
    public static int LowerBound<X>(this IReadOnlyList<X> @this, X value)
    {
        return LowerBound(@this, value, 0, @this.Count, Comparer<X>.Default);
    }

    /// <summary>
    /// Performs binary search
    /// to find the upper bound index of the specified value in the range.
    /// </summary>
    public static int UpperBound<X>(this IReadOnlyList<X> @this, X value, int lb, int ub, IComparer<X> comparer)
    {
        if (lb > ub) throw new ArgumentOutOfRangeException(nameof(ub));

        while (lb != ub)
        {
            var m = lb + (ub - lb) / 2;
            if (comparer.Compare(@this[m], value) <= 0)
            {
                lb = m + 1;
            }
            else
            {
                ub = m;
            }
        }

        return lb;
    }

    /// <summary>
    /// Performs binary search
    /// to find the upper bound index of the specified value.
    /// </summary>
    public static int UpperBound<X>(this IReadOnlyList<X> @this, X value, IComparer<X> comparer)
    {
        return UpperBound(@this, value, 0, @this.Count, comparer);
    }

    /// <summary>
    /// Performs binary search
    /// to find the upper bound index of the specified value in the range.
    /// </summary>
    public static int UpperBound<X>(this IReadOnlyList<X> @this, X value, int lb, int ub)
    {
        return UpperBound(@this, value, lb, ub, Comparer<X>.Default);
    }

    /// <summary>
    /// Performs binary search
    /// to find the upper bound index of the specified value.
    /// </summary>
    public static int UpperBound<X>(this IReadOnlyList<X> @this, X value)
    {
        return UpperBound(@this, value, 0, @this.Count, Comparer<X>.Default);
    }
}

public sealed partial class Program
{
    int Solve()
    {
        var a = scanner;
        var n = a.N();
        var xs = n.MakeArray(_ => a.N());
        Array.Sort(xs);

        var max = 0;

        for (var i = -1; i <= 100001; i++)
        {
            var lb = xs.LowerBound(i - 1);
            var ub = xs.UpperBound(i + 1);
            max = Math.Max(max, ub - lb);
        }

        return max;
    }

    public void EntryPoint()
    {
        WriteLine(Solve());
    }
}