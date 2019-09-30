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
    private int N, K;
    private int[] A;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        K = int.Parse(line[1]);
        A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }


    public void Solve()
    {
        Scan();
        var a = new long[N];
        var b = new long[N];
        long bSum = 0;
        long aSum = 0;
        for (int i = 0; i < N; i++)
        {
            aSum += A[i];
            bSum += Math.Max(0, A[i]);
            a[i] = aSum;
            b[i] = bSum;
        }
        long ans = 0;
        for (int i = 0; i <= N - K; i++)
        {
            long q = 0;
            long w = a[i + K - 1];
            long e = b[N - 1] - b[i + K - 1];

            if (i > 0)
            {
                q = b[i - 1];
                w -= a[i - 1];
            }
            //Console.WriteLine($"{i} {q} {w} {e}");
            ans = Math.Max(q + e + Math.Max(0, w), ans);
        }
        Console.WriteLine(ans);
    }
}