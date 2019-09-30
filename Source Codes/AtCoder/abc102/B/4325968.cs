using System;
using System.Linq;

namespace B.Maximum_Difference
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Ai = Console.ReadLine().Split().Select(int.Parse);

            Console.WriteLine(Math.Abs(Ai.Max() - Ai.Min()));
        }
    }
}