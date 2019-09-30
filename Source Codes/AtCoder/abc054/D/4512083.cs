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
        static void Solve()
        {
            var o = ReadAndParseIntArr();
            var n = o[0];
            var ma = o[1];
            var mb = o[2];
            var a = new int[n];
            var b = new int[n];
            var c = new int[n];
            for(int i=0;i<n;++i)
            {
                o = ReadAndParseIntArr();
                a[i] = o[0];
                b[i] = o[1];
                c[i] = o[2];
            }

            var dp = new int[41, 1001, 1001];
            for(int i=0;i<dp.GetLength(0);++i)
            {
                for(int j=0;j<dp.GetLength(1);++j)
                {
                    for (int k = 0; k < dp.GetLength(2); ++k)
                    {
                        dp[i, j,k] = int.MaxValue;
                    }
                }
            }
            dp[0, 0, 0] = 0;
            for(int i=0;i<n;++i)
            {
                var ai = a[i];
                var bi = b[i];
                var ci = c[i];
                for(int xa = 0; xa < dp.GetLength(1); ++xa)
                {
                    for (int xb = 0; xb < dp.GetLength(2); ++xb)
                    {
                        if( dp[i,xa, xb] == int.MaxValue) { continue; }
                        dp[i + 1, xa, xb] =  Math.Min(dp[i+1, xa, xb], dp[i, xa, xb]);
                        dp[i + 1, xa + ai, xb + bi] =  Math.Min(dp[i+1, xa+ai, xb+bi], dp[i, xa, xb] + ci);
                 
                    }
                }
            }
            var ans = int.MaxValue;
            for(int xa = 1; xa < dp.GetLength(1);++xa)
            {
                for (int xb = 1; xb < dp.GetLength(2); ++xb)
                {
                    if (xa % ma == 0 && xb % mb == 0 && xa / ma == xb / mb)
                    //if( xa * mb == xb * ma)
                    {
                        ans = Math.Min(ans, dp[n, xa, xb]);
                    }
                }
            }
            if (ans == int.MaxValue)
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine(ans);
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

        private static void Swap<T>(ref T x, ref T y)
        {
            T t = x;
            x = y;
            y = t;
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

    public class DisjointSet
    {
        private int[] rank;
        private int[] p;
        private int[] size;
        public DisjointSet(int n)
        {
            rank = new int[n];
            p = new int[n];
            size = new int[n];
            for(int i=0;i<n;++i)
            {
                MakeSet(i);
            }
        }
        public void MakeSet(int x)
        {
            p[x] = x;
            rank[x] = 0;
            size[x] = 1;
        }
        public bool IsSame(int x, int y)
        {
            return FindSet(x) == FindSet(y);
        }
        public void Unite(int x , int y)
        {
            Link(FindSet(x), FindSet(y));
        }
        public void Link(int x, int y)
        {
            if( rank[x] > rank[y])
            {
                p[y] = x;
                size[x] += size[y];
                size[y] = 0;
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
                size[x] = 0;
                if( rank[x] == rank[y])
                {
                    rank[y]++;
                }
            }
        }
        public int FindSet(int x)
        {
            if( x != p[x])
            {
                p[x] = FindSet(p[x]);
            }
            return p[x];
        }
        public int Size(int x)
        {
            int root = FindSet(x);
            return size[root];
        }
    }
}