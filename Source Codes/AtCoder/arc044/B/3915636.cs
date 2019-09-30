using System;
using System.Linq;

namespace arc044_b
{
    class Program
    {
        const int mod = 1000000007;
        static long Calc_pow(long x, long pow)
        {
            if (pow == 0) return 1;
            long a = Calc_pow(x, pow / 2);
            a = a * a % mod;
            if (pow % 2 == 1) a *= x;
            return a % mod;
        }
        static long Bitshift(long count)
        {
            if (count == 0) return 1;
            long a = Bitshift(count / 2);
            a = a * a % mod;
            if (count % 2 == 1) a *= 2;
            return a % mod;
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int max = x.Max();
            long[] count = new long[max + 1];
            for (int i = 0; i < n; i++) count[x[i]]++;
            long ret = 1;
            if (x[0] == 0 && count[0] == 1)
            {
                for (int i = 1; i <= max; i++)
                {
                    long now = Bitshift(count[i - 1]) - 1 + mod; now %= mod;
                    ret *= Calc_pow(now, count[i]); ret %= mod;
                    ret *= Bitshift(count[i] * (count[i] - 1) / 2); ret %= mod;
                }
                Console.WriteLine(ret);
            }
            else Console.WriteLine(0);
        }
    }
}