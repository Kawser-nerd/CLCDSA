using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    { 
        static void Main(string[] args)
        {
            //[summary]A - AtCoder Crackers
            var line = ReadLine();
            int n = line[0];
            int k = line[1];

            if (n % k == 0)
            {
                Console.WriteLine(0);
            }
            else
            {
                Console.WriteLine(1);
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