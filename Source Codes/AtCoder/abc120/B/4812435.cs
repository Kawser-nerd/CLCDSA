using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
           Console.WriteLine(ABC120_B());
        }

        static int ABC120_B()
        {
            var ABK = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var A = ABK[0];
            var B = ABK[1];
            var K = ABK[2];
            var list = new List<int>();
            for (var i = 1; i <= 100; i++)
            {
                if (A % i == 0 && B % i == 0)
                    list.Add(i);
            }
            return list.OrderByDescending(x => x).ToArray()[K - 1];
        }
    }
}