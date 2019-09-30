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

    long p;

    long MeguruBinarySearch(long ok, long ng, Func<long, bool> isOk)
    {
        while (Math.Abs(ok - ng) > 1)
        {
            var m = (ok + ng) / 2;
            if (isOk(m))
            {
                ok = m;
            }
            else
            {
                ng = m;
            }
        }

        return ok;
    }

    bool CanReach(long t)
    {
        var x = p;
        for (var s = t; s >= 0; s--)
        {
            if (x <= s)
            {
                return true;
            }

            x -= s;
        }

        return false;
    }

    long Solve()
    {
        return MeguruBinarySearch(p, 0, CanReach);
    }

    public void Run()
    {
        p = ReadLine(long.Parse)[0];
        WriteLineOne(Solve());
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