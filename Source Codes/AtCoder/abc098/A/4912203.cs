using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - Add Sub Mul
            var line = ReadLine();
            int a = line[0];
            int b = line[1];
            var calc = new int[3];

            calc[0] = a + b;
            calc[1] = a - b;
            calc[2] = a * b;

            Console.WriteLine(calc.Max());
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}