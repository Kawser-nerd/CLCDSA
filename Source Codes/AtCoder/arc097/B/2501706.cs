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

public sealed class UnionFindForest
{
    private readonly int[] _parents;
    private readonly int[] _ranks;

    /// <summary>
    /// Constructs n-vertex UFF.
    /// </summary>
    public UnionFindForest(int n)
    {
        _parents = new int[n];
        _ranks = new int[n];

        for (var v = 0; v < n; v++)
        {
            _parents[v] = v;
            _ranks[v] = 1;
        }
    }

    /// <summary>
    /// Gets the representative of the specified vertex's group.
    /// </summary>
    public int Root(int v)
    {
        if (_parents[v] == v)
        {
            return v;
        }

        var r = Root(_parents[v]);
        _parents[v] = r;
        return r;
    }

    /// <summary>
    /// Gets a value indicating whether two vertices belong to the same group.
    /// </summary>
    public bool Connects(int u, int v)
    {
        return Root(u) == Root(v);
    }

    private static void Swap<X>(ref X l, ref X r)
    {
        var t = l;
        l = r;
        r = t;
    }

    /// <summary>
    /// Merges the specified vertices' group.
    /// </summary>
    public void Merge(int u, int v)
    {
        u = Root(u);
        v = Root(v);
        if (u == v) return;

        if (_ranks[u] > _ranks[v])
        {
            Swap(ref u, ref v);
        }

        _parents[u] = v;
        _ranks[v] += _ranks[u];
    }
}

public sealed partial class Program
{
    UnionFindForest Uff;

    private long Solve()
    {
        return 0;
    }

    public void EntryPoint()
    {
        var I = _scanner;
        var N = I.N();
        var M = I.N();
        var A = N.MakeArray(i => I.N() - 1);
        Uff = new UnionFindForest(N);

        var S = new bool[N];
        for (var i = 0; i < M; i++)
        {
            var l = I.N() - 1;
            var r = I.N() - 1;
            Uff.Merge(l, r);
            S[l] = true;
            S[r] = true;
        }

        var k = 0;
        var groups = Enumerable.Range(0, N).GroupBy(i => Uff.Root(i));
        foreach (var g in groups)
        {
            var R = new List<int>();
            foreach (var i in g)
            {
                if (Uff.Connects(i, A[i]))
                {
                    k++;
                }
            }
        }

        WriteLine(k);
    }
}