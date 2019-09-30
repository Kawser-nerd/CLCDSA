using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

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

        static long Solve(string S)
        {
            int N = S.Length;
            var dp = new long[N + 1][];
            dp[N] = new long[4];
            dp[N][3] = 1;
            for (int i = N - 1; i >= 0; --i)
            {
                dp[i] = new long[4];
                if (S[i] == 'A' || S[i] == '?') { dp[i][0] = dp[i + 1][1]; }
                if (S[i] == 'B' || S[i] == '?') { dp[i][1] = dp[i + 1][2]; }
                if (S[i] == 'C' || S[i] == '?') { dp[i][2] = dp[i + 1][3]; }
                for (int j = 0; j < 4; ++j)
                {
                    dp[i][j] += (S[i] == '?') ? dp[i + 1][j] * 3 : dp[i + 1][j];
                    dp[i][j] %= 1000000007;
                }
            }
            return dp[0][0];
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve(Read()));
        }
    }
}