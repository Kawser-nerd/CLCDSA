using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Globalization;
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
    private readonly TextReader _reader;
    private readonly StringBuilder _sb = new StringBuilder();

    /// <summary>
    /// Reads next word separated by spaces.
    /// </summary>
    public string Word()
    {
        _sb.Clear();

        while (true)
        {
            var r = _reader.Read();

            if (r == ' ' || r == '\r' || r == '\n')
            {
                if (r == '\r' && _reader.Peek() == '\n')
                {
                    _reader.Read();
                }

                // Ignore leading spaces.
                if (_sb.Length == 0) continue;

                break;
            }
            else if (r == -1)
            {
                break;
            }
            else
            {
                _sb.Append((char)r);
            }
        }

        return _sb.ToString();
    }

    /// <summary>
    /// Reads next word as <see cref="int"/>.
    /// </summary>
    public int N()
    {
        return int.Parse(Word().Trim());
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

    /// <summary>
    /// Reads next line and splits it by spaces.
    /// </summary>
    public X[] Words<X>(Func<string, X> func)
    {
        return _reader.ReadLine().Split(' ').Select(func).ToArray();
    }

    public Scanner(TextReader reader)
    {
        _reader = reader;
    }
}

public partial class Program
{
    private readonly TextReader _input;
    private readonly TextWriter _output;
    private readonly Scanner _scanner;

    private void WriteLine(int value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(long value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(double value)
    {
        _output.WriteLine(value.ToString(CultureInfo.InvariantCulture));
    }

    private void WriteLine(char value)
    {
        _output.WriteLine(value);
    }

    private void WriteLine(string value)
    {
        _output.WriteLine(value);
    }

    public Program(TextReader input, TextWriter output)
    {
        _input = input;
        _output = output;
        _scanner = new Scanner(input);
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).EntryPoint();
    }
}

public sealed partial class Program
{
    const int MAX = 30000;

    int N;

    private static int gcd(int l, int r)
    {
        if (r == 0)
        {
            return l;
        }
        else
        {
            return gcd(r, l % r);
        }
    }

    private static int lcm(int l, int r)
    {
        return l / gcd(l, r) * r;
    }

    private static long gcdL(long l, long r)
    {
        if (r == 0)
        {
            return l;
        }
        else
        {
            return gcdL(r, l % r);
        }
    }

    private bool BruteForceCore(int[] a, int min, int max, int i)
    {
        if (a.Length == i)
        {
            var sum = a.Sum();
            var disjoint = a.Aggregate((l, r) => gcd(l, r)) == 1;
            var special = a.All(x => gcd(x, sum - x) != 1);
            return disjoint && special;
        }

        for (var x = min; x <= max; x++)
        {
            a[i] = x;
            if (BruteForceCore(a, x + 1, max, i + 1))
            {
                return true;
            }
        }

        return false;
    }

    private int[] BruteForce(int N, int l)
    {
        var a = new int[N];
        for (var m = l; m <= MAX; m++)
        {
            if (BruteForceCore(a, 2, m, 0))
            {
                return a;
            }
        }
        throw new Exception("No solution.");
    }

    private int Next(int n, int r)
    {
        if (n % 6 >= r)
        {
            n += 6;
        }
        return (n - (n % 6)) + r;
    }

    private int[] Solve()
    {
        if (N <= 5)
        {
            var t = new int[][] {
                new int[] { 5, 9, 16 },
                new int[] { 2, 3, 4, 9 },
                new int[] { 2, 3, 4, 6, 9 },
            };
            return t[N - 3];
        }

        var set = new HashSet<int>();
        var max = 0;
        var sum = 0L;
        for (var n = 2; ; n++)
        {
            if (n % 2 == 0 || n % 3 == 0)
            {
                set.Add(n);
                sum += n;
                max = Math.Max(max, n);
                if (set.Count == N)
                {
                    break;
                }
            }
        }

        switch (sum % 6)
        {
            case 2:
                set.Remove(8);
                set.Add(Next(max, 0));
                break;
            case 3:
                set.Remove(9);
                set.Add(Next(max, 0));
                break;
            case 5:
                set.Remove(9);
                set.Add(Next(max, 4));
                break;
            default:
                break;
        }

        return set.ToArray();
    }

    public void EntryPoint()
    {
        var I = _scanner;
        N = I.N();
        WriteLine(Solve().Intercalate(" "));
        return;
    }
}