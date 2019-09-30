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


public class Edge {
    public int V, Capacity, Rev;
}

public class FordFulkerson
{
    int N;
    List<Edge>[] G;
    bool[] Done;

    public FordFulkerson(int n)
    {
        N = n;
        G = n.MakeArray(_ => new List<Edge>());
    }

    public void Insert(int u, int v, int capacity)
    {
        // edge u?v

        G[u].Add(new Edge() {
            V = v,
            Capacity = capacity,
            Rev = G[v].Count,
        });
        G[v].Add(new Edge() {
            V = u,
            Capacity = 0,
            Rev = G[u].Count - 1
        });
    }

    int Dfs(int v, int t, int f)
    {
        if (v == t) return f;
        Done[v] = true;
        foreach (var e in G[v])
        {
            if (Done[e.V] || e.Capacity <= 0) continue;
            var d = Dfs(e.V, t, Math.Min(f, e.Capacity));
            if (d > 0) {
                e.Capacity -= d;
                G[e.V][e.Rev].Capacity += d;
                return d;
            }
        }

        return 0;
    }

    public int MaxFlow(int s, int t)
    {
        const int INF = 1 << 28;
        var flow = 0;
        while (true) {
            Done = new bool[N];
            var f = Dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
}

public sealed partial class Program
{
    private long Solve()
    {
        return 0;
    }

    public void EntryPoint()
    {
        var I = _scanner;

        var N = I.N();
        var R = N.MakeArray(_ => {
            var x = I.N();
            var y = I.N();
            return Tuple.Create(x, y);
        });
        var U = N.MakeArray(_ => {
            var x = I.N();
            var y = I.N();
            return Tuple.Create(x, y);
        });

        // S ? red ? blue ? T
        var ff = new FordFulkerson(2 * N + 2);
        var S = 2 * N;
        var T = 2 * N + 1;

        for (var i = 0; i < N; i++)
        {
            for (var j = 0; j < N; j++)
            {
                if (R[i].Item1 < U[j].Item1
                && R[i].Item2 < U[j].Item2
                )
                {
                    ff.Insert(i, N + j, 1);
                }
            }

            ff.Insert(S, i, 1);
            ff.Insert(N + i, T, 1);
        }

        var flow = ff.MaxFlow(S, T);

        WriteLine(flow);
    }
}