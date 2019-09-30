using System;
using System.Collections.Generic;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = Console.ReadLine().Split(' ');
            var n1 = int.Parse(a[0]);
            var n2 = int.Parse(a[2]);

            if(a[1]=="+")
            {
                Console.WriteLine(n1+n2);
            }
            else
            {
                Console.WriteLine(n1-n2);
            }
        }
    }
}