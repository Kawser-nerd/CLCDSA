// Written after reading official answer. Solved with weighted union find forest.
// https://beta.atcoder.jp/contests/arc090/tasks/arc090_b

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
        _output.WriteLine(value);
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




public class WeightedUnionFindForest
{
    public readonly int N;
    public int[] Parent;
    public long[] Cost;
    public int[] Rank;

    public WeightedUnionFindForest(int n)
    {
        N = n;

        Parent = new int[n];
        Cost = new long[n];
        Rank = new int[n];

        for (var i = 0; i < n; i++)
        {
            Parent[i] = i;
        }
    }

    public int Root(int u, out long cost)
    {
        if (Parent[u] == u)
        {
            cost = Cost[u];
            return u;
        }
        else
        {
            var v = Root(Parent[u], out cost);
            cost += Cost[u];

            Parent[u] = v;
            Cost[u] = cost;
            return v;
        }
    }

    public void Assign(int lv, int rv, long cost)
    {
        // [ lv_1 ] ?[cost_1]-- [ rv_1 ]
        //    ?                    ?
        //   [lc]                 [rc]
        //    ?                    ?
        // [ lv_2 ] ?[cost_2]-- [ rv_2 ]
        {
            long lc, rc;

            lv = Root(lv, out lc);
            rv = Root(rv, out rc);
            cost = -rc + cost + lc;
        }

        if (Rank[lv] < Rank[rv])
        {
            // Generic merging tech.
            Assign(rv, lv, -cost);
            return;
        }

        Parent[rv] = lv;
        Cost[rv] = cost;
        Rank[lv] += Rank[rv] + 1;
    }

    public bool IsValid()
    {
        for (var v = 0; v < N; v++)
        {
            long _;
            Root(v, out _);
        }

        for (var v = 0; v < N; v++)
        {
            if (Parent[v] == v && Cost[v] != 0) return false;
        }
        return true;
    }
}

public sealed partial class Program
{
    int N, M;

    public void EntryPoint()
    {
        var I = _scanner;
        N = I.N();
        M = I.N();

        var wuff = new WeightedUnionFindForest(N);

        for (var mi = 0; mi < M; mi++)
        {
            var l = I.N() - 1;
            var r = I.N() - 1;
            var d = I.L();

            wuff.Assign(l, r, -d);
        }

        var ok = wuff.IsValid();

        WriteLine(ok ? "Yes" : "No");
    }
}