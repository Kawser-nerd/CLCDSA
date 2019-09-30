using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Maximum Sum
            var numbers = ReadLine();
            int k = int.Parse(Console.ReadLine());

            int max = numbers.Max();
            numbers.Remove(max);

            for(int i = 1; i <= k; i++)
            {
                max *= 2;
            }

            int sum = max + numbers.Sum();
            Console.WriteLine(sum);
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            return array.Select(x => int.Parse(x)).ToList();
        }
    }
}