using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N, A, B, K;
        public long M = 998244353;

        public void Run()
        {
            {
                var line = Input.ReadLongArray();
                N = line[0];
                A = line[1];
                B = line[2];
                K = line[3];
            }

            var comb = new FermatCombination(300000);
            long ret = 0;
            for (long a = 0; a <= N; a++)
            {
                long R = K - a * A;
                if (R >= 0 && R % B == 0 && R / B <= N)
                {
                    long b = R / B;
                    ret += comb.Combination(N, a) * comb.Combination(N, b);
                    ret %= M;
                }
            }

            Console.WriteLine(ret);
        }
    }

    // libs ----------
    class FermatCombination
    {
        public long[] Factrial; // ??
        public long[] Inverse; // ??
        public long MOD = 998244353;

        public FermatCombination(int n)
        {

            Factrial = new long[n + 1];
            Inverse = new long[n + 1];
            Factrial[0] = 1;
            Inverse[0] = 1;

            for (int i = 1; i <= n; i++)
            {
                Factrial[i] = (Factrial[i - 1] * i) % MOD;
            }

            for (int i = 1; i <= n; i++)
            {
                // ????????????????
                Inverse[i] = Power(Factrial[i], MOD - 2, MOD) % MOD;
            }
        }

        public long Permutation(long n, long k)
        {
            return Factrial[n] * Inverse[n - k] % MOD;
        }

        public long Combination(long n, long k)
        {
            return Factrial[n] * Inverse[k] % MOD * Inverse[n - k] % MOD;
        }

        public static long Power(long x, long n, long M)
        {
            long tmp = 1;

            if (n > 0)
            {
                tmp = Power(x, n / 2, M);
                if (n % 2 == 0) tmp = (tmp * tmp) % M;
                else tmp = (((tmp * tmp) % M) * x) % M;
            }

            return tmp;
        }
    }

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}