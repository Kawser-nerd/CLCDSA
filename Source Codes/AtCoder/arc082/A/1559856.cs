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
        var n = io.I;
        var a = io.Is(n);

        Array.Sort(a);
        var gs = a.GroupBy(x => x).ToArray();
        var ans = 0;

        for (var i = 0; i < gs.Length; i++)
        {
            var t0 = gs[i].First();
            var t1 = i + 1 < gs.Length ? gs[i + 1].First() : -114514;
            var t2 = i + 2 < gs.Length ? gs[i + 2].First() : -114514;
            var t = gs[i].Count();

            if (t0 + 2 == t1) t += gs[i + 1].Count();
            else if (t0 + 1 == t1)
                if (t1 + 1 == t2) t += gs[i + 1].Count() + gs[i + 2].Count();
                else t += gs[i + 1].Count();

            ans = Max(ans, t);
        }

        io.Write(ans);
    }
}