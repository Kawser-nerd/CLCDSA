using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - Maximize the Formula
            var line = ReadLine();

            var numbers = line.OrderByDescending(n => n).ToList();

            string s = numbers[0].ToString() + numbers[1].ToString();
            int x = int.Parse(s);
            int y = numbers[2];

            Console.WriteLine(x + y);
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