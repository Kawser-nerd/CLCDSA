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
            SolveA();
            //SolveB();
            //SolveC();
            //SolveD();
        }
        private const long MOD = 1000000007;
        private const int White = 0;
        private const int Gray = 1;
        private const int Black = 2;
        private static int[] Color = null;
        private static bool[,] Graph;
        static void SolveA()
        {
            var o = ReadAndParseIntArr();
            int n = o[0];
            int m = o[1];
            Color = new int[n ];
            Graph = new bool[n , n] ;

            var edges = new int[m][];
            for (int i=0;i<m;++i)
            {
                var o1 = ReadAndParseIntArr();
                int a = o1[0]-1;
                int b = o1[1]-1;

                Graph[a, b] = true;
                Graph[b, a] = true;
                edges[i] = new int[] { a, b };
            }
            

            int ans = 0;
            for(int i=0;i<m;++i)
            {
                var edge = edges[i];
                // ???????
                SetEdge( edge, false);
                dfs_init();
                ans += IsBridge() ? 1 : 0;
                SetEdge( edge, true);
            }
            Console.WriteLine(ans);
        }
        private static void SetEdge( int[] edge, bool b)
        {
            Graph[edge[0], edge[1]] = b;
            Graph[edge[1], edge[0]] = b;
        }
        private static void dfs_init()
        {
            for(int i=0;i<Color.Length;++i)
            {
                Color[i] = White;
            }
            dfs(0);
        }
        private static void dfs(int u)
        {
            Color[u] = Gray;
            for(int v=0;v<Color.Length;++v)
            {
                if(Graph[u,v] && Color[v] == White )
                {
                    dfs(v);
                }
            }
            Color[u] = Black;

        }
        private static bool IsBridge()
        {
            return Color.Any(p => p == White);
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
        #endregion
    }
}