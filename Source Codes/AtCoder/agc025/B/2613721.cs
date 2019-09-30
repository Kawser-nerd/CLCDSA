using System;
using System.Linq;

namespace agc025_b
{
    class Program
    {
        const long mod = 998244353;
        public static long calc(long x, long pow)
        {
            if (pow == 0) return 1;
            long a = calc(x, pow / 2);
            a = a * a % mod;
            if (pow % 2 == 1) a *= x;
            return a % mod;
        }
        static long[] fact;
        public static long combination(long n, long r)
        {
            return fact[n] * calc((fact[r] * fact[n - r]) % mod, mod - 2) % mod;
        }
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            fact = new long[x[0] + 100];
            fact[0] = 1;
            for (int i = 1; i < fact.Count(); i++) fact[i] = fact[i - 1] * i % mod;
            long ret = 0;
            for (int i = 0; i <= x[0]; i++)
            {
                if ((x[3] - x[1] * i) % x[2] == 0)
                {
                    long a = (x[3] - x[1] * i) / x[2];
                    if (0 <= a && a <= x[0])
                    {
                        ret += combination(x[0], i) * combination(x[0], a) % mod;
                        ret %= mod;
                    }
                }
            }
            Console.WriteLine(ret);
        }
    }
}