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

public class Summary
{
    public int Index;
    public long Sum;
    public bool AllNegative;
    public long Max;
    public int MaxIndex;
    public int Count;
}

public sealed partial class Program
{
    Summary Summarize(long[] A, int index)
    {
        var N = A.Length;

        var s = new Summary()
        {
            Index = index,
            Count = N,
            Sum = 0L,
            Max = A[index],
            MaxIndex = index,
            AllNegative = true
        };

        for (var i = index; i < N; i += 2)
        {
            if (A[i] > 0)
            {
                s.Sum += A[i];
                s.AllNegative = false;
            }

            if (A[i] > s.Max)
            {
                s.Max = A[i];
                s.MaxIndex = i;
            }
        }

        if (s.AllNegative)
        {
            s.Sum = s.Max;
        }

        return s;
    }

    List<int> Instr(long[] A, Summary summary)
    {
        var N = A.Length;
        var output = new List<int>();

        if (summary.AllNegative)
        {
            var len = N;

            for (var i = 0; i < summary.MaxIndex; i++)
            {
                output.Add(1);
                len--;
            }

            while (len >= 2)
            {
                output.Add(len);
                len--;
            }

            return output;
        }
        else
        {
            var i = 0;
            var len = N;

            while (i < summary.Index)
            {
                output.Add(1);
                len--;
                i++;
            }

            // ???????????????
            while (i < N && A[i] <= 0)
            {
                output.Add(1);
                output.Add(1);
                len -= 2;
                i += 2;
            }

            // ?????????????????????????????
            // ??? (i + 2) ???????????????????????????
            // S x T y ...
            // T > 0 ?? [2] ? (S+T) y ...
            // T <= 0 ?? [3] ? S (x+y) ...

            while (i < N)
            {
                if (i + 2 < N && A[i + 2] > 0)
                {
                    output.Add(2);
                    len -= 2;
                    i += 2;
                }
                else if (i + 3 < N && A[i + 2] <= 0)
                {
                    output.Add(3);
                    len -= 2;
                    i += 2;
                }
                else
                {
                    break;
                }
            }

            while (len > 1)
            {
                output.Add(len);
                len--;
            }
            return output;
        }
    }

    public void EntryPoint()
    {
        var I = _scanner;
        var N = I.N();
        var A = N.MakeArray(_ => I.L());

        var s1 = Summarize(A, 0);
        var s2 = Summarize(A, 1);

        if (s1.Sum >= s2.Sum)
        {
            var instr = Instr(A, s1);
            WriteLine(s1.Sum);
            WriteLine(instr.Count);
            foreach (var i in instr)
            {
                WriteLine(i);
            }
        }
        else
        {
            var instr = Instr(A, s2);
            WriteLine(s2.Sum);
            WriteLine(instr.Count);
            foreach (var i in instr)
            {
                WriteLine(i);
            }
        }

        return;
    }
}