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

        private static long[,] dp;
        static void Solve()
        {
            var o = ReadAndParseIntArr();
            var n = o[0];
            var c = o[1];
            var d = new int[c ][];
            for(int i=0;i<c;++i)
            {
                d[i] = ReadAndParseIntArr();
            }
            var cc = new int[n][];
            for(int i=0;i<n;++i)
            {
                cc[i] = ReadAndParseIntArr();
            }

            // ????
            var sum = new int[3,c];
            for (int idx = 0; idx < 3; ++idx)
            {
                for (int dstC = 0; dstC < c; ++dstC)
                {
                    int sumi = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < n; ++j)
                        {
                            if ((i + j) % 3 != idx) { continue; }
                            int srcC = cc[i][j]-1;
                            sumi += d[srcC][dstC];
                        }
                    }
                    sum[idx, dstC] = sumi;
                }
            }

            int min = int.MaxValue;
            for(int c0 = 0; c0 < c; ++c0)
            {
                for(int c1 = 0;c1<c;++c1)
                {
                    if( c0 == c1) { continue; }
                    for(int c2 = 0;c2<c;++c2)
                    {
                        if( c2 == c1 || c2 == c0) { continue; }
                        min = Math.Min(min, sum[0, c0] + sum[1, c1] + sum[2, c2]);
                    }
                }
            }
            Console.WriteLine(min);
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