using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
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

    public static BigInteger Abs(this BigInteger @this)
    {
        return @this.Sign >= 0 ? @this : -@this;
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

public sealed class Solver
{
    bool IsSorted(long[] xs)
    {
        for (var i = 0; i < xs.Length - 1; i++)
        {
            if (xs[i] > xs[i + 1])
            {
                return false;
            }
        }

        return true;
    }

    Tuple<int, int>[] SolveCore(BigInteger[] xs, int maxIndex)
    {
        var n = xs.Length;
        var instr = new List<Tuple<int, int>>();
        var max = xs[maxIndex];

        var i = 0;

        while (i + 1 < n && instr.Count <= n * 2)
        {
            if (xs[i] <= xs[i + 1])
            {
                i++;
                continue;
            }

            if (xs[i] <= xs[i + 1] + max)
            {
                xs[i + 1] += max;
                instr.Add(Tuple.Create(maxIndex, i + 1));
                continue;
            }

            xs[n - 1] += max;
            instr.Add(Tuple.Create(maxIndex, n - 1));

            if (max < xs[n - 1])
            {
                maxIndex = n - 1;
                max = xs[maxIndex];
            }

            continue;
        }

        return instr.ToArray();
    }

    public Tuple<int, int>[] Solve(BigInteger[] xs)
    {
        var maxAbs = new BigInteger(-1);
        var index = 0;
        for (var i = 0; i < xs.Length; i++)
        {
            var a = xs[i].Abs();
            if (maxAbs < a)
            {
                maxAbs = a;
                index = i;
            }
        }

        if (xs[index] < 0)
        {
            var n = xs.Length;
            var ys = xs.Select(x => -x).Reverse().ToArray();
            var instr = SolveCore(ys, n - index - 1);
            return instr.Select(t => Tuple.Create(n - t.Item1 - 1, n - t.Item2 - 1)).ToArray();
        }
        else
        {
            return SolveCore(xs, index);
        }
    }

    public void VerifyRandomly()
    {
        var rng = new Random();
        var xl = -1000000;
        var xr = 1000000 + 1;

        for (var n = 50; n <= 50; n++)
        {
            Console.WriteLine("n = " + n);

            for (var r = 0; r < 1000000; r++)
            {
                var xs = n.MakeArray(i => new BigInteger(rng.Next(xl, xr)));
                var instr = Solve(xs);

                if (instr.Length > n * 2)
                {
                    Console.WriteLine("Couldn't solve: " + xs.Select(x => x.ToString()).Intercalate(", "));
                }
            }
        }
    }
}

public sealed partial class Program
{
    int N;
    int[] A;

    private long Solve()
    {
        return 0;
    }

    private void Read()
    {
        var a = _scanner;
        N = a.N();
        A = N.MakeArray(i => a.N());
    }

    public void EntryPoint()
    {
        //new Solver().VerifyRandomly();

        Read();

        var solver = new Solver();
        var instr = solver.Solve(A.Select(x => new BigInteger(x)).ToArray());

        WriteLine(instr.Length);
        foreach (var t in instr)
        {
            WriteLine(string.Format("{0} {1}", t.Item1 + 1, t.Item2 + 1));
        }
    }
}