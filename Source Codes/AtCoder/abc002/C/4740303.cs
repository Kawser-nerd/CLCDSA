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
            var lis = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
            decimal a = lis[2] - lis[0];
            decimal b = lis[3] - lis[1];
            decimal c = lis[4] - lis[0];
            decimal d = lis[5] - lis[1];

            WriteLine(Math.Abs(a * d - b * c) / 2);

            ReadLine();
        }
    }
}