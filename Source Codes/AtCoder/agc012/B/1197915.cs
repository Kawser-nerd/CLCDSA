using System;
using System.Collections.Generic;
using System.Linq;

namespace AGC012
{
    public class B
    {
        private void Run()
        {
            var input = Console.ReadLine().Trim().Split();
            var N = int.Parse(input[0]);
            var M = int.Parse(input[1]);

            var edges = Enumerable.Range(0, N).Select(_ => new List<int>()).ToArray();

            while (M-- > 0)
            {
                input = Console.ReadLine().Trim().Split();
                var a = int.Parse(input[0]) - 1;
                var b = int.Parse(input[1]) - 1;
                edges[a].Add(b);
                edges[b].Add(a);
            }

            var Q = int.Parse(Console.ReadLine().Trim());
            var queries = new List<Tuple<int, int, int>>();
            while (Q-- > 0)
            {
                input = Console.ReadLine().Trim().Split();
                var v = int.Parse(input[0]) - 1;
                var d = int.Parse(input[1]);
                var c = int.Parse(input[2]);
                queries.Add(Tuple.Create(v, d, c));
            }

            var color = new int[N];
            var maxUsedDistance = new int[N];
            foreach (var query in queries.AsEnumerable().Reverse())
            {
                var v = query.Item1;
                var d = query.Item2;
                var c = query.Item3;

                var q = new Queue<Tuple<int, int>>();
                q.Enqueue(Tuple.Create(v, d));
                while (q.Count > 0)
                {
                    var t = q.Dequeue();
                    var index = t.Item1;
                    var rest = t.Item2;

                    if (color[index] == 0) { color[index] = c; }
                    if (rest == 0) { continue; }
                    if (maxUsedDistance[index] >= rest) { continue; }
                    maxUsedDistance[index] = rest;

                    foreach (var edge in edges[index])
                    {
                        if (maxUsedDistance[edge] > rest - 1) { continue; }
                        q.Enqueue(Tuple.Create(edge, rest - 1));
                    }
                }
            }
            Console.WriteLine(string.Join(Environment.NewLine, color));
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}