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
        private struct Pos
        {
            public int row;
            public int col;
        }
        private const long MOD = 1000000007;
        static void SolveA(string[] args)
        {
            int[][] c = new int[3][];
            c[0] = ReadAndParseIntArr();
            c[1] = ReadAndParseIntArr();
            c[2] = ReadAndParseIntArr();
            for(int b1 = 0; b1<=100;++b1)
            {
                int[] a = new int[3];
                int[] b = new int[3];
                b[0] = b1;
                a[0] = c[0][0] - b1;
                a[1] = c[1][0] - b1;
                a[2] = c[2][0] - b1;
                b[1] = c[0][1] - a[0];
                b[2] = c[0][2] - a[0];
                if(IsValid(a, b, c))
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
            Console.WriteLine("No");
        }
        private static bool IsValid(int[] a, int [] b, int[][] c)
        {
            for(int i=0;i<3;++i)
            {
                for(int j=0;j<3;++j)
                {
                    if( c[i][j] != a[i] + b[j]) { return false; }
                }
            }
            return true;
        }
    }
}