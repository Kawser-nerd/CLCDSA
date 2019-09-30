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

    static int Solve(List<int>[] A)
    {
        int M = A[0].Count;
        int min = int.MaxValue;
        for (int i = 0; i < M; ++i)
        {
            var counts = new Dictionary<int, int>();
            foreach (var a in A)
            {
                if (!counts.ContainsKey(a[0])) { counts[a[0]] = 0; }
                ++counts[a[0]];
            }
            var max = counts.OrderByDescending(pair => pair.Value).First();
            min = Math.Min(max.Value, min);
            for (int j = 0; j < A.Length; ++j) { A[j].Remove(max.Key); }
        }
        return min;
    }

    static void Main(string[] args)
    {
        int[] values = ReadInts();
        List<int>[] A = new List<int>[values[0]];
        for (int i = 0; i < A.Length; ++i) { A[i] = ReadInts().ToList(); }
        Console.WriteLine(Solve(A));
    }
}