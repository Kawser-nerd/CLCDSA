using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ABC_110
{
    class D
    {

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            long m = long.Parse(input[1]);
            long mask = 1000000000 + 7;
            long[] primes = PrimeNumbers(1, (long)Math.Sqrt(m));
            var primeCnts = new long[primes.Length];
            long mSub = m;
            for(int i = 0; i < primes.Length; i++)
            {
                while (mSub % primes[i] == 0)
                {
                    mSub /= primes[i];
                    primeCnts[i]++;
                }
                //Console.WriteLine(primes[i] + " " + primeCnts[i]);
            }
            long res = 1;
            for(int i = 0; i < primes.Length; i++)
            {
                if (primeCnts[i] == 0) continue;

                res *= Combination(primeCnts[i] + n - 1, primeCnts[i], mask);
                res %= mask;
            }
            if (mSub > 1)
            {
                res *= n;
                res %= mask;
            }
            Console.WriteLine(res);
        }

        static long Combination(long n, long m, long mask)
        {
            if (n - m < m)
            {
                m = n - m;
            }

            long val = Permutation(n, m, mask);
            for (int i = 1; i <= m; i++)
            {
                val = MultiMod(val, ReverseMod(i, mask - 2, mask), mask);
            }
            return val;
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

        static long[] PrimeNumbers(long min, long max)
        {
            var primes = new List<long>();
            if (min <= 2 && max >= 2)
            {
                primes.Add(2);
            }
            for (long i = 3; i <= max; i += 2)
            {
                long rootI = (long)Math.Sqrt(i);
                bool isPrime = true;
                for (long j = 3; j <= rootI; j += 2)
                {
                    if (i % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (isPrime)
                {
                    primes.Add(i);
                }
            }
            return primes.ToArray();
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