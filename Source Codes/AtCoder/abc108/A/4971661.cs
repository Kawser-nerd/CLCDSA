using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var K = int.Parse(Console.ReadLine());

            Console.WriteLine((K / 2) * ((K + 1) / 2));
        }
    }
}