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
            WriteLine(new List<string>(ReadLine().Split(' ')).Select(int.Parse).Max());

            ReadLine();
        }
    }
}