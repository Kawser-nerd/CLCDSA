using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var R = int.Parse(Console.ReadLine());

            if (R < 1200)
                Console.WriteLine("ABC");
            else if (R < 2800)
                Console.WriteLine("ARC");
            else
                Console.WriteLine("AGC");
        }
    }
}