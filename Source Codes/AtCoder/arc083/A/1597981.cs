using System;
using System.Collections;
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
    string[] input = In.ReadToEnd().Split(new[] { " ", "\n", "\r" },
        StringSplitOptions.RemoveEmptyEntries);

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

#region Library

static class Extentions
{
}

#endregion

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
        Solve(new IO());
        Out.Flush();
    }

    static void Solve(IO io)
    {
        var a = io.L;
        var b = io.L;
        var c = io.L;
        var d = io.L;
        var e = io.L;
        var f = io.L;

        var ans0 = 0.0;
        var ans1 = 0L;
        var ans2 = 0L;

        for (var i = 0; i * a * 100 <= f; i++)
        {
            for (var j = 0; ; j++)
            {
                var w = i * a + j * b;
                if (w == 0) break;

                for (var k = 0; w * 100 + k * c <= f; k++)
                {
                    for (var l = 0; ; l++)
                    {
                        var s = k * c + l * d;
                        if (w * 100 + s > f || s > e * w) break;

                        var t = (double)s / (w * 100 + s);

                        if (t >= ans0)
                        {
                            ans0 = t;
                            ans1 = w * 100 + s;
                            ans2 = s;
                        }
                    }
                }

                if (w * 100 > f) break;
            }
        }

        io.Write(ans1, ans2);
    }
}