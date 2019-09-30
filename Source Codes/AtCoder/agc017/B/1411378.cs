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

    long n, a, b, c, d;

    void Read()
    {
        var line = ReadLine(long.Parse);
        n = line[0];
        a = line[1];
        b = line[2];
        c = line[3];
        d = line[4];
    }

    bool IsOk(int m)
    {
        // a + ?(c + p_i) - ?(c + q_i) = b ??? (p_i), (q_i) ?????????
        // ??? 0 <= p_i, q_i <= d - c = r?
        // (p_i) ???? m ????(q_i) ???? l?
        var r = d - c;
        var l = n - 1 - m;

        // a + (m - l) * c + ?p - ?q = b
        // ?p - ?q = b - a + (l - m) * c = f
        // ?p ? [0, m * r] ????q ? [0, l * r] ????????
        // ?p - ?q ? [-l * r, m * r] ????????
        // f ? [-l * r, m * r] ???????
        var f = b - a + (l - m) * c;
        return -l * r <= f && f <= m * r;
    }

    bool Solve()
    {
        for (var m = 0; m <= n - 1; m++)
        {
            if (IsOk(m)) return true;
        }

        return false;
    }

    public void Run()
    {
        Read();
        WriteLineOne(Solve() ? "YES" : "NO");
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