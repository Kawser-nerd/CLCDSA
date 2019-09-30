using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var abc = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            Console.WriteLine(Math.Min(abc[1] / abc[0], abc[2]));
        }
    }
}