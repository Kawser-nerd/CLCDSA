// ARC 008 D ???????????

using System;
using System.Collections.Generic;

class Program
{
    static long N;
    static int M;
    static long[] p;
    static double[] a;
    static double[] b;

    static TO[] Seg;
    static int n;

    static void Main()
    {
        /* ??????? */
        string[] input = Console.ReadLine().Split();
        N = long.Parse(input[0]);
        M = int.Parse(input[1]);
        p = new long[M];
        a = new double[M];
        b = new double[M];
        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split();
            p[i] = long.Parse(input[0]) - 1;
            a[i] = double.Parse(input[1]);
            b[i] = double.Parse(input[2]);
        }

        /* ????????TO???????????????? */
        SortedList<long, long> sl = new SortedList<long, long>();
        foreach (var i in p)
        {
            try { sl.Add(i, i); }
            catch { continue; }
        }
        N = sl.Count;

        /* TO??????????? */
        n = 1;
        while (n < N) n *= 2;
        Seg = new TO[2 * n - 1];
        for (int i = 0; i < 2 * n - 1; i++)
            Seg[i] = new TO(1.0, 0.0);

        double min = 1;
        double max = 1;

        /* ????????????? */
        for (int i = 0; i < M; i++)
        {
            int p_ = sl.IndexOfKey(p[i]);
            double a_ = a[i];
            double b_ = b[i];
            Prank(p_, a_, b_);
            min = Math.Min(min, Seg[0].a + Seg[0].b);
            max = Math.Max(max, Seg[0].a + Seg[0].b);
        }

        /* ????? */
        Console.WriteLine(min);
        Console.WriteLine(max);
    }

    /* ???????? */
    static void Prank(int p, double a, double b)
    {
        p += n - 1;
        Seg[p] = new TO(a, b);
        while (p > 0)
        {
            p = (p - 1) / 2;
            double al = Seg[p * 2 + 1].a;
            double bl = Seg[p * 2 + 1].b;
            double ar = Seg[p * 2 + 2].a;
            double br = Seg[p * 2 + 2].b;
            Seg[p] = new TO(al * ar, ar * bl + br);
        }
    }
}

struct TO // ???????????
{
    public double a { get; set; }
    public double b { get; set; }

    public TO(double a, double b) // ???????
    { this.a = a; this.b = b; }
}