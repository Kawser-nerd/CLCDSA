using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static List<int[]>[] costs;
        static long[] dis;
        static bool[] reach;
        static void Main(string[] args)
        {
            var N = ReadInt();
            costs = new List<int[]>[N + 1];
            for (int i = 0; i < N + 1; i++) costs[i] = new List<int[]>();
            for (int i = 0; i < N - 1; i++)
            {
                var input = ReadArrayInt();
                var a = input[0];
                var b = input[1];
                var c = input[2];
                costs[a].Add(new int[] { b, c });
                costs[b].Add(new int[] { a, c });
            }
            dis = Enumerable.Repeat(long.MaxValue, N + 1).ToArray();
            reach = new bool[N + 1];
            var QK = ReadArrayInt();
            var Q = QK[0];
            var K = QK[1];
            Dfs(K, -1, 0);
            for (int i = 0; i < Q; i++)
            {
                var xy = ReadArrayInt();
                Console.WriteLine(dis[xy[0]] + dis[xy[1]]);
            }

            Console.WriteLine();
            Console.ReadLine();
        }

        static void Dfs(int v, int p, long d)
        {
            dis[v] = d;
            reach[v] = true;
            for (int i = 0; i < costs[v].Count; i++)
            {
                if (!reach[costs[v][i][0]])
                {
                    if (costs[v][i][0] == p) continue;
                    Dfs(costs[v][i][0], v, d + costs[v][i][1]);
                }
            }
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}