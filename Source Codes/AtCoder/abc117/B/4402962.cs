using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] L = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderByDescending(x => x).ToArray();
            int sum = L.Sum() - L[0];
            Console.WriteLine("{0}", (L[0] < sum) ? "Yes" : "No");
        }
    }
}