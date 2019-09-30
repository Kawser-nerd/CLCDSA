using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _030
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nx = ReadInts();
            int n = nx[0];
            int x = nx[1]-1;
            int[] hs = ReadInts();
            List<int>[] originGraph = new List<int>[n];
            for (int i = 0; i < n; i++)originGraph[i]=new List<int>();

            for(int i = 0; i < n - 1; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                originGraph[a].Add(b);
                originGraph[b].Add(a);
            }
            bool[] visited = new bool[n];
            WriteLine(DFS(originGraph, hs,ref visited, x));
        }

        static long DFS(List<int>[] graph, int[] hs,ref bool[] visited, int now)
        {
            visited[now] = true;
            long distance = 0;
            for (int i = 0; i < graph[now].Count; i++)
            {
                if (visited[graph[now][i]]) continue;
                
                long nextDistance= DFS(graph, hs, ref visited, graph[now][i]);
                if (nextDistance > 0) distance += nextDistance + 2;
                else if (hs[graph[now][i]] == 1) distance += 2;
            }
            return distance;
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}