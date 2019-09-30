using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AGC013
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
                var A = int.Parse(input[0]) - 1;
                var B = int.Parse(input[1]) - 1;
                edges[A].Add(B);
                edges[B].Add(A);
            }

            var hasEdgeIndex = Enumerable.Range(0, N).FirstOrDefault(i => edges[i].Count > 0);
            var head = new List<int>();
            var tail = new List<int>();
            var used = new bool[N];

            used[hasEdgeIndex] = true;
            Action<List<int>, int> dfs = null;
            dfs = (list, current) =>
            {
                foreach (var e in edges[current])
                {
                    if (used[e]) { continue; }
                    used[e] = true;
                    list.Add(e);
                    dfs(list, e);
                    break;
                }
            };
            dfs(head, hasEdgeIndex);
            dfs(tail, hasEdgeIndex);

            var result = head.AsEnumerable().Reverse().Concat(new[] { hasEdgeIndex }).Concat(tail).Select(i => i + 1).ToArray();
            Console.WriteLine(result.Length);
            Console.WriteLine(string.Join(" ", result));
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