using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC114
{
    class Program
    {
        public static void Main(string[] args)
        {
            int X = int.Parse(Console.ReadLine());
            Console.WriteLine(
                (X == 3 || X == 5 || X == 7)? "YES":
                "NO"
            );
        }
    }
}