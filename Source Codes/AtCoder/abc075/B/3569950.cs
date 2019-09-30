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

            var s = new string[h];
            for(int i=0;i<h;++i)
            {
                s[i] = Console.ReadLine();
            }

            char[,] table = new char[h, w];
            for(int y=0;y<h;++y)
            {
                for(int x=0;x<w;++x)
                {
                    if (s[y][x] == '#')
                    {
                        table[y, x] = '#';
                    }
                    else
                    {
                        int total = 0;
                        int sx = Math.Max(0, x - 1);
                        int ex = Math.Min(w - 1, x + 1);
                        int sy = Math.Max(0, y - 1);
                        int ey = Math.Min(h - 1, y + 1);
                        for (int j = sy; j <= ey; ++j)
                        {
                            for (int i = sx; i <= ex; ++i)
                            {
                                if(s[j][i] == '#')
                                {
                                    total++;
                                }
                            }
                        }
                        table[y, x] = (char)('0' + total);
                    }
                }
            }
            for(int y=0;y<h;++y)
            {
                var c = new char[w];
                for(int x=0;x<w;++x)
                {
                    c[x] = table[y, x];
                }
                Console.WriteLine(new string(c));
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