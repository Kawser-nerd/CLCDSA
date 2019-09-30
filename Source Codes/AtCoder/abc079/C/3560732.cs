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
            int o = ReadAndParseInt();
            int[] d = new int[] { o % 10, -o % 10 };
            o /= 10;
            int[] c = new int[] { o % 10, -o % 10 };
            o /= 10;
            int[] b = new[] { o % 10, -o % 10 };

            int a = o / 10;

            for(int i=0;i<b.Length;++i)
            {
                int b2 = b[i];

                for (int j=0;j<c.Length;++j)
                {
                    int c2 = c[j];

                    for (int k = 0;k<d.Length;++k)
                    {
                        int d2 = d[k];
                        if( a+b2 + c2 + d2 == 7)
                        {
                            string ans = a.ToString();
                            ans += AddMsg(b2);
                            ans += AddMsg(c2);
                            ans += AddMsg(d2);
                            ans += "=7";
                            Console.WriteLine(ans);
                            return;
                        }
                    }
                }
            }

        }
        private static string AddMsg(int val)
        {
            string tmp = val >= 0 ? "+" : "-";
            return tmp + Math.Abs(val);
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