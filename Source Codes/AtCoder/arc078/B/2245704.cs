using System;
using System.Collections.Generic;
using System.Linq;
/*
using System.Text;
using System.Diagnostics;
using System.IO;
*/

namespace AtCoder
{
    class Program
    {
        private const int M = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static bool Solve(int N, List<int>[] paths)
        {
            int[] b = Enumerable.Repeat(int.MaxValue, N).ToArray();
            {
                var q = new Queue<int>();
                b[0] = 0;
                q.Enqueue(0);
                while (q.Count > 0)
                {
                    int i = q.Dequeue();
                    foreach (var j in paths[i])
                    {
                        if (b[j] > b[i] + 1)
                        {
                            b[j] = b[i] + 1;
                            q.Enqueue(j);
                        }
                    }
                }
            }
            int[] w = Enumerable.Repeat(int.MaxValue, N).ToArray();
            {
                var q = new Queue<int>();
                w[N - 1] = 0;
                q.Enqueue(N - 1);
                while (q.Count > 0)
                {
                    int i = q.Dequeue();
                    foreach (var j in paths[i])
                    {
                        if (w[j] > w[i] + 1)
                        {
                            w[j] = w[i] + 1;
                            q.Enqueue(j);
                        }
                    }
                }
            }
            int fennec = 0;
            int snuke = 0;
            for (int i = 0; i < N; ++i)
            {
                if (b[i] <= w[i]) { ++fennec; } else { ++snuke; }
            }
            return fennec > snuke;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            var paths = new List<int>[N];
            for (int i = 0; i < N; ++i) { paths[i] = new List<int>(); }
            for (int i = 0; i < N - 1; ++i)
            {
                int[] values = ReadInts();
                int a = values[0] - 1;
                int b = values[1] - 1;
                paths[a].Add(b);
                paths[b].Add(a);
            }
            Console.WriteLine(Solve(N, paths) ? "Fennec" : "Snuke");
        }
    }
}