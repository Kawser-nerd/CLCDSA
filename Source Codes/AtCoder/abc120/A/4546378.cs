using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - Favorite Sound
            var line = ReadLine();
            int a = line[0];
            int b = line[1];
            int c = line[2];

            if (b / a > c)
            {
                Console.WriteLine(c);
            }
            else
            {
                Console.WriteLine(b / a);
            }
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            var numbers = new List<int>();

            foreach (var s in array)
            {
                int num = int.Parse(s);
                numbers.Add(num);
            }

            return numbers;
        }
    }
}