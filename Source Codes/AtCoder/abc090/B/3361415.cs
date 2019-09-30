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
            var ab = ReadAndParseIntArr();
            int a = ab[0];
            int b = ab[1];
            int cnt = 0;
            for(int i=a;i<=b;++i)
            {
                string sz = i.ToString();
                if( sz[0] == sz[4] && sz[1] == sz[3])
                {
                    cnt++;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}