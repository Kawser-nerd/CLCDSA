using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_B
{
    class _025
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long[] nabk = ReadLongs();
            long n = nabk[0];
            long a = nabk[1];
            long b = nabk[2];
            long k = nabk[3];
            long mask = 998244353;
            long[] permutations = AllPermutations(n, mask);
            long[] combs = new long[n + 1];
            long div = 1;
            for (long i = 0; i <= n; i++)
            {
                div = MultiMod(div, i + 1, mask);
                if (i == 0)
                {
                    combs[i] = 1;
                }
                else
                {
                    combs[i] = MultiMod(permutations[n],
                        ReverseMod(permutations[i], mask - 2, mask), mask);
                    combs[i] = MultiMod(combs[i],
                        ReverseMod(permutations[n - i], mask - 2, mask), mask);
                }
            }
            /*for (int i = 0; i <= n; i++)
            {
                WriteLine(combs[i]);
            }*/
            long res = 0;
            for (long cnt = 0; cnt * b <= k && cnt <= n; cnt++)
            {
                long margin = k - cnt * b;
                if (margin % a > 0 || margin / a > n) continue;

                long val = MultiMod(combs[cnt], combs[margin / a], mask);
                res += val;
                res %= mask;
                //WriteLine(cnt + " " + margin / a);
            }
            WriteLine(res);
        }

        static long Combination(long n, long m, long mask)
        {
            if (n < m) return 0;

            if (n - m < m) m = n - m;

            long val = Permutation(n, m, mask);
            long div = Permutation(m, m, mask);
            return MultiMod(val, ReverseMod(div, mask - 2, mask), mask);
        }

        static long Permutation(long n, long m, long mask)
        {
            long val = 1;
            for (long i = 0; i < m; i++)
            {
                val *= ((n - i) % mask);
                val %= mask;
            }
            return val;
        }

        static long[] AllPermutations(long n, long mask)
        {
            var perms = new long[n + 1];
            perms[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                perms[i] = perms[i - 1] * i;
                perms[i] %= mask;
            }
            return perms;
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