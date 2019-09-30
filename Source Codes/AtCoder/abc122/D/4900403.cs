using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace AtCoder.ABC122.D
{
    class Program
    {
        static void Rep(int n, Action<int> action) { for (var i = 0; i < n; ++i) { action(i); } }
        static void Rep(int n, int s, Action<int> action) { for (var i = s; i < n; ++i) { action(i); } }
        static int A = 0, G = 1, C = 2, T = 3;
        static long mod = (long)Math.Pow(10, 9) + 7;
        public static void Main()
        {
            // Solve(3);
            // Solve(4);
            // Solve(5);
            // Solve(100);

            var N = int.Parse(Console.ReadLine());
            Solve(N);
        }
        static void Solve(int N)
        {
            var dp = new long[N + 1, 4, 4, 4];
            Rep(N, i => Rep(4, j => Rep(4, k => Rep(4, l =>
            {
                dp[i, j, k, l] = 0;
            }))));
            Rep(4, j => Rep(4, k => Rep(4, l =>
            {
                if (j == A && k == G && l == C) return;
                if (j == A && k == C && l == G) return;
                if (j == G && k == A && l == C) return;
                dp[3, j, k, l] = 1;
            })));
            Rep(N + 1, 4, i => Rep(4, j => Rep(4, k => Rep(4, l => Rep(4, m =>
            {
                // NG????
                // AGC
                // ACG
                // GAC
                // A?GC
                // AG?C
                // mjkl
                if (j == A && k == G && l == C) return;
                if (j == A && k == C && l == G) return;
                if (j == G && k == A && l == C) return;
                if (m == A && k == G && l == C) return;
                if (m == A && j == G && l == C) return;
                dp[i, j, k, l] += dp[i - 1, m, j, k];
                dp[i, j, k, l] %= mod;
            })))));
            long ans = 0;
            Rep(4, j => Rep(4, k => Rep(4, l =>
            {
                ans += dp[N, j, k, l];
                ans %= mod;
            })));
            Console.WriteLine(ans);
        }
        Dictionary<int, int> cache = new Dictionary<int, int>();
        static int Count(string S, int begin, int end)
        {
            return CountChar(S.Substring(begin, end - begin + 1), "AC");
        }
        public static int CountChar(string s, string c)
        {
            return (s.Length - (s.Replace(c, "").Length)) / c.Length;
        }
    }
}