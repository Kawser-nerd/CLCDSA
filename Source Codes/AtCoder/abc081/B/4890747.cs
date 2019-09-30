using System;
using System.Linq;
using System.Collections.Generic;

namespace abc081_b
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var a = Console.ReadLine().Split(' ').Select(s => int.Parse(s));
            Console.WriteLine(Shift(a));
        }

        static int Shift(IEnumerable<int> A)
        {
            if (A.Any(a => a % 2 == 1)) return 0;
            var count = 1;
            var x = A.Select(s => s / 2);
            count += Shift(x);
            return count;
        }
    }
}