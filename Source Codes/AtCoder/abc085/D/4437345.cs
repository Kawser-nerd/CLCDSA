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
        private struct AB
        {
            public long a;
            public long b;
        }

        static void Solve()
        {
            var o = ReadAndParseIntArr();

            var n = o[0];
            var h = o[1];
            var a = new List<int>();
            var b = new List<int>();
            for(int i=0;i<n;++i)
            {
                o = ReadAndParseIntArr();
                a.Add(o[0]);
                b.Add(o[1]);
            }

            int maxA = a.Max();
            b.Sort();
            b.Reverse();
            var sum = new long[n+1];
            sum[0] = 0;
            for(int i=1;i<sum.Length;++i)
            {
                sum[i] = sum[i - 1] + b[i-1];
            }

            long ans = long.MaxValue;
            for(int throwThord = 0; throwThord < sum.Length;++throwThord)
            {
                long atkTotal = 0;
                long workH = h;
               
                workH -= sum[throwThord];
                atkTotal = throwThord;
                if (workH >= 1)
                {
                    atkTotal += (workH - 1) / maxA + 1;
                }
                ans = Math.Min(ans, atkTotal);
            }

            Console.WriteLine(ans);
        }
        private static int CompareAB(AB x , AB y)
        {
            if( y.a > x.a)
            {
                return 1;
            }else if( y.a < x.a)
            {
                return -1;
            }
            else
            {
                return x.b.CompareTo(y.b);
                   
            }
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