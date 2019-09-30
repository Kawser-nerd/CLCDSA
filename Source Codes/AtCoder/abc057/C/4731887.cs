using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program {
        static void Main(string[] Args) {
            long N = long.Parse(ReadLine());
            long sN = (long)Math.Sqrt(N);

            List<int> res = new List<int>();

            for(long A = 1;A <= sN; A++) {
                if(N % A == 0) {
                    long B = N / A;
                    res.Add(Math.Max(A.ToString().Length, B.ToString().Length));
                }
            }

            WriteLine(res.Min());

            ReadLine();
        }
    }
}