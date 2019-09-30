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
        private static List<long> ps = null;
        static void Solve()
        {
            var nk = ReadAndParseLongArr();
            long n = nk[0];
            long x = nk[1];
            long length = powNoMod(2, n + 2) - 3;

            ps = new List<long>();
            for(int i=0;i<=n;++i)
            {
                ps.Add(powNoMod(2, i + 1) - 1);
            }
            long ans = CalcP(x-1, 0, length - 1, (int)n);
            Console.WriteLine(ans);
        }
        private static long CalcP( long x, long a, long b, int n)
        {
            if(a == b) { return 1; }
            long halfP = (b-a) / 2 + a;
            if( x == a)
            {
                return 0;
            }
            else if( x < halfP)
            {
                return CalcP(x, a + 1, halfP - 1, n-1);
            }else if( x == halfP)
            {
                return ps[n-1] + 1;
            }
            else // (x <= b)
            {
                return ps[n-1] + 1 + CalcP(x, halfP + 1, b - 1, n-1);
            }
        }

        private static long powNoMod(long x, long n)
        {
            if (n == 0) { return 1; }
            long res = powNoMod(x * x , n / 2);
            if (n % 2 == 1)
            {
                res = res * x;
            }
            return res;
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