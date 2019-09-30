using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.DP
{
    class ARC059_F
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string s = Read();
            int remain = n - s.Length;
            int poses = s.Length;
            long mask = 1000000000 + 7;

            long[] dp = new long[n + 1];
            dp[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                long[] next = new long[n + 1];
                for (int j = 0; j < i; j++)
                {
                    if (dp[j] == 0) continue;

                    if (j == 0)
                    {
                        next[j] += dp[j];
                        next[j] %= mask;
                    }
                    else
                    {
                        next[j - 1] += dp[j];
                        next[j - 1] %= mask;
                    }
                    next[j + 1] += dp[j] * 2;
                    next[j+1] %= mask;
                }
                dp = next;
            }

            long res = dp[s.Length];
            long pats = 1;
            for(int i = 0; i < s.Length; i++)
            {
                pats *= 2;
                pats %= mask;
            }
            res = MultiMod(res, ReverseMod(pats, mask - 2, mask), mask);
            WriteLine(res);
        }

        static long MultiMod(long a, long b, long mask)
        {
            return ((a % mask) * (b % mask)) % mask;
        }

        static long ReverseMod(long a, long pow, long mask)
        {
            if (pow == 0) return 1;
            else if (pow == 1) return a % mask;
            else
            {
                long halfMod = ReverseMod(a, pow / 2, mask);
                long nextMod = MultiMod(halfMod, halfMod, mask);
                if (pow % 2 == 0)
                {
                    return nextMod;
                }
                else
                {
                    return MultiMod(nextMod, a, mask);
                }
            }
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}