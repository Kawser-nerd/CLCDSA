using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long MOD = 1000000007;

        public void Run()
        {
            var comb = new FermatCombination(1000000);

            N = Input.ReadInt();

            long ret = 0;
            {
                var v = comb.Permutation(N - 1, N - 1);
                ret += (v * (N)) % MOD;
                ret %= MOD;
            }

            for (int k = 0; k < N; k++)
            {
                // C(K ? 1, N ? 1 ? K) × K! × (N ? 1 ? K)!  

                if (k - 1 < N - 1 - k) continue;
                var v1 = comb.Combination(k - 1, N - 1 - k);
                var v2 = comb.Permutation(k, k);
                var v3 = comb.Permutation(N - 1 - k, N - 1 - k);
                var v = (((v1 * v2) % MOD) * v3) % MOD;
                ret += (MOD - v);
                ret %= MOD;
            }

            Console.WriteLine(ret);
        }
    }

    // libs ----------
    // ????????????????
    class FermatCombination
    {
        public long[] Factrial; // ??
        public long[] Inverse; // ??
        public long MOD = 1000000007;

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
                Inverse[i] = Power(Factrial[i], (int)MOD - 2, MOD) % MOD;
            }
        }

        public long Permutation(int n, int k)
        {
            return Factrial[n] * Inverse[n - k] % MOD;
        }

        public long Combination(int n, int k)
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