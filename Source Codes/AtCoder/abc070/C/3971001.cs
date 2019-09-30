using System;

namespace ABC070_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var T = new long[N];

            for (int i = 0; i < N; i++)
            {
                T[i] = long.Parse(Console.ReadLine());
            }

            Console.WriteLine(Lcm(T));
        }

        private static long Lcm(long[] t)
        {
            var lcm = t[0];
            for (int i = 1; i < t.Length; i++)
            {
                lcm = lcm / Gcd(lcm, t[i]) * t[i];
            }

            return lcm;
        }

        public static long Gcd(long x, long y)
        {
            return (y == 0) ? x : Gcd(y, (x % y));
        }
    }
}