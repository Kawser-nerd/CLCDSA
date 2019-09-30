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
            var charTotalArr = new Dictionary<char, long>();
            for(int i=0;i<n;++i)
            {
                string sz  = Console.ReadLine();
                char c = sz[0];
                if( charTotalArr.ContainsKey(c))
                {
                    charTotalArr[c]++;

                }
                else
                {
                    charTotalArr[c] = 1;
                }
            }
            

            string[] compArr =
            {
                "MAR","MAC","MAH","MRC","MRH","MCH","ARC","ARH","RCH","ACH"
            };
            long total = 0;
            foreach(var seach in compArr)
            {
                if (!charTotalArr.ContainsKey(seach[0])) { continue; }
                if (!charTotalArr.ContainsKey(seach[1])) { continue; }
                if (!charTotalArr.ContainsKey(seach[2])) { continue; }
                total += charTotalArr[seach[0]] * charTotalArr[seach[1]] * charTotalArr[seach[2]];
            }
            Console.WriteLine(total);
        }
    }
}