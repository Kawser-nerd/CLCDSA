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

            if (r == '\r')
            {
                if (_reader.Peek() == '\n') _reader.Read();
                break;
            }
            else if (r == -1 || r == ' ' || r == '\n')
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

public sealed partial class Program
{
    int N;
    int[] A;

    private Tuple<int, int>[] SolveCore(int[] xs, int maxIndex)
    {
        return Enumerable.Range(0, N).Select(i => Tuple.Create(maxIndex, i)).Concat(Enumerable.Range(0, N - 1).Select(i => Tuple.Create(i, i + 1))).ToArray();
    }

    private Tuple<int, int>[] Solve()
    {
        var maxIndex = 0;
        var maxAbs = int.MinValue;

        for (var i = 0; i < N; i++)
        {
            var a = Math.Abs(A[i]);
            if (maxAbs < a)
            {
                maxAbs = a;
                maxIndex = i;
            }
        }

        if (A[maxIndex] >= 0)
        {
            return SolveCore(A, maxIndex);
        }
        else
        {
            var ys = A.Select(a => -a).Reverse().ToArray();
            var instr = SolveCore(ys, N - 1 - maxIndex);
            return instr.Select(t => Tuple.Create(N - 1 - t.Item1, N - 1 - t.Item2)).ToArray();
        }
    }

    private void Read()
    {
        var a = _scanner;
        N = a.N();
        A = N.MakeArray(i => a.N());
    }

    bool Validate(Tuple<int, int>[] instr)
    {
        var xs = A.ToArray();
        foreach (var t in instr)
        {
            xs[t.Item2] += xs[t.Item1];
        }

        for (var i = 0; i + 1 < N; i++)
        {
            if (xs[i] > xs[i + 1]) return false;
        }
        return true;
    }

    public void EntryPoint()
    {
        Read();

        var instr = Solve();
        Debug.Assert(Validate(instr));

        WriteLine(instr.Length);
        foreach (var t in instr)
        {
            WriteLine(string.Format("{0} {1}", t.Item1 + 1, t.Item2 + 1));
        }
    }
}