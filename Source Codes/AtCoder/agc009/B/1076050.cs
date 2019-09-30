using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    private static List<int>[] children;
    static int Solve(int n)
    {
        int N = children[n].Count;
        var counts = new int[N];
        for (int i = 0; i < N; ++i) { counts[i] = Solve(children[n][i]); }
        Array.Sort(counts, (a, b) => (b - a));
        int max = 0;
        for (int i = 0; i < N; ++i) { max = Math.Max(counts[i] + i + 1, max); }
        return max;
    }
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        children = new List<int>[N + 1];
        for (int i = 1; i <= N; ++i) { children[i] = new List<int>(); }
        for (int i = 2; i <= N; ++i)
        {
            int n = int.Parse(Console.ReadLine());
            children[n].Add(i);
        }
        Console.WriteLine(Solve(1));
    }
}