using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - AtCoder?????????
            var line = ReadLine();
            int n = line[0];
            int k = line[1];

            var allRates = ReadLine();
            var rates = allRates.OrderBy(x => x).Skip(n - k).ToList();

            Console.WriteLine(GetMaxRate(rates));
        }

        static double GetMaxRate(List<int> rates)
        {
            double max = 0;

            foreach(var rate in rates)
            {
                max = (max + rate) / 2;
            }

            return max;
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