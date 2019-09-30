using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_028
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadLong();
            long[] array = ReadLongs();
            var sums = new long[(int)n];
            sums[0] = array[0];
            for (int i = 1; i < n; i++)
            {
                sums[i] = sums[i - 1] + array[i];
            }
            long mask = 1000000000 + 7;
            long permutation = 1;
            for (int i = 1; i < n; i++)
            {
                permutation = (permutation * (i + 1)) % mask;
            }
            var permDivs = new long[n];
            permDivs[0] = permutation;
            long permSum = permutation;
            for (int i = 1; i < n; i++)
            {
                permDivs[i] = (permutation
                    * ReverseMod((i + 1), mask - 2, mask)) % mask;
                permSum += permDivs[i];
                permSum %= mask;
            }
            long res = 0;
            for (int i = 0; i < n / 2; i++)
            {
                res += permSum
                    * ((array[i] + array[n - i - 1]) % mask);
                res %= mask;
                permSum += permDivs[i + 1];
                permSum -= permDivs[n - 1 - i];
                permSum += mask;
                permSum %= mask;
            }
            if (n % 2 == 1)
            {
                res += permSum * array[n / 2];
                res %= mask;
            }
            //Console.WriteLine(permSums[n - 1]);
            Console.WriteLine(res);
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