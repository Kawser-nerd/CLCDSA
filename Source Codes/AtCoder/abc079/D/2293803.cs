using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static int Solve(int H, int W, int[][] C, int[][] A)
        {
            var costs = new int[10];
            for (int i = 0; i < 10; ++i)
            {
                if (i != 1)
                {
                    int[] d = Enumerable.Repeat(int.MaxValue, 10).ToArray();
                    var q = new Queue<int>();
                    d[i] = 0;
                    q.Enqueue(i);
                    while (q.Count > 0)
                    {
                        int j = q.Dequeue();
                        for (int k = 0; k < 10; ++k)
                        {
                            if (j != k && d[k] > d[j] + C[j][k])
                            {
                                d[k] = d[j] + C[j][k];
                                q.Enqueue(k);
                            }
                        }
                    }
                    costs[i] = d[1];
                }
            }
            return A.Sum(a => a.Select(i => (i < 0) ? 0 : costs[i]).Sum());
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            int H = v[0];
            int W = v[1];
            var C = new int[10][];
            for (int i = 0; i < 10; ++i) { C[i] = ReadInts(); }
            var A = new int[H][];
            for (int i = 0; i < H; ++i) { A[i] = ReadInts(); }
            Console.WriteLine(Solve(H, W, C, A));
        }
    }
}