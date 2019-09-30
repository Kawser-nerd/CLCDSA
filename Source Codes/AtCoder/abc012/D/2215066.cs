using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static int[] dx = new int[] { 0, 0, 1, -1 };
    static int[] dy = new int[] { 1, -1, 0, 0 };

    static void Solve()
    {
        var n = sc.Int();
        var m = sc.Int();

        var cost = new long[n][];

        for (int i = 0; i < n; i++)
        {
            cost[i] = new long[n];
            for (int j = 0; j < n; j++)
                cost[i][j] = 100000000L;
        }

        for (int i = 0; i < n; i++)
            cost[i][i] = 0;
        
        for (int i = 0; i < m; i++)
        {
            var a = sc.Int() - 1;
            var b = sc.Int() - 1;
            var t = sc.Int();

            cost[a][b] = cost[b][a] = t;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    cost[j][k] = Math.Min(cost[j][k], cost[j][i] + cost[i][k]);
        
        pr.WriteLine(cost.Select(x => x.Max()).Min());
    }

    static double F(double prev, double next, double t)
    {
        return Math.Pow(Math.Exp((next - prev) / t), 2);
    }

    static int[,] Mul(int[,] a, int[,] b)
    {
        var ret = new int[a.GetLength(0), b.GetLength(1)];
        for (int i = 0; i < a.GetLength(0); i++)
            for (int j = 0; j < b.GetLength(1); j++)
                for (int k = 0; k < a.GetLength(1); k++)
                    ret[i, j] += a[i, k] * b[k, j];

        return ret;
    }

    static int[,] Pow(int[,] a, int n)
    {
        var b = new int[a.GetLength(1), a.GetLength(0)];

        var f = n % 2 == 1;

        for (int i = 0; i < a.GetLength(0); i++)
            b[i, i] = 1;

        while (n > 0)
        {
            if (n % 2 == 1)
                b = Mul(a, b);


            n >>= 1;
        }

        return b;
    }

    class Coord
    {
        public int x;
        public int y;
    }

    static void Main(string[] args)
    {
        // pr.AutoFlush = true;
        Solve();
        pr.Flush();
        // Console.ReadKey();
    }

    static Scanner sc = new Scanner();
    static Printer pr = new Printer();
}

#region IO
class Scanner
{
    private int _i = 0;
    private string[] line = new string[0];

    private T[] Enumerate<T>(int n, Func<T> f)
    {
        T[] ret = new T[n];
        for (int i = 0; i < n; i++)
            ret[i] = f();
        return ret;
    }

    public string Str()
    {
        if (line.Length <= _i)
        {
            line = Console.ReadLine().Split(' ');
            _i = 0;
        }

        return line[_i++];
    }

    public int Int() => int.Parse(Str());
    public long Long() => long.Parse(Str());
    public double Double() => double.Parse(Str());
    public int[] Int(int n) => Enumerate(n, Int);
    public long[] Long(int n) => Enumerate(n, Long);
    public double[] Double(int n) => Enumerate(n, Double);
    public string[] Str(int n) => Enumerate(n, Str);
}

class Printer : StreamWriter
{
    public Printer() : base(Console.OpenStandardOutput())
    {
        AutoFlush = false;
    }
}
#endregion