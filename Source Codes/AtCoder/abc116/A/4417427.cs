using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] l = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
            Console.WriteLine("{0}", l[0] * l[1] / 2);
        }
    }
}