using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            Solve();
        }
        private const int MOD = 1000000007;
        private static Dictionary<string,int> dic = new Dictionary<string, int>();

        static void Solve()
        {
            var o = ReadAndParseIntArr();
            int h = o[0];
            int w = o[1];
            int k = o[2];
            var dp = new int[h + 1, w + 1];
            dp[0, 0] = 1;
            for(int i=0;i<h;++i)
            {
                for(int j=0;j<w;++j)
                {
                    int rowPatternTotal = 1 << (w - 1);
                    for (int a = 0; a < rowPatternTotal; ++a)
                    {
                        bool ok = true;
                        for (int b = 0; b < w - 2; ++b)
                        {
                            bool left = ((a >> b) & 1) != 0;
                            bool right = ((a >> (b + 1)) & 1) != 0;
                            if (left && right)
                            {
                                ok = false;
                            }
                        }
                        if (ok)

                        {
                            if( j >= 1 && ((a >> (j-1)) & 1) != 0)
                            {
                                dp[i + 1, j - 1] += dp[i, j];
                                dp[i + 1, j - 1] %= MOD;
                            }else if( j <= w-2 && ((a >> j) & 1) != 0)
                            {
                                dp[i + 1, j + 1] += dp[i, j];
                                dp[i + 1, j + 1] %= MOD;
                            }
                            else
                            {
                                dp[i + 1, j] += dp[i, j];
                                dp[i + 1, j] %= MOD;
                            }
                        }
                    }
                }
            }
            Console.WriteLine(dp[h, k - 1]);
        }
#region ????????
        private static bool isPrime(long x)
        {
            if (x == 2) { return true; }
            if (x < 2 || x % 2 == 0) { return false; }
            long i = 3;
            while (i * i <= x)
            {
                if (x % i == 0) { return false; }
                i = i + 2;
            }
            return true;
        }
        private static long lcm(long x, long y)
        {
            return x / gcd(x, y) * y;
        }
        private static long gcd(long x, long y)
        {
            return y > 0 ? gcd(y, x % y) : x;
        }
        private static long pow(long x, long n)
        {
            if (n == 0) { return 1; }
            long res = pow(x * x % MOD, n / 2);
            if (n % 2 == 1)
            {
                res = res * x % MOD;
            }
            return res;
        }
        private static int ReadAndParseInt()
        {
            return int.Parse(Console.ReadLine());
        }
        private static int[] ReadAndParseIntArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        }
        private static long ReadAndParseLong()
        {
            return long.Parse(Console.ReadLine());
        }
        private static long[] ReadAndParseLongArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
        }
#endregion
    }
}