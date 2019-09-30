using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - ABD
            int n = int.Parse(Console.ReadLine());

            if (n <= 999)
            {
                Console.WriteLine("ABC");
            }
            else
            {
                Console.WriteLine("ABD");
            }
        }
    }
}