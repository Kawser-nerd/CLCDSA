using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_096
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            long[] primes = PrimeNumbers(1, 55555);
            int primeI = 0;
            for(int i = 0; i < n; i++)
            {
                for (; primeI < primes.Length; primeI++)
                {
                    if (primes[primeI] % 5 == 1)
                    {
                        Console.Write(primes[primeI] + " ");
                        primeI++;
                        break;
                    }
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