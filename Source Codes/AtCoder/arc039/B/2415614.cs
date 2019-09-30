using System;
using System.Linq;

namespace arc039_b
{
    class Program
    {
        const int mod = 1000000007;
        public static long calc(long x, long pow)
        {
            if (pow == 1) return x;
            long a = calc(x, pow / 2);
            a = a * a % mod;
            if (pow % 2 == 1)
                a *= x;
            return a % mod;
        }
        static long[] fact;
        public static long combination(long n, long r)
        {
            return fact[n] * calc((fact[r] * fact[n - r]) % mod, mod - 2) % mod;
        }
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            fact = new long[x.Sum() + 1]; fact[1] = 1;
            for (int i = 2; i <= x.Sum(); i++) fact[i] = fact[i - 1] * i % mod;
            if (x[0] > x[1])
            {
                Console.WriteLine(Math.Max(1,combination(x.Sum() - 1, x[1])));
            }
            else
            {
                Console.WriteLine(Math.Max(1, combination(x[0], x[1] % x[0])));
            }
        }
    }
}