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

    static void Solve(IO io)
    {
        var n = io.I;
        var m = io.I;

        var a = new int[n][];
        for (var i = 0; i < n; i++) a[i] = io.Is(m);

        var idx = new int[n][];
        for (var i = 0; i < n; i++)
        {
            idx[i] = new int[m];
            for (var j = 0; j < m; j++) idx[i][a[i][j] - 1] = j + 1;
        }

        var minidx = Enumerable.Repeat(1, n).ToArray();

        var set = new HashSet<int>(Enumerable.Range(1, m));
        var min = int.MaxValue;
        while (set.Any())
        {
            var max = 0;
            var maxidx = 0;
            for (var j = 0; j < m; j++)
            {
                if (!set.Contains(j + 1)) continue;

                var cnt = 0;
                for (var i = 0; i < n; i++)
                {
                    if (idx[i][j] == minidx[i]) cnt++;
                }
                if (cnt > max)
                {
                    max = cnt;
                    maxidx = j + 1;
                }
            }
            set.Remove(maxidx);
            min = Min(min, max);
            for (var i = 0; i < n; i++)
            {
                minidx[i] = int.MaxValue;
                for (var j = 0; j < m; j++)
                {
                    if (!set.Contains(j + 1)) continue;
                    minidx[i] = Min(minidx[i], idx[i][j]);
                }
            }
        }

        io.Write(min);
    }
}