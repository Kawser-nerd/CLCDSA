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
            var o = ReadAndParseIntArr();
            int h = o[0];
            int w = o[1];
            var a = new string[h];
            for(int i =0;i<h;++i)
            {
                a[i] = Console.ReadLine();

            }
            var list = new List<string>();
            list.Add(GetSharp(w));
            for(int i=0;i<h;++i)
            {
                sb.Clear();
                sb.Append("#");
                sb.Append(a[i]);
                sb.Append("#");
                list.Add(sb.ToString());
            }
            list.Add(GetSharp(w));

            foreach(string sz in list)
            {
                Console.WriteLine(sz);
            }
        }
        private static StringBuilder sb = new StringBuilder();
        private static string GetSharp(int w)
        {
            w += 2;
            sb.Clear();
            for(int i=0;i<w;++i)
            {
                sb.Append("#");
            }
            return sb.ToString();
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