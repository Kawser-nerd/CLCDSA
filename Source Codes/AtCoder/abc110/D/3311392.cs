using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice
{
    class Program
    {
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
        static void Main(string[] args)
        {
            SolveA(args);
            //SolveB(args);
            //SolveC(args);
            //SolveD(args);


        }

        private const long MOD = 1000000007;
        static void SolveA(string[] args)
        {
            var nm = ReadAndParseIntArr();
            int n = nm[0];
            int m = nm[1];

            long ans = 1;
            var prime = TryRivision(m);
            foreach(var pair in prime)
            {
                int p = pair.Key;
                int b = pair.Value;
                ans *= Comp(b + n - 1, n - 1);
                ans %= MOD;
            }
            Console.WriteLine(ans);
        }
       
        /// <summary>
        /// ?????
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        private static Dictionary<int, int> TryRivision(int n)
        {
            var hash = new Dictionary<int, int>();
            int k = (int) Math.Sqrt(n);
             for(int i = 2; i<=k;++i)
            {
                while (true)
                {
                    if( n % i == 0)
                    {
                        if (hash.ContainsKey(i))
                        {
                            hash[i]++;
                        }
                        else
                        {
                            hash.Add(i, 1);
                        }
                        n /= i;
                    }
                    else
                    {
                        break;
                    }
                }
            }
             if( n != 1)
            {
                hash.Add(n, 1);
            }
            return hash;
        }

        private static long Comp(int a, int b)
        {
            long top = 1;
            for(int i=0;i<b;++i)
            {
                top *= (a - i);
                top %= MOD;
            }
            long btm = 1;
            for(int i=0;i<b;++i)
            {
                btm *= (b - i);
                btm %= MOD;
            }

            btm = ModInv(btm);
            return top * btm % MOD;
        }
        private static long ModInv(long a)
        {
            return ModPow(a, MOD - 2);
        }
        private static long ModPow(long a, long n)
        {
            if (n == 0)
            {
                return 1;
            }
            long res = ModPow(a * a % MOD, n / 2);
            if( n % 2 == 1)

            {
                res = res * a % MOD;
            }
            return res;
        }

    }
}