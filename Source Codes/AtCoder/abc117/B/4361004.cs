using System;
using System.Linq;
using System.Collections.Generic;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] L = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
            int max = L[L.Length - 1];
            int sum = L.Sum() - max;
            if (max < sum) { Console.WriteLine("Yes"); }
            else { Console.WriteLine("No"); }
        }
    }
}