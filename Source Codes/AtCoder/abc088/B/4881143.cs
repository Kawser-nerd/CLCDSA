using System;
using System.Linq;

namespace B___Card_Game_for_Two
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Ai = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).ToArray();

            Console.WriteLine(Ai.Where((e, i) => i % 2 == 0).Sum() - Ai.Where((e, i) => i % 2 == 1).Sum());
        }
    }
}