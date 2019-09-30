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
            var Length = (input.Length-2).ToString();
            Console.WriteLine(input[0]+Length+input[input.Length-1]);
        }

    }

}