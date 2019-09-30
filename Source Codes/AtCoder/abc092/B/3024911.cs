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
            int n = ReadAndParseInt();
            int[] dx = ReadAndParseIntArr();
            int d = dx[0];
            int x = dx[1];
            int[] a = new int[n];
            for(int i=0;i<n;++i)
            {
                a[i] = ReadAndParseInt();
            }

            int sum = x;
            for(int i=0;i<n;++i)
            {
                int tmpa = a[i];
                sum += (d - 1) / tmpa + 1;
            }
            Console.WriteLine(sum);
        }
        
    }
}