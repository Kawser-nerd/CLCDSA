using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.IO;

namespace ConsoleApp2
{
    class Program {
        static decimal C(int a,int b) {
            decimal res = 1;
            for (int i = 0; i < b; i++) {
                res *= (a - i);
                res /= (i + 1);
            }
            return res;
        }


        static void Main(string[] Args) {
            int K = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList()[1];
            var R = new List<string>(ReadLine().Split(' ')).Select(int.Parse).OrderBy(x => -x).Take(K).OrderBy(x => x).ToList();

            decimal rate = 0;
            foreach (var e in R)
                rate = (rate + e) / 2;

            WriteLine(rate);

            ProgramEndPointLabel:;

            ReadLine();
        }
    }
}