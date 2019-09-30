using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _032
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            List<int>[] graph = new List<int>[n];
            for (int i = 0; i < n; i++) graph[i] = new List<int>();
            for(int i = 0; i < m; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0]-1;
                int b = ab[1]-1;
                graph[a].Add(b);
                graph[b].Add(a);
            }
            int res = -1;
            bool[] visited = new bool[n];
            for(int i = 0; i < n; i++)
            {
                if (visited[i]) continue;

                res++;
                visited[i] = true;
                Queue<int> queue = new Queue<int>();
                queue.Enqueue(i);
                while (queue.Count > 0)
                {
                    int index = queue.Dequeue();
                    for(int j = 0; j < graph[index].Count; j++)
                    {
                        int next = graph[index][j];
                        if (visited[next]) continue;

                        visited[next] = true;
                        queue.Enqueue(next);
                    }
                }
            }
            WriteLine(res);
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