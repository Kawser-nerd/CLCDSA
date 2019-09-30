using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

static class Program
{
    private static string Read() { return Console.ReadLine(); }
    private static int ReadInt() { return int.Parse(Read()); }
    private static long ReadLong() { return long.Parse(Read()); }
    private static double ReadDouble() { return double.Parse(Read()); }
    private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
    private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
    private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

    private static int Solve(int N, int W, int[] w, int[] v, int w0)
    {
        int[][] dp1 = new int[N + 1][];
        for (int i = 0; i <= N; ++i) { dp1[i] = new int[300]; }

        for (int i = 0; i < N; ++i)
        {
            int[][] dp2 = new int[N + 1][];
            for (int j = 0; j <= N; ++j) { dp2[j] = new int[300]; }
            for (int j = 0; j <= N; ++j)
            {
                for (int k = 0; k < 300; ++k)
                {
                    int J = j + 1;
                    int K = k + w[i];
                    dp2[j][k] = Math.Max(dp1[j][k], dp2[j][k]);
                    if (J <= N && K < 300) { dp2[J][K] = Math.Max(dp1[j][k] + v[i], dp2[J][K]); }
                }
            }
            dp1 = dp2;
        }
        int max = 0;
        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j < 300; ++j)
            {
                if (W >= Math.BigMul(i, w0) + j) { max = Math.Max(dp1[i][j], max); }
            }
        }
        return max;
    }
    static void Main(string[] args)
    {
        int[] args1 = ReadInts();
        int N = args1[0];
        int W = args1[1];
        int[] w = new int[N];
        int[] v = new int[N];
        int w0 = 0;
        for (int i = 0; i < N; ++i)
        {
            int[] args2 = ReadInts();
            if (i == 0) { w0 = args2[0]; }
            w[i] = (i > 0) ? args2[0] - w0 : 0;
            v[i] = args2[1];
        }
        Console.WriteLine(Solve(N, W, w, v, w0));
    }
}