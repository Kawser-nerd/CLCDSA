using System;
using System.Linq;

namespace B.Toll_Gates
{
    class Program
    {
        static void Main(string[] args)
        {
            var NMX = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int N = NMX[0];
            int M = NMX[1];
            int X = NMX[2];

            var Ai = Console.ReadLine().Split().Select(int.Parse).ToArray();

            Console.WriteLine(Math.Min(Ai.Count(i => i > X), Ai.Count(i => i < X)));

        }
    }
}