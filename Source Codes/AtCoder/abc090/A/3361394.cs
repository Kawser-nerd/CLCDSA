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
            string sz0 = Console.ReadLine();
            string sz1 = Console.ReadLine();
            string sz2 = Console.ReadLine();

            string ans = sz0[0].ToString();
            ans += sz1[1];
            ans += sz2[2];
            Console.WriteLine(ans);
        }
    }
}