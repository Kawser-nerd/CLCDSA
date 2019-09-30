using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static bool Solve(int N, int M, Tuple<int, int>[] tuples)
        {
            var islands = new HashSet<int>[N];
            for (int i = 0; i < N; ++i) { islands[i] = new HashSet<int>(); }
            foreach (var tuple in tuples)
            {
                int a = tuple.Item1;
                int b = tuple.Item2;
                islands[a].Add(b);
                islands[b].Add(a);
            }
            var distances = Enumerable.Repeat(int.MaxValue, N).ToArray();
            distances[0] = 0;
            var queue = new Queue<int>();
            queue.Enqueue(0);
            while (queue.Count > 0)
            {
                int a = queue.Dequeue();
                foreach (int b in islands[a])
                {
                    if (distances[b] > distances[a] + 1)
                    {
                        queue.Enqueue(b);
                        distances[b] = distances[a] + 1;
                    }
                }
            }
            return distances[N - 1] == 2;
        }
        static void Main(string[] args)
        {
            int[] values1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int N = values1[0];
            int M = values1[1];
            var tuples = new Tuple<int, int>[M];
            for (int i = 0; i < M; ++i)
            {
                int[] values2 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                tuples[i] = new Tuple<int, int>(values2[0] - 1, values2[1] - 1);
            }
            Console.WriteLine(Solve(N, M, tuples) ? "POSSIBLE" : "IMPOSSIBLE");
        }
    }
}