using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var a = int.Parse(input[0]);
            var b = int.Parse(input[1]);
            var c = int.Parse(input[2]);
            var d = int.Parse(input[3]);
            var x = 0;
            var z = 0;
            if (a>c)
            {
                x = a;
            }
            else
            {
                x = c;
            }

            if (b<d)
            {
                z = b;
            }
            else
            {
                z = d;
            }

            //Console.WriteLine(z - x);
            if (z-x<=0)
            {
                Console.WriteLine(0);
            }
            else
            {
                Console.WriteLine(z - x);
            }
        }
    }
}