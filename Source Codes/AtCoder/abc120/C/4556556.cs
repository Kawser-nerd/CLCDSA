using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - Unification
            string s = Console.ReadLine();

            int zeros = s.Count(x => x == '0');
            int ones = s.Length - zeros;

            if (zeros > ones)
            {
                Console.WriteLine(ones * 2);
            }
            else
            {
                Console.WriteLine(zeros * 2);
            }
        }
    }
}