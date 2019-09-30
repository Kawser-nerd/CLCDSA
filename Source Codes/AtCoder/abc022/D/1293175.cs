using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

struct P
{
    public double X, Y;

    public P(double x, double y)
    {
        X = x;
        Y = y;
    }
}


class Magatro
{
    private int N;
    private P[] A, B;
    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        A = new P[N];
        B = new P[N];
        for (int i = 0; i < N; i++)
        {
            var line = Console.ReadLine().Split(' ');
            int x = int.Parse(line[0]);
            int y = int.Parse(line[1]);
            A[i] = new P(x, y);
        }
        for (int i = 0; i < N; i++)
        {
            var line = Console.ReadLine().Split(' ');
            int x = int.Parse(line[0]);
            int y = int.Parse(line[1]);
            B[i] = new P(x, y);
        }
    }

    private double Dist(P a, P b)
    {
        return Math.Sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
    }

    private double Max(P[] p)
    {
        double x = 0;
        double y = 0;
        foreach (var item in p)
        {
            x += item.X;
            y += item.Y;
        }
        x /= N;
        y /= N;
        P o = new P(x, y);
        double res = -1;
        foreach (var item in p)
        {
            res = Math.Max(res, Dist(o, item));
        }
        return res;
    }
    

    public void Solve()
    {
        Scan();
        double minA = Max(A);
        double minB = Max(B);
        Console.WriteLine(minB / minA);
    }
}