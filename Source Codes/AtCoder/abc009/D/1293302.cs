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
    private int K, M;
    private long[] A, C;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        K = int.Parse(line[0]);
        M = int.Parse(line[1]);
        A = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        C = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }

    private long[][] F(long[][] a, long[][] b) //a * b
    {
        int m = a.Length;
        int n = b.Length;
        int p = b[0].Length;
        long[][] result = new long[m][];
        for (int i = 0; i < m; i++)
        {
            result[i] = new long[p];
        }
        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < n; k++)
            {
                for(int j = 0; j < p; j++)
                {
                    result[i][j] ^= a[i][k] & b[k][j];
                }
            }
        }
        return result.ToArray();
    }

    long[][] Pow(long[][] a, long n)
    {
        var ret = new long[K][];
        for (int i = 0; i < K; i++)
        {
            ret[i] = new long[K];
            ret[i][i] = long.MaxValue;
        }
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ret = F(ret, a);
            }
            a = F(a, a);
            n /= 2;
        }
        return ret;
    }

    public void Solve()
    {
        Scan();
        if (M <= K)
        {
            Console.WriteLine(A[M - 1]);
            return;
        }
        long[][] T = new long[K][];
        for (int i = 0; i < K; i++)
        {
            T[i] = new long[K];
            if (i == 0)
            {
                for (int j = 0; j < K; j++)
                {
                    T[0][j] = C[j];
                }
            }
            else
            {
                T[i][i - 1] = long.MaxValue;
            }
        }
        var bn = Pow(T, M - K);
        var D = new long[K][];
        for (int i = 0; i < K; i++)
        {
            D[i] = new long[] { A[K - 1 - i] };
        }
        var ans = F(bn, D);
        Console.WriteLine(ans[0][0]);
    }
}