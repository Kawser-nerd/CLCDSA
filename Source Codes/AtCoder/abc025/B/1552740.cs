using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace cs
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] blocks;
            blocks = ReadLine().Split(' ');
            short N = short.Parse(blocks[0]);
            short A = short.Parse(blocks[1]);
            short B = short.Parse(blocks[2]);
            int pos = 0;
            for(int i = 0; i < N; i++)
            {
                blocks = ReadLine().Split(' ');
                short d = short.Parse(blocks[1]);
                if (d < A)
                    d = A;
                else if (d > B)
                    d = B;
                if (blocks[0] == "East")
                    pos += d;
                else
                    pos -= d;
            }
            if (pos > 0)
                Console.WriteLine($"East {pos}");
            else if (pos < 0)
                Console.WriteLine($"West {-pos}");
            else 
                Console.WriteLine($"{pos}");
        }
    }
}