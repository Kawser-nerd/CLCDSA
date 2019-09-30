using System;
using System.Linq;

namespace arc033_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] y = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine((double)x.Intersect(y).Count() / x.Union(y).Count());
        }
    }
}