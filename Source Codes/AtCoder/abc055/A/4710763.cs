using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program {
        static void Main(string[] Args) {
            int N = int.Parse(ReadLine());
            WriteLine((N * 800) - (N / 15) * 200);

            ReadLine();
        }
    }
}