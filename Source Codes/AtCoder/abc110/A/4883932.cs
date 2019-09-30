using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC086
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            Array.Sort(a);
            Console.WriteLine(a[2] * 10 + a[1] + a[0]);
        }
    }
}