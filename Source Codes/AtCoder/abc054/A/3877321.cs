using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var alice = input[0];
        var bob = input[1];

        if (alice == bob)
        {
            Console.WriteLine("Draw");
        }
        else
        {
            if (alice > bob)
            {
                if (bob == 1)
                {
                    Console.WriteLine("Bob");
                }
                else
                {
                    Console.WriteLine("Alice");
                }
            }
            else
            {
                if (alice == 1)
                {
                    Console.WriteLine("Alice");
                }
                else
                {
                    Console.WriteLine("Bob");
                }
            }
        }
    }
}