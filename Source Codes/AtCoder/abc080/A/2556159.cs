using System;
using System.Linq;

namespace ABC080_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var NAB = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var p1 = NAB[0] * NAB[1];
            Console.WriteLine(p1 < NAB[2] ? p1 : NAB[2]);
        }
    }
}