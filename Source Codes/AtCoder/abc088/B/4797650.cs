using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC088_B();
        }

        static void ABC088_B()
        {
            var N = int.Parse(Console.ReadLine());
            var cards = Console.ReadLine().Split(' ').Select(int.Parse).OrderByDescending(x => x);
            var alice = new List<int>();
            var bob = new List<int>();

            foreach (var card in cards)
            {
                if (alice.Count == bob.Count)
                    alice.Add(card);
                else
                    bob.Add(card);
            }
            Console.WriteLine(alice.Sum() - bob.Sum());
        }
    }
}