using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_061
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            var edges = new int[m, 3];
            for (int i = 0; i < m; i++)
            {
                int[] abc = ReadInts();
                edges[i, 0] = abc[0] - 1;
                edges[i, 1] = abc[1] - 1;
                edges[i, 2] = -abc[2];
            }
            long dist = BellmanFord(n, edges, 0, n - 1);
            Console.WriteLine(dist == long.MinValue
                ? "inf" : (-dist).ToString());
        }

        static long BellmanFord(int n,int[,] edges, int start,int goal)
        {
            int m = edges.GetLength(0);
            var distances = new long[n];
            for (int i = 0; i < n; i++)
            {
                distances[i] = long.MaxValue;
            }
            distances[start] = 0;

            for (int i = 0; i < n - 1; i++)
            {
                for (int v = 0; v < m; v++)
                {
                    int a = edges[v, 0];
                    int b = edges[v, 1];
                    long c = edges[v, 2];
                    if (distances[a] != long.MaxValue
                        && distances[b] > distances[a] + c)
                    {
                        distances[b] = distances[a] + c;
                    }
                }
            }

            //negative check
            var negative = new bool[n];
            for (int i = 0; i < n; i++)
            {
                for (int v = 0; v < m; v++)
                {
                    int a = edges[v, 0];
                    int b = edges[v, 1];
                    long c = edges[v, 2];
                    if (distances[a] != long.MaxValue
                        && distances[b] > distances[a] + c)
                    {
                        distances[b] = distances[a] + c;
                        negative[b] = true;
                    }
                    if (negative[a]) negative[b] = true;
                }
            }

            return negative[goal] ? long.MinValue : distances[goal];
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}