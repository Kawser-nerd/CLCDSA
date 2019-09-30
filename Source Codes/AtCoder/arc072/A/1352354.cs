using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    int n;
    long[] xs;

    void Read()
    {
        n = ReadLine(int.Parse)[0];
        xs = ReadLine(long.Parse);
    }

    long Solve(long[] xs)
    {
        var count = 0L;
        var s = xs[0];

        for (var i = 1; i < xs.Length; i++)
        {
            var t = s + xs[i];

            if (Math.Sign(t) == 0)
            {
                var d = s > 0 ? 1 : -1;
                t -= d;
                count += 1;
            }
            else if (Math.Sign(s) == Math.Sign(t))
            {
                var d = t + (t > 0 ? 1 : -1);
                t -= d;
                count += Math.Abs(d);
            }

            s = t;
        }

        return count;
    }

    long Calc()
    {
        if (xs[0] == 0)
        {
            var ys = xs.ToArray();
            xs[0] = 1;
            ys[0] = -1;
            return Math.Min(Solve(xs), Solve(ys)) + 1;
        }
        else
        {
            var ys = xs.ToArray();
            var d = ys[0] + (ys[0] > 0 ? 1 : -1);
            ys[0] -= d;

            return Math.Min(Solve(xs), Solve(ys) + Math.Abs(d));
        }
    }

    public void Run()
    {
        Read();
        WriteLineOne(Calc());
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}