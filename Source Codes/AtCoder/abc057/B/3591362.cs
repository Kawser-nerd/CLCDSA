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
        private const long MOD = 1000000007;

        static void Solve()
        {
            var o = ReadAndParseIntArr();
            int n = o[0];
            int m = o[1];
            var a = new int[n];
            var b = new int[n];
            for(int i=0;i<n;++i)
            {
                o = ReadAndParseIntArr();
                a[i] = o[0];
                b[i] = o[1];
            }
            var c = new int[m];
            var d = new int[m];
            for(int i=0;i<m;++i)
            {
                o = ReadAndParseIntArr();
                c[i] = o[0];
                d[i] = o[1];
            }

            for(int i=0;i<n;++i)
            {
                int minDist = int.MaxValue;
                int minIdx = int.MaxValue;
                int pa = a[i];
                int pb = b[i];
                for(int j=0;j<m;++j)
                {
                    int dist = Math.Abs(pa - c[j]) + Math.Abs(pb - d[j]);
                    if( dist < minDist)
                    {
                        minDist = dist;
                        minIdx = j;
                    }
                }
                Console.WriteLine(minIdx + 1);
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
        #endregion
    }
}