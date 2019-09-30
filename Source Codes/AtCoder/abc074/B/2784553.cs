using System;
using System.Linq;

namespace ABC074_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var k = int.Parse(Console.ReadLine());
            var x = Console.ReadLine().Split().Select(int.Parse).ToArray();

            var d = x.Sum(a => Math.Min(a * 2 , (k - a) * 2));
            Console.WriteLine(d);
        }
    }
}