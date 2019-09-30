using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Console;
using static System.Convert;
using static System.Math;
using static Extentions;

class IO
{
    int idx;
    string[] input;

    public IO(TextReader reader)
    {
        input = reader.ReadToEnd().Split(new[] { " ", "\n", "\r" },
            StringSplitOptions.RemoveEmptyEntries);
    }

    T Get<T>(Func<string, T> parser) => parser(input[idx++]);

    public string S => Get(s => s);
    public char C => Get(char.Parse);
    public int I => Get(int.Parse);
    public long L => Get(long.Parse);
    public double F => Get(double.Parse);
    public decimal D => Get(decimal.Parse);
    public BigInteger B => Get(BigInteger.Parse);

    T[] Gets<T>(int n, Func<string, T> parser)
        => input.Skip((idx += n) - n).Take(n).Select(parser).ToArray();

    public string[] Ss(int n) => Gets(n, s => s);
    public char[] Cs(int n) => Gets(n, char.Parse);
    public int[] Is(int n) => Gets(n, int.Parse);
    public long[] Ls(int n) => Gets(n, long.Parse);
    public double[] Fs(int n) => Gets(n, double.Parse);
    public decimal[] Ds(int n) => Gets(n, decimal.Parse);
    public BigInteger[] Bs(int n) => Gets(n, BigInteger.Parse);

    public void Write<T>(params T[] xs) => WriteLine(string.Join(" ", xs));
    public void Write(params object[] xs) => WriteLine(string.Join(" ", xs));
}

static class Extentions
{
}

static class Program
{
    public static void Main()
    {
        var sw = new StreamWriter(OpenStandardOutput()) { NewLine = "\n" };
#if DEBUG
        sw.AutoFlush = true;
#else
        sw.AutoFlush = false;
#endif
        SetOut(sw);
        Solve(new IO(In));
        Out.Flush();
    }

    public static void Solve(IO io)
    {
        var k = io.L;
        var n = 50L;

        var t = k;
        while ((t - 1) % n != 0) t--;

        var a = new long[n];
        var u = a[0] = n + (t - 1) / n;
        a[1] = a[0] - n;
        for (var i = 2; i < n; i++) a[i] = a[i - 1] + 1;

        for (var i = 0; i < k - t; i++)
        {
            for (var j = 0; j < n; j++)
            {
                if (a[j] == u - n) a[j] = u;
                else a[j]--;
            }
        }

        io.Write(n);
        io.Write(a);
    }
}