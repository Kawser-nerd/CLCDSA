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

    long n, m;

    void Read()
    {
        var line = ReadLine(long.Parse);
        n = line[0];
        m = line[1];
    }

    static long BinarySearch(long ok, long ng, Func<long, bool> isOk)
    {
        while (Math.Abs(ok - ng) > 1)
        {
            var mid = (ok + ng) / 2;
            if (isOk(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return ok;
    }

    long Count(long n, long m, long k)
    {
        var s = n + k;
        var c = m - 2 * k;
        return k < 0 || s <= 0 || c <= 0 ? 0 : Math.Min(s, c / 2);
    }

    long Solve()
    {
        var l =
            BinarySearch(ok: 0L, ng: m / 2, isOk: k =>
                Count(n, m, k) - Count(n, m, k - 1) >= 0
            );
        return Count(n, m, l);
    }

    public void Run()
    {
        Read();
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