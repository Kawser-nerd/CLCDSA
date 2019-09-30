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
        static void SolveA(string[] args)
        {
            int[] abx = ReadAndParseIntArr();
            int a = abx[0];
            int b = abx[1];
            int x = abx[2];
            x -= a;
            if(0 <= x && x <= b)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
        
    }
}