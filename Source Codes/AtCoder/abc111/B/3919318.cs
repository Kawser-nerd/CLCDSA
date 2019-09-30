using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - AtCoder Beginner Contest 111
            var line = Console.ReadLine();
            int n = int.Parse(line);

            //???1?????
            var c = line.Substring(0, 1);

            //x?????("x"???????3????????)
            string s = String.Concat(Enumerable.Repeat(c, 3));
            int x = int.Parse(s);

            if (n > x)
            {
                Console.WriteLine(x + 111);
            }
            else
            {
                Console.WriteLine(x);
            }
        }
    }
}