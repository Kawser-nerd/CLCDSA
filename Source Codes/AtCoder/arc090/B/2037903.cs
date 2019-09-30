using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace AtCoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static bool Solve(int N, int M, Dictionary<int, int>[] children)
        {
            var distances = new Dictionary<int, int>();
            for (int i = 0; i < N; ++i)
            {
                if (!distances.ContainsKey(i))
                {
                    var q = new Queue<int>();
                    q.Enqueue(i);
                    distances[i] = 0;
                    while (q.Count > 0)
                    {
                        int a = q.Dequeue();
                        foreach (var pair in children[a])
                        {
                            int b = pair.Key;
                            if (distances.ContainsKey(b))
                            {
                                if (distances[b] != distances[a] + pair.Value) { return false; }
                            }
                            else
                            {
                                q.Enqueue(b);
                                distances[b] = distances[a] + pair.Value;
                            }
                        }
                    }
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            int[] values1 = ReadInts();
            int N = values1[0];
            int M = values1[1];
            var children = new Dictionary<int, int>[N];
            for (int i = 0; i < N; ++i) { children[i] = new Dictionary<int, int>(); }
            for (int i = 0; i < M; ++i)
            {
                int[] values2 = ReadInts();
                int L = values2[0] - 1;
                int R = values2[1] - 1;
                int D = values2[2];
                children[L][R] = D;
                children[R][L] = -D;
            }
            Console.WriteLine(Solve(N, M, children) ? "Yes" : "No");
        }
    }
}