using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
            var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            int n = (int)input[0];
            long m = input[1];
            var rtm = Math.Pow(m, 0.5);
            if (n == 1)
            {
                Console.WriteLine(m);
                return;
            }
            var prev = m;
            for (int i = 1; i <= rtm; i++)
            {
                if (m % i != 0) continue;
                if (n <= i)
                {
                    Console.WriteLine(m/i);
                    return;
                }


                if (m / i < n)
                {
                    Console.WriteLine(prev);
                    return;
                }
                prev = i;
            }
            Console.WriteLine(prev);
    }
}