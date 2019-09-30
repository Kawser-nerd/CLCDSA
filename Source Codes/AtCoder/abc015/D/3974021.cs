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

        static void Solve()
        {
            int w = ReadAndParseInt();
            var nk = ReadAndParseIntArr();
            int n = nk[0];
            int k = nk[1];
            var a = new int[n];
            var b = new int[n];
            
            for(int i=0;i<n;++i)
            {
                var tmp = ReadAndParseIntArr();
                a[i] = tmp[0];
                b[i] = tmp[1];
            }
            var dp = new int[n + 1, k + 1, w + 1];

            for(int i=0;i<n;++i)
            {
                for(int j=0;j<dp.GetLength(1);++j)
                {
                    for(int c=0;c<dp.GetLength(2);++c)
                    {
                        if (j - 1 >= 0 && c - a[i] >= 0)
                        {
                            dp[i + 1, j, c] = Math.Max(dp[i, j - 1, c - a[i]] + b[i], dp[i, j, c]);
                        }
                        else
                        {
                            dp[i + 1, j, c] = dp[i, j, c];
                        }
                    }
                
                }
            }
            int ans = 0;
            for(int i=0;i<dp.GetLength(1);++i)
            {
                for(int j=0;j<dp.GetLength(2);++j)
                {
                   
                        ans = Math.Max(ans, dp[n, i, j]);
                    
                }
            }
            Console.WriteLine(ans);
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