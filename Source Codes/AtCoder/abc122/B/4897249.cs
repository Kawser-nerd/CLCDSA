using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace AtCoder.ABC122.B
{
    class Program
    {
        public static void Main()
        {
            // Solve("A"); //1
            // Solve("X"); //0
            // Solve("ATCODER"); //3
            // Solve("HATAGAYA"); //5
            // Solve("SHINJUKU"); //0
            // Solve("ACGTACGT"); //8
            // Solve("AXAXAXAXAX"); //1
            // Solve("AAAAAAAAAA"); //10
            // Solve("TGCAXXXXXX"); //4
            // Solve("TXCAXXXCGA"); //3
            // Solve("XXXXXXXXXA"); //1
            // Solve("AXXXXXXXXX"); //1
            // Solve("AAAAAAAAAX"); // 9 
            // Solve("XAAAAAAAAA"); // 9
            // Solve("AAX"); // 2
            // Solve("XAA"); // 2
            // Solve("AX"); // 1
            // Solve("XA"); // 1
            Solve(Console.ReadLine());
        }
        static void Solve(string S)
        {
            var reg = new Regex(@"^[ACGT]+$");
            if (reg.IsMatch(S))
            {
                Console.WriteLine(S.Length);
                return;
            }
            var max = 0;
            for (int i = 1; i < S.Length; ++i)
            {
                for (int j = 0; j + i <= S.Length; ++j)
                {
                    if (i < max) { continue; }
                    var str = S.Substring(j, i);
                    max = reg.IsMatch(str) ? i : max;
                    //Console.WriteLine($"{str}({j},{i}): {reg.IsMatch(str)}, max={max}");
                }
            }
            Console.WriteLine(max);
        }
    }
}