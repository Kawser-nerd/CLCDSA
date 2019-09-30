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
        private static Dictionary<string,int> dic = new Dictionary<string, int>();

        static void Solve()
        {
            int n = ReadAndParseInt();
            for(int i=0;i<n;++i)
            {
                var s = Console.ReadLine();
                SafeAdd(s);
            }

            int m = ReadAndParseInt();
            for(int i=0;i<m;++i)
            {
               var s = Console.ReadLine();
                SafeRemove(s);
            }
            int ans = 0;
            foreach(var p in dic)
            {
                if( p.Value >= 1)
                {
                    ans = Math.Max(ans, p.Value);
                }
            }
            Console.WriteLine(ans);

        }
        private static void SafeAdd(string s)
        {
            if(dic.ContainsKey(s))
            {
                dic[s]++;
            }
            else
            {
                dic.Add(s, 1);
            }
        }
        private static void SafeRemove(string s)
        {
            if (dic.ContainsKey(s))
            {
                dic[s]--;
            }
            else
            {
                dic.Add(s, -1);
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