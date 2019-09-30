using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - Rated for Me
            int r = int.Parse(Console.ReadLine());

            if (r < 1200)
            {
                Console.WriteLine("ABC");
            }
            else if (r < 2800)
            {
                Console.WriteLine("ARC");
            }
            else
            {
                Console.WriteLine("AGC");
            }
        }
    }
}