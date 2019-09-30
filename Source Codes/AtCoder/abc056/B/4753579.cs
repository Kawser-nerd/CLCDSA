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

            if (lis[0] + lis[1] >= lis[2] && lis[0] + lis[2] >= lis[1])
                WriteLine(0);
            else
                WriteLine(
                    Math.Min(
                        Math.Max(Math.Abs(lis[2] - lis[1] - lis[0]), 0),
                        Math.Max(Math.Abs(lis[1] - lis[0] - lis[2]), 0)
                        )
                    );
            

            ProgramEndPointLabel:;

            ReadLine();
        }
    }
}