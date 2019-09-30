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

    int MaxIndex(IReadOnlyList<long> xs)
    {
        var max = long.MinValue;
        var maxIndex = 0;

        for (var i = 1; i < xs.Count; i++)
        {
            if (max < xs[i])
            {
                max = xs[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    public void Run()
    {
        var k = ReadLine(long.Parse)[0];
        const int N = 50;

        var m = k / N;
        var xs = Enumerable.Range(0, N).Select(i => i + m).ToArray();

        var l = (int)(k % N);
        for (var j = 0; j < l; j++)
        {
            for (var i = 0; i < N; i++)
            {
                if (i == j)
                {
                    xs[i] += N;
                }
                else
                {
                    xs[i]--;
                }
            }
        }

        WriteLineOne(N);
        WriteLineOne(string.Join(" ", xs));
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