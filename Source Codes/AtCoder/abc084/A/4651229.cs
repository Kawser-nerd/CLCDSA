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
            string input = Console.ReadLine();

            int num1 = Convert.ToInt32(input);

            Console.WriteLine(48 - num1);
        }
    }
}