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

        private static int h;
        private static int w;
        private static string[] s;
        private static int[] color;
        private static int[] path;
        private static Queue<int> q = new Queue<int>();
        private static int[,] g;
        static void Solve()
        {
            var o = ReadAndParseIntArr();
            h = o[0];
            w = o[1];
             s = new string[h];
            for(int i=0;i<h;++i)
            {
                s[i] = Console.ReadLine();
            }
            int n = h * w;
             g = new int[n, n];
            int whiteTotal = 0;
            for(int i=0;i<h;++i)
            {
                for(int j=0;j<w;++j)
                {
                    int idx = i * w + j;
                    if(s[i][j] == '#')
                    {
                        //g[idx, idx, i +1, j ] = 
                    }else
                    {
                        whiteTotal++;
                        SetGraph(g, idx, i+1, j, 1);
                        SetGraph(g, idx, i, j+1, 1);
                        SetGraph(g, idx, i-1, j, 1);
                        SetGraph(g, idx, i, j-1, 1);
                    }
                }
            }
            path = new int[n];
            color = new int[n];
            bfs();

            int pathLen = 1;
            int u = path.Length - 1;
            while (true) {
                if(path[u] == -1) { break; }
                else
                {
                    u = path[u];
                    pathLen++;
                }
                    }
            var ans = pathLen == 1 ? -1 : whiteTotal - pathLen;
            Console.WriteLine(ans);
        }
        private static void SetGraph(int[,] g, int idx, int i, int j, int flg)
        {
            
            if( 0 <= i && i < h)
            {
                if( 0 <= j && j < w)
                {
                    int idx2 = i * w + j;
                    if (s[i][j] == '.')
                    {
                        g[idx, idx2] = flg;
                    }
                }
            }
        }
        private static void bfs()
        {
            for(int i=0;i<path.Length;++i)
            {
                path[i] = -1;
            }
            color[0] = 1;
            path[0] =  -1;
            q.Enqueue(0);
            while(q.Count >= 1)
            {
                int u = q.Dequeue();
                for(int v = 0; v < h*w;++v)
                {
                    if( g[u,v] == 1 && color[v] == 0)
                    {
                        color[v] = 1;
                        path[v] = u;
                        q.Enqueue(v);
                    }
                }
                color[u] = 2;
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