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

    IEnumerable<long> Solve()
    {
        for (var i = n - 1; i >= 0; i -= 2)
        {
            yield return xs[i];
        }

        for (var i = n % 2; i < n; i += 2)
        {
            yield return xs[i];
        }
    }

    public void Run()
    {
        Read();
        output.WriteLine(string.Join(" ", Solve()));
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