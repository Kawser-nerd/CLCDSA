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
            int n = ReadAndParseInt();
            string[] s = (Console.ReadLine().Split(' '));
            var hash = new HashSet<string>();
            foreach(var tmp in s)
            {
                if(! hash.Contains(tmp))
                {
                    hash.Add(tmp);
                }
            }
            if( hash.Count == 3)
            {
                Console.WriteLine("Three");
            }
            else
            {
                Console.WriteLine("Four");
            }
        }
    }
}