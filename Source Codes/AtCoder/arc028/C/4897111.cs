using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _028
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var graph = new Dictionary<int, bool>[n];
            List<int>[] balances = new List<int>[n];
            for (int i = 0; i < n; i++)
            {
                balances[i] = new List<int>();
                graph[i] = new Dictionary<int, bool>();
            }
            for(int i = 1; i < n; i++)
            {
                int p = ReadInt();
                graph[i].Add(p, true);
                graph[p].Add(i, true);
            }
            var queue = new Queue<int>();
            for(int i = 0; i < n; i++)
            {
                if (graph[i].Count == 1) queue.Enqueue(i);
            }
            while (queue.Count > 0)
            {
                int now = queue.Dequeue();
                if (graph[now].Count == 0) continue;
                int sum = 0;
                for (int i = 0; i < balances[now].Count; i++)
                {
                    sum += balances[now][i];
                }
                balances[now].Add(n - 1 - sum);

                int to = graph[now].First().Key;
                balances[to].Add(sum + 1);
                graph[now].Remove(to);
                graph[to].Remove(now);
                if (graph[to].Count == 1) queue.Enqueue(to);
            }
            for (int i = 0; i < n; i++)
            {
                int max = 0;
                for (int j = 0; j < balances[i].Count; j++)
                {
                    max = Max(max, balances[i][j]);
                }
                WriteLine(max);
            }
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