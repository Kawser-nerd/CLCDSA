using System;
using System.Collections.Generic;

namespace BC_005_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var hs = new SortedSet<int>();
            for (int i = 0; i < n; i++)
                hs.Add(int.Parse(Console.ReadLine()));

            Console.WriteLine(hs.Min);
        }
    }
}