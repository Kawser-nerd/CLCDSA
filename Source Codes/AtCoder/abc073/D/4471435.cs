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

        private static int[] r;
        private static bool[] color;
        private static int[] path;
        private static long[,] g;
        static void Solve()
        {

            var o = ReadAndParseIntArr();
            var N = o[0];
            var M = o[1];
            var R = o[2];
            r = ReadAndParseIntArr();
            color = new bool[r.Length];
            path = new int[r.Length];

            g = new long[N + 1, N + 1];
            for(int i=0;i<=N;++i)
            {
                for(int j=0;j<=N;++j)
                {
                    g[i, j] = long.MaxValue;
                }
            }
            for(int i=0;i<M;++i)
            {
                o = ReadAndParseIntArr();
                var a = o[0];
                var b = o[1];
                var c = o[2];
                g[a, b] = c;
                g[b, a] = c;
            }

            // floyd warshall
            for(int k=0;k<=N;++k)
            {
                for(int i=0;i<=N;++i)
                {
                    if( g[i, k] == long.MaxValue) { continue; }
                    for(int j=0;j<=N;++j)
                    {
                        if( g[k, j] == long.MaxValue) { continue; }
                        g[i, j] = Math.Min(g[i, j], g[i, k] + g[k, j]);
                    }
                }
            }

            var ans = dfs(r.Length);
            Console.WriteLine(ans);

        }
        private static long dfs(int d)
        {
            if( d == 0)
            {
                // ??
                long len = 0;
                for(int i=1;i<path.Length;++i)
                {
                    int v0 = r[path[i - 1]];
                    int v1 = r[path[i]];
                    // ??????
                    if( g[v0, v1] == long.MaxValue)
                    {
                        return long.MaxValue;
                    }
                    len += g[v0, v1];
                }
                return len;
            }

            long ret = long.MaxValue;
            for(int v=0;v<r.Length;++v)
            {
                if( color[v]) { continue; }
                color[v] = true;
                path[path.Length -d] = v;
                ret = Math.Min(ret, dfs(d - 1));
                color[v] = false;
            }
            return ret;
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

        private static void Swap(ref long x, ref long y)
        {
            long t = x;
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