using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - Day of Takahashi
            var line = ReadLine();
            int a = line[0];
            int b = line[1];

            if (a <= b)
            {
                Console.WriteLine(a);
            }
            else
            {
                Console.WriteLine(a - 1);
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