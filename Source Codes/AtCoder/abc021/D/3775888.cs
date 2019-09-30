using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_021
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadLong();
            long k = ReadLong();
            long mask = 1000000000 + 7;
            Console.WriteLine(Combination(n + k - 1, k, mask));
        }

        static long Combination(long n, long m, long mask)
        {
            if (n - m < m)
            {
                m = n - m;
            }

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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}