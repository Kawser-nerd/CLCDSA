using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_039
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string input = Console.ReadLine();
            var keys = new string[7]
            {
                "WBWBWWBWBWBWWBWBWWBW",
                "WBWWBWBWBWWBWBWWBWBW",
                "WWBWBWBWWBWBWWBWBWBW",
                "WBWBWBWWBWBWWBWBWBWW",
                "WBWBWWBWBWWBWBWBWWBW",
                "WBWWBWBWWBWBWBWWBWBW",
                "WWBWBWWBWBWBWWBWBWWB"
            };
            if (keys[0].Equals(input))
            {
                Console.WriteLine("Do");
            }
            else if (keys[1].Equals(input))
            {
                Console.WriteLine("Re");
            }
            else if (keys[2].Equals(input))
            {
                Console.WriteLine("Mi");
            }
            else if (keys[3].Equals(input))
            {
                Console.WriteLine("Fa");
            }
            else if (keys[4].Equals(input))
            {
                Console.WriteLine("So");
            }
            else if (keys[5].Equals(input))
            {
                Console.WriteLine("La");
            }
            else if (keys[6].Equals(input))
            {
                Console.WriteLine("Si");
            }
        }
    }
}