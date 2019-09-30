using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - 105
            int n = int.Parse(Console.ReadLine());
            int divisors = 0;

            if (n >= 195)
            {
                divisors = 5;
            }
            else if (n >= 189)
            {
                divisors = 4;
            }
            else if (n >= 165)
            {
                divisors = 3;
            }
            else if (n >= 135)
            {
                divisors = 2;
            }
            else if (n >= 105)
            {
                divisors = 1;
            }

            Console.WriteLine(divisors);
        }
    }
}