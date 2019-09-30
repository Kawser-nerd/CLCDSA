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

public sealed class Edge
    : IComparable<Edge>
{
    public int U, V;
    public long W;

    public Edge(int u, int v, long w)
    {
        U = u;
        V = v;
        W = w;
    }

    public int CompareTo(Edge other)
    {
        return Comparer<long>.Default.Compare(W, other.W);
    }
}

public sealed partial class Program
{
    int n;
    long[][] md;

    bool Verify()
    {
        for (var k = 0; k < n; k++)
        {
            for (var u = 0; u < n; u++)
            {
                for (var v = 0; v < n; v++)
                {
                    if (md[u][v] > md[u][k] + md[k][v])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    long Solve()
    {
        if (!Verify())
        {
            return -1;
        }

        /*
        var es = new Edge[n * n];
        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                es[i] = new Edge(i, j, md[i][j]);
            }
        }
        Array.Sort(es);

        var d = n.MakeArray(i => n.MakeArray(j => (long)int.MaxValue));
        for (var i = 0; i < n; i++)
        {
            d[i][i] = 0;
        }

        var notmin = 0;
        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < n; j++)
            {
                if (d[i][j] != md[i][j]) notmin++;
            }
        }

        for (var ei = 0; ei < es.Length; ei++)
        {
            var u = es[ei].U;
            var v = es[ei].V;
            var w = es[ei].W;

            var bipassExists = false;
            for (var k = 0; k < n; k++)
            {
                if (d[u][k] + d[k][v] == d[u][v])
                {

                }
            }
        }
        */

        var es = new HashSet<long>();
        for (var u = 0; u < n; u++)
        {
            for (var v = u + 1; v < n; v++)
            {
                es.Add(((long)u << 32) + v);
            }
        }

        {
            for (var u = 0; u < n; u++)
            {
                for (var v = 0; v < n; v++)
                {
                    if (u == v) continue;

                    var e = ((long)Math.Min(u, v) << 32) + Math.Max(u, v);
                    if (!es.Contains(e)) continue;

                    var bipassExists = false;
                    for (var k = 0; k < n; k++)
                    {
                        if (k == u || k == v) continue;

                        if (md[u][k] + md[k][v] == md[u][v])
                        {
                            bipassExists = true;
                            break;
                        }
                    }

                    if (bipassExists)
                    {
                        es.Remove(e);
                    }
                }
            }
        }

        return
            es.Sum(e =>
            {
                var u = (int)(e >> 32);
                var v = (int)(e & 0xFFFFFFFF);
                return md[u][v];
            });
    }

    void EntryPoint()
    {
        var q = scanner;
        n = q.N();
        md = n.MakeArray(i => n.MakeArray(j => q.L()));
        WriteLine(Solve());
    }
}