using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC113
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int X = int.Parse(s[0]);
            int Y = int.Parse(s[1]);
            Console.WriteLine(X + Y / 2);
        }
    }
}