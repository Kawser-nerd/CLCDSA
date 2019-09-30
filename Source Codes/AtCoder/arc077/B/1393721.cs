using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC077
{
    public class D
    {
        private const long Mod = 1000000000 + 7;

        public static long ModPow(long x, long n, long mod)
        {
            long res = 1;
            while (n > 0)
            {
                if ((n & 1) != 0) { res = (res * x) % mod; }
                x = (x * x) % mod;
                n >>= 1;
            }
            return res;
        }

        public static long ModInverse(long x, long p)
        {
            return ModPow(x, p - 2, p);
        }

        private void Run()
        {
            var n = int.Parse(Console.ReadLine().Trim());
            var A = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();
            var counts = new int[n];
            foreach (var a in A)
            {
                counts[a - 1]++;
            }
            var duplicatedValue = Array.FindIndex(counts, x => x > 1) + 1;
            int firstIndex = Array.IndexOf(A, duplicatedValue);
            int secondIndex = Array.LastIndexOf(A, duplicatedValue);

            var factorial = new long[n + 2];
            factorial[0] = 1;
            for (int i = 1; i < factorial.Length; i++)
            {
                factorial[i] = (i * factorial[i - 1]) % Mod;
            }

            Func<int, int, long> choose = (int n2, int k2) =>
            {
                if (n2 < k2) { return 0; }
                long r = factorial[n2];
                r = (r * ModInverse(factorial[k2], Mod)) % Mod;
                r = (r * ModInverse(factorial[n2 - k2], Mod)) % Mod;
                return r;
            };

            int leftCount = firstIndex;
            int rightCount = A.Length - 1 - secondIndex;

            Console.WriteLine(n); // k==1
            for (int k = 2; k <= n + 1; k++)
            {
                long result = choose(A.Length, k);
                result += Mod - choose(leftCount + rightCount, k - 1);
                result %= Mod;
                Console.WriteLine(result);
            }
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new D().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}