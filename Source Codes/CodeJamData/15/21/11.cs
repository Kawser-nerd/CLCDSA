using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;

namespace flaggen
{
    internal class Program
    {
        private const int size = (int) 1e6;
        private static int[] dp;
        private static long[] dp2;

        private static int GetReversedNumber(int num)
        {
            return int.Parse(new string(num.ToString().Reverse().ToArray()));
        }

        private static void Main(string[] args)
        {
            dp = new int[size + 1];
            var graph = new List<HashSet<int>>(size + 1);
            for (int i = 0; i <= size; ++i)
            {
                dp[i] = -1;
                graph.Add(new HashSet<int>(new[] { i + 1, GetReversedNumber(i) }));
            }
            dp[1] = 1;
            var q = new Queue<int>(new[] { 1 });
            while (q.Count > 0)
            {
                var top = q.Dequeue();
                foreach (var next in graph[top])
                    if (next <= size && (dp[next] == -1 || dp[next] > dp[top] + 1))
                    {
                        dp[next] = dp[top] + 1;
                        q.Enqueue(next);
                    }
            }

            dp2 = new long[15];
            dp2[0] = 1;
            dp2[1] = 10;
            for (int i = 2; i < 15; ++i)
                dp2[i] = dp2[i - 1]
                    + long.Parse(string.Join("", Enumerable.Repeat("9", i / 2)))
                    + long.Parse(string.Join("", Enumerable.Repeat("9", (i + 1) / 2))) + 1;

            using (var reader = new StreamReader(@"..\..\in.txt"))
            using (var writer = new StreamWriter(@"..\..\out.txt"))
            {
                var t = int.Parse(reader.ReadLine());
                for (int i = 1; i <= t; i++)
                {
                    var n = long.Parse(reader.ReadLine());
                    var ans = n < 100 ? Solve(n) : SolveAlt(n);
                    writer.WriteLine("Case #{0}: {1}", i, ans);
                }
            }
        }

        private static int Solve(long n)
        {
            return dp[n];
        }

        private static long SolveAlt(long n)
        {
            var str = n.ToString();
            var strReversed = new string(n.ToString().Reverse().ToArray());
            if (str.EndsWith("0"))
                return SolveAlt(n - 1) + 1;
            var temp = long.Parse(str.Substring(str.Length / 2))
                + long.Parse(new string(str.Substring(0, str.Length / 2).Reverse().ToArray()));
            return dp2[str.Length - 1] + Math.Min(temp, n - (long) Math.Pow(10, str.Length - 1));
        }
    }
}