using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var price = 700;

            foreach (var item in input)
            {
                if (item == 'o')
                    price += 100;
            }
            Console.WriteLine(price);

        }

    }

}