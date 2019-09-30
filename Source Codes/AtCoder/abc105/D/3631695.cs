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
        private static Dictionary<string,int> dic = new Dictionary<string, int>();

        static void Solve()
        {
            var o = ReadAndParseIntArr();
            long n = o[0];
            long m = o[1];
            var a = ReadAndParseLongArr();

            var accum = new long[n+1];
            for(int i=0;i<n;++i)
            {
                accum[i+1] =  (accum[i] + a[i]) % m;
            }

            Dictionary<long, long> dic = new Dictionary<long, long>();
            long ans = 0;
            for(int i=0;i<accum.Length;++i)
            {
                long key = accum[i];
                if( dic.ContainsKey(key))
                {
                    ans += dic[key];
                    dic[key]++;
                }
                else
                {
                    dic.Add(key, 1);
                }
            }
            Console.WriteLine(ans);
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