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
            var a = ReadAndParseIntArr();

            int[] table = { 399, 799, 1199, 1599, 1999, 2399, 2799, 3199 ,4800};
            int[] colorTotals = new int[table.Length];
            for(int i=0;i<a.Length;++i)
            {
                int rate = a[i];
                for(int j=0;j<table.Length;++j)
                {
                    if( rate <= table[j])
                    {
                        colorTotals[j]++;
                        break;
                    }
                }
            }
            int staticColorTotal = 0;
            for(int i=0;i<table.Length-1;++i)
            {
                if( colorTotals[i] >= 1)
                {
                    staticColorTotal++;
                }
            }

            int min = staticColorTotal;
            if( colorTotals[colorTotals.Length-1] >= 1)
            {
                if( staticColorTotal == 0)
                {
                    min = 1;
                }
            }
            int max = staticColorTotal + colorTotals[colorTotals.Length - 1];
            Console.WriteLine($"{min} {max}");
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