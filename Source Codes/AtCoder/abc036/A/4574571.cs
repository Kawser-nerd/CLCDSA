using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - ??
            var line = ReadLine();
            int a = line[0];
            int b = line[1];

            if (b % a == 0)
            {
                Console.WriteLine(b / a);
            }
            else
            {
                Console.WriteLine(b / a + 1);
            }
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}