using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_C
{
    class _001
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            List<int>[] graph = new List<int>[n];
            for (int i = 0; i < n; i++) graph[i] = new List<int>();
            int[][] abs = new int[n - 1][];
            for(int i = 0; i < n - 1; i++)
            {
                abs[i] = ReadInts();
                abs[i][0]--;
                abs[i][1]--;
                int a = abs[i][0];
                int b = abs[i][1];
                graph[a].Add(b);
                graph[b].Add(a);
            }
            int res = int.MaxValue;
            if (k % 2 == 0)
            {
                int dist = k / 2;
                for(int i = 0; i < n; i++)
                {
                    Queue<int[]> queue = new Queue<int[]>();
                    bool[] visited = new bool[n];
                    queue.Enqueue(new int[2] { i, 0 });
                    int tmp = 0;
                    while (queue.Count > 0)
                    {
                        int[] val = queue.Dequeue();
                        if (visited[val[0]]) continue;
                        visited[val[0]] = true;
                        if (val[1] > dist) tmp++;

                        for(int j = 0; j < graph[val[0]].Count; j++)
                        {
                            int index = graph[val[0]][j];
                            if (visited[index]) continue;

                            queue.Enqueue(new int[2] { index, val[1] + 1 });
                        }
                    }
                    res = Min(res, tmp);
                }
            }
            else
            {
                int dist = (k - 1) / 2;
                for (int i = 0; i < n-1; i++)
                {
                    Queue<int[]> queue = new Queue<int[]>();
                    bool[] visited = new bool[n];
                    queue.Enqueue(new int[2] { abs[i][0], 0 });
                    queue.Enqueue(new int[2] { abs[i][1], 0 });
                    int tmp = 0;
                    while (queue.Count > 0)
                    {
                        int[] val = queue.Dequeue();
                        if (visited[val[0]]) continue;
                        visited[val[0]] = true;
                        if (val[1] > dist) tmp++;

                        for (int j = 0; j < graph[val[0]].Count; j++)
                        {
                            int index = graph[val[0]][j];
                            if (visited[index]) continue;

                            queue.Enqueue(new int[2] { index, val[1] + 1 });
                        }
                    }
                    res = Min(res, tmp);
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