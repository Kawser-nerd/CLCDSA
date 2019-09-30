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
            int rate = Convert.ToInt32(Console.ReadLine());
            int targetRate = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(targetRate * 2 - rate);
        }
    }
}