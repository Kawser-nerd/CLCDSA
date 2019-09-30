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
        static int[][] b;
        static int[][] c;
        static char[,] d = new char[3,3];
        static Dictionary<int, int> dic = new Dictionary<int, int>();
        static void Solve()
        {
             b = new int[2][];
            b[0] = ReadAndParseIntArr();
            b[1] = ReadAndParseIntArr();
             c = new int[3][];
            c[0] = ReadAndParseIntArr();
            c[1] = ReadAndParseIntArr();
            c[2] = ReadAndParseIntArr();

            for (int i = 0; i < 3; ++i)
            {
                for(int j=0;j<3;++j)
                {
                    d[i, j] = '.';
                }
            }
            int score = F( 9);
            Console.WriteLine(score);
            int total = 0;
            foreach(var bi in b)
            {
                total += bi.Sum();
            }
            foreach(var ci in c)
            {
                total += ci.Sum();
            }
            Console.WriteLine(total - score);
        }
        private static int F(int turn)
        {
            if(turn == 0)
            {
                return CalcScore();
            }

            int ans = turn % 2 == 0 ? int.MaxValue : 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3;++j)
                {
                    if(d[i,j] != '.') { continue; }

                    d[i, j] = turn % 2 == 0 ? 'x' : 'o';
                    int score = F( turn - 1);
                    d[i, j] = '.';
                    
                    if( turn % 2 == 0) { ans = Math.Min(score, ans); }
                    else { ans = Math.Max(ans, score); }
                }
            }
            return ans;
            
        }
        // ???????
        private static int CalcScore()
        {
            int h = Hash();
            if( dic.ContainsKey(h)) { return dic[h]; }
            int score = 0;
            for(int i = 0;i<b.Length;++i)
            {
                
                for(int j=0;j<b[i].Length;++j)
                {
                    if(d[i,j] == d[i + 1, j])
                    {
                        score += b[i][j];
                    }
                }
            }
            for (int i = 0; i < c.Length; ++i)
            {
                for (int j = 0; j < c[i].Length; ++j)
                {
                    if (d[i, j] == d[i,j+1])
                    {
                        score += c[i][j];
                    }
                }
            }
            dic.Add(h, score);
            return score;
        }
        private static int Hash()
        {
            int h = 0;
            for(int i=0;i<3;++i)
            {
                for(int j=0;j<3;++j)
                {
                    char c = d[i, j];
                    int offset = (i * 3 + j) * 2;
                    if( c == 'o') { h += 1 << offset; }
                    else if( c == 'x') { h += 2 << offset; }
                }
            }
            return h;
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