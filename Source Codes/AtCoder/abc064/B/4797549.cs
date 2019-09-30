using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Math;


namespace AtCodeeeer
{
    class AtCOOOOOOOOOOOder
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            List<int> ls = new List<int>();
            ls.AddRange(ReadLine().Split(' ').Select(int.Parse).ToArray());
            WriteLine(ls.Max() - ls.Min());
        }
    }
}