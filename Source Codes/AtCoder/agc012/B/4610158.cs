using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _012_B
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
            var graph = new List<int>[n];
            for(int i = 0; i < n; i++)
            {
                graph[i] = new List<int>();
            }
            for (int i = 0; i < m; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                graph[a].Add(b);
                graph[b].Add(a);
            }
            int q = ReadInt();
            int[][] vdcs = new int[q][];
            for(int i =0; i < q; i++)
            {
                vdcs[i] = ReadInts();
            }
            var coloredTimes = new int[n, 11];
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 11; j++)
                {
                    coloredTimes[i, j] = -1;
                }
            }
            for(int i = q - 1; i >= 0; i--)
            {
                int v = vdcs[i][0] - 1;
                int d = vdcs[i][1];
                Queue<int[]> queue = new Queue<int[]>();
                queue.Enqueue(new int[2] { v, d });
                while (queue.Count > 0)
                {
                    int[] val = queue.Dequeue();
                    if (coloredTimes[val[0], val[1]] != -1) continue;

                    for(int j = val[1]; j >= 0; j--)
                    {
                        if (coloredTimes[val[0], j] != -1) break;
                        coloredTimes[val[0], j] = i;
                    }
                    if (val[1] == 0) continue;

                    for(int j = 0; j < graph[val[0]].Count; j++)
                    {
                        queue.Enqueue(new int[2] {
                            graph[val[0]][j] , val[1] - 1 });
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                if (coloredTimes[i, 0] == -1)
                {
                    WriteLine(0);
                }
                else
                {
                    WriteLine(vdcs[coloredTimes[i, 0]][2]);
                }
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