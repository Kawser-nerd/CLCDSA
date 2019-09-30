using System;

namespace abc021_d
{
    class Program
    {
        const int mod = 1000000007;
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
            int n = int.Parse(Console.ReadLine());
            int k = int.Parse(Console.ReadLine());
            fact = new long[n + k]; fact[0] = 1;
            for (int i = 1; i < n + k; i++) fact[i] = fact[i - 1] * i % mod;
            Console.WriteLine(combination(n + k - 1, n - 1));
        }
    }
}