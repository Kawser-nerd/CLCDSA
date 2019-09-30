using System;
using System.Collections.Generic;
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
            var n = ReadAndParseInt();
            var a = ReadAndParseIntArr();
            var listA = new List<int>();
            listA.Add(0);
            listA.AddRange(a);
            listA.Add(0);
            int sum = 0;

            for (int i = 1; i < listA.Count; ++i)
            {
                sum += Math.Abs(listA[i] - listA[i - 1]);
            }


            for (int i = 1; i < listA.Count - 1; ++i)
            {
                int ans = sum;
                int removedPos = listA[i];
                if(InBetween(i, listA))
                {
                    // ???????
                }else if(IsOutside(i, listA))
                {
                    // ?????
                    ans -= 2 * Math.Abs(listA[i - 1] - listA[i]);
                }else if( IsOutside2(i, listA))
                {
                    // ?????
                    ans -= 2 * Math.Abs(listA[i] - listA[i + 1]);
                }

                Console.WriteLine(ans);
            }
        }
        private static bool InBetween(int i, List<int> a)
        {
            return (a[i - 1] <= a[i] && a[i] <= a[i + 1]) ||
                (a[i + 1] <= a[i] && a[i] <= a[i - 1]);
        }

        private static bool IsOutside(int i, List<int> a)
        {
            int a0 = a[i - 1];
            int a1 = a[i];
            int a2 = a[i + 1];
            return (a2 <= a0 && a0 <= a1) || (a1 <= a0 && a0 <= a2);
        }
        private static bool IsOutside2(int i, List<int> a)
        {
            int a0 = a[i - 1];
            int a1 = a[i];
            int a2 = a[i + 1];
            return (a1 <= a2 && a2 <= a0) || (a0 <= a2 && a2 <= a1);
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