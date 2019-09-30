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
            int[] nmx = ReadAndParseIntArr();
            int n = nmx[0];
            int m = nmx[1];
            int x = nmx[2];
            int[] tmpa = ReadAndParseIntArr();
            int[] a = new int[n + 1];
            for(int i=0;i<tmpa.Length;++i)
            {
                a[tmpa[i]] = 1;
            }
            int sum0 = 0;
            for(int i=0;i<=x;++i)
            {
                sum0 += a[i];
            }
            int sum1 = 0;
            for(int i=x;i<=n;++i)
            {
                sum1 += a[i];
            }
            int ans = Math.Min(sum0, sum1);
            Console.WriteLine(ans);
        }
        
    }
}