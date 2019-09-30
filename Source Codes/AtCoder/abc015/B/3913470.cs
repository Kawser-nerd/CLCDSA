using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ???????
            int n = int.Parse(Console.ReadLine());
            var numbers = ReadLine();

            foreach(int num in numbers)
            {
                if (num == 0)
                {
                    n--;
                }
            }

            double d = numbers.Sum() / (double)n;
            Console.WriteLine(Math.Ceiling((decimal)d));
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