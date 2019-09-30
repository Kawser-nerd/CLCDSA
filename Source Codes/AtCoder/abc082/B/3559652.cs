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
            string s = Console.ReadLine();
            string t = Console.ReadLine();
            var listS = new List<char>(s);
            var listT = new List<char>(t);

            listS.Sort();
            listT.Sort();

            bool b = IsValid0(listS, listT) || IsValid1(listS, listT);
            string ans = b ? "Yes" : "No";
            Console.WriteLine(ans);
        }
        private static bool IsValid0(List<char> s, List<char> t)
        {
            if( s.Count >= t.Count) { return false; }
            for(int i=0;i<s.Count;++i)
            {
                if(s[i] != t[i]) { return false; }
            }
            return true;
        }
        private static bool IsValid1(List<char> s, List<char> t)
        {
            for(int i=0;i<s.Count;++i)
            {
                char c = s[i];
                for(int j=i;j<t.Count;++j)
                {
                    if( t[j] > c)
                    {
                        return true;
                    }
                }
                // ???????
                if( i >= t.Count) { return false; }
                if( c != t[i]) { return false; }
            }
            return false;
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