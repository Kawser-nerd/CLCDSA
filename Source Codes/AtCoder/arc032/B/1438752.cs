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
        input = reader.ReadToEnd().Split(new[] { " ", Environment.NewLine },
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
    public static void Swap<T>(ref T x, ref T y)
    {
        var tmp = x;
        x = y;
        y = tmp;
    }
}

class UnionFind
{
    int[] tree;

    public UnionFind(int length)
    {
        tree = Enumerable.Repeat(-1, length).ToArray();
    }

    public bool Union(int x, int y)
    {
        x = this.Find(x);
        y = this.Find(y);
        if (x == y) return false;
        if (tree[x] > tree[y]) Swap(ref x, ref y);
        tree[x] += tree[y];
        tree[y] = x;
        return true;
    }

    int Find(int x)
    {
        if (tree[x] < 0) return x;
        return tree[x] = this.Find(tree[x]);
    }

    public bool IsSameGroup(int x, int y) => this.Find(x) == this.Find(y);
}

static class Program
{
    public static void Main()
    {
#if !DEBUG
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
#endif
        Solve(new IO(In));
        Out.Flush();
    }

    static void Solve(IO io)
    {
        var n = io.I;
        var m = io.I;

        var uf = new UnionFind(n);

        for (var i = 0; i < m; i++)
        {
            var a = io.I - 1;
            var b = io.I - 1;

            uf.Union(a, b);
        }

        var ans = 0;

        for (var i = 1; i < n; i++)
        {
            if (uf.Union(i - 1, i)) ans++;
        }

        io.Write(ans);
    }
}