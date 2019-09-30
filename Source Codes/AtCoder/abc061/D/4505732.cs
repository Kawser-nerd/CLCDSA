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
        private struct Node
        {
            public long v;
            public long c;
        }
        private static List<Node>[] g;
        private static long[] dist;
        static void Solve()
        {

            var o = ReadAndParseLongArr();
            var n = o[0];
            var m = o[1];
            g = new List<Node>[n];
            for(int i=0;i<g.Length;++i)
            {
                g[i] = new List<Node>();
            }
            for(int i=0;i<m;++i)
            {
                o = ReadAndParseLongArr();
                var a = o[0]-1;
                var b = o[1]-1;
                var c = -o[2];
                g[a].Add(new Node() { v = b, c = c });
            }
            bool positive = BellmanFord(n, 0);
            var ans = dist[n - 1];

            if (positive)
            {
                Console.WriteLine(-ans);
            }
            else
            {
                Console.WriteLine("inf");
            }

        }

        private static bool BellmanFord(long n, long s)
        {
            dist = new long[n];
            for(int i=0;i<n;++i)
            {
                dist[i] = long.MaxValue;
            }
            dist[s] = 0;
            for(int loop=0;loop<n;++loop)
            {
                for(int v=0;v<n;++v)
                {
                    foreach(var node in g[v])
                    {
                        if( dist[v] == long.MaxValue) { continue; }
                        if( dist[node.v] > dist[v] + node.c)
                        {
                            if( loop == n - 1 && node.v == n - 1)
                            {
                                return false;
                            }
                            dist[node.v] = dist[v] + node.c;
                        }
                    }
                }
            }
            return true;
        }

        private static bool Negative2()
        {
            bool[] negatives = new bool[g.Length];
            for(int loop = 0;loop < g.Length;++loop)
            {
                for(int v=0;v<g.Length;++v)
                {
                    if(dist[v] == long.MaxValue) { continue; }
                    var list = g[v];

                    foreach(var node in list)
                    {
                        if( dist[node.v] > dist[v] + node.c)
                        {
                            dist[node.v] = dist[v] + node.c;
                            negatives[node.v] = true;
                        }

                        if (negatives[v] == true)
                        {
                            negatives[node.v] = true;
                    }
                    }
                    
                }
            }
            return negatives[g.Length - 1];
        }

        private static bool Negative()
        {
            for(int v=0;v<g.Length;++v)
            {
                var list = g[v];
                foreach(var node in list)
                {
                    //if (dist[v] == long.MaxValue) { continue; }
                    if ( dist[v] + node.c < dist[node.v])
                    {
                        return true;
                    }
                }
            }
            return false;
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