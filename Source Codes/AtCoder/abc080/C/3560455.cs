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
       
        static void SolveA()
        {
            int n = ReadAndParseInt();
            int[,] f = new int[n,10];
            int[,] p = new int[n,11];
            for(int i=0;i<n;++i)

            {
                var o = ReadAndParseIntArr();
                for(int j=0;j<o.Length;++j)
                {
                    f[i,j] = o[j];
                }
            }
            for(int i=0;i<n;++i)
            {
                var o = ReadAndParseIntArr();
                for(int j=0;j<o.Length;++j)
                {
                    p[i, j] = o[j];
                }
            }

            int maxProfit = int.MinValue;
            for(int i = 1;i<1024;++i)
            {
                maxProfit = Math.Max(maxProfit, CalcProfit(n, f, p, i));
            }
            Console.WriteLine(maxProfit);
        }
        private static int CalcProfit(int n, int[,] f, int[,] p, int joisino)
        {
            int profit = 0;
            for(int shop=0;shop<n;++shop)
            {
                int c = 0;
                for(int time=0;time<10;++time)
                {
                    if( f[shop, time] == 1 && (joisino & (1 << time)) != 0) { c++; }
                }
                profit += p[shop, c];
            }
            return profit;
        }

        #region ????????
        private static bool isPrime(long x)
        {
            if( x == 2) { return true; }
            if( x < 2 || x % 2 == 0) { return false; }
            long i = 3;
            while( i * i <= x)
            {
                if( x % i == 0) { return false; }
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