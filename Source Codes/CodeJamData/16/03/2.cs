using System;
using System.Linq;
using System.Numerics;

namespace CoinJam
{
    class Program
    {
        static int[] Primes =
            {
                    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
            };

        static void Main(string[] args)
        {
            var n = 32;
            var j = 500;

            Console.WriteLine("Case #1:");

            for (var i = (1L << (n-1)) + 1; j > 0 && i < 1L << n ; i += 2)
            {
                var divisors = GetDivisors(i);

                if (divisors != null)
                {
                    Console.WriteLine(ToBits(i) + " " + string.Join(" ", divisors));
                    j--;
                }
            }
        }

        private static string ToBits(long i)
        {
            var s = "";
            while (i > 0)
            {
                s = i % 2 + s;
                i /= 2;
            }
            return s;
        }

        private static int[] GetDivisors(long i)
        {
            var divisors = new int[9];
            for (var j = 0; j < divisors.Length; j++)
            {
                var divisor = GetDivisorForBase(i, j + 2);
                if (divisor.HasValue)
                {
                    divisors[j] = divisor.Value;
                }
                else
                {
                    return null;
                }
            }
            return divisors;
        }

        private static int? GetDivisorForBase(long i, int b)
        {
            var n = InterpretInBase(i, b);

            foreach (var prime in Primes)
            {
                if (n % prime == 0) return prime;
            }

            return null;
        }

        private static BigInteger InterpretInBase(long l, int b)
        {
            var n = BigInteger.Zero;
            var k = BigInteger.One;
            while (l > 0)
            {
                n += (l % 2) * k;
                k *= b;
                l /= 2;
            }
            return n;
        }
    }
}
