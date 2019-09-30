using System;
using System.Linq;

namespace abc034_c
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
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long[] fact = new long[x.Sum()]; fact[1] = 1;
            for (int i = 2; i < x.Sum(); i++) fact[i] = (fact[i - 1] * i) % 1000000007;
            long inverse_element = calc((fact[x[0] - 1] * fact[x[1] - 1]) % mod, mod - 2);
            Console.WriteLine((fact[x.Sum() - 2] * inverse_element) % mod);
        }
    }
}