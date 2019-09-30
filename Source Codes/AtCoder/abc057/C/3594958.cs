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

        private class Data
        {
            public long prime;
            public long cnt;
            public Data(long prime, long cnt)
            {
                this.prime = prime;
                this.cnt = cnt;
            }
        }
        static void Solve()
        {
            var n = ReadAndParseLong();
            var list = new List<long>();

            int ans = CalcDigit(n);
            for(long i=1;i*i<=n;++i)
            {
                if (n % i != 0) { continue; }
                long b = n / i;
                int digit = Math.Max(CalcDigit(i), CalcDigit(b));
                ans = Math.Min(ans, digit);
            }
            Console.WriteLine(ans);
        }
        private static int CalcDigit(long n)
        {
            int digit = 0;
            while (n > 0)
            {
                n /= 10;
                digit++;
            }
            return digit;
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