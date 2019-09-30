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

    static void Main(string[] args)
    {
        int[] args1 = ReadInts();
        int N = args1[0];
        int T = args1[1];
        int[] t = ReadInts();
        int sum = Enumerable.Range(0, N - 1).Sum(i => Math.Min(t[i + 1] - t[i], T)) + T;
        Console.WriteLine(sum);
    }
}