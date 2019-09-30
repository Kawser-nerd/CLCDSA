using System;
using System.Linq;

namespace A___Round_Up_the_Mean
{
    class Program
    {
        static void Main(string[] args)
        {
            var a_b = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Console.WriteLine(Math.Ceiling(a_b.Average()));
        }
    }
}