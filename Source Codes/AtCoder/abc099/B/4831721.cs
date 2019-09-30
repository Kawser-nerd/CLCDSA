using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Stone Monument
            var line = ReadLine();
            int a = line[0];
            int b = line[1];
            int diff = b - a;

            int height = 0;

            for(int i = 1; i < diff; i++)
            {
                height += i;
            }

            Console.WriteLine(height - a);
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}