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
        const int kWhite = 0;
        const int kGray = 1;
        const int kBlack = 2;
        static int[] d;
        static void Solve()
        {
            var o = ReadAndParseIntArr();
            int n = o[0];
            int m = o[1];
            var u = new int[m];
            var v = new int[m];
            var l = new int[m];
            // ????
            var g = new int[n + 1, n + 1];
            for(int i=0;i<g.GetLength(0);++i)
            {
                for(int j=0;j<g.GetLength(1);++j)
                {
                    g[i, j] = int.MaxValue;
                }
            }
            for (int i=0;i<m;++i)
            {
                o = ReadAndParseIntArr();
                u[i] = o[0];
                v[i] = o[1];
                l[i] = o[2];

                g[u[i], v[i]] = l[i];
                g[v[i], u[i]] = l[i];
            }

            int ans = int.MaxValue;
            for(int i=0;i<=n;++i)
            {
                if( g[1, i] != int.MaxValue)
                {
                    // ????1-i????????????0????????
                    int cost = g[1, i];
                    g[1, i] = int.MaxValue;
                    g[i, 1] = int.MaxValue;
                    g[0, i] = cost;
                    g[i, 0] = cost;

                    dijkstra(n+1, g, 1);
                    if( d[0] != int.MaxValue)
                    {
                        ans = Math.Min(ans, d[0]);
                    }

                    g[1, i] = cost;
                    g[i, 1] = cost;
                    g[0, i] = int.MaxValue;
                    g[i, 0] = int.MaxValue;
                }
            }
            if( ans == int.MaxValue)
            {
                ans = -1;
            }
            Console.WriteLine(ans);
        }
        private static void dijkstra(int n, int[,] g, int s)
        {
            int minv;
            d = new int[n+1];
            int[] color = new int[n+1];
            for(int i=0;i<d.Length;++i)
            {
                d[i] = int.MaxValue;
                color[i] = kWhite;
            }
            d[s] = 0;
            color[s] = kGray;
            while(true)
            {
                minv = int.MaxValue;
                int u = -1;
                for(int i=0;i<n;++i)
                {
                    if( minv > d[i] && color[i] != kBlack)
                    {
                        u = i;
                        minv = d[i];
                    }
                }
                if( u == -1) { break; }
                color[u] = kBlack;
                for(int v = 0;v < n;++v)
                {
                    if( color[v] != kBlack && g[u,v] != int.MaxValue)
                    {
                        if( d[v] > d[u] + g[u,v])
                        {
                            d[v] = d[u] + g[u, v];
                            color[v] = kGray;
                        }
                    }
                }
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