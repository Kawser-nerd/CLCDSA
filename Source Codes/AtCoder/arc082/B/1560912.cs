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
        var p = io.Is(n).ToList();

        if (n % 2 != 0) { n++; p.Add(-1); }

        var t = new bool[n];
        for (var i = 0; i < n; i++) t[i] = p[i] == i + 1;
        var ans = 0;

        for (var i = 0; i < n; i++)
        {
            if (i == n - 1) { if (t[i]) ans++; break; }
            if (t[i] && !t[i + 1]) { ans++; i++; }
            if (t[i] &&  t[i + 1]) { ans++; i++; }
        }

        io.Write(ans);
    }
}