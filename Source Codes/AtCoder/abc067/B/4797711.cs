using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC067_B();
        }

        static void ABC067_B()
        {
            var NK = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var ln = Console.ReadLine().Split(' ').Select(int.Parse).OrderByDescending(x => x).ToArray();
            var sum = 0;

            for (var i = 0; i < NK[1]; i++)
                sum += ln[i];
            Console.WriteLine(sum);
        }
    }
}