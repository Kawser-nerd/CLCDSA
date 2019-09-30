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
            long[] c = new long[n-1];
            long[] s = new long[n-1];
            long[] f = new long[n-1];
            for(int i=0;i<n-1;++i)
            {
                var tmp = ReadAndParseIntArr();
                c[i] = tmp[0];
                s[i] = tmp[1];
                f[i] = tmp[2];
            }

            for(int i=0;i<n-1;++i)
            {
                long sec = CalcSec(i, c, s, f);



                Console.WriteLine(sec);
            }
            Console.WriteLine(0);
        }
        private static long CalcSec(int startStation, long[] c, long[] s, long[] f)
        {
            long time = 0;
            for(int i = startStation;i<c.Length;++i)
            {
                if(s[i] <= time && (time % f[i] == 0))
                {
                    time += c[i];
                }
                else if (time < s[i])
                {
                    time = s[i] + c[i];
                }else
                {
                    // ??
                    //time += (time - s[i]) % f[i];
                    time = f[i] * (long) Math.Ceiling((1.0 + time) / f[i]);
                    time += c[i];
                }
            }
            return time;
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