using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
using System.Linq.Expressions;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private long H, W;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        H = long.Parse(line[0]);
        W = long.Parse(line[1]);
    }

    public void Solve()
    {
        Scan();

        long ans = long.MaxValue;
        for (int i = 0; i <= H; i++)
        {
            long a = W * i;
            long b = ((W + 1) / 2) * (H - i);
            long c = (W / 2) * (H - i);
            long max = Math.Max(Math.Max(a, b), c);
            long min = Math.Min(Math.Min(a, b), c);
            ans = Math.Min(ans, max - min);
            b = W * ((H - i) / 2);
            c = W * ((H - i + 1) / 2);
            max = Math.Max(Math.Max(a, b), c);
            min = Math.Min(Math.Min(a, b), c);
            ans = Math.Min(ans, max - min);
        }
        for (int i = 0; i <= W; i++)
        {
            long a = H * i;
            long b = ((H + 1) / 2) * (W - i);
            long c = (H / 2) * (W - i);
            long max = Math.Max(Math.Max(a, b), c);
            long min = Math.Min(Math.Min(a, b), c);
            ans = Math.Min(ans, max - min);
            b = H * ((W - i) / 2);
            c = H * ((W - i + 1) / 2);
             max = Math.Max(Math.Max(a, b), c);
             min = Math.Min(Math.Min(a, b), c);
            ans = Math.Min(ans, max - min);
        }
        Console.WriteLine(ans);
    }
}