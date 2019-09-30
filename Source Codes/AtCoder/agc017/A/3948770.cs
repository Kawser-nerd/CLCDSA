using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _017_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] np = ReadInts();
            int n = np[0];
            int p = np[1];
            int[] array = ReadInts();

            long zeroCnt = 0;
            long oneCnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (array[i] % 2 == 0) zeroCnt++;
                else oneCnt++;
            }
            long zeroPats = (long)Math.Pow(2, zeroCnt);
            long onePats = 0;
            for(long i = 0; i <= oneCnt; i += 2)
            {
                long val = 0;
                long m = Math.Min(oneCnt - i, 0);
                onePats += Combination(oneCnt, i);
            }

            long allPat = (long)Math.Pow(2, n);
            if (p == 0)
            {
                Console.WriteLine(zeroPats * onePats);
            }
            else
            {
                Console.WriteLine(allPat - zeroPats * onePats);
            }
        }

        static long Combination(long n, long m)
        {
            if (n - m < m) m = n - m;

            long val = Permutation(n, m);
            long div = Permutation(m, m);
            return val / div;
        }

        static long Permutation(long n, long m)
        {
            long val = 1;
            for (long i = 0; i < m; i++)
            {
                val *= (n - i);
            }
            return val;
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