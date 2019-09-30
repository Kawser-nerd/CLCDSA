using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x=> int.Parse(x)).ToArray();

            var answer = input[0] * 100 + input[1] * 10 + input[2];

            if (answer % 4 == 0) Console.WriteLine( "YES");
            else Console.WriteLine("NO");

        }

    }

}