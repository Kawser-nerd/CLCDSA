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

    static List<int> Draw(List<int>[] edges, bool[] visited, int n)
    {
        var path = new List<int>();
        while (true)
        {
            visited[n] = true;
            path.Add(n);
            var nexts = edges[n].Where(edge => !visited[edge]);
            if (nexts.Count() == 0) { return path; }
            n = nexts.ElementAt(0);
        }
    }
    static void Main(string[] args)
    {
        int[] args1 = ReadInts();
        int N = args1[0];
        int M = args1[1];
        var edges = new List<int>[N];
        for (int i = 0; i < N; ++i) { edges[i] = new List<int>(); }
        for (int i = 0; i < M; ++i)
        {
            int[] args2 = ReadInts();
            int A = args2[0] - 1;
            int B = args2[1] - 1;
            edges[A].Add(B);
            edges[B].Add(A);
        }
        bool[] visited = new bool[N];
        var path = new List<int>();
        for (int i = 0; i < N; ++i)
        {
            if (edges[i].Count > 0)
            {
                visited[i] = true;
                if (edges[i].Count > 0)
                {
                    path.AddRange(Draw(edges, visited, edges[i][0]));
                    path.Reverse();
                }
                path.Add(i);
                var nexts = edges[i].Where(edge => !visited[edge]);
                if (nexts.Count() > 0)
                {
                    path.AddRange(Draw(edges, visited, nexts.ElementAt(0)));
                }
                break;
            }
        }
        Console.WriteLine(path.Count);
        Console.WriteLine(string.Join(" ", path.Select(n => n + 1)));
    }
}