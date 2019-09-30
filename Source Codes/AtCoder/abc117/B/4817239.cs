using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC117_B();
        }

        static void ABC117_B()
        {
            var N = int.Parse(Console.ReadLine());
            var Ln = Console.ReadLine().Split(' ').Select(int.Parse).OrderByDescending(x => x).ToList();
            var max = Ln[0];
            Ln.RemoveAt(0);
            if (max < Ln.Sum())
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}