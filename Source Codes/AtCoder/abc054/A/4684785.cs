using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args) {
            List<int> Str = new List<int>{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
            var arg = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList<int>();
            WriteLine(
                (Str.IndexOf(arg[0]) == Str.IndexOf(arg[1]) ? "Draw" :
                (Str.IndexOf(arg[0]) > Str.IndexOf(arg[1]) ? "Alice" : "Bob")));

            ReadLine();


        }
    }
}