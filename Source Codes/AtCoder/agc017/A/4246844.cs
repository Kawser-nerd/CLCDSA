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
        private static long[,] dp = null;
        static void Solve()
        {
            var np = ReadAndParseIntArr();
            int n = np[0];
            int p = np[1];
            var a = ReadAndParseIntArr();
            // even?odd???????
            int evenTotal = 0;
            int oddTotal = 0;
            foreach(var ai in a)
            {
                if( ai % 2 == 0)
                {
                    evenTotal++;
                }
                else
                {
                    oddTotal++;
                }
            }
            int max = Math.Max(evenTotal, oddTotal);
            dp = new long[max+1, max+1];
            long ansEven = 0;

            // ???even??????
            for(int i=0;i<=evenTotal;i++)
            {
                ansEven += Combination(evenTotal, i);
            }

            // odd??????
            if( p % 2 == 0)
            {
                long ansA = 0;
                // odd???????????????
                for(int i = 0;i<=oddTotal;i+=2)
                {
                    ansA += Combination(oddTotal, i);
                }
                ansEven *= ansA;
            }
            else
            {
                long ansA = 0;
                // odd???????????????
                for(int i=1;i<=oddTotal;i+=2)
                {
                    ansA += Combination(oddTotal, i);
                }
                ansEven *= ansA;
            }
            Console.WriteLine(ansEven);
        }
        private static long Combination(long n, long r)
        {
            if( dp[n, r] != 0) { return dp[n, r]; }
            if( r == 0 || r == n) {
                dp[n, r] = 1;
                return 1;
            }
            else if( r == 1) {
                dp[n, r] = n;
                return n;
            }
            else {
                long val = Combination(n - 1, r - 1) + Combination(n - 1, r);
                dp[n, r] = val;
                return val; }
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