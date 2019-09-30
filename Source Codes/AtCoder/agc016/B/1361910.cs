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
    int[] ks;

    bool CanColorize(int count, int k)
    {
        return count <= 1 ? k == 0 : 1 <= k && k <= count / 2;
    }

    bool Solve()
    {
        var sorted = ks.OrderBy(k => k).ToArray();
        var d = sorted.Last() - sorted.First();

        if (d == 0)
        {
            if (sorted[0] == n - 1) return true;

            return CanColorize(n, sorted[0]);
        }
        else if (d == 1)
        {
            var minValue = sorted[0];
            var minValueCount = sorted.TakeWhile(k => k == minValue).Count();
            if (minValue < minValueCount) return false;

            var maxValue = sorted.Last();
            var maxValueCount = maxValue - minValueCount;
            return CanColorize(n - minValueCount, maxValueCount);
        }
        else
        {
            return false;
        }
    }

    public void Run()
    {
        n = ReadLine(int.Parse)[0];
        ks = ReadLine(int.Parse);
        WriteLineOne(Solve() ? "Yes" : "No");
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