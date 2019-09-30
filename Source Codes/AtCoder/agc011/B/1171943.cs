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

    static int Solve(int N, long[] A)
    {
        long sum = 0;
        long[] sums = new long[N];
        for (int i = 0; i < N; ++i)
        {
            sums[i] = sum + A[i];
            sum += A[i];
        }
        for (int i = 1; i < N; ++i)
        {
            if (sums[N - i - 1] * 2 < A[N - i]) { return i; }
        }
        return N;
    }
    static void Main(string[] args)
    {
        int N = ReadInt();
        var A = ReadLongs();
        Console.WriteLine(Solve(N, A.OrderBy(a => a).ToArray()));
    }
}