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
    int N, A, B;

    static int[] Failure = new[] { -1 };

    int[] TrySplit(int m, int k)
    {
        if (m < k) return null;

        var xs = new int[k + 1];
        var r = m % k;

        for (var i = 0; i < k; i++)
        {
            xs[i] = (m + k - 1) / k + (r == 0 || i < r ? 0 : -1);
        }

        return xs;
    }

    private int[] Solve()
    {
        if (A == N && B == 1)
        {
            return Enumerable.Range(1, N).ToArray();
        }
        if (A == 1 && B == N)
        {
            return Enumerable.Range(1, N).Reverse().ToArray();
        }

        if (A <= 1 || B <= 1) return Failure;
        if (N <= A || N <= B) return Failure;

        var chunkLengths = TrySplit(N - A, B - 1);
        if (chunkLengths == null) return Failure;
        chunkLengths[B - 1] = A;

        // Console.Error.WriteLine(chunkLengths.Intercalate(", "));
        if (chunkLengths.Sum() != N) throw new Exception("Bug.");

        if (!(chunkLengths.Length == B
        && chunkLengths.All(l => 1 <= l && l <= A)))
        {
            return Failure;
        }

        var chunks = B.MakeArray(i => new int[chunkLengths[i]]);
        var queue = new Queue<Tuple<int, int>>();
        for (var j = 0; j < B; j++)
        {
            queue.Enqueue(Tuple.Create(j, 0));
        }
        for (var i = 0; i < N; i++)
        {
            var pair = queue.Dequeue();
            var j = pair.Item1;
            var k = pair.Item2;

            chunks[j][k] = 1 + i;

            if (k + 1 < chunkLengths[j])
            {
                queue.Enqueue(Tuple.Create(j, k + 1));
            }
        }

        var result = new int[N];
        {
            var i = 0;
            foreach (var chunk in chunks.Reverse())
            {
                foreach (var x in chunk)
                {
                    result[i] = x;
                    i++;
                }
            }
        }
        return result;
    }

    public void EntryPoint()
    {
        // Check();

        var I = _scanner;
        N = I.N();
        A = I.N();
        B = I.N();

        WriteLine(Solve().Select(x => x.ToString()).Intercalate(" "));
    }

    void Check()
    {
        for (var m = 1; m < 20; m++)
        {
            for (var k = 1; k < m; k++)
            {
                var xs = TrySplit(m, k);
                if (xs == null) continue;

                if (xs.Sum() != m)
                {
                    Console.Error.WriteLine($"m={m} k={k} xs={ xs.Intercalate(", ")}");
                }
            }
        }
    }
}