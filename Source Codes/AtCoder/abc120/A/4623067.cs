using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int A = int.Parse(str[0]);
            int B = int.Parse(str[1]);
            int C = int.Parse(str[2]);
            int D = B / A;
            Console.WriteLine("{0}", (D < C)? D: C);
        }
    }
}