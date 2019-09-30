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

        class Solver
        {
            private int[][] costs;
            public Solver(int N, int[][] paths)
            {
                costs = new int[N][];
                for (int i = 0; i < N; ++i)
                {
                    costs[i] = Enumerable.Repeat(int.MaxValue, N).ToArray();
                    var q = new Queue<int>();
                    costs[i][i] = 0;
                    q.Enqueue(i);
                    while (q.Count > 0)
                    {
                        int j = q.Dequeue();
                        for (int k = 0; k < N; ++k)
                        {
                            if (paths[j][k] < int.MaxValue && costs[i][k] > costs[i][j] + paths[j][k])
                            {
                                costs[i][k] = costs[i][j] + paths[j][k];
                                q.Enqueue(k);
                            }
                        }
                    }
                }
            }
            private int Solve(List<int> cities, int a)
            {
                int R = cities.Count;
                if (R == 0) { return 0; }
                int min = int.MaxValue;
                for (int i = 0; i < R; ++i)
                {
                    int b = cities[i];
                    cities.RemoveAt(i);
                    min = Math.Min(costs[a][b] + Solve(cities, b), min);
                    cities.Insert(i, b);
                }
                return min;
            }
            public int Solve(List<int> cities)
            {
                int R = cities.Count;
                int min = int.MaxValue;
                for (int i = 0; i < R; ++i)
                {
                    int a = cities[i];
                    cities.RemoveAt(i);
                    min = Math.Min(Solve(cities, a), min);
                    cities.Insert(i, a);
                }
                return min;
            }
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            int N = v1[0];
            int M = v1[1];
            var cities = ReadInts().Select(r => r - 1).ToList();
            var paths = new int[N][];
            for (int i = 0; i < N; ++i) { paths[i] = Enumerable.Repeat(int.MaxValue, N).ToArray(); }
            for (int i = 0; i < M; ++i)
            {
                int[] v2 = ReadInts();
                int A = v2[0] - 1;
                int B = v2[1] - 1;
                int C = v2[2];
                paths[A][B] = C;
                paths[B][A] = C;
            }
            Console.WriteLine(new Solver(N, paths).Solve(cities));
        }
    }
}