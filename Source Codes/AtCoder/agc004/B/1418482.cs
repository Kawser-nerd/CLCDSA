using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, X;
    private int[] A;
    private int[] B;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        X = int.Parse(line[1]);
        A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    private long Calc(int k)
    {
        for (int i = 0; i < N; i++)
        {
            int p = i - k;
            if (p < 0)
            {
                p += N;
            }
            B[i] = Math.Min(B[i], A[p]);
        }
        return (long)X * k + B.Sum(i => (long)i);
    }

    public void Solve()
    {
        Scan();

        B = new int[N];

        for (int i = 0; i < N; i++)
        {
            B[i] = int.MaxValue;
        }

        long ans = long.MaxValue;

        for (int k = 0; k < N; k++)
        {
            ans = Math.Min(ans, Calc(k));
        }

        Console.WriteLine(ans);
    }
}