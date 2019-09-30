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
        static void Solve()
        {
             b = new int[2][];
            b[0] = ReadAndParseIntArr();
            b[1] = ReadAndParseIntArr();
             c = new int[3][];
            c[0] = ReadAndParseIntArr();
            c[1] = ReadAndParseIntArr();
            c[2] = ReadAndParseIntArr();

            var sb = new StringBuilder();
            for(int i = 0; i < 9; ++i) { sb.Append(' '); }
            int score = F(sb.ToString(), 9);
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
        private static int F(string state, int turn)
        {
            if(turn == 0)
            {
                return CalcScore(state);
            }

            var scoreList = new List<int>();
            for (int i = 0; i < state.Length; ++i)
            {
                if (state[i] != ' ') { continue; }

                var ca = state.ToCharArray();
                ca[i] = turn % 2 == 0 ? 'x' : 'o';
                int score = F(new string(ca), turn - 1);
                scoreList.Add(score);
            }
            if ( turn % 2 == 0)// ??
            {
                return scoreList.Min();
            }
            else// ??
            {
                return scoreList.Max();
            }
            
        }
        // ???????
        private static int CalcScore(string state)
        {
            char[,] table = new char[3, 3];
            for(int i=0;i<state.Length;++i)
            {
                table[i % 3, i / 3] = state[i];
            }
            int score = 0;
            for(int i = 0;i<b.Length;++i)
            {
                
                for(int j=0;j<b[i].Length;++j)
                {
                    if(table[i,j] == table[i + 1, j])
                    {
                        score += b[i][j];
                    }
                }
            }
            for (int i = 0; i < c.Length; ++i)
            {
                for (int j = 0; j < c[i].Length; ++j)
                {
                    if (table[i, j] == table[i,j+1])
                    {
                        score += c[i][j];
                    }
                }
            }
            return score;
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