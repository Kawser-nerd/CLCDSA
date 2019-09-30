using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - ????????????
            var line = ReadLine();
            int x = line[0];
            int y = line[1];

            Console.WriteLine(y / x);            
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}