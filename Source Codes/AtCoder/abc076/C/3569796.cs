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
        private const string kUnrestorable = "UNRESTORABLE";
        static void SolveA()
        {
            string s = Console.ReadLine();
            string t = Console.ReadLine();
            
            if( t.Length > s.Length)
            {
                Console.WriteLine(kUnrestorable);
                return;
            }
            
            bool isMatch = true;

            var sList = new List<string>();
            for (int start = 0; start + t.Length <= s.Length; ++start)
            {
                var work = s.ToCharArray();
                isMatch = true;
                for (int i = 0; i < t.Length; ++i)
                {
                    if (s[start + i] == '?')
                    {
                        work[start + i] = t[i];
                    }
                    else if (s[start + i] == t[i])
                    {

                    }
                    else
                    {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch)
                {
                    for (int i = 0; i < work.Length; ++i)
                    {
                        if (work[i] == '?')
                        {
                            work[i] = 'a';
                        }
                    }
                    sList.Add(new string(work));
                }
            }

            if (sList.Count >= 1)
            {
                sList.Sort();
                Console.WriteLine(sList[0]);
            }
            else
            {
                Console.WriteLine(kUnrestorable);
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