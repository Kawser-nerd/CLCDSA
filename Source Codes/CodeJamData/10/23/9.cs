using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamCs
{
    class Program
    {
        public static int[,] memo;
        public static int[,] c;
        public const int MODULO = 100003;

        public static void Main(string[] args)
        {
            using (var reader = new StreamReader("C.in"))
            using (var writer = new StreamWriter("C.out"))
            {
                int testCount = int.Parse(reader.ReadLine());
                for (int test = 1; test <= testCount; test++)
                {
                    int n = int.Parse(reader.ReadLine());
                    memo = new int[n + 1,n + 1];
                    for (int i = 0; i <= n; ++i)
                        for (int j = 0; j <= n; ++j)
                            memo[i, j] = -1;
                    c = new int[n + 1, n + 1];
                    for (int i = 0; i <= n; i++)
                    {
                        c[i, 0] = 1;
                        for (int j = 1; j <= i; j++)
                            c[i, j] = (c[i - 1, j] + c[i - 1, j - 1]) % MODULO;
                    }

                    int ans = 0;
                    for (int i = 1; i < n; i++)
                        ans = (ans + f(n, i)) % MODULO;

                    writer.WriteLine("Case #{0}: {1}", test, ans);
                }
            }
        }

        private static int f(int n, int p)
        {
            if (memo[n, p] != -1)
                return memo[n, p];
            if (p == 1)
                return memo[n, p] = 1;
            int ans = 0;
            for (int i = 1; i < p; ++i)
                ans = (int) (ans + (((long) f(p, i) * c[n - p - 1, p - i - 1]) % MODULO) % MODULO);
            ans = ans % MODULO;
            memo[n, p] = ans;
            return ans;
        }
    }
}