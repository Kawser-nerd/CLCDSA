using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string d = Console.ReadLine();

            switch(d)
            {
                case "25":
                    Console.WriteLine("Christmas");
                    break;
                case "24":
                    Console.WriteLine("Christmas Eve");
                    break;
                case "23":
                    Console.WriteLine("Christmas Eve Eve");
                    break;
                case "22":
                    Console.WriteLine("Christmas Eve Eve Eve");
                    break;
                default:
                    break;
            }

        }

    }
}