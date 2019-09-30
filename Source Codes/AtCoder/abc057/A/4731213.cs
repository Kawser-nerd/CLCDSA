using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program {
        static void Main(string[] Args) {
            WriteLine(new List<string>(ReadLine().Split(' ')).Select(int.Parse).Sum() % 24);

            ReadLine();
        }
    }
}