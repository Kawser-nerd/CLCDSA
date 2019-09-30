using System;
using System.Collections.Generic;
using System.Linq;
namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            Solve();
        }
        private const int MOD = 1000000007;
        private static long n;
        private static long maxw;
        private static long[] v;
        private static long[] w;
        static void Solve()
        {
            var nk = ReadAndParseIntArr();
            int n = nk[0];
            int k = nk[1];
            var a = new int[n];
            var sum = new int[n+1];
            for(int i=0;i<n;++i)
            {
                a[i] = ReadAndParseInt();
                
                sum[i+1] = sum[i] + a[i];
               
            }

            if( sum[n] == k)
            {
                Console.WriteLine(1);
                return;
            }

            var dp = new long[n + 1, n + 1];
            for(int i=0;i<dp.GetLength(0);++i)
            {
                for(int j=0;j<dp.GetLength(1);++j)
                {
                    dp[i, j] = long.MaxValue / 2;
                }
            }
            dp[0, 0] = 0;
            dp[1, 0] = 0;
            dp[1, 1] = 1;
            for (int i = 1; i < n; ++i)
            {
                for (int j = 0; j < i+1; ++j)
                {
                    if( dp[i,j] == long.MaxValue / 2) { continue; }

                    // good 
                    long win = dp[i, j] * a[i] / sum[i] + 1;
                    if( win <= a[i])
                    {
                        dp[i + 1, j + 1] = dp[i, j] + win;
                    }
                    // same
                    dp[i + 1, j] = Math.Min(dp[i + 1, j], dp[i, j]);
                }
            }
            long ans = 0;
            for(int i = 0; i < dp.GetLength(1); ++i)
            {
                if( dp[n, i] <= k)
                {
                    ans= Math.Max(i, ans);
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

        /// <summary>
        /// ???????????????????
        /// </summary>
        /// <typeparam name="T">???????</typeparam>
        /// <param name="arr">??????????????????</param>
        /// <param name="start">??????? [inclusive]</param>
        /// <param name="end">??????? [exclusive]</param>
        /// <param name="value">?????</param>
        /// <param name="comparer">????(????????)</param>
        /// <returns>????????????????</returns>
        public static int LowerBound<T>(IReadOnlyList<T> arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            int mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static int LowerBound<T>(IReadOnlyList<T> arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Count, value, Comparer<T>.Default);
        }

        /// <summary>
        /// ?????????????????????
        /// </summary>
        /// <typeparam name="T">???????</typeparam>
        /// <param name="arr">??????????????????</param>
        /// <param name="start">??????? [inclusive]</param>
        /// <param name="end">??????? [exclusive]</param>
        /// <param name="value">?????</param>
        /// <param name="comparer">????(????????)</param>
        /// <returns>??????????????????</returns>
        public static int UpperBound<T>(IReadOnlyList<T> arr, int start, int end, T value, IComparer<T> comparer)
        {
            int low = start;
            int high = end;
            int mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static int UpperBound<T>(IReadOnlyList<T> arr, T value)
        {
            return UpperBound(arr, 0, arr.Count, value, Comparer<T>.Default);
        }
        #endregion
    }
}