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
        private static long[] Lucas = new long[100];
        static void SolveA()
        {
            int n = ReadAndParseInt();
            Lucas[0] = 2;
            Lucas[1] = 1;
            for(int i=2;i<=n;++i)
            {
                Lucas[i] = Lucas[i - 1] + Lucas[i - 2];
            }
            Console.WriteLine(Lucas[n]);
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