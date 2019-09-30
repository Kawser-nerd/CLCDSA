using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public sealed partial class Program
{
    long x;

    long Solve()
    {
        var k = (x / 11) * 2;
        var r = x % 11;
        if (r == 0) return k;
        if (r <= 6) return k + 1;
        return k + 2;
    }

    void Read()
    {
        var a = scanner;
        x = a.L;
    }

    public void EntryPoint()
    {
        Read();
        WriteLine(Solve());
    }
}

#region Custom Library
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

    public static void ForEach<X>(this IEnumerable<X> @this, Action<X, int> action)
    {
        var list = @this as IReadOnlyList<X>;
        if (list != null)
        {
            var count = list.Count;
            for (var i = 0; i < count; i++)
            {
                action(list[i], i);
            }
        }
        else
        {
            var i = 0;
            foreach (var x in @this)
            {
                action(x, i);
                i++;
            }
        }
    }
}

public sealed class Scanner
{
    readonly TextReader reader;

    /// <summary>
    /// Reads next word separated by spaces.
    /// </summary>
    public string Word()
    {
        var sb = default(StringBuilder);
        var firstChar = default(char);
        var count = 0;

        while (true)
        {
            var c = reader.Read();

            if (c == '\r')
            {
                if (reader.Peek() == '\n') reader.Read();
                break;
            }
            else if (c == -1 || c == ' ' || c == '\n')
            {
                break;
            }
            else
            {
                switch (count)
                {
                    case 0:
                        firstChar = (char)c;
                        count = 1;
                        break;
                    case 1:
                        sb = new StringBuilder();
                        sb.Append(firstChar).Append((char)c);
                        count = 2;
                        break;
                    default:
                        sb.Append((char)c);
                        break;
                }
            }
        }

        switch (count)
        {
            case 0:
                return "";
            case 1:
                return firstChar.ToString();
            default:
                return sb.ToString();
        }
    }

    /// <summary>
    /// Reads next word as <see cref="int"/>.
    /// </summary>
    public int N
    {
        get
        {
            return int.Parse(Word());
        }
    }

    /// <summary>
    /// Reads next word as <see cref="long"/>.
    /// </summary>
    public long L
    {
        get
        {
            return long.Parse(Word());
        }
    }

    /// <summary>
    /// Reads next word as <see cref="double"/>.
    /// </summary>
    public double F
    {
        get
        {
            return double.Parse(Word());
        }
    }

    public int[] Ns(int count)
    {
        return count.MakeArray(_ => N);
    }

    public long[] Ls(int count)
    {
        return count.MakeArray(_ => L);
    }

    public double[] Fs(int count)
    {
        return count.MakeArray(_ => F);
    }

    /// <summary>
    /// Reads next line and splits it by spaces.
    /// </summary>
    public IEnumerable<X> Words<X>(Func<string, X> func)
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
        new Program(Console.In, Console.Out).EntryPoint();
    }
}
#endregion