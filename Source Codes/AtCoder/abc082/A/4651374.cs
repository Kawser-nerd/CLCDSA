using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            decimal a = Convert.ToDecimal(input[0]);
            decimal b = Convert.ToDecimal(input[1]);

            Console.WriteLine(Math.Ceiling((a + b) / 2));
        }
    }
}